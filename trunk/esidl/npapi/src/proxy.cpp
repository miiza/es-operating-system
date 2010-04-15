/*
 * Copyright 2009, 2010 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <esnpapi.h>
#include <org/w3c/dom.h>

#include <assert.h>

std::map<const std::string, Object* (*)(ProxyObject object)> ProxyControl::proxyConstructorMap;

ProxyControl::ProxyControl(NPP npp) :
    npp(npp),
    nestingCount(1)
{
}

ProxyControl::~ProxyControl()
{
    printf("%s: newList.size(): %u\n", __func__, newList.size());
    printf("%s: oldList.size(): %u\n", __func__, oldList.size());
    while (!newList.empty())
    {
        ProxyObject* proxy = newList.front();
        proxy->invalidate();
    }
    while (!oldList.empty())
    {
        ProxyObject* proxy = oldList.front();
        proxy->invalidate();
    }
    assert(newList.size() == 0);
    assert(oldList.size() == 0);
}

Object* ProxyControl::createProxy(NPObject* object, const Reflect::Type type)
{
    if (!object)
    {
        return 0;
    }

    std::string className = getInterfaceName(npp, object);
    if (className == "Object")
    {
        // TODO: We should define 'Object' interface
        return 0;
    }

    bool usedHint = false;
    for (;;)
    {
        std::map<const std::string, Object* (*)(ProxyObject object)>::iterator it;
        it = proxyConstructorMap.find(className);
        if (it != proxyConstructorMap.end())
        {
            ProxyObject browserObject(object, npp);
            if (Object* object = (*it).second(browserObject))
            {
                track(interface_cast<ProxyObject*>(object));
                return object;
            }
        }
        if (!type.isObject() || usedHint)
        {
            break;
        }
        className = type.getQualifiedName();
        size_t pos = className.rfind(':');
        if (pos != std::string::npos)
        {
            className = className.substr(pos + 1);
            printf("%s: use the class name '%s' as hinted.\n", __func__, className.c_str());
        }
        usedHint = true;
    }
    return 0;
}

long ProxyControl::enter()
{
    return ++nestingCount;
}

long ProxyControl::leave()
{
    --nestingCount;
    assert(0 <= nestingCount);
    if (nestingCount == 0)
    {
        while (!newList.empty())
        {
            ProxyObject* proxy = newList.front();
            if (0 < proxy->release())
            {
                newList.pop_front();
                assert(proxy);
                assert(proxy->age == ProxyObject::NEW);
                proxy->age = ProxyObject::OLD;
                oldList.push_back(proxy);
            }
        }
    }
    return nestingCount;
}

void ProxyControl::track(ProxyObject* proxy)
{
    assert(proxy);
    assert(proxy->age == ProxyObject::CREATED);
    proxy->age = ProxyObject::NEW;
    newList.push_back(proxy);
}

void ProxyControl::untrack(ProxyObject* proxy)
{
    assert(proxy);
    switch (proxy->age)
    {
    case ProxyObject::NEW:
        newList.remove(proxy);
        break;
    case ProxyObject::OLD:
        oldList.remove(proxy);
        break;
    default:
        break;
    }
}
    
void ProxyControl::registerMetaData(const char* meta, Object* (*createProxy)(ProxyObject object), const char* alias)
{
    Reflect::Interface interface(meta);
    std::string name = interface.getName();
    if (alias)
    {
        name = alias;
    }
    proxyConstructorMap[name] = createProxy;
    printf("%s\n", name.c_str());
}

ProxyObject::ProxyObject(NPObject* object, NPP npp) :
    object(object),
    npp(npp),
    count(0),
    age(CREATED)
{
}

ProxyObject::ProxyObject(const ProxyObject& original) :
    object(original.object),
    npp(original.npp),
    count(original.count),
    age(original.age)
{
    assert(age == CREATED);
}

ProxyObject::~ProxyObject()
{
    // Remove this from newList or oldList if it is still included
    PluginInstance* instance = static_cast<PluginInstance*>(npp->pdata);
    if (!instance)
    {
        return;
    }
    ProxyControl* proxyControl = instance->getProxyControl();
    assert(proxyControl);
    proxyControl->untrack(this);
}

unsigned int ProxyObject::retain()
{
    if (count == 0)
    {
        NPN_RetainObject(object);
    }
    return ++count;
}

unsigned int ProxyObject::release()
{
    if (0 < count)
    {
        if (count == 1)
        {
            NPN_ReleaseObject(object);
        }
        --count;
    }
    if (count == 0)
    {
        delete this;
        return 0;
    }
    return count;
}

unsigned int ProxyObject::mark()
{
    return ++count;
}

void ProxyObject::invalidate()
{
    if (1 < count)
    {
        count = 1;  // Enforce delete by release()
    }
    release();
}

PluginInstance::PluginInstance(NPP npp, NPObject* window) :
    proxyControl(npp),
    stubControl(npp),
    window(0)
{
    npp->pdata = this;
    this->window = interface_cast<org::w3c::dom::html::Window*>(proxyControl.createProxy(window, Reflect::Type("O14::html::Window")));
    if (this->window)
    {
        ProxyObject* proxy = interface_cast<ProxyObject*>(this->window);
        proxy->mark();
        proxy->retain();
    }
}

PluginInstance::~PluginInstance()
{
    if (window)
    {
        window->release();
    }
}
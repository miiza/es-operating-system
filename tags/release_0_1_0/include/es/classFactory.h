/*
 * Copyright (c) 2006
 * Nintendo Co., Ltd.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Nintendo makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */

#ifndef NINTENDO_ES_BASE_ICLASS_FACTORY_TEMPLATE_H_INCLUDED
#define NINTENDO_ES_BASE_ICLASS_FACTORY_TEMPLATE_H_INCLUDED

#include <new>
#include <es.h>
#include <errno.h>
#include <es/exception.h>
#include <es/ref.h>
#include <es/base/IClassFactory.h>

/**
 * This class implements the <code>IClassFactory</code> interface.
 * @param C the class of objects to be constructed from the <code>ClassFactory</code> class.
 *        C must have a default constructor.
 */
template<class C>
class ClassFactory : public es::IClassFactory
{
    Ref ref;

public:
    void* createInstance(const Guid& riid)
    {
        void* objectPtr = 0;
        C* instance = new(std::nothrow) C;
        if (!instance)
        {
            throw SystemException<ENOMEM>();
        }
        objectPtr = instance->queryInterface(riid);
        instance->release();
        return objectPtr;
    }

    void* queryInterface(const Guid& riid)
    {
        void* objectPtr;
        if (riid == es::IClassFactory::iid())
        {
            objectPtr = static_cast<es::IClassFactory*>(this);
        }
        else if (riid == es::IInterface::iid())
        {
            objectPtr = static_cast<es::IClassFactory*>(this);
        }
        else
        {
            return NULL;
        }
        static_cast<es::IInterface*>(objectPtr)->addRef();
        return objectPtr;
    }

    unsigned int addRef(void)
    {
        return ref.addRef();
    }

    unsigned int release(void)
    {
        unsigned int count = ref.release();
        if (count == 0)
        {
            delete this;
        }
        return count;
    }
};

#endif  // #ifndef NINTENDO_ES_BASE_ICLASS_FACTORY_TEMPLATE_H_INCLUDED
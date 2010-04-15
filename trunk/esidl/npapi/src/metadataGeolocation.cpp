/*
 * Copyright 2008-2010 Google Inc.
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

#include "esnpapi.h"
#include "proxyImpl.h"

#include <org/w3c/dom.h>

using namespace org::w3c::dom;

void initializeGeolocationMetaData()
{
    ProxyControl::registerMetaData(geolocation::Coordinates::getMetaData(), Proxy_Impl<ProxyObject, geolocation::Coordinates_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::Geolocation::getMetaData(), Proxy_Impl<ProxyObject, geolocation::Geolocation_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::NavigatorGeolocation::getMetaData(), Proxy_Impl<ProxyObject, geolocation::NavigatorGeolocation_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::PositionCallback::getMetaData(), Proxy_Impl<ProxyObject, geolocation::PositionCallback_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::PositionErrorCallback::getMetaData(), Proxy_Impl<ProxyObject, geolocation::PositionErrorCallback_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::PositionError::getMetaData(), Proxy_Impl<ProxyObject, geolocation::PositionError_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::Position::getMetaData(), Proxy_Impl<ProxyObject, geolocation::Position_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(geolocation::PositionOptions::getMetaData(), Proxy_Impl<ProxyObject, geolocation::PositionOptions_Bridge<Any, invoke> >::createInstance);
}
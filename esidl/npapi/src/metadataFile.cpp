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

void initializeFileMetaData()
{
    ProxyControl::registerMetaData(file::Blob::getMetaData(), Proxy_Impl<ProxyObject, file::Blob_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(file::FileError::getMetaData(), Proxy_Impl<ProxyObject, file::FileError_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(file::File::getMetaData(), Proxy_Impl<ProxyObject, file::File_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(file::FileReader::getMetaData(), Proxy_Impl<ProxyObject, file::FileReader_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(file::FileReaderSync::getMetaData(), Proxy_Impl<ProxyObject, file::FileReaderSync_Bridge<Any, invoke> >::createInstance);

    ProxyControl::registerMetaData(file::FileReader_Constructor::getMetaData(), Proxy_Impl<ProxyObject, file::FileReader_Constructor_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(file::FileReaderSync_Constructor::getMetaData(), Proxy_Impl<ProxyObject, file::FileReaderSync_Constructor_Bridge<Any, invoke> >::createInstance);
}

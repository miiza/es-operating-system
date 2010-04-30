/*
 * Copyright 2008-2010 Google Inc.
 * Copyright 2006, 2007 Nintendo Co., Ltd.
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

#include "test.h"

#include <com/getfirebug/Console.h>

using namespace org::w3c::dom;

#include <math.h>
#include <new>

void TestInstance::down(events::Event* evt)
{
    events::MouseEvent* mouse = interface_cast<events::MouseEvent*>(evt);
    printf("down %p\n", mouse);
    if (mouse)
    {
        printf("(%d, %d), (%d, %d), (%d, %d), (%d, %d), (%d, %d) @ %llu\n",
               mouse->getScreenX(), mouse->getScreenY(),
               mouse->getClientX(), mouse->getClientY(),
               mouse->getPageX(), mouse->getPageY(),
               mouse->getX(), mouse->getY(),
               mouse->getOffsetX(), mouse->getOffsetY(),
               mouse->getTimeStamp());

        html::HTMLCanvasElement* canvas = interface_cast<html::HTMLCanvasElement*>(mouse->getTarget());
        if (canvas)
        {
            html::CanvasRenderingContext2D* context = interface_cast<html::CanvasRenderingContext2D*>(canvas->getContext("2d"));
            if (context)
            {
                int x = mouse->getClientX() - canvas->getOffsetLeft();
                int y = mouse->getClientY() - canvas->getOffsetTop();
                context->setFillStyle("blue");
                context->fillRect(x, y, 5, 5);
            }
        }
    }
    // Test variadic operation
    com::getfirebug::Console* console = interface_cast<com::getfirebug::Console*>(window->getElement("console"));
    printf("console = %p\n", console);
    if (console)
    {
#ifdef __GXX_EXPERIMENTAL_CXX0X__
        console->log("Hello %d %d %d!\n", Sequence<Any>({ 1, 2, 3 }));
#else
        Any params[] = { 1, 2, 3 };
        Sequence<Any> arguments(params, 3);
        console->log("Hello %d %d %d!\n", arguments);
#endif
    }
}

void TestInstance::drawCharts(Document* document)
{
    // Test [Constructor]
    XMLHttpRequest_Constructor* xmlHttpRequest = interface_cast<XMLHttpRequest_Constructor*>(window->getElement("XMLHttpRequest"));
    printf("XMLHttpRequest = %p\n", xmlHttpRequest);
    if (xmlHttpRequest)
    {
        XMLHttpRequest* xhr = xmlHttpRequest->createInstance();
        if (xhr)
        {
            printf("XMLHttpRequest.getReadyState() = %u\n", xhr->getReadyState());
        }
    }

    // Test 'stringifier'
    html::HTMLAnchorElement* anchor = interface_cast<html::HTMLAnchorElement*>(document->getElementById("anchor"));
    printf("anchor = %p\n", anchor);
    if (anchor)
    {
        printf("anchor.getHref() = \"%s\"\n", anchor->getHref().c_str());
    }

    // Test interface_cast implied by the 'implements' statement while Document does
    // not inherit DocumentEvent.
    events::DocumentEvent* documentEvent = interface_cast<events::DocumentEvent*>(document);
    printf("documentEvent = %p\n", documentEvent);

    // Test Nullable
    Nullable<std::string> documentURI = document->getDocumentURI();
    printf("documentURI = %s\n", documentURI.hasValue() ? documentURI.value().c_str() : "null");

    // Test getting a sequence object
    stylesheets::StyleSheetList styleSheets = document->getStyleSheets();
    printf("styleSheets.length = %u\n", styleSheets.getLength());
    for (unsigned i = 0; i < styleSheets.getLength(); ++i)
    {
        stylesheets::StyleSheet* styleSheet = styleSheets[i];
        if (styleSheet)
        {
            printf("    %s\n", styleSheet->getHref().c_str());
        }
    }

    // Test passing a sequence object
    webgl::WebGLByteArray_Constructor* byteArrayConstructor = interface_cast<webgl::WebGLByteArray_Constructor*>(window->getElement("WebGLByteArray"));
    printf("WebGLByteArray_Constructor = %p\n", byteArrayConstructor);
    if (byteArrayConstructor)
    {
        webgl::WebGLByteArray* byteArray = byteArrayConstructor->createInstance(Sequence<webgl::GLbyte>({ 1, 2, 3 }));
        printf("byteArray = %p\n", byteArray);
        if (byteArray)
        {
            for (unsigned i = 0; i < 3; ++i)
            {
                printf("    %d\n", byteArray->get(i));
            }
        }
    }

    // Test BarProp
    html::BarProp* prop = interface_cast<html::BarProp*>(window->getElement("statusbar"));
    printf("prop = %p\n", prop);
    if (prop)
    {
        printf("statusbar.visible = %d\n", prop->getVisible());
    }

    std::string title = interface_cast<html::HTMLDocument*>(document)->getTitle();
    printf("title = %s\n", title.c_str());

    Element* element = document->createElement("div");
    if (element)
    {
        if (Node* node = document->createTextNode("hello, world."))
        {
            element->appendChild(node);
        }
        if (html::HTMLElement* body = interface_cast<html::HTMLDocument*>(document)->getBody())
        {
            body->appendChild(element);
        }
    }

    html::HTMLCanvasElement* canvas = interface_cast<html::HTMLCanvasElement*>(document->getElementById("canvas"));
    if (!canvas)
    {
        return;
    }

    html::CanvasRenderingContext2D* context = interface_cast<html::CanvasRenderingContext2D*>(canvas->getContext("2d"));
    if (!context)
    {
        return;
    }

    context->setFillStyle("white");
    context->fillRect(0, 0, 640, 480);

    // Bar graph
    float top = 50.0f;
    float bottom = 250.0f;

    float width = 20.0f;
    float height;
    float x;
    float y;

    context->setStrokeStyle("rgb(0, 0, 0)");

    height = 100.0f;
    x = 100.0f;
    context->setLineWidth(3);
    context->setFillStyle("rgb(255, 0, 0)");

    context->fillRect(x, bottom - height, width, height);

    x += 50.0f;
    height = 200.0f;
    context->setFillStyle("rgb(0, 255, 0)");
    context->fillRect(x, bottom - height, width, height);

    x += 50.0f;
    height = 80.0f;
    context->setFillStyle("rgb(0, 0, 255)");
    context->fillRect(x, bottom - height, width, height);

    x += 50.0f;
    height = 50.0f;
    context->setFillStyle("rgb(255, 255, 0)");
    context->fillRect(x, bottom - height, width, height);

    x += 50.0f;
    height = 30.0f;
    context->setFillStyle("rgb(0, 255, 255)");
    context->fillRect(x, bottom - height, width, height);

    context->moveTo(80.0f, top);
    context->lineTo(80.0f, bottom);
    context->lineTo(350.0f, bottom);
    context->setLineWidth(4);
    context->stroke();

    // Circle graph
    float r = 100.0f;  // radius
    float cx = 180.0f; // center
    float cy = 450.0f; // center
    // angle
    float s = 270.0f/180.0f;
    float e = 120.0f/180.0f;

    context->setFillStyle("rgb(255, 0, 0)");
    context->beginPath();
    context->arc(cx, cy, r, M_PI * s, M_PI * e, 0);
    context->lineTo(cx, cy);
    context->closePath();
    context->fill();

    s = e;
    e = 240.0f/180.0f;
    context->setFillStyle("rgb(0, 255, 0)");
    context->beginPath();
    context->arc(cx, cy, r, M_PI * s, M_PI * e, 0);
    context->lineTo(cx, cy);
    context->closePath();
    context->fill();

    s = e;
    e = 260.0f/180.0f;
    context->setFillStyle("rgb(0, 0, 255)");
    context->beginPath();
    context->arc(cx, cy, r, M_PI * s, M_PI * e, 0);
    context->lineTo(cx, cy);
    context->closePath();
    context->fill();

    s = e;
    e = 270.0f/180.0f;
    context->setFillStyle("rgb(255, 255, 0)");
    context->beginPath();
    context->arc(cx, cy, r, M_PI * s, M_PI * e, 0);
    context->lineTo(cx, cy);
    context->closePath();
    context->fill();

    events::EventTarget* eventTarget = interface_cast<events::EventTarget*>(canvas);
    printf("eventTarget: %p # This must be a non-zero value.\n", eventTarget);
    if (eventTarget && downHandler)
    {
        eventTarget->addEventListener("mouseup", downHandler, true);
    }
}

void TestInstance::initialize()
{
    downHandler = new (std::nothrow) EventHandler(this, &TestInstance::down);

    testClass = new (std::nothrow) TestClass(this);
    if (testClass)
    {
        window->setElement("Test", testClass);
    }

    document = window->getDocument();
    if (document)
    {
        drawCharts(document);
        document->retain();  // Just for testing oldList
    }
}

TestInstance::~TestInstance()
{
    if (downHandler)
    {
        downHandler->release();
    }
    if (testClass)
    {
        testClass->release();
    }
}
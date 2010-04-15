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

void initializeSvgMetaDataO_U()
{
    ProxyControl::registerMetaData(svg::SVGPaint::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPaint_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegArcAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegArcAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegArcRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegArcRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegClosePath::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegClosePath_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoCubicAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoCubicAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoCubicRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoCubicRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoCubicSmoothAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoCubicSmoothAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoCubicSmoothRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoCubicSmoothRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoQuadraticAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoQuadraticAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoQuadraticRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoQuadraticRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoQuadraticSmoothAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoQuadraticSmoothAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegCurvetoQuadraticSmoothRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegCurvetoQuadraticSmoothRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSeg::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSeg_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoHorizontalAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoHorizontalAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoHorizontalRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoHorizontalRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoVerticalAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoVerticalAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegLinetoVerticalRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegLinetoVerticalRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegList::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegList_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegMovetoAbs::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegMovetoAbs_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPathSegMovetoRel::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPathSegMovetoRel_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPatternElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPatternElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPoint::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPoint_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPointList::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPointList_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPolygonElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPolygonElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPolylineElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPolylineElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGPreserveAspectRatio::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGPreserveAspectRatio_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGRadialGradientElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGRadialGradientElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGRectElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGRectElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGRect::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGRect_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGRenderingIntent::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGRenderingIntent_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGScriptElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGScriptElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGSetElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGSetElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGStopElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGStopElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGStringList::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGStringList_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGStylable::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGStylable_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGStyleElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGStyleElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGSVGElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGSVGElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGSwitchElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGSwitchElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGSymbolElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGSymbolElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTests::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTests_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTextContentElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTextContentElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTextElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTextElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTextPathElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTextPathElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTextPositioningElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTextPositioningElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTitleElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTitleElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTransformable::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTransformable_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTransform::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTransform_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTransformList::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTransformList_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTRefElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTRefElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGTSpanElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGTSpanElement_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGUnitTypes::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGUnitTypes_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGURIReference::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGURIReference_Bridge<Any, invoke> >::createInstance);
    ProxyControl::registerMetaData(svg::SVGUseElement::getMetaData(), Proxy_Impl<ProxyObject, svg::SVGUseElement_Bridge<Any, invoke> >::createInstance);
}
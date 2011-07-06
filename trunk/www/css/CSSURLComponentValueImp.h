// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_CSSURLCOMPONENTVALUEIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_CSSURLCOMPONENTVALUEIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/css/CSSURLComponentValue.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class CSSURLComponentValueImp : public ObjectMixin<CSSURLComponentValueImp>
{
public:
    // CSSURLComponentValue
    Nullable<std::u16string> getUrl() __attribute__((weak));
    void setUrl(Nullable<std::u16string> url) __attribute__((weak));
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return css::CSSURLComponentValue::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return css::CSSURLComponentValue::getMetaData();
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_CSSURLCOMPONENTVALUEIMP_H_INCLUDED
// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_COUNTERIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_COUNTERIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/css/Counter.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class CounterImp : public ObjectMixin<CounterImp>
{
public:
    // Counter
    std::u16string getIdentifier();
    std::u16string getListStyle();
    std::u16string getSeparator();
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return css::Counter::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return css::Counter::getMetaData();
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_COUNTERIMP_H_INCLUDED
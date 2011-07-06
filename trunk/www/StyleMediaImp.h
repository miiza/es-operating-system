// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_STYLEMEDIAIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_STYLEMEDIAIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/StyleMedia.h>

#include <org/w3c/dom/html/BooleanCallback.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class StyleMediaImp : public ObjectMixin<StyleMediaImp>
{
public:
    // StyleMedia
    std::u16string getType() __attribute__((weak));
    bool matchMedia(std::u16string mq_list) __attribute__((weak));
    void addMediaListener(std::u16string mq_list, html::BooleanCallback mq_callback) __attribute__((weak));
    void removeMediaListener(std::u16string mq_list, html::BooleanCallback mq_callback) __attribute__((weak));
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::StyleMedia::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::StyleMedia::getMetaData();
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_STYLEMEDIAIMP_H_INCLUDED
// Generated by esidl (r1745).
// This file is expected to be modified for the Web IDL interface
// implementation.  Permission to use, copy, modify and distribute
// this file in any software license is hereby granted.

#ifndef ORG_W3C_DOM_BOOTSTRAP_HTMLTABLEELEMENTIMP_H_INCLUDED
#define ORG_W3C_DOM_BOOTSTRAP_HTMLTABLEELEMENTIMP_H_INCLUDED

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <org/w3c/dom/html/HTMLTableElement.h>
#include "HTMLElementImp.h"

#include <org/w3c/dom/html/HTMLElement.h>
#include <org/w3c/dom/html/HTMLCollection.h>
#include <org/w3c/dom/html/HTMLTableCaptionElement.h>
#include <org/w3c/dom/html/HTMLTableSectionElement.h>

namespace org
{
namespace w3c
{
namespace dom
{
namespace bootstrap
{
class HTMLTableElementImp : public ObjectMixin<HTMLTableElementImp, HTMLElementImp>
{
public:
    // HTMLTableElement
    html::HTMLTableCaptionElement getCaption() __attribute__((weak));
    void setCaption(html::HTMLTableCaptionElement caption) __attribute__((weak));
    html::HTMLElement createCaption() __attribute__((weak));
    void deleteCaption() __attribute__((weak));
    html::HTMLTableSectionElement getTHead() __attribute__((weak));
    void setTHead(html::HTMLTableSectionElement tHead) __attribute__((weak));
    html::HTMLElement createTHead() __attribute__((weak));
    void deleteTHead() __attribute__((weak));
    html::HTMLTableSectionElement getTFoot() __attribute__((weak));
    void setTFoot(html::HTMLTableSectionElement tFoot) __attribute__((weak));
    html::HTMLElement createTFoot() __attribute__((weak));
    void deleteTFoot() __attribute__((weak));
    html::HTMLCollection getTBodies() __attribute__((weak));
    html::HTMLElement createTBody() __attribute__((weak));
    html::HTMLCollection getRows() __attribute__((weak));
    html::HTMLElement insertRow() __attribute__((weak));
    html::HTMLElement insertRow(int index) __attribute__((weak));
    void deleteRow(int index) __attribute__((weak));
    std::u16string getSummary() __attribute__((weak));
    void setSummary(std::u16string summary) __attribute__((weak));
    // HTMLTableElement-30
    std::u16string getAlign() __attribute__((weak));
    void setAlign(std::u16string align) __attribute__((weak));
    std::u16string getBgColor() __attribute__((weak));
    void setBgColor(std::u16string bgColor) __attribute__((weak));
    std::u16string getBorder() __attribute__((weak));
    void setBorder(std::u16string border) __attribute__((weak));
    std::u16string getCellPadding() __attribute__((weak));
    void setCellPadding(std::u16string cellPadding) __attribute__((weak));
    std::u16string getCellSpacing() __attribute__((weak));
    void setCellSpacing(std::u16string cellSpacing) __attribute__((weak));
    std::u16string getFrame() __attribute__((weak));
    void setFrame(std::u16string frame) __attribute__((weak));
    std::u16string getRules() __attribute__((weak));
    void setRules(std::u16string rules) __attribute__((weak));
    std::u16string getWidth() __attribute__((weak));
    void setWidth(std::u16string width) __attribute__((weak));
    // Object
    virtual Any message_(uint32_t selector, const char* id, int argc, Any* argv)
    {
        return html::HTMLTableElement::dispatch(this, selector, id, argc, argv);
    }
    static const char* const getMetaData()
    {
        return html::HTMLTableElement::getMetaData();
    }
    HTMLTableElementImp(DocumentImp* ownerDocument) :
        ObjectMixin(ownerDocument, u"table") {
    }
    HTMLTableElementImp(HTMLTableElementImp* org, bool deep) :
        ObjectMixin(org, deep) {
    }
};

}
}
}
}

#endif  // ORG_W3C_DOM_BOOTSTRAP_HTMLTABLEELEMENTIMP_H_INCLUDED
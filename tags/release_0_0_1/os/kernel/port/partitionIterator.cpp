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

// Disk partition manager. Since this manager can be applied to both
// ATA hard disks and SCSI hard disks, this manager is implemented
// separately from the hard disk device drivers.

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <es.h>
#include <es/handle.h>
#include "partition.h"

using namespace LittleEndian;

//
// PartitionIterator
//

PartitionIterator::
PartitionIterator(PartitionContext* context, int ipos) :
    context(context), ipos(ipos)
{
    context->addRef();
}

PartitionIterator::
~PartitionIterator()
{
    context->release();
}

bool PartitionIterator::
hasNext(void)
{
    Monitor::Synchronized method(context->monitor);

    PartitionStreamList::Iterator iter = context->partitionList.begin();
    int i = 0;
    PartitionStream* stream;
    while (stream = iter.next())
    {
        if (++i == ipos + 1)
        {
            return true;
        }
    }
    return false;
}

IInterface* PartitionIterator::
next()
{
    Monitor::Synchronized method(context->monitor);

    PartitionStreamList::Iterator iter = context->partitionList.begin();
    int i = 0;
    PartitionStream* stream;
    while (stream = iter.next())
    {
        if (++i == ipos + 1)
        {
            ++ipos;
            addRef();
            return static_cast<IBinding*>(this);
        }
    }
    return 0;
}

int PartitionIterator::
remove(void)
{
    // remove() removes the previous item.
    PartitionStreamList::Iterator iter = context->partitionList.begin();
    char name[PartitionContext::MAX_PREFIX_LEN + 4];
    Handle<IBinding> binding;

    --ipos;           // ipos is decremented in order to get the previous item.
    binding = next(); // ipos is restored because next() increments ipos.

    if (binding->getName(name, sizeof(name)) < 0)
    {
        return -1;
    }

    long long ret;
    ret = context->unbind(name);
    if (ret == 0)
    {
        // If the previous item was successfully removed,
        // ipos must be decremented.
        --ipos;
    }
    // ipos indicates the same item as before, after all.
    return ret;
}

//
// PartitionIterator : IBinding
//

IInterface* PartitionIterator::
getObject()
{
    Monitor::Synchronized method(context->monitor);

    PartitionStreamList::Iterator iter = context->partitionList.begin();
    int i = 0;
    PartitionStream* stream;
    while (stream = iter.next())
    {
        if (++i == ipos)
        {
            stream->addRef();
            return static_cast<IStream*>(stream);
        }
    }
    return 0;
}

int PartitionIterator::
setObject(IInterface* object)
{
    return -1;
}

int PartitionIterator::
getName(char* name, unsigned int len)
{
    Monitor::Synchronized method(context->monitor);

    PartitionStreamList::Iterator iter = context->partitionList.begin();
    int i = 0;
    PartitionStream* stream;
    while (stream = iter.next())
    {
        if (++i == ipos)
        {
            u8 id = stream->getId();
            const char* prefix;
            if (stream->isPrimaryPartition())
            {
                prefix = PartitionContext::PREFIX_PRIMARY;
            }
            else if (stream->isExtendedPartition())
            {
                prefix = PartitionContext::PREFIX_EXTENDED;
            }
            else if (stream->isLogicalPartition())
            {
                prefix = PartitionContext::PREFIX_LOGICAL;
            }
            else
            {
                return -1;
            }

            memset(name, len, 0);

            if (stream->isExtendedPartition())
            {
#ifdef WIN32
                return _snprintf(name, len, "%s", prefix);
#else
                return snprintf(name, len, "%s", prefix);
#endif
            }

#ifdef WIN32
            return _snprintf(name, len, "%s%u", prefix, id);
#else
            return snprintf(name, len, "%s%u", prefix, id);
#endif
            return 0;
        }
    }
    return -1;
}

//
// PartitionIterator : IInterface
//

bool PartitionIterator::
queryInterface(const Guid& riid, void** objectPtr)
{
    if (riid == IID_IIterator)
    {
        *objectPtr = static_cast<IIterator*>(this);
    }
    else if (riid == IID_IBinding)
    {
        *objectPtr = static_cast<IBinding*>(this);
    }
    else if (riid == IID_IInterface)
    {
        *objectPtr = static_cast<IIterator*>(this);
    }
    else
    {
        *objectPtr = NULL;
        return false;
    }
    static_cast<IInterface*>(*objectPtr)->addRef();
    return true;
}

unsigned int PartitionIterator::
addRef(void)
{
    return ref.addRef();
}

unsigned int PartitionIterator::
release(void)
{
    unsigned int count = ref.release();
    if (count == 0)
    {
        delete this;
        return 0;
    }
    return count;
}
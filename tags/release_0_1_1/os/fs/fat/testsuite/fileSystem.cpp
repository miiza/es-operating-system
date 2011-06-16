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

#include <new>
#include <stdlib.h>
#include <es.h>
#include <es/handle.h>
#include "vdisk.h"
#include "fatStream.h"

#define TEST(exp)                           \
    (void) ((exp) ||                        \
            (esPanic(__FILE__, __LINE__, "\nFailed test " #exp), 0))

long long writeData(Handle<IContext> root, long long size)
{
    Handle<IFile> file;
    file = root->lookup("testfile.txt");
    if (!file)
    {
        file = root->bind("testfile.txt", 0);
    }
    TEST(file);
    Handle<IStream>  stream = file->getStream();
    TEST(stream);

    long long filesize;
    filesize = file->getSize();

    char* buf = new char[size];
    memset(buf, size % 0xff, size);
    long long ret = stream->write(buf, size, filesize);
    delete [] buf;
    TEST(ret == size);

    filesize = file->getSize();
    return filesize;
}

int main(int argc, char* argv[])
{
    IInterface* ns = 0;
    esInit(&ns);
    Handle<IContext> nameSpace(ns);

    Handle<IClassStore> classStore(nameSpace->lookup("class"));
    esRegisterFatFileSystemClass(classStore);

    Handle<IStream> disk = new VDisk(static_cast<char*>("fat16_5MB.img"));
    long long diskSize;
    diskSize = disk->getSize();
    esReport("diskSize: %lld\n", diskSize);

    Handle<IFileSystem> fatFileSystem;
    long long freeSpace0;
    long long totalSpace0;
    long long freeSpace;
    long long totalSpace;

    fatFileSystem = reinterpret_cast<IFileSystem*>(
        esCreateInstance(CLSID_FatFileSystem, IFileSystem::iid()));
    fatFileSystem->mount(disk);
    fatFileSystem->format();
    freeSpace0 = fatFileSystem->getFreeSpace();
    totalSpace0 = fatFileSystem->getTotalSpace();
    esReport("Free space %lld, Total space %lld\n", freeSpace0, totalSpace0);
    {
        Handle<IContext> root;

        root = fatFileSystem->getRoot();

        long long size = 1024 * 1024LL;
        long long ret;
        long count = 5;

        freeSpace = freeSpace0;
        while (count--)
        {
            if (freeSpace < size)
            {
                size = freeSpace;
            }
            ret = writeData(root, size);
            freeSpace = fatFileSystem->getFreeSpace();
            totalSpace = fatFileSystem->getTotalSpace();
            esReport("Free space %lld, Total space %lld\n",
                freeSpace, totalSpace);
            TEST(freeSpace + ret == freeSpace0);
            TEST(totalSpace == totalSpace0);
        }
    }

    fatFileSystem->defrag();

    fatFileSystem->dismount();
    fatFileSystem = 0;

    fatFileSystem = reinterpret_cast<IFileSystem*>(
        esCreateInstance(CLSID_FatFileSystem, IFileSystem::iid()));
    fatFileSystem->mount(disk);
    freeSpace = fatFileSystem->getFreeSpace();
    totalSpace = fatFileSystem->getTotalSpace();
    esReport("Free space %lld, Total space %lld\n", freeSpace, totalSpace);
    esReport("\nChecking the file system...\n");
    TEST(fatFileSystem->checkDisk(false));
    fatFileSystem->dismount();
    fatFileSystem = 0;

    esReport("done.\n\n");
}
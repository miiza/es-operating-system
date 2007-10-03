/*
 * Copyright (c) 2007
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

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include "esidl.h"

#ifdef __cplusplus
extern "C" {
#endif

int yyparse(void);

extern FILE* yyin;

#ifdef __cplusplus
}
#endif

namespace
{
    Node* specification;
    Node* current;          // Current name space
    char  filename[PATH_MAX + 1];
    char* includePath;
    std::string javadoc;
}

int Node::level = 1;

Node* getSpecification()
{
    return specification;
}

Node* setSpecification(Node* node)
{
    Node* prev = specification;
    specification = node;
    return prev;
}

Node* getCurrent()
{
    return current;
}

Node* setCurrent(const Node* node)
{
    Node* prev = current;
    current = const_cast<Node*>(node);
    return prev;
}

char* getFilename()
{
    return filename;
}

void setFilename(const char* name)
{
    if (*name == '"')
    {
        size_t len = strlen(name) - 2;
        assert(len < PATH_MAX);
        memmove(filename, name + 1, len);
        filename[len] = '\0';
    }
    else
    {
        strncpy(filename, name, PATH_MAX);
    }
}

std::string& getJavadoc()
{
    return javadoc;
}

void setJavadoc(const char* doc)
{
    javadoc = doc ? doc : "";
}

std::string getOutputFilename(const char* input, const char* suffix)
{
    std::string filename(input);

    int begin = filename.rfind(".");
    int end   = filename.size();
    if (0 <= begin)
    {
        filename.replace(begin + 1, end, suffix);
    }
    else
    {
        filename += ".";
        filename += suffix;
    }

    if (includePath)
    {
        int pos = filename.find(includePath);
        if (pos == 0)
        {
            filename.replace(pos, strlen(includePath) + 1, "");
        }
        else
        {
            int slash = filename.rfind("/");
            if (0 <= slash)
            {
                filename.replace(0, slash + 1, "");
            }
        }
    }

    std::string dir;
    std::string path(filename);
    for (;;)
    {
        int slash = path.find("/");
        if (slash < 0)
        {
            break;
        }
        dir += path.substr(0, slash);
        path.erase(0, slash + 1);
        mkdir(dir.c_str(), 0777);
        dir += '/';
    }

    return filename;
}

void Module::add(Node* node)
{
    if (node->getRank() == 1)
    {
        if (dynamic_cast<Interface*>(node) && !node->isLeaf())
        {
            ++interfaceCount;
        }
        if (dynamic_cast<ConstDcl*>(node))
        {
            ++constCount;
        }
        if (dynamic_cast<Module*>(node))
        {
            ++moduleCount;
        }
    }
    Node::add(node);
}

void StructType::add(Node* node)
{
    ++memberCount;
    Node::add(node);
}

void Interface::add(Node* node)
{
    if (dynamic_cast<ConstDcl*>(node))
    {
        ++constCount;
    }
    else if (dynamic_cast<OpDcl*>(node))
    {
        ++methodCount;
    }
    else if (Attribute* attr = dynamic_cast<Attribute*>(node))
    {
        if (attr->isReadonly())
        {
            ++methodCount;
        }
        else
        {
            methodCount += 2;
        }
    }
    Node::add(node);
}

void OpDcl::add(Node* node)
{
    if (dynamic_cast<ParamDcl*>(node))
    {
        ++paramCount;
    }
    Node::add(node);
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "-I") == 0)
            {
                ++i;
                includePath = argv[i];
            }
        }
    }

    Module* node = new Module("");
    setSpecification(node);
    setCurrent(node);

    try
    {
        yyin = stdin;
        yyparse();
        fclose(yyin);
        printf("yyparse() ok.\n");
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }

    printf("-I %s\n", includePath);
    printf("-----------------------------------\n");
    print();
    printf("-----------------------------------\n");
    printCxx(getOutputFilename(getFilename(), "h"));
    printf("-----------------------------------\n");
    printEnt(getOutputFilename(getFilename(), "ent"));
    printf("-----------------------------------\n");

    delete node;

    return EXIT_SUCCESS;
}

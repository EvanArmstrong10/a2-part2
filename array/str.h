//lang::CwC

#pragma once 
#include <stdio.h>
#include <string.h>
#include "object.h"

class String : public Object {
    public:
    char* data;


    String() {
        this->data = new char[1];
    }

    String(const char* str) {
        int len = strlen(str);
        delete this->data;
        this->data = new char[len + 1];
        strcpy(this->data, str);
    }

    virtual bool equals(String* s) {
        return strcmp(this->data, s->data) == 0;
    }

    String* duplicate() {
        String* dup = new String(this->data);
        return dup;
    }

    int len() {
        return strlen(data);
    }

    void print() {
        printf("%s\n", this->data);
    }

};

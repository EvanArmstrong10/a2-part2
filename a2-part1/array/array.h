
#pragma once
#include "object.h"
#include "string.h"

class Array : public Object {
    public:
        int size_;
        int capacity_; 
        Object* data_;

        Array();
        virtual ~Array();


        virtual Object* get(int index);
        virtual void set(int index, Object* element);
        virtual void push_back(Object* element);
        virtual void swap(int index1, int index2);
        virtual Object* remove(int index);
        virtual int size();
};

class StrArray : public Array {
    public:
        String* data;

        StrArray();
        ~StrArray();

        String* get(int index);
        void set(int index, String* element);
        void push_back(String* element);
        String* remove(int index);
};

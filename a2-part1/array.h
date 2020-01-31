
#pragma once
#include "object.h"
#include "string.h"

class Array : public Object {
    public:
        int size_;
        int capacity_; 
        Object** data_;

        // array constructor allocates a list of size 1 of Objects
        Array() {
            capacity_ = 4;
            data_ = new Object*[capacity_];
            size_ = 0;
        }

        // virtual destructor
        virtual ~Array() {
            delete[] data_;
        }

        // doubles the capacity of the data
        virtual void resize_() {
            capacity_ = capacity_ * 2;
            Object** new_data = new Object*[capacity_];
            for (int ii = 0; ii < size_; ii++) {
                new_data[ii] = data_[ii];
            }
            delete[] data_;
            data_ = new_data;
        }

        // returns the element at the given index
        virtual Object* get(int index) {
            if (index >= 0 && index < size_) {
                return data_[index];
            }
            else {
                return NULL;
            }
        }

        // sets the given index of this array to the given element
        virtual void set(int index, Object* element) {
            if (index >= 0 && index <= size_) {
                if (size_ == capacity_) {
                    resize_();
                }
                data_[index] = element;
                size_++;
            }
        }
        
        virtual void push_back(Object* element) {
            if (capacity_ == size_) {
                resize_();
            }
            data_[size_] = element;
            size_++;
        }

        virtual void swap(int index1, int index2) {
            Object* temp = data_[index1];
            data_[index1] = data_[index2];
            data_[index2] = temp;
        }

        virtual Object* remove(int index) {
            Object* temp = data_[index];
            for (int ii = index + 1; ii < size_; ii++) {
                data_[ii-1] = data_[ii];
            }
            size_--;
            return temp;
        }

        virtual int size() {
            return size_;
        }
};

class StrArray : public Array {
    public:
        String** data_;

        StrArray() {
            capacity_ = 4;
            data_ = new String*[capacity_];
            size_ = 0;
        }

        ~StrArray() {
            delete[] data_;
        }

        void resize_() {
            capacity_ = capacity_ * 2;
            String** new_data = new String*[capacity_];
            for (int ii = 0; ii < size_; ii++) {
                new_data[ii] = data_[ii];
            }
            delete[] data_;
            data_ = new_data;
        }

        String* get(int index) {
            if (index >= 0 && index < size_) {
                return data_[index];
            }
            else {
                return NULL;
            }
        }

        void set(int index, String* element) {
            if (index >= 0 && index <= size_) {
                if (size_ == capacity_) {
                    resize_();
                }
                data_[index] = element;
                size_++;
            }
        }

        void push_back(String* element) {
            if (capacity_ == size_) {
                resize_();
            }
            data_[size_] = element;
            size_++;
        }

        String* remove(int index) {
            String* temp = data_[index];
            for (int ii = index + 1; ii < size_; ii++) {
                data_[ii-1] = data_[ii];
            }
            size_--;
            return temp;
        }
};

class IntArray : public Object {
    public:
        int size_;
        int capacity_; 
        int* data_;

        IntArray() {
            capacity_ = 4;
            data_ = new int[capacity_];
            size_ = 0;
        }

        ~IntArray() {
            delete[] data_;
        }

        void resize_() {
            capacity_ = capacity_ * 2;
            int* new_data = new int[capacity_];
            for (int ii = 0; ii < size_; ii++) {
                new_data[ii] = data_[ii];
            }
            delete[] data_;
            data_ = new_data;
        }

        int get(int index) {
            printf("%i %i\n", size_, index);
            if (index >= 0 && index < size_) {
                return data_[index];
            }
        }

        void set(int index, int element) {
            if (index >= 0 && index <= size_) {
                if (size_ == capacity_) {
                    resize_();
                }
                data_[index] = element;
                size_++;
            }
        }

        void push_back(int element) {
            if (capacity_ == size_) {
                resize_();
            }
            data_[size_] = element;
            size_++;
        }

        void swap(int index1, int index2) {
            int temp = data_[index1];
            data_[index1] = data_[index2];
            data_[index2] = temp;
        }

        int remove(int index) {
            int temp = data_[index];
            for (int ii = index + 1; ii < size_; ii++) {
                data_[ii-1] = data_[ii];
            }
            size_--;
            return temp;
        }

        int size() {
            return size_;
        }
};

class FloatArray : public Object {
    public:
        int size_;
        int capacity_; 
        float* data_;

        FloatArray() {
            capacity_ = 4;
            data_ = new float[capacity_];
            size_ = 0;
        }

        ~FloatArray() {
            delete[] data_;
        }

        void resize_() {
            capacity_ = capacity_ * 2;
            float* new_data = new float[capacity_];
            for (int ii = 0; ii < size_; ii++) {
                new_data[ii] = data_[ii];
            }
            delete[] data_;
            data_ = new_data;
        }

        float get(int index) {
            if (index >= 0 && index < size_) {
                return data_[index];
            }
        }
        
        void set(int index, float element) {
            if (index >= 0 && index <= size_) {
                if (size_ == capacity_) {
                    resize_();
                }
                data_[index] = element;
                size_++;
            }
        }

        void push_back(float element) {
            if (capacity_ == size_) {
                resize_();
            }
            data_[size_] = element;
            size_++;
        }

        void swap(int index1, int index2) {
            int temp = data_[index1];
            data_[index1] = data_[index2];
            data_[index2] = temp;
        }

        float remove(int index) {
            float temp = data_[index];
            for (int ii = index + 1; ii < size_; ii++) {
                data_[ii-1] = data_[ii];
            }
            size_--;
            return temp;
        }

        int size() {
            return size_;
        }
};

class BoolArray : public Object {
    public:
        int size_;
        int capacity_; 
        bool* data_;

        BoolArray() {
            capacity_ = 4;
            data_ = new bool[capacity_];
            size_ = 0;
        }

        ~BoolArray() {
            delete[] data_;
        }

        void resize_() {
            capacity_ = capacity_ * 2;
            bool* new_data = new bool[capacity_];
            for (int ii = 0; ii < size_; ii++) {
                new_data[ii] = data_[ii];
            }
            delete[] data_;
            data_ = new_data;
        }

        bool get(int index) {
            if (index >= 0 && index < size_) {
                return data_[index];
            }
        }

        void set(int index, bool element) {
            if (index >= 0 && index <= size_) {
                if (size_ == capacity_) {
                    resize_();
                }
                data_[index] = element;
                size_++;
            }
        }

        void push_back(bool element) {
            if (capacity_ == size_) {
                resize_();
            }
            data_[size_] = element;
            size_++;
        }

        void swap(int index1, int index2) {
            int temp = data_[index1];
            data_[index1] = data_[index2];
            data_[index2] = temp;
        }

        bool remove(int index) {
            bool temp = data_[index];
            for (int ii = index + 1; ii < size_; ii++) {
                data_[ii-1] = data_[ii];
            }
            size_--;
            return temp;
        }

        int size() {
            return size_;
        }
};
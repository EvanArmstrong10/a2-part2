#include "array.h"
#include <assert.h>

Array* create_array(){
    return new Array();
}

void test_get() {
    Array* a = create_array();
    String* s = new String("Fling");
    a->set(0, s);
    assert(a->get(0)->equals(s));
    delete a;
}

void test_set() {
    Array* a = create_array();
    String* s = new String("Fling");
    a->set(0, s);
    assert(a->data_[0]->equals(s));
    delete a;
}

void test_push_back() {
    Array* a = create_array();
    String* s = new String("Fling");
    a->push_back(s);
    assert(1 == a->size());
    delete a;
}

void test_swap() {
    Array* a = create_array();
    String* s = new String("Fling");
    String* t = new String("Sting");
    a->push_back(s);
    a->push_back(t);
    a->swap(0, 1);
    assert(a->get(0)->equals(t));
    assert(a->get(1)->equals(s));
}

void test_remove() {
    Array* a = create_array();
    String* s = new String("Fling");
    a->push_back(s);
    Object* t = a->remove(0);
    assert(t->equals(s));
}

void test_size() {
    Array* a = create_array();
    assert(a->size() == 0);
    String* s = new String("Bling");
    a->push_back(s);
    assert(a->size() == 1);
}

void test_IntArray() {
    IntArray* ia = new IntArray();
    assert(ia->size() == 0);
    ia->push_back(3);
    ia->push_back(6);
    assert(ia->size() == 2);
    assert(ia->remove(0) == 3);
    assert(ia->size() == 1);
}

void test_FloatArray() {
    FloatArray* ia = new FloatArray();
    assert(ia->size() == 0);
    ia->push_back(3.1);
    ia->push_back(6.2);
    assert(ia->size() == 2);
    float temp = ia->remove(0);
    assert(temp > 3.09999 && temp < 3.1001);
    assert(ia->size() == 1);
}

void test_BoolArray() {
    BoolArray* ia = new BoolArray();
    assert(ia->size() == 0);
    ia->push_back(0);
    ia->push_back(1);
    assert(ia->size() == 2);
    assert(ia->remove(0) == 0);
    assert(ia->size() == 1);
}


int main(int argc, char* argv[]) {
    test_get();
    test_set();
    test_push_back();
    test_swap();
    test_remove();
    test_size();
    test_IntArray();
    test_FloatArray();
    test_BoolArray();
}
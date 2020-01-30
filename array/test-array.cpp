//lang::CwC

#include "array.h"
#include <assert.h>

Array* create_array(){
    return 0;
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
    assert(a->data_[0].equals(s));
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

int main(int argc, char* argv[]) {
    test_get();
    test_set();
    test_push_back();
    test_swap();
    test_remove();
    test_size();
}

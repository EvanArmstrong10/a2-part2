//lang::CwC

#pragma once
#include <cstdlib>

class Object {
    size_t hash_;
  
    public: 
    
    virtual bool equals(Object* that) {
        return this == that;
    }

    size_t hash_maker() {
        return reinterpret_cast<size_t>(this);
    }

    virtual size_t hash() {
        if (!hash_) {
            this->hash_ = this->hash_maker();
        }
        return hash_;
    }

};

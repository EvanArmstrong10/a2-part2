//lang::CwC
#pragma once

#include "object.h"
#include <cstdlib>
#include <string.h>
#include <cstdio> 

/**
 * An immutable String class representing a char*
 * author: chasebish */
class String : public Object {
  public:
  
    char* val_;   // data                                                            
    size_t size_; // number of characters (excluding \0)    

    /** CONSTRUCTORS & DESTRUCTORS **/

    /* Creates a String copying s */
    String(const char* s) {
      char* val_ = new char[strlen(s) + 1]; 
      size_ = strlen(s);                                        
      strcpy(val_, s);
    }

    /* Copies a String copying the value from s */
    String(String* const s) {
        val_ = new char[s->size()];
        strcpy(val_, s->val_);
        size_ = s->size_;

    }

    ~String() {
        delete[] val_;
    }



    /** INHERITED METHODS **/

    /* Inherited from Object, generates a hash for a String */
    // professor provided
    size_t hash() {
      size_t hash = 0;                                                             
      for (size_t i = 0; i < size_; ++i)                                           
          hash = val_[i] + (hash << 6) + (hash << 16) - hash;                        
      return hash;  
    }

    /* Inherited from Object, checks equality between an String and an Object */
    // professor provided
    bool equals(Object* const obj) {
      if (obj == nullptr) return false;
      String* tgt = dynamic_cast<String*>(obj);
      if (tgt == nullptr) return false;
      return cmp(tgt)== 0;
    }


    /** STRING METHODS **/
  
    /** Compares strings based on alphabetical order
    * < 0 -> this String is less than String s
    * = 0 -> this String is equal to String s
    * > 0 -> this String is greater than String s
    */
    int cmp(String* const s) {
        return strcmp(val_, s->val_);
    }

    /* Creates a new String by combining two existing Strings */
    String* concat(String* const s) {
      char* res = new char[size_ + s->size() + 1];                             
      for (size_t i = 0; i < size_; i++)                                           
          res[i] = val_[i];                                                          
      for (size_t i = size_, j = 0; i < size_ + s->size(); i++, j++)           
          res[i] = val_[j];                                                          
      res[size_] = '\0';                                                           
      return new String(res);
    }

    /* Returns the current length of the String */
    size_t size() {
        return size_;
    }
};
#pragma once

#include <stdlib.h>

/**
 * A class that represents the top of the object hierarchy.
 * author: chasebish */
class Object {
public:
  /** CONSTRUCTORS & DESTRUCTORS **/

  /* Default Object constructor */
  Object() {}

  /* Default Object destructor, to be overriden by subclasses */
  virtual ~Object() {}


  /** VIRTUAL METHODS **/

  /* Returns whether two objects are equal, to be overriden by subclasses */
  virtual bool equals(Object* const obj) {
      return hash() == obj->hash();
  }

  /* Returns an object's hash value. Identical objects should have identical hashes */
  virtual size_t hash() {
      void* addr = this;
      return (size_t) addr;
  }
};
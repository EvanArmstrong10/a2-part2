# Overview

Our API is based on our collective experience with CwC until this point
as well as our interactions with Arrays in other languages.  Some invariants
that we agreed on for Array are mutability of contents and dynamic sizing.
While there is certainly extra functionality that could be included, for
example, some sort of iterative print function, we felt that this design
was capable of being extended when necessary.

#### Fields

Fields necessarily constrain implementation.  That's why we kept the fields
as short as possible.  The size and capacity of an array are necessary to
ensure that dynamic sizing is possible.  The data needs to be stored
somewhere and since we are working with C, an array of Objects seems
reasonable.  While some other class of lists could be invented for the
Array to use in its implementation, it's unlikely.  Arrays are one of the
most basic data structures in any language, so we felt it should rely on
as little as possible.

#### Methods

The methods are also relatively concise. Getting and setting are standard
and require indices.  Pushback ensures that the user can add to the Array
without knowing the length and so forces the implementation to allow that.
Remove returns the object in the place of removal to enforce the user's
maintenance of memory leaks.  Finally the size method allows access to
a private field.

#### Constructor/Destructor

These methods don't have much constraints other than that a custom
destructor will be necessary in order to delete any objects that are
stored in the array.

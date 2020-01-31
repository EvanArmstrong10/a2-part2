**Implementation:**

    **Includes:**
        - Queue: handles Object and String types  
        - Array: handles Object and String types, as well as primitive types (int, bool, float)
        - Map: handles Object and String types

    Our implementation has 3 data structures Queue, Array and Map, all meant to store and manipulate data in a quick, efficient way.
    
    Queue:
        We have a standard Object queue that has the following functions: 
            *at_capacity, contains, dequeue, dequeue_all, double_capacity, enqueue, enqueue_all, equals, get, hase_me,  peek and queue_size*

        With our string and object implementation, all queue functions extend to strings as well as objects

        In order to support rapid enqueing and dequeing without getting bogged down by new and delete, our queues allocate memory when they reach a given capacity_. A size_ field keeps track of the end of the data in the queue and it is never larger than the capacity_. This prevents reallocation every time we enqueue.

    Array
        We have an Object, String, Int, Float, and Bool Array, all with the following functions:
            *get, push_back, remove, resize_, set, size and swap*

        Our String array inherits its functionality from Object Array.
        Int, Float and Bool arrays are their own objects with the same functionality.

        We elected to use duplicate code for the primitive types instead of wrapper classes to save memory. On a large scale wrapper classes take up way too much memory to be useful.

        Similar to our queue, we elected to allocate memory for new arrays when the current array reaches a certain capacity_, the end of the data in the array is marked with a size_ field.

    Map

**Critiques**

    Queue Critique:

        - Documentation Quality
        - 
        -
    
    Array Critique:
        -
        -
        -
    
    Map Critique:
        -
        -
        -



**Implementation:**
  

    Includes:
        - Queue: handles Object and String types  
        - Array: handles Object and String types, as well as primitive types (int, bool, float)
        - Map: handles Object and String types

    Our implementation has 3 data structures Queue, Array and Map, 
    all meant to store and manipulate data in a quick, efficient way.
    
    Queue:
        We have a standard Object queue that has the following functions: 
            *at_capacity, contains, dequeue, dequeue_all, double_capacity, enqueue, enqueue_all, equals, get, hase_me,  peek and queue_size*

        With our string and object implementation, 
        all queue functions extend to strings as well as objects

        In order to support rapid enqueing and dequeing without getting bogged down by new and delete, 
        our queues allocate memory when they reach a given capacity_. 
        A size_ field keeps track of the end of the data in the queue and it is never larger than the capacity_. 
        This prevents reallocation every time we enqueue.

    Array
        We have an Object, String, Int, Float, and Bool Array, all with the following functions:
            *get, push_back, remove, resize_, set, size and swap*

        Our String array inherits its functionality from Object Array.
        Int, Float and Bool arrays are their own objects with the comparable functionality.

        We elected to use duplicate code for the primitive types instead of wrapper classes to save memory. 
        If the object is to work with large files, larger wrapper classes would bog down memory and performance.

        Similar to our queue, we elected to allocate memory for new arrays when the current array reaches a certain capacity_, 
        the end of the data in the array is marked with a size_ field.

    Map
        We have a Hashmap class that supports Objects which indirectly supports Strings. The following functions public methods are visible:
            *hash, expand, get, put, remove, size, key_array, and equals*
        
        There is an additional "private" method index_key_ for indexing hashes.

        Alongside the Hashmap class, we have a class for Hashmap_Pair as spec'ed. This has the following methods:
            *getVal, getKey* 

**Critiques**

    Queue Critique:

        1. Documentation Quality:
            
            The given code was to spec, it included a couple functions that weren't tested properly 
            and we didn't believe they were necessary. We had them delete those. 
            We also added the functionality of keeping track of a capacity, 
            as that allowed us to manage memory more efficiently.

        2. Responsiveness:

            The group was very responsive. We only had to raise 2 issues but in both cases the issues were
            closed within the hour.   

        3. Test Quality:

            The given tests were comprehensive and thorough, 
            apart from the missing tests for the functions we deleted. 
            We did not feel the need to add any additional tests.
    
    Array Critique:
        
        1. Documentation Quality:

            The given code was initially out of spec as it didn't include support for primitive data types.
            For this, we forked the repo and submitted a pull request adding methods that mimicked the functionality
            of the given Array classes.

        2. Responsiveness:
            
            We had to submit a few requests to alter the tests to match the specs, but the pair was quick to respond
            and were very cooperative. Issues never were open for more than a few hours at a time. Would be happy to
            work with them again.
        
        3. Test Quality:

            Once the tests were changed to match the new in spec API, tests were largely comprehensive. We did not feel
            additional tests needed to be added.


    Map Critique:
        1. Documentation Quality:

            The spec quality was good overall. All necessary methods and classes were included to enable
            a quality implementation. However, fields and constructors were provided and had to be changed.

        2. Responsiveness:

            The group was much less responsive than the other two groups we worked with. Additionally, there was a fair
            bit of confusion about what was an implementation detail and what should be specified in the interface.
            Because of this, there was a number of tests that were directly testing data structures and field names that
            had to be changed. 5 or 6 issues were closed and had to be reopened as a result of this. Responsiveness varied.
        
        3. Test Quality:

            Test quality was poor overall. While most of the spec'ed methods were covered by the tests, there were
            a large number of tests that were implementation specific and needed to be changed. As previously mentioned,
            about half a dozens issues had to be opened before this was fully resolved.



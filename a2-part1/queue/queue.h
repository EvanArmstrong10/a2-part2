//lang::CwC

#include "object.h"

class Queue : public Object
{
public:

    Object** queue_;
    int size_;
    int capacity_;

    // Constructor
    Queue() : Object()
    {
        queue_ = new Object*[2];
        size_ = 0;
        capacity_ = 2;
    }

    // Deconstructor
    virtual ~Queue()
    {
    }

    void double_capacity() 
    {
        Object** temp = new Object*[capacity_ * 2];
        for (size_t x = 0; x < size_; x++) {
            temp[x] = queue_[x];
        }
        if (size_ > 0) {
            delete[] queue_;
        }
        queue_ = temp;
        capacity_ *= 2;
    }


    bool at_capacity()
    {
        return size_ == capacity_;
    }

    // Adds a new Object to the Queue
    void enqueue(Object *item_)
    {
        if (at_capacity()) {
            double_capacity();
            queue_[size_] = item_;
            size_ ++;
        }
        else {
            queue_[size_] = item_;
        }
    }

    // Removes the head Object from the Queue
    // Returns the removed head
    Object *dequeue()
    {
        if (size_ == 0) {
            return NULL;
        }
        else {
            Object *temp_ = queue_[0];
            for (size_t x = 0; x < size_ - 1; x++) {
                queue_[x] = queue_[x+1];
            }
            size_ --;
            return temp_;
        }
    }

    // Returns the head Object of the Queue without removing it
    Object *peek()
    {
        if (size_ == 0) {
            return NULL;
        }
        else {
            return queue_[0];
        }
    }

    // Checks to see if the Queue contains a specific Object already
    bool contains(Object *o)
    {
        if (size_ == 0) {
            return false;
        }
        else {
            for (size_t x = 0; x < size_ - 1; x++) {
                if (queue_[x]->equals(0)) {
                    return true;
                }
            }
            return false;
        }
    }

    // Combines a given Queue into this Queue
    void enqueue_all(Queue *q)
    {
        for (size_t x = 0; x < q->size_; x++) {
            enqueue(q->queue_[x]);
        }
    }

    // Removes all items from this Queue
    void dequeue_all()
    {
        delete queue_;
        queue_ = new Object*[2];
    }

    // Returns size of queue
    size_t queue_size()
    {
        return size_;
    }

    // Checks for equality between this Queue and the Object passed in
    bool equals(Object *o)
    {
        Queue* temp = dynamic_cast<Queue*>(o);
        if (temp == 0 || size_ != temp->size_) {
            return false;
        }
        else {
            for (size_t x = 0; x < size_; x++) {
                if (!(temp->queue_[x]->equals(queue_[x]))) {
                    return false;
                }
            }
        }
        return true;
    }

    // Generates a hash value for this Object
    long unsigned int hash_me()
    {
        long unsigned temp = 0;
        for (size_t x = 0; x < size_; x++) {
            temp = temp + queue_[x]->hash();
        }
        return temp;
    }
};

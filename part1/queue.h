//lang::CwC

#pragma once
#include "object.h"
#include <stdlib.h>


class Queue : public Object
{
    public:

        Object** queue_;
        size_t size_;
        size_t  capacity_;

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
            delete[] queue_;
        }

        void double_capacity() 
        {
        capacity_ *= 2;
        Object** temp = new Object*[capacity_];
        for (size_t x = 0; x < size_; x++) {
            temp[x] = queue_[x];
        }
        delete[] queue_;
        queue_ = temp;
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
            }
            queue_[size_] = item_;
            size_ ++;
        }

        // Removes the head Object from the Queue
        // Returns the removed head
        Object *dequeue()
        {
            if (size_ == 0) {
                return NULL;
            }
            Object *temp_ = queue_[0];
            for (size_t x = 0; x < size_ - 1; x++) {
                queue_[x] = queue_[x+1];
            }
            size_ --;
            return temp_;
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

        // Returns the element at index
        Object* get(size_t index) {
            return queue_[index];
        }

        // Checks to see if the Queue contains a specific Object already
        bool contains(Object *o)
        {
            for (size_t x = 0; x < size_; x++) {
                if (get(x)->equals(o)) {
                    return true;
                }
            }
            return false;
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
            delete[] queue_;
            queue_ = new Object*[2];
            size_ = 0;
            capacity_ = 2;
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
            if (temp == 0) return false;
            if (size_ != temp->queue_size()) return false;
            for (size_t x = 0; x < size_; x++) {
                if (!(temp->queue_[x]->equals(queue_[x]))) {
                    return false;
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

/*
The Circular Queue's main element is a vector,
Also, we implemented two pointers: head and tail to mark the current data,
integer cur is current size of queue.

When do enqueue, we put the new number at tail, and plus tail by 1, 
when de dequeue, we just move forward the head pointer, not remove number really,

Always do modulus after moving head or tail, because the queue is circular.
*/

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data.resize(k);
        size=k,head=0,tail=0,cur=0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(cur==size) return false;
        else{
            data[tail++]=value;
            cur++;
            tail%=size;
            return true;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(cur==0) return false;
        else{
            head++;
            head%=size;
            cur--;
            return true;
        }
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(cur==0) return -1;
        else return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(cur==0) return -1;
        else return data[(tail-1+size)%size];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return cur==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return cur==size;
    }
private:
    vector<int> data;
    int size,head,tail,cur;
};
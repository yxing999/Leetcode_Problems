/*
Implement two heap, 
a min-heap stores bigger half part numbers,
a max-heap stores smaller half part numbers,
keep the size of min_heap equals to that of max_heap, or bigger by 1.

Time : addNum(int num): O(log n);
	   findMedian(): O(1).

Follow up questions:
1.If all integer numbers from the stream are between 0 and 100, how would you optimize it?
  Set 101 buckets for number 0-100, every bucket i record the number of i,
  Implement an integer n, record the number of all numbers.
  Implement two 2D pointers, left[i][j] and right[i][j], mark the median, i-th bucket, j-th position at this slot.
  when add a number into buckets, adjust left and right to maintain them point to median.

  Time: addNum(int num): O(1);
  	    findMedian():O(1).
2.If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
  To be solved....
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_h.push(num);
        max_h.push(min_h.top());
        min_h.pop();
        if(min_h.size()<max_h.size()){
            min_h.push(max_h.top());
            max_h.pop();
        }
    }
    
    double findMedian() {
        return min_h.size()==max_h.size()? (min_h.top()+max_h.top())/2.0:min_h.top();
    }
private:
    priority_queue<int> max_h;
    priority_queue<int,vector<int>,greater<int>> min_h;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
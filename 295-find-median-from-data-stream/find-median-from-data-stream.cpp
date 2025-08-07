class MedianFinder {
private:
     priority_queue<int> maxHeap;
     // // Max-heap: stores the smaller half of numbers (top = largest of smaller half)
     priority_queue<int,vector<int>,greater<int>> minHeap; // 
     // Min-heap: stores the larger half of numbers (top = smallest of larger half)
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>1+maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(minHeap.size()==0) return 0.0;
        else if(minHeap.size()==maxHeap.size())
        {
            return (double)(minHeap.top()+maxHeap.top())/2.0;
        }
        else return (double)minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
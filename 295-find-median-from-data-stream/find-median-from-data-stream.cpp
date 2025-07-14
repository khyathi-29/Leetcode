class MedianFinder {
private:
     priority_queue<int> minHeap;// return min value to store max values
     priority_queue<int,vector<int>,greater<int>> maxHeap; // 
     // return max value to store min value;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size()>1+minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.size()==0) return 0.0;
        else if(minHeap.size()==maxHeap.size())
        {
            return (double)(minHeap.top()+maxHeap.top())/2.0;
        }
        else return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
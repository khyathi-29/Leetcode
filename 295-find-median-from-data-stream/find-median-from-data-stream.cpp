class MedianFinder {
public:
   priority_queue<int> maxHeap;
   priority_queue<int,vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        int k = minHeap.top();
        minHeap.pop();
        maxHeap.push(k);
        if(maxHeap.size()> 1+ minHeap.size())
        {
            int t = maxHeap.top();
            maxHeap.pop();
            minHeap.push(t);
        }
        return;
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()) return (double)(minHeap.top()+maxHeap.top())/2.00;
    else return (double)maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
priority_queue<int> maxHeap;// to store minimum elements
priority_queue<int,vector<int>,greater<int>> minHeap;//to store maximum elements
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
        }
        else if (minHeap.empty()){
            if(maxHeap.top()> num){
                int k = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(k);
            } else minHeap.push(num);
        }
        else if(maxHeap.size()==minHeap.size()){
            if(num > minHeap.top()){
                int k = minHeap.top();
                minHeap.pop();
                maxHeap.push(k);
                minHeap.push(num);
            }
            else maxHeap.push(num);
        }
        else if (maxHeap.size()> minHeap.size()){
              if(num < maxHeap.top()){
                int k = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(k);
              }
              else minHeap.push(num);

        }
        
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        
        return (maxHeap.top() + minHeap.top()) / 2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
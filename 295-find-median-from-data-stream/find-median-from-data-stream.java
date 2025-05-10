class MedianFinder {
    PriorityQueue<Integer> minHeap;//to store maxValues
    PriorityQueue<Integer> maxHeap; //to min Values

    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
    }
    
    public void addNum(int num) {
        minHeap.add(num);
        maxHeap.add(minHeap.poll());
        if(maxHeap.size()>1+minHeap.size()){
            minHeap.add(maxHeap.poll());
        }
        
    }
    
    public double findMedian() {
        if(maxHeap.size()>minHeap.size()) return maxHeap.peek();
        else{
            return (maxHeap.peek()+minHeap.peek())/2.0;
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
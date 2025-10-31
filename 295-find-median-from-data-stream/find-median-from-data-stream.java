class MedianFinder {
       PriorityQueue<Integer> minHeap;
       PriorityQueue<Integer> maxHeap;
    public MedianFinder() {
        minHeap = new PriorityQueue<>();//stores larger value
        maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        
    }
    
    public void addNum(int num) {
        minHeap.offer(num);
        maxHeap.offer(minHeap.poll());
        if(maxHeap.size()>1+minHeap.size())
        {
            minHeap.offer(maxHeap.poll());
        }
    }
    
    public double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            return (double)(minHeap.peek()+maxHeap.peek())/2.00;
        }
        else return(double) maxHeap.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
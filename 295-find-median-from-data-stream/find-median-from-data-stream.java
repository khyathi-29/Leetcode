class MedianFinder {
    PriorityQueue<Integer> minHeap ;
    PriorityQueue<Integer> maxHeap ;
    //maxHeap stores the smaller half of the numbers (in reversed order — the largest of the small numbers is on top)
    //minHeap stores the larger half of the numbers (smallest of the large numbers is on top).

    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }
    
    public void addNum(int num) {
        maxHeap.offer(num);
        minHeap.offer(maxHeap.poll());
        if(minHeap.size()>maxHeap.size())
        {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    public double findMedian() {
        int s = minHeap.size() + maxHeap.size();
        if(s%2==0) return (double)(minHeap.peek()+maxHeap.peek())/2.00;
        else return (double)maxHeap.peek();
        
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
class RecentCounter {
    List<Integer> l;

    public RecentCounter() {
        l = new ArrayList<>();
    }
    
    public int ping(int t) {
        l.add(t);
        int low = 0;
        int high = l.size()-1;
        while(low<=high)
        {
            int mid = (low+high)>>1;
            if(l.get(mid)<t-3000){
                low = mid+1;
            }
            else high = mid-1;
        }
        return l.size()-low;
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
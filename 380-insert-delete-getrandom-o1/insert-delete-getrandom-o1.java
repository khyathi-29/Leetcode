class RandomizedSet {
    private Map<Integer,Integer> mp;
    private List<Integer> l;
    public RandomizedSet() {
        mp = new HashMap<>();
        l = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val)){
            return false;
        }
        else{
            mp.put(val,l.size());
            l.add(val);
            return true;
        }
        
    }
    
    public boolean remove(int val) {
        if(!mp.containsKey(val)){
            return false;
        }
        else{
            int index = mp.get(val);
            int exchange = l.get(l.size()-1);
            l.set(index,exchange);
            mp.put(exchange,index);
            mp.remove(val);
            l.remove(l.size()-1);
            return true;
        }
        
    }
    
    public int getRandom() {
        Random r = new Random();
        return l.get(r.nextInt(l.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
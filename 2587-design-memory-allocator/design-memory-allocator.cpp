class Allocator {
    vector<int> mem;
    int n;
    unordered_map<int,vector<int>> mp;
public:
    Allocator(int n) {
        mem = vector<int> (n,0);
        this->n =n;
    }
    
    int allocate(int size, int mID) {
        int free=0;
        for(int i=0;i<n;i++){
            if(mem[i]==0) free++;
            else free=0;
            if(free==size){
                while(size>0){
                    mem[i]=mID;
                    mp[mID].push_back(i);
                    size--;
                    i--;
                }
                return i+1;
            }
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        int s = mp[mID].size();
        for(int i : mp[mID]) mem[i]=0;
        mp.erase(mID);
        return s;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
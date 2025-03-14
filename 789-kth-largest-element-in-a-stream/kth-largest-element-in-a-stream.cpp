class KthLargest {
    priority_queue<int, vector<int>,greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k ;
      //sort(nums.begin(),nums.end(),[](int a,int b){return a>b;});
      for(int i : nums){
        q.push(i);
        if(k < q.size()) q.pop();
      }
      //for(int i=0;i<k;i++) q.push(nums[i]);

    }
    
    int add(int val) {
       q.push(val);
       if(q.size()>k) q.pop();
       return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
class Solution {
public:
    int sum;
    vector<float> s;
    Solution(vector<int>& w) {
     sum = 0;
    for(int i=0;i<w.size();i++){
        sum+=w[i];
        s.push_back(sum);// push prefix sum 
      }
        
    }
    
    int pickIndex() {
    float Num =  (float)rand() / RAND_MAX;
    float randNum =  Num * sum;
     int low = 0;
     int high = s.size()-1;
     int ans = 0;
     while(low<=high){
        int mid = low + ((high-low)/2);
       if(s[mid]>randNum) high = mid-1;
       else if (s[mid]==randNum) return mid;
        else {
            low = mid+1;
            ans = low;
        }
     }
     return ans;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
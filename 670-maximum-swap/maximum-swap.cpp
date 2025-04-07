class Solution {
public:
    int maximumSwap(int num) {
        vector<int> n;
        while(num){
          n.push_back(num%10);
          num=num/10;
        }
        reverse(n.begin(),n.end());
        int max_val = n[n.size()-1];
        int max_ind = n.size()-1;
        int i1 = n.size()-1;// incase swap index of the first
        int j1 = n.size()-1; // incase swap index of the second

        for(int i=n.size()-2;i>-1;i--){
            if(n[i]> max_val){
                max_val = n[i];
                max_ind = i;
            }
            else if(n[i]<max_val){
                i1 = i;
                j1 = max_ind;
            }
        }
        int k = n[i1];
        n[i1]=n[j1];
        n[j1]=k;
        int ans =0;
        for(int i=0;i<n.size();i++){
            ans =ans*10+n[i];
        }
        return ans;
      
    }
};
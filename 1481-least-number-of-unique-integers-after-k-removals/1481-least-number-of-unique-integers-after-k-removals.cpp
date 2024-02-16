class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> a;
        for(int i=0;i<arr.size();i++)
        {
            a[arr[i]]++;
        }
        vector<int> b;
        for(auto i= a.begin();i!=a.end();i++)
        {
            b.push_back(i->second);
        }
        
        sort(b.begin(),b.end());
        //int count =0;
        for(int i=0;i<b.size();i++)
        {
            if(k<b[i])
            {
               return b.size()-i;
            }
            else
            {
              k=k-b[i];
              b[i]=0;
            }
        }
        
        return 0;
        
    }
};
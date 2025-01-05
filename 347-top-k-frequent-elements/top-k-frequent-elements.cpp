class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }
        vector<vector<int>>temp(nums.size()+1);// make it frequency vector of size n+1
        for(auto num : umap)
        {
            temp[num.second].push_back(num.first);
        }
        int count=0;
        for(int i= temp.size()-1;i>-1;i--)
        {
            if(temp[i].size()!=0){
            for(int j=0;j<temp[i].size();j++){
            ans.push_back(temp[i][j]);
            count++;
            if(count==k) return ans;
            }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size());
        vector<int> ans;
        stack<int> s;
        unordered_map<int,int> mp;
       for(int i=nums2.size()-1;i>-1;i--)
       {
        while(s.empty()!= true && s.top()<=nums2[i])
        {
            s.pop();
        }
        if(s.empty()) nge[i]=-1;
        else nge[i]=s.top();
        s.push(nums2[i]);
       }
       for(int i=0;i<nums2.size();i++)
       {
          mp[nums2[i]]=i;
       } 
       for(int i=0;i<nums1.size();i++)
       {
        int k = mp[nums1[i]];
        ans.push_back(nge[k]);
       }
       return ans;
    }
};
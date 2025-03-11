class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(),-1);
        vector<int> ans;
        unordered_map<int,int> m;
        stack<int> s;
        s.push(0);
        m[nums2[0]]=0;
        for(int i=1;i<nums2.size();i++){
            m[nums2[i]]=i;
            while(!s.empty() && nums2[s.top()] < nums2[i]){
                nge[s.top()]=nums2[i];
                s.pop();
            }
            s.push(i);
        }
        for(int n: nums1){
                ans.push_back(nge[m[n]]);
        }
        return ans;
    }
};
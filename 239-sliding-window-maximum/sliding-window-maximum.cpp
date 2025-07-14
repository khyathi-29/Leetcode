class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> de;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!de.empty() && nums[de.back()] <= nums[i])
            {
                de.pop_back();
            }
            // above loop removes values which are less than the current index
            // and makes sure loop is in descending order;
            de.push_back(i);
            
            if(de.front()<=i-k)
            {
                de.pop_front();
            }
            // above if removes the left elements which we shouldn't consider
            
            if(i>=k-1)
            {
                int a = nums[de.front()];
                ans.push_back(a);
            }
        }
        return ans;
        
    }
};
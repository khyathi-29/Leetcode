class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, cur, ans);
        return ans;
    }
private:
    void backtrack(const vector<int>& nums, vector<bool>& used,
                   vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (used[i]==true) continue;
            // skip duplicates: only use nums[i] if the identical previous was used
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]==true) continue;

            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, used, cur, ans);
            cur.pop_back();
            used[i] = false;
        }
    }
};

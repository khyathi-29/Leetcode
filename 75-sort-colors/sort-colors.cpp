class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int i =0;
        while(i<=high && low<=high)
        {
            if(nums[i]==0){
                swap(nums,i,low);
                low++;
                i++;
            }
            else if(nums[i]==2)
            {
                swap(nums,i,high);
                high--;
            }
            else i++;
        }
        return;
    }
    void swap(vector<int>& ans, int i, int j)
    {
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] =temp;
    }

};
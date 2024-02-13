class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int j =0;
        int k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(val!=nums[i])
            {
                nums[j]=nums[i];
                j++;
            }
            else
            {
                k=k+1;
            }
        }
        
        return (nums.size()-k);
    }
};
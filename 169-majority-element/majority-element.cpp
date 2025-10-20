class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int majorityElement = 0;
        for(int i : nums)
        {
            if(count==0){
                majorityElement = i;
                count = 1;
            }
            else if(majorityElement == i) count++;
            else count--;
        }
        return majorityElement;
    }
};
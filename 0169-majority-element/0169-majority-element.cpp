class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =0;
        int current_element;
        for(int k: nums)
        {
            if(count ==0)
            {
                current_element=k;
                count++;
            }
            else if(k==current_element) count++;
            else count--;
        }

        if(count>0) return current_element;
        else return -1;
    }
};
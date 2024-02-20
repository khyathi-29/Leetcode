class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c1=0;
        int c2=0;
        int c3 =0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                c1++;
            }
            else if(bills[i]==10)
            {
                c2++;
                c1--;
            }
            else
            {
                if(c2>0)
                {
                c3++;
                c1--;
                c2--;
                }
                else
                {
                    c3++;
                    c1=c1-3;
                }
            }
            if(c1<0 || c2<0 || c3<0)
            {
                return false;
            }
        }
        
        return true;
        
    }
};
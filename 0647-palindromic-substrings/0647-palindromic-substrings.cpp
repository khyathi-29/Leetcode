class Solution {
public:
   // similar to give maxpalindrome sub string
    int countSubstrings(string s) {
        if(s.size()==1) return 1;
        int count = 0;
        //even check;
        for(int i=0;i<s.size();i++)
        {
            int l=i;
            int r=i;
            palindrome(s,l,r,count);
        }
        //odd check;
        for(int i=0;i<s.size()-1;i++)
        {
            int l=i;
            int r=i+1;
            palindrome(s,l,r,count);
        }
        return count;

    }
    void palindrome(string s, int l,int r,int& count)
    {
        while(l>-1 && r<s.size())
        {
            if(s[l]==s[r])
            {
                count+=1;
                l--;
                r++;
            }
            else return;
        }
        return;
    }
};
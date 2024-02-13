class Solution {
public:
    bool isPalindrome(int x) {
        int ans = x;
        if ( x < 0)
        {
            return false;
        }
        vector<int> a;
        while(x>0)
        {
            a.push_back(x%10);
            x=x/10;
        }
        long int rev =0;
        for( int i = 0; i<a.size(); i++)
        {
             rev = rev*10 + a[i];
             cout<<rev<<endl;
            
        }
        if ( rev == ans)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};
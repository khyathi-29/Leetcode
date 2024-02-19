class Solution {
public:
    bool isPowerOfTwo(int n) {
        int k=n;
        if(n==1)
        {
            return true;
        }
        while(k>1 && k%2==0)
        { 
         k=k/2;
        }
        if(k==1)
        {
            return true;
        }

        return false;
        
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> a(rowIndex+1);
        long long int ans=1;
        a[0]=1;
        if(rowIndex==0)
          return a;
        if(rowIndex==1)
          return {1,1};
        for(int i=1;i<rowIndex+1;i++)
        {
           ans=(ans*(rowIndex+1-i))/i;
           a[i]=ans;
        }
        return a;  
    }
};
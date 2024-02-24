class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a;
        k=k-1;
        string ans="";
        int fact =1;
        for(int i=1;i<n+1;i++)
        {
            a.push_back(i);
            fact=fact*i;
        }
        fact = fact/n;
        while(1)
        {
           ans = ans + to_string(a[k/fact]);
           a.erase(a.begin()+k/fact);
           if(a.size()==0)
           {
               break;
           }  
           k = k%fact;
           fact = fact/a.size();   
        }
        
        
        return ans;
    }
};
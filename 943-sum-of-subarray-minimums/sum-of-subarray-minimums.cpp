class Solution {
    const int MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> Nse;
        stack<int> Pse;
        for(int i =0 ;i< n ; i++)
        {
            while(!Nse.empty() && arr[Nse.top()]> arr[i])
            {
                nse[Nse.top()] = i;
                Nse.pop();
            }
            Nse.push(i);
        }
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!Pse.empty() && arr[Pse.top()]>= arr[i])
            {
                pse[Pse.top()] = i;
                Pse.pop();
            }
            Pse.push(i);
        }
        long long count = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = (1LL * arr[i] * left % MOD) * right % MOD;
            count = (count + contrib) % MOD;
        }

        return (int)count;
    }
};
   
class Solution {
public:
    int romanToInt(string ss) {
        int n = ss.length()-1;
        if(n<0) return 0;
        unordered_map<char,int> s;
        s['I'] = 1;
        s['V'] = 5;
        s['X'] = 10;
        s['L'] = 50;
        s['C'] = 100;
        s['D'] = 500;
        s['M'] = 1000;
        int ans = s[ss[n]];
        int prev = ans;
        int current;
        for(int i = n-1; i>=0 ;i--)
        {
            int current = s[ss[i]];
            if(current<prev) ans -=current;
            else ans+=current;
            prev = current;
        }
        return ans;
    }
};
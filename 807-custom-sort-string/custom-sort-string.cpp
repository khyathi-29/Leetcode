class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        // count occurence of each charector in string s;
        for(char c : s){
            m[c]++;
        }
        string ans = "";
        for(char c : order){
            if(m.find(c)!=m.end()){
                while(m[c]>0){
                    ans = ans+c;
                    m[c]--;
                }
            }
        }
        for(auto& it : m){
            while(it.second>0){
                ans = ans+it.first;
                m[it.first]--;
            }
        }
        return ans;
        
    }
};
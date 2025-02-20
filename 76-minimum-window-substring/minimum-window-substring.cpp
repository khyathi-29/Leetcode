class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> check;
        int ans_r = 0;
        int ans_l = 0;
        int ans = INT_MAX;
        int count = 0;
        if(s.size()<t.size()) return "";
        for(char c : t){
            check[c]++;
        }
        int l =0;
        int r=0;
        for(int r=0;r< s.size();r++){
            cout<<count<<endl;
            if(check[s[r]]>0){ 
                count++;
            }
            check[s[r]]--;
            while(count==t.size()){
                if(r-l+1<ans){
                    ans_r = r;
                    ans_l = l;
                    ans = r-l+1;
                }
                check[s[l]]++;
                if(check[s[l]]>0){
                    count--;
                }
                l++;
            } 
        }
        string tt ="";
        if(ans == INT_MAX)return tt;
        for(int i = ans_l; i<=ans_r;i++){
        tt = tt + s[i];
        }
        
        return tt;
        
    }
};
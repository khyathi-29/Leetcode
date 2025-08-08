class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s ;
        for(int i : nums) s.push_back(to_string(i));
        sort(s.begin(),s.end(),[](string a, string b){
           return (a+b)>(b+a);
        });
        string ans = "";
        if(s[0]=="0") return "0";// since its highest number all other numbers are going to be 0
        for(string temp : s){
            ans += temp;
        }
        return ans;
    }
};
class Solution {
public:
    void letterCombinationsHelper(int j,string digits,string& temp,vector<string>& n,vector<string>&ans){
        if(j==digits.size()) { 
            ans.push_back(temp);
            return;
        }
        int num = digits[j]-'0';
        cout<<num<<endl;
        for(char c : n[num]){
             temp = temp+c;
             letterCombinationsHelper(j+1,digits,temp,n,ans);
             temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits) {
      vector<string> n = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      vector<string> ans;
      string temp ="";
      if(digits=="") return ans;
      letterCombinationsHelper(0,digits,temp,n,ans);
     return ans;
      }
      
    };

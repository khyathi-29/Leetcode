class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> temp;
      Helper(0,s,ans,temp);  
      return ans;
        
    }
    void Helper(int index, string s, vector<vector<string>>& ans, vector<string>& temp)
    {
       // cout<<"called"<<endl;
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i < s.size();i++){
            //cout<<"insideloop"<<endl;
            string a = s.substr(index,i-index+1);
            if(isPalindrome(a)==true){
                temp.push_back(a);
                Helper(i+1,s,ans,temp);
                temp.pop_back();
            }
            
        }
    } 
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
        if(s[start]!=s[end]) return false;
           start++;
           end--;
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> temp;
      int n = s.size();
      // pre compute if string [i--j] is palindrome or not
      vector<vector<bool>>isPalindrome(n,vector<bool>(n,true));

      // to check
      //Build palindrome lookup table using dynamic programming
        // For any substring, it's a palindrome if:
        // 1. First and last characters match AND
        // 2. The substring between them is also a palindrome
      for(int i= n-1;i>-1;i--)
      {
        for(int j=i+1;j<n;j++)
        {
            isPalindrome[i][j]= (s[i]==s[j])&& isPalindrome[i+1][j-1];
        }
      }
      Helper(0,isPalindrome, s,ans,temp);  
      return ans;
        
    }
    void Helper(int index,vector<vector<bool>>& isPalindrome, string s, vector<vector<string>>& ans, vector<string>& temp)
    {
       // cout<<"called"<<endl;
        if(index==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = index ; i < s.size();i++){
            //cout<<"insideloop"<<endl;
            string a = s.substr(index,i-index+1);
            if(isPalindrome[index][i]==true){
                temp.push_back(a);
                Helper(i+1,isPalindrome,s,ans,temp);
                temp.pop_back();
            }
            
        }
    } 
    
};
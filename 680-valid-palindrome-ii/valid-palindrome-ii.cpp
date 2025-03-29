class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int count = 0;
        while(i<=j){
            if(s[i]!=s[j]){
              return isPalindrom(s,i,j-1) || isPalindrom(s,i+1,j);  
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindrom(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
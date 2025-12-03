class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j);
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i+=1;
                j-=1;
            }
            else return false;
        }
        return true;
    }
};
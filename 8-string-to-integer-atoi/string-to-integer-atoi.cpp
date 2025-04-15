
class Solution {
public:


    int myAtoi(string s) {
       int i=0;
       while(i<s.size() && s[i]==' ') i++;
       bool isPositive = true;
       if(s[i]=='-'){
           isPositive = false;
       }
       if(s[i]=='+'||s[i]=='-') i=i+1;
       int ans =0;
       while(i<s.size() && isdigit(s[i])){
           int val = s[i]-'0';
           if(ans>INT_MAX/10 || (ans==INT_MAX/10 && val>INT_MAX%10)){
            if(isPositive) return INT_MAX;
            else return INT_MIN;
           }
           ans = ans*10+val;
           i++;
       }
       if(isPositive) return ans;
       else return -ans;
    }
};
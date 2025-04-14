class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        bool isValidInt = false;
        bool decimal = false;
        if(s[i]=='+'|| s[i]=='-') {
            i++;
            if(i==s.size()) return false;
        }
        while(i<s.size()){
            if(s[i]=='.')
            {
                if(decimal==true) return false;
                else decimal = true;
            }
            else if(isdigit(s[i])==true)
            {
                isValidInt =true;
                while(i<s.size() && isdigit(s[i])==true)i++;
                i=i-1;
            }
            else if(s[i]=='e' || s[i]=='E') {
                if(!isValidInt) return false;
                return isValid(s,i+1);
            }
            else return false;
            i++;
        }
        if(decimal == true  && isValidInt==false) return false;
        return true;
        
    }
    bool isValid(string s, int start){
        if(start==s.size()) return false;
        if(s[start]=='+' || s[start]=='-') start=start+1;
        if(start==s.size()) return false;
        while(start<s.size() )
        {
            if(isdigit(s[start])==true) start++;
            else return false;
        } 
        return true;
    }
};
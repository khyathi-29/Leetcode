class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        bool isValidInt = false;
        bool decimal = false;
        if(s[i]=='+'|| s[i]=='-') {
            i++;// removes the sign for positive and negative values
            if(i==s.size()) return false; // if no number exists after sign return false;
        }
        while(i<s.size()){
            if(s[i]=='.')
            {
                // checks if its first occurence of decimal point or not if not first return false
                // if first updates decimal bool to true to keep track
                if(decimal==true) return false;
                else decimal = true;
            }
            else if(isdigit(s[i])==true)
            {
                // if its number traverse till end
                isValidInt =true;
                while(i<s.size() && isdigit(s[i])==true)i++;
                i=i-1;
                // so we don't skip next element
            }
            else if(s[i]=='e' || s[i]=='E') {
                if(!isValidInt) return false;
                //if number doesn't appear before e return false;
                return isValid(s,i+1);
                //checks if e is followed by only numbers or not
            }
            else return false; // else return false;
            i++;
        }
        if(decimal == true  && isValidInt==false) return false;
        // checks if decimal is followed by integer or has integer before decimal 
        // example . is not valid but .3 3. are both valid
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
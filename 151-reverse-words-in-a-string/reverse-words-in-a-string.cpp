class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string ans = "";
        int i =0 ;
        while(i<s.size())
        {
            if(s[i]==' ') i++;
            else break;
        }
        // the below function removes unnecessary blank spaces at start
         while(i<s.size())
        {
            if(s[i]!=' ')
            {
                temp = temp+s[i];
            }
            else if(temp!=""){
                ans = temp + " "+ans;
                temp = "";
            }
            i++;
        }
        if(temp!="") ans=temp+" "+ans;
        ans.pop_back();
        //removes the extra blank space added
        return ans;
    }
};
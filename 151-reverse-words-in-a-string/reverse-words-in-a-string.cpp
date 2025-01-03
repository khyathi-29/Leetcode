class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                temp=temp+s[i];
            }
            else if(temp!=""){//to avoid adding extra blank spaces
            cout<<temp<<endl;
                 if(ans=="") ans =ans+ temp;// to add a word initially
                else ans = temp + " " + ans;// to add words later
                temp="";
            }
        }
        if(temp!=""){
            if(ans!="")ans=temp+ " "+ ans;
            else ans = ans+temp;
        }
        return ans;
    }
};
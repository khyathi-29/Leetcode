
class Solution {
public:

//"0-1". for this case used started to check if taking numbers started
//this flag ensures that if not strted we can consider taking numbers
// and also +- etc 
// sign to check if sign assigned or not before number parsing 
//after number parsing==> its a pos number 
//whenever a number appears add it to a (building value) instead of making it a string and again calculating the values
    int myAtoi(string s) {
        bool sign = false;
        bool started = false;
        int val = 1;
        long long a=0;
        string temp = "";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' && started==false)continue;
            else if((s[i]=='+' || s[i]=='-') && sign==false && started==false){
                sign = true;
                started = true;
                if(s[i]=='-') val=-1;
            }
            //else if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) break;
            //else if(sign == true && (s[i]=='+' || s[i]=='-')) break;
            else if(s[i]>='0'&& s[i]<='9'){
                started=true;
                a=a*10+int(s[i]-'0');
              if(a*val>INT_MAX) return INT_MAX;
              if(a*val<INT_MIN) return INT_MIN;
            }
            else break;
            cout<<temp<<endl;

        }

        return a*val;
    }
};
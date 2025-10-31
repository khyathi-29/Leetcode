class Solution {
public:
    string addBinary(string a, string b) {
        string an = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(i>-1 || j>-1 || carry!=0)
        {
              int ans = carry;
              if(i>-1) ans+=a[i]-'0';
              if(j>-1) ans+=b[j]-'0';
              if(ans==1){ 
                an = "1"+ an;
                carry = 0;
              }
              else if(ans == 0){
                an = "0"+ an;
                carry = 0;
              }
              else if(ans==2){
                an = "0"+an;
                carry= 1;
              }
              else{
                an = "1"+an;
                carry= 1;
              }
              i--;
              j--;
        }
        return an; 
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string ans;
        while(i>-1 || j>-1 || carry==1){
            int temp=0;
            if(i>-1) temp+=num1[i]-'0'; 
            if(j>-1) temp+=num2[j]-'0'; 
            if(carry==1) temp+=1;
            cout<<temp<<endl;
            carry = temp/10;
            temp = temp%10;
            ans=to_string(temp)+ans;
            i--;
            j--;

        }
        return ans;
    }
};
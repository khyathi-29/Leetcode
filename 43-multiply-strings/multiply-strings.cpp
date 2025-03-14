class Solution {
public:
    string multiply(string num1, string num2) {
        int carry = 0;
        vector<int> ans(num1.size()+num2.size(),0);
        if(num1=="0" || num2=="0") return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
      for(int i=0;i<num2.size();i++) {
        for(int j =0;j< num1.size();j++){
            int a = num2[i]-'0';//
            int b = num1[j]-'0';
            ans[i+j] += a*b;
            ans[i+j+1] += ans[i+j]/10;
            ans[i+j]=ans[i+j]%10;
        }
      } 
      for(int i=ans.size()-1;i>-1;i--){
        if(ans[i]==0) ans.pop_back();
        else break;
      }
      string s = "";
      for(int i=0;i<ans.size();i++){
        char c = '0'+ans[i];
        s=c+s;
      }
      
      return s;
    }
};
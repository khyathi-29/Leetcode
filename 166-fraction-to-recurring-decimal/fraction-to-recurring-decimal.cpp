class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string ans = "";
        string sign = "";
        if(num==0) return "0";
        if((num<0)^(den<0)) sign="-";
        long denominator = abs((long)den);
        long numerator = abs((long)num);
        if(numerator<0)numerator=-numerator;
        if(denominator<0) denominator=-denominator;
        long nonfraction = abs(numerator/denominator);
        long fraction = numerator%denominator;
        ans=ans+sign;
        ans = ans+to_string(nonfraction);
        if(fraction==0) return ans;
        ans=ans+".";
        int i = ans.size();
        unordered_map<long,int>mp;
        while(fraction){
             fraction = fraction*10;
             if(mp.find(fraction)!=mp.end()){
                ans.insert(mp[fraction],1,'(');
                ans=ans+')';
                return ans;
             }
             else{
                mp[fraction]=ans.size();
                ans = ans+to_string(fraction/denominator);
                fraction=fraction%denominator;
             }
        }
        return ans;

    }
};
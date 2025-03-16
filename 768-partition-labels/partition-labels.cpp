class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int> startm;//first occurence
        unordered_map<char,int> endm;// second occurence
        for(int i=0;i<s.size();i++)
        {
            if(startm.find(s[i])==startm.end()) startm[s[i]]=i;
            if(endm.find(s[n-i-1])==endm.end()) endm[s[n-i-1]]=n-i-1;
        }
        vector<int> ans;
        int pstart =0;//partition start;
        int pend = 0;
        for(int i=0;i< s.size();i++){
            pend = max(pend,endm[s[i]]); // ending index for elements occured till now;
            if(i==pend){
               int length = pend+1-pstart;//partition length
               ans.push_back(length);
               pstart = i+1;//next partitions start;
               pend = 0;
            }
        }
        
       return ans ;
    }
};
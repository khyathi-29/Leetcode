class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ans;
        vector<int> a(26,0);
        vector<int> b(26,0);
        int count =0;
        int k = s1.size();

        if(k>s2.size()) return ans;
        int j=0;
        for(char c: s1){
            int i = c-'a';
               a[i]+=1;
        }
        for(j=0;j<s1.size();j++){
             char c = s2[j];
             int i = c-'a';
             b[i]++;
        }
        int i=0;
        while(i<26){
            if(a[i]==b[i]) count++;
            i++;
        }
         if(count==26) ans.push_back(0);
         while(j < s2.size()){
            int current = s2[j]-'a';
            int before = s2[j-k]-'a';
             // moving window by 1 
            if(b[before]==a[before]) count--; //if previous was a match now it won't be match
            b[before]--;
            if(b[before]==a[before]) count++; // after removal its a match so incerement count by 1

            if(b[current]==a[current]) count--; //if before frequency update it's a match now it won't be a match
            b[current]++;
            if(b[current]==a[current]) count++;// after freq update i'ts a match now
            if(count==26) ans.push_back(j+1-s1.size());
            j++;
        }
        return ans;
    }
};
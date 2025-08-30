class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        int count =0;
        int k = s1.size();

        if(k>s2.size()) return false;
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

         while(j < s2.size()){
            if(count==26) return true;
            int current = s2[j]-'a';
            int before = s2[j-k]-'a';
             // moving window by 1 
            if(b[before]==a[before]) count--; //if previous was a match now it won't be match
            b[before]--;
            if(b[before]==a[before]) count++; // after removal its a match so incerement count by 1

            if(b[current]==a[current]) count--; //if before frequency update it's a match now it won't be a match
            b[current]++;
            if(b[current]==a[current]) count++;// after freq update i'ts a match now
            j++;
        }
        if(count==26)return true;
        return false;
    }
};
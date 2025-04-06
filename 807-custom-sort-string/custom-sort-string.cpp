class Solution {
public:
    string customSortString(string order, string s) {
       vector<int> frequency(26,0);
        // count occurence of each charector in string s;
        for(char c : s){
            frequency[c-'a']++;
        }
        string ans = "";
        // now add all occurences of that charector into string in the order string given
        for(char c : order){
                while(frequency[c-'a']>0){
                    ans = ans+c;
                    frequency[c-'a']--;
                }
        }
        // now if there are any remaining charectors in the frequency add them as well.
        for(int i=0;i<26;i++){
            while(frequency[i]>0){
                char c = 'a'+i;
                ans = ans+c;
                frequency[i]--;
            }
        }
        return ans;
        
    }
};
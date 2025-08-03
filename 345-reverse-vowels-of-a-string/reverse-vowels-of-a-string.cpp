class Solution {
public:
    string reverseVowels(string s) {
        int low = 0;
        int high = s.size()-1;
        set<char> ss = { 'a','e','i','o','u','A','E','I','O','U'};
        while(low<=high)
        {
            while(ss.find(s[low])==ss.end() && low<=high) low++;
            while(ss.find(s[high])==ss.end() && low<=high) high--;
            if(low<=high){
            char c = s[low];
            s[low] = s[high];
            s[high] = c;
            high--;
            low++;
            }
            else break;
        }

        return s;
    }
};
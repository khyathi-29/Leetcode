class Solution {
public:
    bool isValid(string word) {
        bool vowel = false;
        bool consonent = false;
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        s.insert('A');
        s.insert('E');
        s.insert('I');
        s.insert('O');
        s.insert('U');
        if(word.length()<3) return false;
        for(char c : word)
        {
            if( !isdigit(c) && !isalpha(c) ) return false;
            if( isalpha(c)){
                if(s.find(c)==s.end()) consonent = true;
                else vowel = true;
            }
        }
         return vowel&consonent;
    }
};
class Solution {
public:
    int minAddToMakeValid(string st) {
        stack<char> s;
        int count = 0;
        for(char c : st){
            if(c=='(') s.push(c);
            else if (c==')'){
                if(!s.empty()) s.pop();
                else count++;
            } 
        }
        return count + s.size();
        
    }
};
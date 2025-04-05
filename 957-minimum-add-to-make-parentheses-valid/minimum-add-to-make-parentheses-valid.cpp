class Solution {
public:
    int minAddToMakeValid(string st) {
        int openbrackets = 0;
        int count = 0;
        for(char c : st){
            if(c=='(') openbrackets++;
            else if (c==')'){
                  if(openbrackets==0) count++; 
                  else openbrackets--;
            } 
        }
        return count + openbrackets;
        
    }
};
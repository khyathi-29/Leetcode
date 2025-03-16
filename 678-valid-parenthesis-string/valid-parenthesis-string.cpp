class Solution {
public:
    bool checkValidString(string s) {
        int minPossible = 0;
        int maxPossible = 0;
        int i=0;
        while(i<s.size()){
         if(s[i]=='('){
            minPossible++;
            maxPossible++;
         }
         else if(s[i]==')'){
            minPossible--;
            maxPossible--;
         }
         else{
            minPossible--;//Here * can be considered opening or closing or null value
            // so if its ( ==> +1 ,NULL==remain same, )==>-1   
            maxPossible++; // since maxpossible its considered as opening bracket
         }
         if(minPossible<0) minPossible =0; // out of these 3 cases consider a case where its minimum as well as valid 
         if(maxPossible<0) return false; 
          i++;
          cout<<minPossible;
         //number of closing brackets > number of opening brackets or start with an opening bracket case
        }
        if (minPossible==0) return true;
        else return false;
    }
        
};
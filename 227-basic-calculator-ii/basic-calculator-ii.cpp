class Solution {
public:
    int calculate(string s) {
     int current = 0,previous =0 ,result =0;
     int i=0;
     char previous_op = '+';
     while(i<s.size()){
        char temp = s[i];
        if(isdigit(temp)){
            while(i<s.size() && isdigit(s[i])){
                  current =current*10 + (s[i]-'0');
                  i++;
            }
            i=i-1;// so that it doesn't go to next charector which is not number
            if(previous_op=='+'){
                result += current;
                previous = current;
            }
            else if(previous_op=='-'){
                result -=current;
                previous = -current;
            }
            else if(previous_op=='*'){
                result -= previous;
                result += previous*current;
                previous = previous*current;
            }
            else{
                result -= previous;
                result += previous/current;
                previous = previous/current;
            }
            current=0;
        }
        else if(s[i]!=' '){
        previous_op=s[i];
        }
        i++;
     }
     
        return result;
    }
};
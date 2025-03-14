class Solution {
public:
    int numberSquare(int n){
        int sum = 0;
        while(n!=0){
        sum += pow(n%10,2);
        n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
    while(n!=1){
        n = numberSquare(n);
        if(s.find(n)!=s.end()) return false;
        else s.insert(n);
    }
        return true;
    }
};
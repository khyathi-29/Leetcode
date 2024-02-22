class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
         int shiftcount = 0;
         int a=left;
         int b=right;
      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1; 
          b = b >> 1;
    }
      return int64_t(a << shiftcount);
    }
};
class Solution {
    public int kthFactor(int n, int k) {
        int i=1; // factor
        int count =0;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                count++;
                if(k==count) return i;
            }
        }
        for (i = (int)Math.sqrt(n); i >= 1; i--) {
            if (n % i == 0 && i != n / i) {// so if perfect square we shouldn't count twice
                count++;
                if (count == k) return n / i;
            }
        }
        return -1;
        
    }
}
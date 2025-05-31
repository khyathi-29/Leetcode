class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int i=0;
        int j = letters.length-1;
        while(i<=j)
        {
            int mid = i+ (j-i)/2;
            if(letters[mid]==target)
            {
              i = mid+1;
            }
            else if(letters[mid]>target) j = mid-1;
            else i = mid+1;

        }
        if(i<letters.length) return letters[i];
        else return letters[0];
    }
}
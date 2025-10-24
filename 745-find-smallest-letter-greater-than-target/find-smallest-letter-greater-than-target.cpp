class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int h = letters.size()-1;
        while(l<=h)
        {
            int mid = (l+h)>>1;
            if(letters[mid]<=target) l = mid+1;
            else h = mid-1;

        }
        return (l<letters.size()) ? letters[l]:letters[0];
    }
};
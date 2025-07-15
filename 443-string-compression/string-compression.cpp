class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int left = 0;
        while(left<chars.size())
        {
            int j = left+1;
            int groupLength = 1;
            while(j<chars.size() && chars[left]==chars[j])
            {
                j++;
                groupLength++;
            }
            chars[i]=chars[left];
            i++;
            if(groupLength>1)
            {
                string number = to_string(groupLength);
                for(char ch : number)
                {
                    chars[i++]=ch;
                }
            }
            left = j;
        }

        return i;
        
    }
};
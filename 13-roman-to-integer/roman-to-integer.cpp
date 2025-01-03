class Solution {
public:
//1. If traversing from last element if current < prev then subtract current from total

    int romanToInt(string s) {
     unordered_map<char,int> umap;
     umap['I']=1;
     umap['V']=5;
     umap['X']=10;
     umap['L']=50;
     umap['C']=100;
     umap['D']=500;
     umap['M']=1000;
     int l = s.size();
     int total=umap[s[l-1]];
     int prev = umap[s[l-1]];
     int current ;
     for(int i= l-2;i>-1;i--)
     {
        int current = umap[s[i]];
        if(current<prev)
        {
            total-=current;
        }
        else total+=current;
        prev = current;
     }
     return total;
    }
};
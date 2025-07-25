class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> a;
        unordered_set<int> b;
        if(trust.size()==0 && n==1) return 1;
        for(int i=0;i<trust.size();i++)
        {
            a[trust[i][1]]++;
            b.insert(trust[i][0]);

        }
    
        for( auto i = a.begin(); i!=a.end(); i++)
        {
            if(i->second==n-1 && b.find(i->first)==b.end()) return i->first;
        }
        return -1;
    }
};
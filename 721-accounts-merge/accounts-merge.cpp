class UnionFind{
    vector<int> parent;
    vector<int> size;
    public :
    UnionFind(int n){
        
        int i = 0;
        while(i<n){
            parent.push_back(i);
            size.push_back(1);
            i++;
        }
    }
    int getUparent(int i){
        if(parent[i]!=i) return parent[i] = getUparent(parent[i]);
        return i;
    }
    void addEdge(int u, int v){
        int p1 = getUparent(u);
        int p2 = getUparent(v);
        if(p1!=p2){
            if(size[p1]>size[p2]){
                size[p1]+=size[p2];
                parent[p2]=p1;
            }
            else{
                size[p2]+=size[p1];
                parent[p1]=p2;
            }
        }

        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind d(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1; j<accounts[i].size();j++){
                  if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                  }
                  else{
                           d.addEdge(i,mp[accounts[i][j]]);
                  }
            }
        }
        unordered_map<int, set<string>> m;
        for(auto i = mp.begin();i!=mp.end();i++){
             int val = i->second;
             string temp = i->first;
             int parent = d.getUparent(val);
             if(m.find(parent)==m.end()){
                m[parent] = {temp};
             }
             else m[parent].insert(temp);
        }
        vector<vector<string>> ans;
        for(auto i = m.begin();i!=m.end();i++){
            
            vector<string> row(i->second.begin(), i->second.end());
            row.insert(row.begin(),accounts[i->first][0]);
            ans.push_back(row);
        }
        return ans;
    
    }
};
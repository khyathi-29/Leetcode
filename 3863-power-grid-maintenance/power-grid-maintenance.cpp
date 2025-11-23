class unionFind{
    public:
    vector<int> p;
    vector<int> s;
    unionFind(int n){
        int i =0;
        while(i<n){
            s.push_back(1);
            p.push_back(i);
            i++;
        }
    }
    int parent(int i){
        if(p[i]!=i) return p[i]=parent(p[i]);
        return i;
    }
    void addEdge(int i, int j){
        int pi = parent(i);
        int pj = parent(j);
        if(pi!=pj){
            if(s[pi]>s[pj]){
                s[pi]+=s[pj];
                p[pj]=p[pi];
            }
            else{
                s[pj]+=s[pi];
                p[pi]=p[pj];
            }
        }
        return;
    }

};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unionFind graph(c+1);
        for(vector<int> temp : connections){
               graph.addEdge(temp[0],temp[1]);
        }
        unordered_map<int, set<int>> mp;
        vector<bool> inActive(c+1,false);
        for(int i=0;i<c+1;i++) {
            int a = graph.parent(i);
            mp[a].insert(i);
        }
        vector<int> ans;
        for(vector<int> temp : queries){
           int val = temp[1];
           int type = temp[0];
           if(type==1){
             int answer = -1;
              if(inActive[val]==true){
                int parent = graph.p[val];
                 if(mp[parent].size()!=0)answer = *mp[parent].begin();
                }
               else answer = val;
                ans.push_back(answer);
            }
              else{
                 inActive[val]=true;
                 mp[graph.p[val]].erase(val);
              }
           }
           return ans;
        }
    };

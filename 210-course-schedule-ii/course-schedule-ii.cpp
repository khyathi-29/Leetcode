class Solution {
public:
   // topological ordering - in bfs using in degree and in dfs using stacks
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      
        vector<int> inDegree(numCourses,0);
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
           // cout<<inDegree[i]<<endl;
            if(inDegree[i]==0)q.push(i);
        }
        //cout<<"ggf"<<endl;
        int count = 0;
        while(!q.empty()){
            count++;
            int node = q.front();
            ans.push_back(node);
           // cout<<node<<" "<<count<<endl;
            q.pop();
            for(int i : adj[node]){
                inDegree[i]--;
                if(inDegree[i]==0)q.push(i);
            }
        }
        //cout<<count<<endl;
      if (count==numCourses) return ans;
      return {};
        
      
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(vector<int> temp : prerequisites){
            adj[temp[1]].push_back(temp[0]);
        }
       vector<bool> visited(n,false),dfsvisited(n,false);
       for(int i=0;i<n;i++){
        if(visited[i]==false){
              bool ans = dfs(i,n,adj,visited,dfsvisited);
              if(ans==false) return false;
        }
       }
       return true;
    }
    bool dfs(int i, int n, vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& dfsvisited)
    {
        visited[i]=true;
        dfsvisited[i]=true;
        for( int j : adj[i]){
            if(visited[j]==false) {
                if(!dfs(j,n,adj,visited,dfsvisited)) return false;
            }
            else{
                if(dfsvisited[j]) return false;
            }
        }
        dfsvisited[i]=false;
        return true;
    }
    
};
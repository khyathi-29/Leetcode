class Solution {
public:
// if there is a cycle in a graph ==> its not possible 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
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
           // cout<<node<<" "<<count<<endl;
            q.pop();
            for(int i : adj[node]){
                inDegree[i]--;
                if(inDegree[i]==0)q.push(i);
            }
        }
        //cout<<count<<endl;
        return count==numCourses;
        
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        distance[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> tempd = distance;
            for(vector<int> f : flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if(distance[u]!=INT_MAX && tempd[v]> distance[u]+w){
                       tempd[v] = distance[u]+w;
                }
            }
             distance = tempd;
        }
        if(distance[dst]==INT_MAX) return -1;
      return distance[dst]; 
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int> d(n,INT_MAX);//cost like distance matrix
      d[src]=0;  
      for(int i=0;i<k+1;i++){
        vector<int> tempd = d;//we need it so that we don't take updated distances in calculating 
        for(vector<int> details : flights){
            int u =details[0];
            int v = details[1];
            int w = details[2];
            if(d[u]!=INT_MAX && tempd[v]> d[u]+w){
                tempd[v]=d[u]+w;
                cout<<d[dst]<<" "<<u<<endl;
            }
        }
        d = tempd;
        cout<<d[dst]<<endl;
      } 
      if(d[dst]==INT_MAX) return -1;
      return d[dst]; 
    }
};
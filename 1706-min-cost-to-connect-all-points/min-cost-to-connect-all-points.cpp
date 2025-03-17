class Solution {
public:
//disjoint set nlog(n) so we use optimised prims algo
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans=0;
        vector<bool> included(n,false);//closest points in collection
        vector<int> minVal(n,INT_MAX);//
        minVal[0] = 0 ;
        int node = 0;
        int count = 0;
        //int prevNode = -1;
        int prevVal = 0;
        while(count<n){
            included[node]=true;
            pair<int,int> edgeweight =make_pair(-1,INT_MAX);//to update small node and its weight;
            for(int i=0;i<n;i++){
                if(included[i]==false){
                    int dist = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    if(dist < minVal[i]){
                    minVal[i] = dist;
                    }
                    if (minVal[i] < edgeweight.second) {
                         edgeweight.second = minVal[i];
                         edgeweight.first = i; }
            }}
            if(edgeweight.first!=-1){
                 node = edgeweight.first;
                //cout<<i<<" "<<node<<endl;
                 ans +=edgeweight.second;
            }
            count++;
        }
        return ans;
}
};
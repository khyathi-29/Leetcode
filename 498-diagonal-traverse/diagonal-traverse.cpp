class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int r = mat.size();
        int c = mat[0].size();
        bool up = true; // if going upward
        int total = mat.size()*mat[0].size();
        int i=0,j=0;
        while(total >0){
            ans.push_back(mat[i][j]);
             if(up == true){
                i=i-1;
                j =j+1;
                
                if(j==c){ // right border case
                   j=c-1;
                   i=i+2;
                   up = false;
                }
                else if(i<0) { // top border case
                    i=0;
                    up = false;
                }
                    
                }
             else{
                i=i+1;
                j =j-1;
                if (i==r) { // left border case
                    i=i-1;
                    j+=2;
                    up = true;
                }
                else if(j<0) {
                    j=j+1;
                    up = true;
                }
                    cout<<"true"<<i<<j<<endl;
                }
                total--;
             }
        return ans;
    }
};
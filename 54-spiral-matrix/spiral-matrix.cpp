class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     //1-- horizontally right
     //2-- vertically down   
     //3-- horizontally left
     //4-- vertically up
     int i1 = 0;
     int i2 = matrix.size()-1;
     int j1 = 0;
     int j2 = matrix[0].size()-1;
     int count = (i2+1)*(j2+1);
     vector<int> ans;
     int type = 1;
     while(count>0 && i1<=i2 && j1<=j2){
        if(type==1){
            cout<<"1"<<endl;
            for(int i = j1;i<=j2;i++){
              ans.push_back(matrix[i1][i]);
              count--;
            }
            i1=i1+1;
            type=2;
        }
        else if(type==2){
            cout<<"2"<<endl;
            for(int i = i1;i<=i2;i++){
              ans.push_back(matrix[i][j2]);
              count--;
            }
            j2 = j2-1;
            type = 3;

        }
        else if( type==3){
            cout<<"3"<<endl;
            for(int i = j2;i>=j1;i--){
              ans.push_back(matrix[i2][i]);
              count--;
            }
            i2 = i2-1;
            type = 4;

        }
        else{
            cout<<"4"<<endl;
            for(int i = i2;i>=i1;i--){
              ans.push_back(matrix[i][j1]);
              count--;
            }
            j1 = j1+1;
            type = 1;

        }

     }
     return ans;
    }
};
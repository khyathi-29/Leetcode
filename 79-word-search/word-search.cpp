class Solution {
public:
    bool check(vector<vector<char>>& board, string word, int& count, int i, int j ){
        if(count == 0) return true;
        bool ans;
        if(i>=board.size() || j>=board[i].size() || i<0 || j<0 || word[count-1]!=board[i][j]){
            return false;
        }else{
        char temp = board[i][j];
        board[i][j] = '%';
        count--;
        ans = check(board, word, count,i+1,j)|| check(board, word, count,i,j+1)||check(board,word,count,i-1,j)||check(board, word, count,i,j-1);
        count++;
        board[i][j] = temp;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int count = word.size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[count-1] && check(board,word,count,i,j)==true) return true;
            }
        }
        return false;
    }
};
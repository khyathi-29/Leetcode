class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        queue<string> q;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        if(s.find(endWord)==s.end()) return 0;
        q.push(beginWord);
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();//elements in the each level
            for(int ss =0 ; ss < size ; ss++){
            string temp = q.front();
            q.pop();
            if(temp==endWord) return count+1;
            for( int i=0;i<temp.size();i++){
                char c = temp[i];
                for(char w = 'a';w <= 'z';w++){
                    if(w!=c){
                        temp[i] = w;
                        
                        if(s.find(temp)!=s.end()){
                          q.push(temp);
                          s.erase(temp);
                        } 
                    }
                }
                temp[i] = c;
            }
            };
            count++;
        }
      return 0;
        
    }
};
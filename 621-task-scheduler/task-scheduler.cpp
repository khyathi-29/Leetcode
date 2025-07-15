class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq(26,0);//since only alphabets
        for(char ch : tasks) freq[ch-'A']++;
        for(int i : freq) if(i>0) pq.push(i);
        //only consider frequencies greater than 1
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty())
        {
          time++;
          if(!pq.empty())
          {
            int topElement = pq.top();
            pq.pop();
            if(topElement>1)
            {
                q.push(make_pair(time+n,topElement-1));
            }
          }
          else{
            time = q.front().first;
          }
          if(!q.empty() && time==q.front().first){
            pq.push(q.front().second);
            q.pop();
          }
        }
        return time;
      
    }
};
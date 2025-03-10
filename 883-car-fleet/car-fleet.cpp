class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> a;
        for(int i=0;i<position.size();i++){
        a.push_back(make_pair(position[i],speed[i]));
        }
        sort(a.begin(), a.end(), [](const pair<int, int>& c, const pair<int, int>& b) {
            return c.first > b.first; 
        });
        //stack<float> s;
        float initial_time = float((target - a[0].first))/float (a[0].second);
        int fleet = 1;
        //96, 49, 25,

        for(int i = 1 ; i <a.size();i++){
             float time_taken = float((target - a[i].first))/float (a[i].second);
             cout<<time_taken<<endl;
             if(initial_time < time_taken){ 
                fleet++;
                initial_time = time_taken;
             }

        }
        return fleet;
    }
};
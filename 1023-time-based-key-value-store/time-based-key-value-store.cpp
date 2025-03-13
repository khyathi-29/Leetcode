class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
      m[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end())return "";
        else{
            int start = 0;
            string result= "";
            int end = m[key].size()-1;
            while(start<=end){
                int mid = (start+end)/2;
                if(timestamp==m[key][mid].first) return m[key][mid].second;
                else if(timestamp > m[key][mid].first){ 
                    result = m[key][mid].second;
                    start = mid+1;
                }
                else end = mid -1;
            }
            return result; //m[key][result].second; in case time based value is lower than the given values 
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
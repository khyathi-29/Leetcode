class DetectSquares {
private:  map<pair<int,int>,int> points;
public:
    DetectSquares() {}
    
    void add(vector<int> point) {
        points[{point[0],point[1]}]++;
        
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y = point[1];
        int result = 0;
            for(auto& k : points){
                int px = k.first.first;
                int py = k.first.second;
                int f2 = points[{px,py}];
                if(abs(px-x)==abs(py-y) && px!=x && py!=y) {
                    int f3 = points[{x,py}];
                    int f4 = points[{px,y}];
                    result = result + (f2*f3*f4);
                }

            }
        return result;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
class StockSpanner {
    stack<pair<int,int>> s;
    int index;
public:
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index= index+1;
        int temp = -1;
        while(!s.empty() && s.top().first<=price)
        {
            s.pop();
        }
        if(s.empty()){ 
            s.push(make_pair(price,index));
            return index-temp;
        }
        else
        {
            temp = s.top().second;
            s.push(make_pair(price,index));
            return index-temp;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
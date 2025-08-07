class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
            // Sort events by start day
    sort(events.begin(), events.end(),
         [](const vector<int>& a, vector<int>& b){
             return a[0]< b[0];
         });

    // Min-heap of event end days
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = events.size();
    int i = 0;             // index into events
    int day = 0;           // current day pointer
    int attended = 0;      // total events attended

    // Initialize day to the earliest start
    if (n > 0) day = events[0][0];

    // Sweep until we've processed all events and emptied the heap
    while (i < n || !pq.empty()) {
        // If no ongoing candidates, jump day to next event start
        if (pq.empty() && i < n) {
            day = max(day, events[i][0]);
        }

        // Add all events starting today or earlier into heap
        while (i < n && events[i][0]<= day) {
            pq.push(events[i][1]);
            ++i;
        }

        // Drop any events that already ended before today
        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }

        // If there's at least one event we can attend today, pick the one
        // with the earliest end (greedy), attend it, and advance the day
        if (!pq.empty()) {
            pq.pop();
            ++attended;
            ++day;
        }
    }

    return attended;
        
    }
};
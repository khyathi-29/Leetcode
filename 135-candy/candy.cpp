class Solution {
public:
    int candy(vector<int>& ratings) {
       if (ratings.size() < 2) {
            return ratings.size(); // If only 1 child, give 1 candy
        }
     int count = 1;
     int i =1;
     int n = ratings.size();
     while(i<n)
     {
        if(ratings[i]==ratings[i-1])
        {
            count+=1;
            i++;
            continue;
        }
        int peak = 1;
        while(i<n && ratings[i]>ratings[i-1])
        {
            peak++; 
            count += peak;
            i++;
        }
        int down =1;
        while(i<n && ratings[i]<ratings[i-1])
        {
            count += down;
            down++; 
            i++;
        }
        if(down > peak) count += down-peak;
     }

        return count;
    }
};
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        int n = arr.size()-1;
        if(arr.size()<3) return false;
        if(arr[0]>=arr[1] || arr[n]>=arr[n-1]) return false;
        int i=1;
        while(i<n)
        {
            if(arr[i]>arr[i-1]) i++;
            else if(arr[i]==arr[i-1]) return false;
            else break; 
        }
        i = i-1;
        while(i<n-1)
        {
            if(arr[i]>arr[i+1]) i++;
            else if(arr[i]==arr[i+1]) return false;
            else break;
        }
        cout<<i<<endl;
        return (i==n-1)?true:false;
    }
};
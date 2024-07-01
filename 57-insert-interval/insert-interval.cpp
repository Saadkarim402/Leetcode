class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>>ans;
        int n=intervals.size();
        //first adding all the intervals which will always be in same order 
        while(i<n&&intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //now changing the new interval 
        while(i<n&&intervals[i][0]<=newInterval[1]){
            newInterval={min(intervals[i][0],newInterval[0]),max(intervals[i][1],newInterval[1])};
            i++;
        }
        ans.push_back(newInterval);

        //remaining
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;  
    }
};
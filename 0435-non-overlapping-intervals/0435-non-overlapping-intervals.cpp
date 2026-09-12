class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time (greedy strategy)
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int n = intervals.size();
        int taken = 1;
        // Store end time of the last non-overlapping interval
        int prevEnd = intervals[0][1];
        for(int i = 1; i < n; i++){ // start from second
            if(intervals[i][0] >= prevEnd){ // noover lap
                taken++;
                prevEnd = intervals[i][1];
            }
        }
        return n - taken;
    }
};
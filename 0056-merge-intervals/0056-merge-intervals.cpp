class Solution {
    // BY GREEDY
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n == 0) return res;
        sort(intervals.begin(), intervals.end());
        vector<int> tempinterval = intervals[0];
       
        for(auto it : intervals){
            if(it[0] <= tempinterval[1]){ // (1,3) (2,4) (2,6)
                tempinterval[1] = max(it[1], tempinterval[1]);
            }    
            else { // no overlapping / merging
                res.push_back(tempinterval);
                tempinterval = it;
            }
        }
        res.push_back(tempinterval);
        return res;
    }
};
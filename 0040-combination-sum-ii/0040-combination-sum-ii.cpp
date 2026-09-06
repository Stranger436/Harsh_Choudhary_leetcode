class Solution {
public:
    void solve(vector<int>& candidates, int target, int indx, vector<int>& ds, vector<vector<int>>& ans){
        int n = candidates.size();
        if(target == 0){ // base case
            ans.push_back(ds);
            return;
        }
        for(int i = indx; i < n; i++){
            if(candidates[i] > target) break;
            if(i > indx && candidates[i] == candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, ds, ans);
        return ans;
    }
};
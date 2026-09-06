class Solution {
public:
    void solve(vector<int>& candidates, int target, int indx, vector<int>& ds, vector<vector<int>>& ans){
        int n = candidates.size();
        if(indx == n){ // base case
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[indx] <= target){
            // pick
            ds.push_back(candidates[indx]);
            solve(candidates, target - candidates[indx], indx, ds, ans);
            // backtrack
            ds.pop_back();
        }
        // not pick
        solve(candidates, target, indx + 1, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> ds;
       solve(candidates, target, 0, ds, ans);
       return ans;
    }
};
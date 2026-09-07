class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int indx){
        int n = nums.size();
        ans.push_back(ds);
        for(int i = indx; i < n; i++){
            if(i > indx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(nums,ans,ds,i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums, ans, ds, 0);
        return ans;
    }
};
class Solution {
public:
    void solve(int n, int indx, vector<int>& nums, int k, vector<vector<int>>& ans){
        if(n == 0 && nums.size() == k){ //If the sum is zero and the number of elements is k
            ans.push_back(nums);
            return;
        }
        // If the sum is less than or equal to zero or the number of elements exceeds k
        if(n <= 0 || nums.size() > k) return;
        for(int i = indx; i <= 9; i++){
            if(i <= n){
                nums.push_back(i);
                solve(n-i, i + 1, nums, k, ans);
                nums.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;      // k = length needed
        vector<int> nums;             // n = sum needed
        // Call the recursive function with initial parameters
        solve(n, 1, nums, k, ans);
        return ans; 
    }
};
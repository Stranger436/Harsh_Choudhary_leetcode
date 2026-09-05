class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> premax(n), sufxmin(n);
        // Prefix maximum: max till ith index
        premax[0] = nums[0]; // first element is the only one at i = 0 it is the max / min
        for(int i = 1; i < n; i++){
            premax[i] = max(premax[i - 1], nums[i]);
        }
        // Suffix minimum: min from ith index till the end
        sufxmin[n - 1] = nums[n - 1]; // last element is the only one at i = 0 it is the max / min
        for(int i = n - 2; i >= 0; i--){
            sufxmin[i] = min(sufxmin[i + 1], nums[i]);
        }

        for(int z = 0; z < n; z++){
            if(premax[z] - sufxmin[z] <= k){
                return z;
            }
        }
        return -1;
    }
};
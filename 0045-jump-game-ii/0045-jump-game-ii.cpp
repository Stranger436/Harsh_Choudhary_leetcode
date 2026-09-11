class Solution {
public:
    int solve(vector<int>& nums){
        int jumps = 0, l = 0, r = 0, n = nums.size();

        while(r < n - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            if(farthest == r){
                return -1;
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
    int jump(vector<int>& nums) {
        return solve(nums);
    }
};
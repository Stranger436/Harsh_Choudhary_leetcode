class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0, r = 0, sum = 0, count = 0;

        while(r < n){
            sum += nums[r];
            if(goal < 0) return 0;
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size(); 
        int l = 0, r = 0, sum = 0, ans = 0;

        while(r < n){
            if(nums[r] % 2 == 1){
                sum += 1;
            }
            else{
                sum += 0;
            }
            while(sum > k){
                if(nums[l] % 2 == 1){
                    sum -= 1;
                }
                l++;
            }
            if(sum <= k){
                ans += r - l + 1;
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atmost(nums, k) - atmost(nums, k - 1);
    }
};
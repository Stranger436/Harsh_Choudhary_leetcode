class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        unordered_map<int,int> freq;
        while(r < n){
            freq[nums[r]]++;
            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
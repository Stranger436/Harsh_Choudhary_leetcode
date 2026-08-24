class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, zer = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zer++;
            }
            while(zer > k){
                if(nums[l] == 0){
                    zer--;
                }
                l++;
            }
            maxLen = max(maxLen, i - l + 1);
        }
        return maxLen;
    }
};
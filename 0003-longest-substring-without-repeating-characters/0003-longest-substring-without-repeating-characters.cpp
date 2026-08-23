class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxsize = 0;
        vector<int> hash(256, -1);
        
        while(r < n){    
            if(hash[s[r]] != -1){ // already inside the map
                l = max(l, hash[s[r]] + 1); // only moves forward if l is out of window means chota then s[r] + 1 then do not move
            }
            int len = r - l + 1;  // current len
            maxsize = max(maxsize, len); 
            hash[(unsigned char)s[r]] = r;
            r++;
        }
        return maxsize;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        int l = 0, r = 0, minLen = INT_MAX, cnt = 0, stindx = -1;
        vector<int> hash(256,0);

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }
        while(r < n){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt == m){
                if(r - l + 1 < minLen){
                    minLen = min(minLen, r - l + 1);
                    stindx = l;
                }
                hash[s[l]]++; // remove it
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return stindx == -1 ? "" : s.substr(stindx, minLen);
    }
};
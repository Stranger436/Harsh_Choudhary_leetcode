class Solution {
public:
    bool ispalind(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int n, vector<int>& dp) {
        if (i == n) return 0;
        int mincost = INT_MAX;
        if(dp[i] != -1) return dp[i];
        // temp will always be from i to j
        for (int j = i; j < n; j++) {
            if (ispalind(s, i, j)) {
                int cost = 1 + solve(s, j + 1, n, dp);
                mincost = min(mincost, cost);
            }
        }
        return dp[i] = mincost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(s, 0, n, dp) - 1;
    }
};
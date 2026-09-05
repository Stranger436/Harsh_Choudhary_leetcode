class Solution {
public:
    void solve(string curr,int n, int open, int close, vector<string>& ans){
        if(curr.length() == 2 * n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            solve(curr+'(', n, open + 1, close, ans);
        }
        if(close < open){
            solve(curr+')', n, open, close + 1, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("",n,0,0,ans);
        return ans;
    }
};
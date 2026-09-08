class Solution {
public:
    bool is_palin(string &s, int start, int end) {
        while(start <= end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>>& ans, vector<string> ds, int indx){
        int n = s.size();
        if(indx == n){
            ans.push_back(ds);
            return;
        }
        for(int i = indx; i < n; i++){
            if(is_palin(s,indx,i)){
                ds.push_back(s.substr(indx, i - indx + 1));
                solve(s,ans,ds,i+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s,ans,ds,0);
        return ans;
    }
};
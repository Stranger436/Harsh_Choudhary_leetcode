class Solution {
public:
    void solve(string digits, vector<string>& ans, string ds, string mapping[], int indx){
        if(indx == digits.size()){
            ans.push_back(ds);
            return;
        }
        int digit = digits[indx] - '0';
        for(int i = 0; i < mapping[digit].size(); i++){
            ds.push_back(mapping[digit][i]);
            solve(digits,ans,ds,mapping,indx+1);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, ds, mapping, 0);
        return ans;
    }
};
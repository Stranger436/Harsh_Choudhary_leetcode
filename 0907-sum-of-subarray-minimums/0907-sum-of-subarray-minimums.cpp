// OPTIMAL
class Solution {
public:
    vector<int> find_PSE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> PSE1(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            } 
            PSE1[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSE1;
    }
    vector<int> find_NSE(vector<int>& arr){
        int n = arr.size();
        vector<int> NSE1(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            NSE1[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE1;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        vector<int> PSE = find_PSE(arr);
        vector<int> NSE = find_NSE(arr);
        int mod = 1e9 + 7; // keep the answer within the required modulo range.

        for(int i = 0; i < n; i++){
            int left = i - PSE[i];
            int right = NSE[i] - i;

            long long freq = (left * right * 1LL); // 1LL => forces to use long long airthematic
            int val = (freq * arr[i] * 1LL) % mod; 

            sum = (sum + val) % mod;
        }
        return sum;
    }
};
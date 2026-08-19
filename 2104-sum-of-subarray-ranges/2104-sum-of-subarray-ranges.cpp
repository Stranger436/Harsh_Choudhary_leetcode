class Solution {
public:

    // SUM OF MAXIMUMS OF SUB-ARRAYS
    vector<int> find_NGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> NGE1(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            NGE1[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return NGE1;
    }

    vector<int> find_PGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> PGE1(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            PGE1[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return PGE1;
    }

    long long sumOfMax(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;

        vector<int> NGE = find_NGE(arr);
        vector<int> PGE = find_PGE(arr);

        for(int i = 0; i < n; i++) {
            long long left = i - PGE[i];
            long long right = NGE[i] - i;

            long long freq = left * right;
            long long val = freq * arr[i];

            sum += val;
        }

        return sum;
    }


    // SUM OF MINIMUMS OF SUB-ARRAYS
    vector<int> find_PSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> PSE1(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            PSE1[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return PSE1;
    }

    vector<int> find_NSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> NSE1(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            NSE1[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return NSE1;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;

        vector<int> PSE = find_PSE(arr);
        vector<int> NSE = find_NSE(arr);

        for(int i = 0; i < n; i++) {
            long long left = i - PSE[i];
            long long right = NSE[i] - i;

            long long freq = left * right;
            long long val = freq * arr[i];

            sum += val;
        }

        return sum;
    }
    // SUM OF SUBARRAY RANGES
    long long subArrayRanges(vector<int>& nums) {
        long long largest = sumOfMax(nums);
        long long smallest = sumSubarrayMins(nums);

        return largest - smallest;
    }
};
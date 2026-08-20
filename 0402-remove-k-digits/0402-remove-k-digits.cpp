class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){ // pop the greater elements
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0){ // if k is still left then remove k elements from last
            st.pop();
            k--;
        }
        if(st.empty()) return "0"; // everything was popped out (basically n = k)

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        while(!res.empty() && res.back() == '0'){ // remove zeroes from back so there will be no zeroes in front of our answer
            res.pop_back();
        }
        if(res.empty()) return "0";
        reverse(res.begin(), res.end()); // reverse to get the correct answer
        return res;
    }
};
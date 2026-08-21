class Solution {
public:

    // Largest Rectangle in Histogram
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        // Sentinel 0 to process remaining bars
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            // Current bar is smaller → calculate area
            while (!st.empty() && heights[i] < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                // Width between smaller elements on both sides
                int width = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        // Stores consecutive 1s vertically for each column
        vector<int> height(m, 0);

        int maxArea = 0;

        // Traverse every row
        for (int i = 0; i < n; i++) {

            // Build histogram for current row
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Find largest rectangle in current histogram
            maxArea = max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }
};
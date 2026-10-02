class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Source or destination blocked
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;
        // Source == destination
        if(n == 1 && m == 1)
            return 1;

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // Source = (0,0)
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        // 8 directions
        int delrow[] = {-1,-1,-1, 0,0, 1,1,1};
        int delcol[] = {-1, 0, 1,-1,1,-1,0,1};
        while(!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Destination
            if(r == n-1 && c == m-1)
                return dis;

            for(int i = 0; i < 8; i++) {
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                grid[newrow][newcol] == 0 && dis + 1 < dist[newrow][newcol]) {
                    dist[newrow][newcol] = dis + 1;
                    q.push({dis + 1, {newrow, newcol}});
                }
            }
        }
        return -1;
    }
};
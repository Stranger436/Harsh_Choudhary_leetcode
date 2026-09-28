class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& col){
        col[node] = color;

        for(auto it : graph[node]){
            if(col[it] == -1){
                if(dfs(it, !color, graph, col) == false) return false;
            }
            else if(col[it] == color){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++){
            if(col[i] == -1){
                if(dfs(i, 0, graph, col) == false) return false;
            }
        }
        return true;
    }
};
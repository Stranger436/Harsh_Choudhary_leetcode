class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> indegree(n,0);
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                // i -> it {edge}
                // need to conver it ot it -> i 
                revgraph[it].push_back(i); // {0,1} isko {1,0} kr diya
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safenodes;
        for(int i = 0; i < n; i++){ // finding that phle se 0 wala
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it : revgraph[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};
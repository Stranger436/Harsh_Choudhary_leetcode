class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(auto it : prerequisites){
            int course = it[0];
            int prerequist = it[1];
            
            adj[prerequist].push_back(course);
            
        }

        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo; // ans
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort so remove its indegree
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};
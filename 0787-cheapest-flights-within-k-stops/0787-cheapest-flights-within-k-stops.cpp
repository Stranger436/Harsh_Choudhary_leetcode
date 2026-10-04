class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // graph creation
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}}); // {stops, {node, distance}}
        vector<int> dist(n , 1e9);
        dist[src] = 0; // src marked as 0

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue; // if stops zyada ho jaye leave that path
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int eDw = iter.second;

                if(cost + eDw < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + eDw;
                    q.push({stops + 1, {adjNode, cost + eDw}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1; // unreachable
        else return dist[dst];
    }
};
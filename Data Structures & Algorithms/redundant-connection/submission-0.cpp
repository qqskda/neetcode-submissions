class Solution {
public:
    bool hasPath(int u, int v, unordered_map<int,vector<int>>& graph, unordered_set<int>& visited)
    {
        if (u == v) return true; // self-loop
        if (visited.contains(u)) return false; // we have been here - loop avoidance
        visited.insert(u);

        for (int nei : graph[u])
        {
            if (hasPath(nei, v, graph, visited)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // DFS
        // When there are n nodes
        // cyclic => edges.size() is at least n + 1
        // non-cyclic => edges.size() is at least n-1

        // 1. edges are one way at the moment. Create two ways for make our life easier
        int size = edges.size();
        unordered_map<int,vector<int>> graph;
        
        for (const vector<int>& edge : edges)
        {
            int u = edge[0], v = edge[1];
            unordered_set<int> visited; // Since it is dfs, we create new one per each destination

            // Before adding u,v to the graph, check if we can reach
            // from u to v with existing added graph

            // Think it like we are drawing a graph one by one.
            if (hasPath(u, v, graph, visited)) return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
        return {};
    }
};

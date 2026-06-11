class Solution {
public:
    void dfs(int node, int parent, int depth, int &maxDepth, vector<vector<int>> &graph) {
        maxDepth = max(maxDepth, depth);
        for (auto &neighbour: graph[node])
            if (neighbour != parent)
                dfs(neighbour, node, depth + 1, maxDepth, graph);
    }

    int assignEdgeWeights(vector<vector<int>> &edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;   // n-1 edges --> n nodes
        // Create adjacency list
        vector<vector<int>> graph(n + 1);   // node numbers: 1 to n
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform dfs from node 1 to find maximum depth
        int maxDepth = 0;
        dfs(1, -1, 0, maxDepth, graph);   // node, parent, current depth, maxDepth, graph
        
        // Ans is 2^(maxDepth - 1) % MOD
        long result = 1;
        for(int i=1; i < maxDepth; i++)
            result = (result * 2) % MOD;
        return result;
    }   
};
class Solution {
public:
    bool dijkstra(long long& mid, int src, int target, long long& k, vector<vector<pair<int,int>>>& adj) {
        int n = adj.size();
        vector<long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        // min heap: distance, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({0, src});
        while(!pq.empty()){
            // pop from priority queue
            auto [d, node] = pq.top();
            pq.pop();

            // discard if distance is greater than previous distance found
            if(d > dist[node]) continue;
            // target reached
            if(node == target) return true;
    
            for(auto& [v, w]: adj[node]){       // scan neighbours
                if(w < mid) continue;           // edge weight < mid
                int new_dist_v = d + w;
                if(new_dist_v > k) continue;    // new distance of v > total distance allowed
                if(new_dist_v < dist[v]){       // better distance found to neighbour v
                    dist[v] = d + w;            // update distance of v
                    pq.push({dist[v], v});      // puch to pq
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        // create graph with valid edges: both u and v online
        vector<vector<pair<int,int>>> adj(n);
        int max_dist = 0;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, w});     // u --> {v, w}
                max_dist = max(max_dist, w);  // max edge cost --> range for binary search
            }
        }

        // binary search over ans range: 0 to m (max edge cost)
        long long l = 0, h = max_dist, ans = -1;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            // Using dijkstra, check if we can reach from 0 to n-1 with given constraints
            // if yes, we found an ans --> store it and look for better
            // if no --> check with smaller mid
            if (dijkstra(mid, 0, n - 1, k, adj)) {
                ans = mid;      // store ans
                l = mid + 1;    // look for better ans
            } else {
                h = mid - 1;    // look for ans
            }
        }
        return ans;
    }
};

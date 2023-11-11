class Graph {
public:
    typedef pair<int, int> p;
    vector<vector<p>> adj_list;
    Graph(int n, vector<vector<int>>& edges) {
        // construct graph
        adj_list.resize(n);
        for (auto edge : edges) {
            adj_list[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adj_list[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        // dijkstra implementation, node1 = root, node2 = target
        int n = adj_list.size();
        vector<int> distances(n, INT_MAX);
        distances[node1] = 0;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (cost > distances[curr]) continue;
            if (curr == node2) return cost;

            for (auto edge : adj_list[curr]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newCost = edgeLength + distances[curr];
                if (distances[neighbor] > newCost) {
                    distances[neighbor] = newCost;
                    pq.push({newCost, neighbor});
                }
            }
        }

        return ((distances[node2] == INT_MAX) ? -1 : distances[node2]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
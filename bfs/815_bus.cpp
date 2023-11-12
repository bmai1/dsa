class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // tracks which routes have a stop
        unordered_map<int, vector<int>> cum;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int route = 0; route < routes[bus].size(); ++route) {
                // routes[bus][route] is the route
                cum[routes[bus][route]].push_back(bus);
            }
        }
        queue<int> q;
        unordered_set<int> visitedRoutes;
        q.push(source);

        int res = 0;
        while (!q.empty()) {
            int n = q.size(); 
            for (int i = 0; i < n; ++i) {
                int curr = q.front(); q.pop();
                if (curr == target) return res;
                for (int bus : cum[curr]) {
                    if (visitedRoutes.count(bus) == 0) {
                        visitedRoutes.insert(bus);
                        for (int nextStop : routes[bus]) {
                            q.push(nextStop);
                        }
                    }
                }
            }
            ++res;
        }
    
        return -1;
    }
};
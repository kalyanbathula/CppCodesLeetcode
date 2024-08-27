class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,vector<double>& succProb, int start_node,int end_node) {

        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> probability(n, INT_MIN);
        pq.push({1.0, start_node});
        while (!pq.empty()) {
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            for (auto neighbour : graph[node]) {
                if (prob * neighbour.second > probability[neighbour.first]) {
                    pq.push({prob * neighbour.second, neighbour.first});
                    probability[neighbour.first] = prob * neighbour.second;
                }
            }
        }
        return probability[end_node]==INT_MIN?0:probability[end_node];
    }
};

int main(){
    
}
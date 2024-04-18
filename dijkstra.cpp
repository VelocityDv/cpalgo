/*

optimal pathing from 1 place to another

from start node to finish node. 

uses idea of greedy algorithm and relaxation .

*/


vector<vector<pair<int, int>>> adj(n);
vector<bool> visited(n, false);
vector<int> dist(n, INF);
vector<int> parents(n, -1);


// dijstras algoirhtm 
// starting vertex
int start = 0;
dist[start] = 0;

for(int i = 0; i < n; i++){
	// keeping track of the smallest vertex distance 
    //Find the unvisited vertex with the smallest distance
    // sometimes people use heap to optimize this time to o(log n)
	int v = -1;
	for (int j = 0; j < n; j++) {
        if (!visited[j] && (v == -1 || dist[j] < dist[v])){
            v = j;

            // cout << i << ": " << v << endl;
        }
    }

    if (dist[v] == INF){
        break;
    }

    visited[v] = true;
    for (auto edge : adj[v]) {
        int to = edge.first;
        int cost = edge.second;

        if (dist[v] + cost < dist[to]) {
            dist[to] = dist[v] + cost;
            parents[to] = v;
        }
    }
}

// use back tracking to get our path
// int end = 1;
// vector<int> path;

// for (int v = end; v != start; v = p[v]){
//     path.push_back(v);
// }
// path.push_back(start);

// reverse(path.begin(), path.end());

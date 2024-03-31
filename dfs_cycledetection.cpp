// based on true and false
bool dfs(const vector<vector<int>>& adj, vector<bool>& visited, int node) {
	if (visited[node])
	    return false;

	visited[node] = true;

	for (auto neighbor : adj[node]) {
	    if (!dfs(adj, visited, neighbor))
		return false;
	}

	visited[node] = false; 
	return true;
}


// optimised using color read cp algorithms website
// https://cp-algorithms.com/graph/depth-first-search.html
bool dfs(const vector<vector<int>>& adj, vector<int>& color, int node) {
	if (color[node] == 1) // Cycle detected
	    return false;
	if (color[node] == 2) // Node already visited
	    return true;

	color[node] = 1; // Mark node as visiting

	for (int neighbor : adj[node]) {
	    if (!dfs(adj, color, neighbor))
		return false;
	}

	color[node] = 2; // Mark node as visited
	return true;
}


// in main

for(int i = 0; i < adj.size(); i++){
if(color[i] == 0){
bool t = dfs(adj, color, i);
if(!t)
    return false;
}
}

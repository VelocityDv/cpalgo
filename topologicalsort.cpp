
// use cases:
/*
	e.g. we have some sort of order we want
	like course scheduleing.

	if we have to do one course first befoer doing another course. 

	need to ensure that if we can find schedule for uni students to study courses

 
*/



// algorithm visit our start node. and then once we reach the end add it to reverse in 
// ans vector
void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> ans, int node){
	visited[node] = true;
	for (int neighbours : adj[node]) {
	    if (!visited[neighbours]){
			dfs(neighbours);
	    }
	}
	ans.push_back(node);
}

void toposort(vector<vector<int>> &adj, vector<bool> &visited, vector<int> ans){
	ans.clear();
	int n = adj.size();
	for (int i = 0; i < n; ++i) {
	    if (!visited[i]) {
			dfs(i);
	    }
	}
	reverse(ans.begin(), ans.end());
}	

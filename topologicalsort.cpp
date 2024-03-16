void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> ans, int node){
	visited[node] = true;
		for (int neighbours : adj[node]) {
		    if (!visited[neighbours])
			dfs(neighbours);
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

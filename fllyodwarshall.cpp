
/*
	uses dp and can detect negative cycle basically infinity minimimum distances

	also can have negative edge basically kinda of like djistra but finds mimum from all edges
	uses dp
*/

// first have to set dp to all the cost of edges.



for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][k] < INF && dp[k][j] < INF)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
        }
    }
}
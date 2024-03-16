class Solution {
public:
    bool dfs(const vector<vector<int>>& adj, vector<int>& color, int node) {
        if (color[node] == 1)
            return false;
        if (color[node] == 2)
            return true;

        color[node] = 1; 

        for (int neighbor : adj[node]) {
            if (!dfs(adj, color, neighbor))
                return false;
        }

        color[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(prerequisites.size() == 0)
            return true;
        
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses, 0);

        vector<int> incomingEdges(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);        
        }

        
        for(int i = 0; i < numCourses; i++){

            if(color[i] == 0){
                bool t = dfs(adj, color, i);
                if(!t)
                    return false;
            }
        }

        return true;

    }
};

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

struct ProcessSchedule {
    int startTime;
    int endTime;
};

struct Dependency {
    int pid1;
    int pid2;
};

class Scheduler {
private:
int main() {
    std::vector<ProcessSchedule> processes = {
        {1, 5},
        {2, 6}
    };

    std::vector<Dependency> dependencies = {
        {1, 2}
    };

    Scheduler scheduler(processes, dependencies);
    scheduler.PrintSchedule();

    return 0;
}
    vector<ProcessSchedule> processes;
    vector<Dependency> dependencies;

public:
    Scheduler(std::vector<ProcessSchedule> processes, std::vector<Dependency> dependencies)
        : processes(processes), dependencies(dependencies) {}

    void PrintSchedule() {
        int n = processes.size();
        vector<vector<int>> adj(n);
        vector<ProcessSchedule> ans(n);
        vector<int> incomingEdges(n);

        for (auto pid : dependencies) {
            adj[pid.pid1 - 1].push_back(pid.pid2 - 1);
            incomingEdges[pid.pid2-1]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(incomingEdges[i] == 0){
                q.push(i);
                ans[i].startTime = processes[i].startTime;
                ans[i].endTime = processes[i].endTime;
            }
            else{
                ans[i].startTime = 0;
                ans[i].endTime = INF;
            }
            i++;
        }



        while(!q.empty()){  
            int top = q.front();
            q.pop();

            visited[top] = true;
            for(int u : adj[top]){
                ans[u].startTime = max(ans[u].startTime, processes[top].startTime+1);
                ans[u].endTime = min(ans[u].endTime, processes[top].endTime-1);
                incomingEdges[u]--;
                if (incomingEdges[u] == 0) {
                    q.push(u);
                }

            }
        } 

        bool impossible = false;
        for (int i = 0; i < processes.size(); ++i) {
            if (incomingEdges[i] > 0) {
                impossible = true;
                break;
            }
        }

        if (impossible) {
            std::cout << "IMPOSSIBLE\n";
        } else {
            for (const auto& process : ans) {
                std::cout << process.startTime << " " << process.endTime << std::endl;
            }
        }

    }
};

int main() {
    // Example usage
    std::vector<ProcessSchedule> processes = {
        {100, 2100},
        {110, 2200}, // Fill in the correct end time for process 1
        {200, 2330}  // Fill in the correct end time for process 2
        // Add more processes
    };

    std::vector<Dependency> dependencies = {
        {1, 2},
        {3, 2}
        // Add more dependencies
    };

    Scheduler scheduler(processes, dependencies);
    scheduler.PrintSchedule();

    return 0;
}

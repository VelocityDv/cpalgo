#include <bits/stdc++.h>
using namespace std;

struct Lion {
    string name;
    int height;

    Lion(string lionName, int lionHeight) {
        name = lionName;
        height = lionHeight;
    }
};

struct LionSchedule {
    string name;
    int enterTime;
    int exitTime;

    LionSchedule(string lionName, int enter, int exit) {
        name = lionName;
        enterTime = enter;
        exitTime = exit;
    }
};

class LionCompetition {
private:
    vector<Lion> lions;
    vector<LionSchedule> schedules;
    priority_queue<int> pq; // Only need to store heights for comparison

public:
    LionCompetition(vector<Lion> lionList, vector<LionSchedule> lionSchedules) { // Corrected variable name
        lions = lionList;
        schedules = lionSchedules; // Corrected variable name
    }

    void lionEntered(int currentTime, int height) {
        pq.push(height);
    }

    void lionLeft(int currentTime, int height) {
        priority_queue<int> tmp;
        while (!pq.empty()) {
            int topElement = pq.top();
            pq.pop();
            if (topElement != height) {
                tmp.push(topElement);
            }
        }
        pq = tmp;
    }

    int searchLionSize(string lionName) {
        for (auto lion : lions) {
            if (lion.name == lionName) {
                return lion.height;
            }
        }
        return -1; // Return a default value if lionName is not found
    }

    vector<string> getBiggestLions(int currentTime) {
        priority_queue<pair<int, string>> lionsCurrent;
        vector<string> ans;

        // Iterate through schedules to find lions in the room at the current time
        for (auto schedule : schedules) {
            if (schedule.enterTime <= currentTime && schedule.exitTime >= currentTime) {
                lionsCurrent.push(make_pair(searchLionSize(schedule.name), schedule.name));
            }
        }

        priority_queue<int> tmp = pq;
        while (!tmp.empty() && !lionsCurrent.empty()) { // Changed condition to check both queues
            int top = tmp.top();
            pair<int, string> topLion = lionsCurrent.top();
            if (top == topLion.first) { // Changed = to ==
                ans.push_back(topLion.second);
                tmp.pop(); // Changed top to tmp
                lionsCurrent.pop();
            } else {
                break;
            }
        }

        return ans; // Return the vector of biggest lions in the room
    }
};

int main() {
    vector<Lion> lionList = {Lion("marry", 300), Lion("rob", 250)};
    vector<LionSchedule> lionSchedule = {LionSchedule("marry", 10, 15), LionSchedule("rob", 13, 20)};

    LionCompetition competition(lionList, lionSchedule);

    // Sample Input Simulation
    competition.lionEntered(8, 200);
    competition.lionEntered(10, 310);
    competition.lionEntered(10, 300);
    vector<string> biggestLions = competition.getBiggestLions(11); // Call getBiggestLions with currentTime 11
    cout << biggestLions.size() << " "; // Output the size of biggestLions
    for (auto x : biggestLions) {
        cout << x << " "; // Output each lion's name
    }
    cout << endl;

    competition.lionEntered(13, 250);
    competition.lionLeft(13, 310);
    biggestLions = competition.getBiggestLions(13); // Call getBiggestLions with currentTime 13
    cout << biggestLions.size() << " "; // Output the size of biggestLions
    for (auto x : biggestLions) {
        cout << x << " "; // Output each lion's name
    }
    cout << endl;

    competition.lionLeft(15, 300);
    biggestLions = competition.getBiggestLions(16); // Call getBiggestLions with currentTime 16
    cout << biggestLions.size() << " "; // Output the size of biggestLions
    for (auto x : biggestLions) {
        cout << x << " "; // Output each lion's name
    }
    cout << endl;

    competition.lionLeft(16, 200);
    competition.lionLeft(20, 250);
    biggestLions = competition.getBiggestLions(21); // Call getBiggestLions with currentTime 21
    cout << biggestLions.size() << " "; // Output the size of biggestLions
    for (auto x : biggestLions) {
        cout << x << " "; // Output each lion's name
    }
    cout << endl;

    return 0;
}


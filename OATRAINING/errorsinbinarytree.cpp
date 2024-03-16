#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

string detectErrors(vector<string>& inputPairs) {
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> incomingEdges;
    unordered_set<char> nodes;

    // Parse input and build the graph
    for (const string& pair : inputPairs) {
        char parent = pair[1];
        char child = pair[3];
        graph[parent].push_back(child);
        incomingEdges[child]++;
        nodes.insert(parent);
        nodes.insert(child);
    }

    // Check for multiple roots
    vector<char> roots;
    for (const char& node : nodes) {
        if (incomingEdges.find(node) == incomingEdges.end()) {
            roots.push_back(node);
        }
    }
    if (roots.size() > 1) {
        return "E1";  // Multiple roots error
    }

    // Check for cycles using DFS
    unordered_set<char> visited;
    stack<char> dfsStack;
    for (char root : roots) {
        dfsStack.push(root);
        while (!dfsStack.empty()) {
            char node = dfsStack.top();
            dfsStack.pop();
            if (visited.find(node) != visited.end()) {
                return "E2";  // Cycle error
            }
            visited.insert(node);
            for (char child : graph[node]) {
                dfsStack.push(child);
            }
        }
    }

    // Check for duplicate edges
    for (const auto& pair : graph) {
        const vector<char>& children = pair.second;
        unordered_set<char> childSet(children.begin(), children.end());
        if (children.size() != childSet.size()) {
            return "E3";  // Duplicate edge error
        }
    }

    return "";
}

int main() {
    string input;
    getline(cin, input);
    vector<string> inputPairs;
    string pair;
    for (char c : input) {
        if (c == '(' || c == ')' || c == ',') {
            continue;
        }
        if (c == ' ') {
            inputPairs.push_back(pair);
            pair = "";
        } else {
            pair += c;
        }
    }
    if (!pair.empty()) {
        inputPairs.push_back(pair);
    }

    string error = detectErrors(inputPairs);
    cout << error << endl;

    return 0;
}


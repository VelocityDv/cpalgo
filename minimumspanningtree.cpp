#include <bits/stdc++.h>

using namespace std;

/*

for everything to have a subset of mimuum distances from each and every node

for N nodes, there must be n-1 paths for all connections 

idea is we find connections from sorted by weights, and if there is cycle we dont add it



*/

struct Edge{
	int src;
	int destination;
	int weight;
	bool operator < (Edge const& other){
		return weight < other.weight;
	}
}


vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main(){
	int n;
	vector<Edge> edges;

	int cost = 0;
	vector<Edge> result;
	parent.resize(n);
	rank.resize(n);
	for (int i = 0; i < n; i++)
	    make_set(i);

	sort(edges.begin(), edges.end());

	for (Edge e : edges) {
	    if (find_set(e.u) != find_set(e.v)) {
	        cost += e.weight;
	        result.push_back(e);
	        union_sets(e.u, e.v);
	    }
	}

}

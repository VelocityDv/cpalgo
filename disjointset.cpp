//dju has 3 main operations around o(1) time

// make_set(v) -> new set of elements consisting of v
//union_sets(a, b) - merges the two specified sets 

//(the set in which the element a is located, and the set in
// which the element b is located)

//find_set(v) - returns the representative 
//(also called leader) of the set that contains the element v. 




// how to detect cycle. check if 2 edge in set. if in same set is cycle
// go through all the edges in our sample sapce. form sets with each edge.
// 5.40 - 11.00
//https://www.youtube.com/watch?v=wU6udHRIkcc&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=17


// dummy implimentation
// void make_set(int v){
// 	parent[v] = v;
// } 

// int find_set(int v){
// 	if(v == parent[v])
// 		return v;
// 	return find_set(parent[v]);
// }

// void union_sets(int a, int b){
// 	a = find_set(a);
// 	b = find_set(b);

// 	if (a != b){
// 		parent[b] = a;
// 	}
// }


//optimised union by rank based on depthh

#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> ranks;

void make_set(int v){
	parent[v] = v;
	ranks[v] = 0;
} 


int find_set(int v){
	if(v == parent[v])
		return v;
	//travel upwards of parent by calling recursively the parent of x
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){

	a = find_set(a);
	b = find_set(b);

	if (a != b){
		if (ranks[a] < ranks[b]){
            swap(a, b);
		}
        parent[b] = a;
        if (ranks[a] == ranks[b]){
            ranks[a]++;
        }
	}
}

int main(){
	//lets say we just get edges

#ifndef LOCAL
    freopen("input.txt", "r", stdin);     
    freopen("output.txt", "w", stdout);     
#endif

	int n, m;
	cin >> n >> m;


	vector<vector<int>> edge(m + 1, vector<int>(2, 0));

	for(int i = 0; i < m; i++){
		cin >> edge[i][0] >> edge[i][1];
	}

	// get edges
	parent.resize(n);
	ranks.resize(n);


	for(int i = 0; i < n; i++){
		make_set(i);
	}



	for(int i = 0; i < edge.size(); i++){
		int a = edge[i][0];
		int b = edge[i][1];

		// cycle detected
		if(find_set(a) == find_set(b)){
			// cout << 
			return 0 ;
		}

		else{
			union_sets(a, b);
		}

		for(int i = 0; i < n; i++){
			cout << ranks[i] << " ";
		}
		cout << endl;
	}

	
}
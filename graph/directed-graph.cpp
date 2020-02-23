#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int n = 7;
vector<vector<int>> graph(n,vector<int>());

void addEdge(int u,int v){
	graph[u].push_back(v);
}

void createGraph(){
	addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 6);
}

void display(){
	for(int i = 0; i < graph.size(); i++){
		cout << i << "->";
		for(int e: graph[i]){
			cout << e << " ";
 		}
 		cout << endl;
	}
}

void topodfs(int src, vector<bool> &vis, vector<int> &st){
	vis[src] = true;
	for(int e : graph[src]){
		if(!vis[e])
			topodfs(e,vis,st);
	}
	st.push_back(src);
}

void topologicalSort(){
	vector<bool> vis(n,false);
	vector<int> st;
	for(int i = 0; i < n; i++){
		if(!vis[i])
			topodfs(i,vis,st);
	}

	while(st.size() > 0){
		cout << st.back();
		st.pop_back();
	}
}

void kahnsAlgo(){
	vector<int> incidentEdges(n,0);
	for(int i = 0; i < n; i++){
		for(int ele: graph[i]){
			incidentEdges[ele]++;
		}
	}

	queue<int> q,ans;
	for(int i = 0; i < incidentEdges.size(); i++){
		if(incidentEdges[i] == 0){
			q.push(i);
		}
	}

	while(q.size() > 0){
		int vtx = q.front();
		q.pop();
		ans.push(vtx);
		for(int nbr : graph[vtx]){
			if(--incidentEdges[nbr] == 0)
				q.push(nbr);
		}
	}

	if(ans.size() != graph.size()){
		cout << "cycle detected, topological sort not possible\n";
	}
	else{
		while(ans.size() != 0){
			cout << ans.front();
			ans.pop();
		}
	}
}

// with cycle detection
bool topologicalDFS(int src, vector<bool> &vis, vector<bool> &cycle, vector<int> &st){
	vis[src] = cycle[src] = true;
	bool res = false;
	for(int e : graph[src]){
		if(!vis[e]){
			res = res || topologicalDFS(e,vis,cycle,st);
		}else if(cycle[e]){
			cout << "cycle\n";
			return true;
		}
	}
	st.push_back(src);
	cycle[src] = false;
	return res;
}

void topologicalDFSMain(){
	vector<bool> vis(n,false);
	vector<bool> cycle(n,false);
	vector<int> st;
	bool res = false;
	for(int i = 0; i < n && !res; i++){
		if(!vis[i]){
			res = res || topologicalDFS(i,vis,cycle,st);
		}
	}
	while(st.size() > 0){
		cout << st.back();
		st.pop_back();
	}
}



void bipartite(){

}

void solve(){
	createGraph();
	display();
	cout << endl;
	topologicalSort();
	cout << endl;
	kahnsAlgo();
	cout << endl;
	topologicalDFSMain();
}

int main(){
	solve();
	return 0;
}
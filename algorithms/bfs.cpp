#include <queue>
#include <iostream>

using namespace std;


// bfs for a graph (impl. adj. list)
void bfs(vector< vector<int> > g, int start){
	queue<int> q; 
	vector<bool> visited(g.size(), false);
	
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()){
		int cur = q.front();
		// do sth with current
		cout << cur << endl;
		q.pop();
		vector<int> adj = g[cur];
		for(int i : adj){
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
			}
		}	
	}
}


int main(){
	vector<int> zero = {3};
	vector<int> one = {2};
	vector<int> two = {0, 1, 2, 3};
	vector<int> three = {1, 2};
	
	vector<vector<int>> g;
	g.push_back(zero);
	g.push_back(one);
	g.push_back(two);
	g.push_back(three);
	
	bfs(g, 0);
	
	return 0;
}
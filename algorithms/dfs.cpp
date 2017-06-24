#include <stack>
#include <iostream>
#include <vector>

using namespace std;

// bfs for a graph (impl. adj. list)
void bfs(vector< vector<int> > g, int start){
	stack<int> s; 
	vector<bool> visited(g.size(), false);
	
	visited[start] = true;
	s.push(start);
	
	while(!s.empty()){
		int cur = s.top();
		// do sth with current
		cout << cur << endl;
		s.pop();
		vector<int> adj = g[cur];
		for(int i : adj){
			if(!visited[i]){
				visited[i] = true;
				s.push(i);
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
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<int> counting_sort(const vector<int> & v){
	int k = *max_element(begin(v), end(v));
	vector<int> c(k+1, 0);
	vector<int> b(v.size(), -1);

	for(int e : v)
		++c[e];

	for(int i = 1; i < c.size(); ++i)
		c[i] += c[i-1];
	
	for(int i = v.size() - 1; i >= 0; --i) {
		b[c[v[i]]-1] = v[i];
		--c[v[i]];
	}
	return b;
}

int main(){
	cout << "Counting sort" << endl;
	vector<int> v = {4, 3, 5, 6, 0, 4, 9};
	auto res = counting_sort(v);
	for(auto e : res){
		cout << e << " ";
	}
	
	return 0;
}
#include <vector>
#include <iostream>

using namespace std;


void counting_sort(vector<int> &v, int max_value){
	vector<int> counts(max_value, 0);
	for(int i : v){
		counts[i-1]++;
	}
	int k = 0;
	for(int i = 0; i < counts.size(); i++){
		int count = counts[i];
		cout << count << endl;
		for(int j = 0; j < count; j++){
			v[k] = i+1;
			k++;
		}
	}
	cout << "asda"<< endl;
}

int main(){
	cout << "Counting sort" << endl;
	vector<int> v = {4, 3, 5, 6, 0, 4, 9};
	cout << v.size() << endl;
	counting_sort(v, 10);
	cout << "a" << endl;
	cout << v.size() << endl;
	cout << "wtf" << endl;
	for(auto a : v){
		cout << a << " ";
	}
	
	return 0;
}
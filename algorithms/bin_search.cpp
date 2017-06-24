#include <vector>
#include <iostream>

using namespace std;

int binSearch(vector<int> v, int i){
	int f = 0, t = v.size()-1, m;
	while(f<=t){
		m = (f+t)/2;
		if(v[m]==i)
			return m;
		else if(v[m]>i)
			f = m + 1;
		else
			t = m - 1;
	}
	return -1;
}


int main(){
	vector<int> v = {1, 3, 4, 6, 8, 9};
	cout << binSearch(v, 4) << endl;
	cout << binSearch(v, 2) << endl;
	
	return 0;
}
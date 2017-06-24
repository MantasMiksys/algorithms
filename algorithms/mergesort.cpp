#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &v, int low, int high, int mid){
	vector<int> merged(v.size());
	int i = low, j = mid + 1, k = low;
	while(i <= mid && j<=high){
		if(v[i] < v[j]){
			merged[k] = v[i];
			i++;
		}else{
			merged[k] = v[j];
			j++;
		}
		k++;
	}
	
	while(i<=mid){
		merged[k] = v[i];
		i++;
		k++;
	}
	
	while(j<=high){
		merged[k] = v[j];
		j++;
		k++;
	}
	
	for(int i=low; i <= high; i++){
		v[i] = merged[i];
	}
}


void mergeSort(vector<int> &v, int low, int high){
	if(low < high){
		int mid = (low+high)/2;
		mergeSort(v, low, mid);
		mergeSort(v, mid+1, high);
		merge(v, low, high, mid);
	}
}

int main(){
	vector<int> v = {4, 3, 5, -1, 0, 4, -10};
	mergeSort(v, 0, v.size()-1);
	for(auto a : v){
		cout << a << " ";
	}
	
	return 0;
}
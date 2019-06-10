#include <iostream>
#include <vector>

using namespace std;

/*
!!! Worst case running time is O(n^2) !!!
Average case O(n log(n))

Why is Quick Sort preferred over MergeSort?
1) It's an in-place sort (no extra storage).
Allocating and de-allocating extra space would increase the running time
2) It's also a cache friendly algorith as it has good locality of reference
when used for arrays.
3) QuickSort is also tail recursive, therefore tail call optimization is done
- Quick Sort (same as Heap Sort) is not stable, while Merge Sort, Bubble Sort,
and Insertion Sort are stable.


What about for lists?
- For lists merge operation of Merge Sort can be implemented without extra space
for linked lists.
- Unlike arrays, we cannot do random access in linked lists. Quick Sort requires
a lot of this kind of access. Therefore, the overhead increases for Quick Sort.
Merge Sort accesses data sequentially and the need for random access is low.

*/


// high is the last element
// and it is used for partition
int partition(vector<int> &v, int low, int high){
	int pivot = v[high];
	int i = low-1;
	for(int j = low; j < high; j++){
		if(v[j] <= pivot){
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[high]);
	return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
	if(low < high){
		int p = partition(v, low, high);
		
		// separately sort elements before partition 
		// and after partition (p element is not included)
		quickSort(v, low, p - 1);
		quickSort(v, p + 1, high);
	}
}

int main(){
	vector<int> v = {4, 0, -3, 5, 7, 0, -6};
	quickSort(v, 0, v.size()-1);
	for(auto i : v){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

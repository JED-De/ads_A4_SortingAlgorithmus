#include "sorting.h"


namespace sorting {


	//************
	// QuickSort *
	//************      
	void QuickSort(vector<int> &arr, int left, int right) {

		//***************************
		// implement quicksort here *
		//************ **************
		if (left < right)
		{
			int q = partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}

	int partition(vector<int> &a, int left, int right) {

		int center = (left + right) / 2;
		if (a[center] < a[left]) {
			swap(a[center], a[left]);
		}
		if (a[right] < a[left]) {
			swap(a[right], a[left]);
		}
		if (a[right] < a[center]) {
			swap(a[right], a[center]);
		}
		swap(a[right], a[center]);

		int x = a[right];
		int i = left - 1;
		for (int j = left; j < right; j++) {
			if (a[j] <= x) {
				i++;
				swap(a[i], a[j]);
			}
		}
		swap(a[i + 1], a[right]);
		return i + 1;
	}

	//************
	// MergeSort *
	//************

	//***************************
	// implement mergesort here *
	//***************************


	void Merge(vector<int> &a, vector<int> &b, int low, int pivot, int high) {
		for (int k = low; k <= high; k++) {
			b[k] = a[k];
		}
		int i = low , j = pivot + 1;
		for (int k = low; k <= high; k++) {
			if (j > high || b[i] <= b[j]){
				a[k] = b[i];
				i++;
			}
			else {
				a[k] = b[j];
				j++;
			}
		}
	}

	void MergeSort(vector<int> &a, vector<int> &b, int low, int high) {

		if (low < high){
			int q = 0;
			q = (low + high) / 2;
			MergeSort(a, b, low, q);
			MergeSort(a, b, q + 1, high);
			Merge(a, b, low, q, high);
		}
	}



	//************
	// Heapsort  *
	//************

	void HeapSort(vector<int> &a, int n) {


		//***************************
		// implement heapsort here *
		//***************************
		int i = n / 2;
		while (i >= 0){
			percDown(a, i, n);
			i--;
		}
		int j = n - 1;
		while (j > 0){
			swap(a[0], a[j]);
			percDown(a, 0, j);
			j--;
		}
	}

	void percDown(vector<int> &a, int p, int n) {
		int child = p;
		int tmp = a[p];
		int j = p;
		while (leftChild(j) < n){
			child = leftChild(j);
			if (child != (n - 1) && a[child] < a[child + 1]) {
				child++;
			}
			if (tmp < a[child]) {
				swap(a[j], a[child]);
				j = child;
			}
			else{
				break;
			}
		}

	}

	int leftChild(int i) {
		return 2 * i + 1;
	}



	//************
	// Shellsort *
	//************
	void ShellSort(vector<int> &a, int n)
	{

		//***************************
		// implement shellsort here *
		//***************************
		int h = 1;
		while (2 * h < n - 1) {
			h *= 2;
		}
		h--;
		for (int gap = h; gap > 0 ; gap /= 2) {
			for (int i = gap; i < n; i++) {
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap) {
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
			
		}
	}


	void randomizeVector(vector<int> &array, int n) {
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}


}
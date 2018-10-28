//Fatemeh Mohammadkhani 9513029
//Algorithms first homework

#include <iostream>
using namespace std;

long int merge(long int* arr, long int middle, long int length) {

	long int i = 0, j = middle, k = 0, cost = 0;
	long int* sorted = new long int[length];

	while (i < middle && j < length) {
		if (arr[i] <=  arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
			cost = (cost % 1000000007 + middle % 1000000007) % 1000000007 - i % 1000000007;
		}
		k++;
	}


	while (i < middle) {
		sorted[k] = arr[i];
		k++;
		i++;
	}
	while (j < length) {
		sorted[k] = arr[j];
		k++;
		j++;
	}


	for (long int c = 0; c < length; c++)
		arr[c] = sorted[c];

	return cost % 1000000007;
}

long int mergeSort(long int* arr, long int length) {

	if (length == 1) return 0;

	long int middle = int (length / 2);
	long int leftCost = mergeSort(arr, middle);
	long int rightCost = mergeSort(arr + middle, length - middle);

	long int mergeCost = merge(arr, middle, length);

	long int finalCost = leftCost % 1000000007 + (rightCost % 1000000007 + mergeCost % 1000000007) % 1000000007;

	return finalCost % 1000000007;
}

int main() {
	long int n;
	cin >> n;
	long int* inArr = new long int[n];
	for (int i = 0; i < n; i++)
		cin >> inArr[i];

	cout << mergeSort(inArr, n) % 1000000007 << endl;

	/*for (int i = 0; i < n; i++)
		cout << inArr[i] << " ";
	*/
	//cin >> n;
	
	return 0;
}

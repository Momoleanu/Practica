#include<iostream>

//Given an array of integers, return a new array such that each element at index i of the new array 
//is the product of all the numbers in the original array except the ones at i
//Ex: [1,2,3,4,5] -> Output: [120, 60,40,30,24]
//Complexitate O(n)

int product(int* arr, int n) {

	int p = 1;

	for (int i = 0; i < n; i++) {
		p *= arr[i];
	}
	return p;
}


int main(void) {

	int n;
	std::cout << "No of elem: ";
	std::cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int p = product(arr, n);

	int* temp = new int[n+1];
	for (int i = 1; i <= n; i++) {
		temp[i] = p / i;
		std::cout << temp[i] << " ";
	}

	delete[] temp;
	delete[] arr;
	
	return 0;
}

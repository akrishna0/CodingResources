#include<iostream>
using namespace std;

int BinarySearch(int arr, int n, int val){
	int start = 0;
	int end = n-1;
	int mid = (start + end)/2;
	while(start < end){

	}
}

int main(){
	int size, value;
	cin>>size>>value;

	int arr[1000];

	for(int i = 0 ; i < size ; i++){
		cin>> arr[i];
	}

	cout<<BinarySearch(arr, size, value);
}

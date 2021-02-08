#include <bits/stdc++.h>
using namespace std;

//Recursive solution
void reverseRecursively(int *arr, int start, int end){
	while(start >= end)
		return;

	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	reverseRecursively(arr, start+1, end-1);
}


//Normal O(n) solution
void revereseArray(int arr[], int start, int end)
{
	while(start<end){
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
    }
}	 

void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
} 

int main() 
{
  int n;
  cin>>n;
	int *arr = new int [n];

	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
//	revereseArray(arr,0,n-1);	
        reverseRecursively(arr, 0, n-1);

	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, n);
	
	return 0;
}


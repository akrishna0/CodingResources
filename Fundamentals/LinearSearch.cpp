#include<iostream>
using namespace std;

int LinearSearch(int array[], int size, int value){
	int index = -1;
	for(int i = 0 ; i < size ; i++){
		if(array[i] == value){
			index = i;
		}
	}
	return index;
}

int main(){
	int size, value;
	cout<<"Enter Size of Array and the value to find"<<endl;
	cin>>size>>value;
	int array[100];
	for(int i = 0 ; i < size ; i++){
		cin>>array[i];
	}

	cout<<LinearSearch(array, size, value);
	cout<<endl;
}

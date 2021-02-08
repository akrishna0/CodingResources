#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
pair<int, int> getMinMax(int *arr, int n){
	pair<int, int> minmax;
	if(n == 1){
		minmax.first = arr[0];
		minmax.second = arr[0];
		return minmax;
	}
	sort(arr, arr+n);
	
	minmax.first = arr[0];
	minmax.second = arr[n-1];
	return minmax;
}
pair<int, int> getMinMaxinOrderN(int * arr, int low, int high){
	pair<int, int> minmax, minmaxLeft, minmaxRight;
	if(low == high){
		minmax.first = arr[low];
		minmax.second = arr[high];
		return minmax;
	}
	if(high == low + 1){
		if(arr[low] > arr[high]){
			minmax.first = arr[ high];
			minmax.second = arr[low];
			return minmax;
		}else{
			minmax.first = arr[low];
			minmax.second = arr[high];
			return minmax;
		}
	}

	int mid = (low + high)/2;
	minmaxLeft = getMinMaxinOrderN(arr, low, mid);
	minmaxRight = getMinMaxinOrderN(arr, mid+1, high);
	
	if(minmaxLeft.first < minmaxRight.first){
		minmax.first = minmaxLeft.first;
	}else{
		minmax.first = minmaxRight.first;
	}

	if(minmaxLeft.second > minmaxRight.second){
		minmax.second = minmaxLeft.second;
	}else{
		minmax.second = minmaxRight.second;
	} 
return minmax;	

}
int main(){
	int n;
	cin>> n ; 
        int *arr = new int[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	pair<int, int> output = getMinMaxinOrderN(arr, 0, n-1);
	cout<<output.first<<endl;
	cout<<output.second<<endl;

	delete []arr;
	return 0;
}


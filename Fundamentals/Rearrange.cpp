#include<iostream>
#include<vector>
using namespace std;
vector<int> Arranged(vector<int> input, int n){
	int i = 0, j = n-1;

	while(i<j){

		//if(i>=j)break;
		if(input[i]>0 && input[j]<0){
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
		if(input[i]<0){
			i++;
		}
		if(input[j]>0){
			j--;
		}
	}
	return input;
}
int main(){
	int n ;
	cin>>n;

	vector<int> input;
	for(int i = 0 ; i < n ; i++){
		int item= 0;
		cin>>item;
		input.push_back(item);
	}
	vector<int> output = Arranged(input, n);
	for(int i = 0 ; i < output.size() ; i++){
		cout<<output.at(i)<<" ";
	}
	cout<<endl;
	return 0;
}

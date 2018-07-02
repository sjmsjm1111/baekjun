#include <iostream>

using namespace std;
void qsel(int a[],int left, int right,int find){
	while(left<right){

		int i=left;
		int j=right;
		int mid=a[(left+right)/2];
		int temp;
		while(i<j){
			if(a[i]>=mid){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				j--;
			}
			else i++;
		}
		if(a[i]>mid) i--;
		if(i>=find) right=i;
		else left=i+1;
	}
}
int arr[5000000];
int main(int argc, char** argv) {
	int t,nth;
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>t>>nth;
	
	for(int i=0;i<t;i++){
		cin>>arr[i];
	}
	qsel(arr,0,t-1,nth-1);
	cout<<arr[nth-1]<<endl;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int topdown_fibonacci(int n){
	if(n>2) return topdown_fibonacci(n-1)+topdown_fibonacci(n-2);
	return 1;
}
int bottomup_fibonacci(int n){
	int arr[45];
	int i;
	arr[0]=1;
	arr[1]=1;
	for(i=2;i<n;i++){
		arr[i]=arr[i-1]+arr[i-2];
	}
	return arr[n-1];
}

int main(int argc, char *argv[]) {
	int a;
	scanf("%d",&a);
	printf("%d\n",bottomup_fibonacci(a));
	return 0;
}

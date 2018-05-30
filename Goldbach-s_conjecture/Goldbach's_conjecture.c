#include <stdio.h>
#include <stdlib.h>

int* mkr_checker(int len);
void free_checker(int* arr);
void seiving(int* arr,int len);
int GB(int* arr, int len);
void printing(int res, int len);


int main(int argc, char *argv[]) {
	int testcase;
	int leng,*temp;
	int result;
	scanf("%d",&testcase);
	while(testcase>0){
		scanf("%d", &leng);
		temp=mkr_checker(leng);
		seiving(temp,leng);
		result=GB(temp,leng);
		printing(result,leng);
		free_checker(temp);
		testcase--;
	}
	return 0;
}

int* mkr_checker(int len){
	int *temp;
	temp=(int*)calloc(len+1,sizeof(int));
	return temp;
}
void free_checker(int* arr){
	free(arr);
}
void seiving(int* arr,int len){
	int p=1;
	int i,j;
	while(p*p<len){
		p++;
	}
	for(i=2 ; i<p ; i++){
		for(j = i*i ; j < len ; j = j+i){
			arr[j]=1;
		}
	}
}
int GB(int* arr, int len){
	int half=len/2;
	int another;
	while(half>1){
		if(arr[half]==0){
			another=len-half;
			if(arr[another]==0){
				return half;
			}
		}
		half--;
	}
}
void printing(int res, int len){
	printf("%d %d\n",res,len-res);
}

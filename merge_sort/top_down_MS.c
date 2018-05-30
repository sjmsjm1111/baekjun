#include <stdio.h>
#include <stdlib.h>

int dummy[1000000];
int container1[1000000];
void MS_top_down(int *arr,int start,int end);
void merge(int *arr, int start, int end);

int main(int argc, char *argv[]) {
	int len,i;

	scanf("%d",&len);
	
	for(i=0;i<len;i++){
		scanf("%d",&(container1[i]));
	}
	MS_top_down(container1,0,len-1);
	for(i=0;i<len;i++){
		printf("%d ",container1[i]);
	}
	printf("\n");
	return 0;
}

void MS_top_down(int *arr,int start,int end){
	if(start<end){
		int half=(start+end)/2 + 1;
		MS_top_down(arr,start,half-1);
		MS_top_down(arr,half,end);
		merge(arr,start, end);
	}
}
void merge(int *arr, int start, int end){
	int half=(start+end)/2 + 1;//우선순위 되지?
	int i=start,j=half;
	int index=start;
	while(i<half&&j<=end){
		if(arr[i]>arr[j]){
			dummy[index]=arr[j];
			j++;
		}
		else{
			dummy[index]=arr[i];
			i++;
		}
		index++;
	} 
	while(i<half){
		dummy[index]=arr[i];
		i++;
		index++;
	}
	while(j<=end){
		dummy[index]=arr[j];
		j++;
		index++;
	}
	for(i=start;i<=end;i++){
		arr[i]=dummy[i];
	}
	return;
}

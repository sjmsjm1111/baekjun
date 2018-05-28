#include <stdio.h>
#include <stdlib.h>
int n;
int count;
int *sieve;
void mkr_arr();
void free_arr();
int do_sieve(int num);
void check(int i,int num);
int main(int argc, char *argv[]) {
	do{
		scanf("%d",&n);
		mkr_arr();
		count = do_sieve(n);
		free_arr();
		printf("%d\n",count);
		count=0;
	}while(n);
	return 0;
}

void mkr_arr(){
	int num = 2*n+1;
	sieve = (int*)calloc(num,sizeof(int));
}

void free_arr(){
	free(sieve);
}

int do_sieve(int num){
	int count=0;
	int p = 1,i;
	int end = 2*num;
	while(p*p<end){
		p++;
	}
	for(i=2;i<p;i++){
		if(sieve[i]==0) check(i,num);
	}
	i=num+1;
	while(i<=end){
		if(sieve[i]==0) count++;
		i++;
	}
	return count;
}

void check(int i,int num){
	int j;
	int start = i*i;
	int end = 2*num;
	for(j=start;j<=end;j=j+i){
		sieve[j]=1;
	}
}

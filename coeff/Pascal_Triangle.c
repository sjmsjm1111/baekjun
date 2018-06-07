#include <stdio.h>
#include <stdlib.h>

int coeff(int n, int r){
	if(n==r||r==0) return 1;
	return coeff(n-1,r)+coeff(n-1,r-1);
}
int main(int argc, char *argv[]) {
	int n,r;
	scanf("%d %d", &n,&r);
	printf("%d",coeff(n,r));
	return 0;
}

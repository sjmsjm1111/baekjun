#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const long long int maximum=1e17;

typedef struct VLLI{
	long long int high=0;
	long long int low =0;
}VLLI;
VLLI DP[101][101];
VLLI operator+(VLLI num1, VLLI num2){
	VLLI result;
	result.high=num1.high+num2.high;
	if(num1.low+num2.low>maximum){
		result.low=num1.low+num2.low-maximum;
		result.high++;
	}else{
		result.low=num1.low+num2.low;
	}
	return result;
}


VLLI comb(int n, int r){
	if(DP[n][r].low!=0||DP[n][r].high!=0) return DP[n][r];
	if(n==r||r==0) {
	DP[n][r].low=1;
	return DP[n][r];
	}
	return DP[n][r]=comb(n-1,r)+comb(n-1,r-1);
}
int main(int argc, char** argv) {
	int n,r;
	VLLI temp;
	cin>>n>>r;
	temp=comb(n,r);
	if(temp.high){
	printf("%lld%lld",temp.high,temp.low);}
	else{
		printf("%lld",temp.low);
	}
	return 0;
}

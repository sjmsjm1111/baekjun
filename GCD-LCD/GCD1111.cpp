#include <iostream>

using namespace std;

long long int GCD(long long int a,long long int b){
	if(b>a) return GCD(b,a);
	if(!b) return a;
	return GCD(b,a%b);
}

int main(int argc, char** argv) {
	long long int A,B,gcd;
	cin>>A>>B;
	gcd=GCD(A,B);
	while(gcd--) cout<<"1";
	
	return 0;
}

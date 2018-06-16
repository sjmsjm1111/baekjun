#include <iostream>
using namespace std;
long long int GCD(long long int a, long long int b){
	if(b>a) return GCD(b,a);
	if(!b) return a;
	return GCD(b,a%b);
}
long long int LCD(int a, int b){
	long long int gcd=GCD(a,b);
	return gcd*(a/gcd)*(b/gcd);
}
int main(int argc, char** argv) {
	long long int A,B;
	cin>>A>>B;
        cout<<LCD(A,B);
	
	return 0;
}

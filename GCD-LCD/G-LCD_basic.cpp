#include <iostream>

using namespace std;

int GCD(int a, int b){
	if(b>a) return GCD(b,a);
	if(!b) return a;
	return GCD(b,a%b);
}
int LCD(int a, int b){
	int gcd=GCD(a,b);
	return gcd*(a/gcd)*(b/gcd);
}

int main(int argc, char** argv) {
	int test_case;
	int A,B;
	cin>>test_case;
	while(test_case--){
		cin>>A>>B;
		cout<<LCD(A,B)<<"\n";
	}
	
	return 0;
}

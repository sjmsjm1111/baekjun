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

/*                         *****MORE FASTER VERSION*****
#include <iostream>

using namespace std;
int A[1001],B[1001];

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
    int temp;
	cin>>test_case;
	temp=test_case;
	while(test_case--){
		cin>>A[test_case]>>B[test_case];
	}
    while(temp--){
        cout<<LCD(A[temp],B[temp])<<"\n";
    }
	
	return 0;
}

1996 KB	0 MS	C++14 / 수정	493 B
because of seperate input with output(calculator). compiler can optimize the codes. 
*/

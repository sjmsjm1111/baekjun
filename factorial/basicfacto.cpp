#include <iostream>

using namespace std;

int fact(int n){
	if(!n) return 1;
	return n*fact(n-1);
}

int main(int argc, char** argv) {
	int num;
	cin>> num ;
	cout<<fact(num)<<'\n';
	return 0;
}

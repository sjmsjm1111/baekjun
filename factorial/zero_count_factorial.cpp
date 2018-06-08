#include <iostream>

using namespace std;

int five_counter(int num){
	int temp,i,result=0;
	while(num>0){
		i=0;
		temp=num;
		while(!(temp%5)){
			temp/=5;
			i++;
		}
		result+=i;
		num--;
	}
	return result;
}

int main(int argc, char** argv) {
	int bound;
	cin>>bound;
	cout<<five_counter(bound);
	return 0;
}

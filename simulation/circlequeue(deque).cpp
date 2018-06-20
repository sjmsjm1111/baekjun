#include <iostream>
#include <deque>

using namespace std;

typedef deque<int> DQ;

deque<int> dq;

void init(int n){
	while(n) dq.push_front(n--);
}
void left(int n){
	DQ temp;
	while(n--){
		temp.push_back(dq.front());
		dq.pop_front();
		dq.push_back(temp.front());
		temp.pop_front();
	}
}
void right(int n){
	DQ temp;
	while(n--){
		temp.push_back(dq.back());
		dq.push_front(temp.front());
		dq.pop_back();
		temp.pop_front();
	}
}
int test(int n){
	int size=dq.size();
	int result;
	int i;
	for(i=0;i<size;i++){
		if(dq[i]==n) break;
	}
	if(i<=size/2) {
		left(i);
		result=i;
	}
	else {
		right(size-i);
		result=size-i;
	}
	dq.pop_front();
	return result;
}
int main(int argc, char** argv) {
		int m,n,temp;
		int result=0;
		cin>>m>>n;
		init(m);
		while(n--){
			cin>>temp;
			result+=test(temp);
		}
	cout<<result;
	return 0;
}

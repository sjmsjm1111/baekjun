#include <iostream>

using namespace std;

int dstn(int m,int l){
	int init=l*(l+1)/2;
	if(init>m||l>100) return -1;
	else if( ( ( m-init ) %l ) ==0) return l;
	else return dstn(m,l+1);
}

void prnt(int rear, int l){
	for(;l>0;l--){
	cout<<rear-l+1<<" ";
	}
}
void cal(int m, int l){
	int d;
	int mv;
	int sum;
	if((l*(l-1)/2)==m){
		prnt(l-1,l);
		return;
	}
	d=dstn(m,l);
	if(d==-1){
		cout<<-1;
		return;
	}
	sum=d*(d+1)/2;
	mv=(m-sum)/d;
	mv+=d;
	prnt(mv,d);
}
int main(int argc, char** argv) {
	int M,L;
	cin>>M>>L;
	cal(M,L);
	return 0;
}

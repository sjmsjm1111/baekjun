#include <iostream>

using namespace std; 
int minus_sum=0,zero_sum=0,one_sum=0;
int paper[2188][2188];
void adding(int a){
	switch(a){
		case -1:
			minus_sum++;
			break;
		case 0:
			zero_sum++;
			break;
		case 1:
			one_sum++;
	}
	return;
}
void cutting(int x1, int y1, int x2 , int y2){
	int init=paper[x1][y1];
	int x_off=x1-1;
	int y_off=y1-1;
	int r=x2-x_off;
	if(x1>=x2||y1>=y2) {
		adding(init);
		return;
	}
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			if(paper[i][j]!=init){
				cutting(x1,y_off+1,x_off+r/3,y_off+r/3);
				cutting(x1+r/3,y_off+1,x_off+r*2/3,y_off+r/3);
				cutting(x1+r*2/3,y_off+1,x2,y_off+r/3);
	
				cutting(x1,y_off+1+r/3,x_off+r/3,y_off+r*2/3);
				cutting(x1+r/3,y_off+1+r/3,x_off+r*2/3,y_off+r*2/3);
				cutting(x1+r*2/3,y_off+1+r/3,x2,y_off+r*2/3);
				
				cutting(x1,y_off+1+r*2/3,x_off+r/3,y2);
				cutting(x1+r/3,y_off+1+r*2/3,x_off+r*2/3,y2);
				cutting(x1+r*2/3,y_off+1+r*2/3,x2,y2);
				return;
			}
		}
	}
	adding(init);
	return;
}
int main(int argc, char** argv) {
	int N;
		ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>paper[i][j];
		}
	}
	cutting(1,1,N,N);
	cout<<minus_sum<<"\n"<<zero_sum<<"\n"<<one_sum;
	return 0;
}

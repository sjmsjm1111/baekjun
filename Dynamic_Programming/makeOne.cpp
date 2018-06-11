#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int DP[1000001];
class gotoOne{
	private:
		int num;
		
		int solve(int x){
			if(DP[x]) return DP[x];
			if(x==1) DP[x]=0;
			else if(x==2||x==3) DP[x]=1;
			else{
				if(!(x%3))
					{
					DP[x]=solve(x/3)+1;
				}
				if(!(x%2))
					{
					DP[x]=!DP[x]||(DP[x]>solve(x/2)+1)?solve(x/2)+1:DP[x];
				}
				DP[x]=!DP[x]||(DP[x]>solve(x-1)+1)?solve(x-1)+1:DP[x];
			}
			return DP[x];
		}		
	public:
		void setting(){
			cin>>num;
			memset(DP,0,sizeof(int)*(num+1));
		};
		void calculate(){
			solve(num);
		}
		void print(){
			cout<<DP[num]<<"\n";
		}
		
};
int main(int argc, char** argv) {
	gotoOne dummy;
	dummy.setting();
	dummy.calculate();
	dummy.print();
	}

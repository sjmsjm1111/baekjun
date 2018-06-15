#include <iostream>
#include <cstring>
using namespace std;
const int vec_x[]={-1,0,1,0};
const int vec_y[]={0,1,0,-1};
int map[501][501];
int DP[501][501];
int xgoal,ygoal;
int result=0;
int dfs(int x, int y){
	if(DP[x][y]!=-1)return DP[x][y];
	if(x==xgoal&&y==ygoal) return 1;
	int i,dx,dy;
	if(DP[x][y]==-1) DP[x][y]=0;
	for(i=0;i<4;i++){
		dx=x+vec_x[i];
		dy=y+vec_y[i];
		if(dx<=xgoal&&dx>0&&dy<=ygoal&&dy>0){
			if(map[x][y]>map[dx][dy]){
				DP[x][y]+=dfs(dx,dy);
			}
		}
	}
	return DP[x][y];
	
}
int main(int argc, char** argv) {
	memset(DP,-1,sizeof(int)*501*501);
	
	cin>>xgoal>>ygoal;
	for(int i=1;i<=xgoal;i++){
		for(int j=1;j<=ygoal;j++){
			cin>>map[i][j];
		}
	}
	cout<<dfs(1,1);
	return 0;
}

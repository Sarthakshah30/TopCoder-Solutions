#include<iostream>
#include<cstring>

using namespace std;
int n,m;
char maze[100][100];
int calculate(int x,int y,char c1,char c2);
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};

int main(){
	int x,y;
	cin>>n>>m;
	for(int i = 0 ; i< n ; i++)
	cin>>maze[i];
	cin>>x>>y;
	cout<<calculate(x,y,'W','.')<<endl;
}

int calculate(int x,int y,char c1,char c2){
	if(x>=n || x<0 || y<0 || y>=m)
	return 0;
	if(maze[x][y]!=c1)
	return 0;
	maze[x][y]=c2;
	int ans=1;
	for(int i = 0 ;i<8 ; i++)
	ans+=calculate(x+dx[i],y+dy[i],c1,c2);
	return ans;
}



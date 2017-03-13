#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include<cstring>
using namespace std;

	int dx[]={-1,0,1,0};
	int dy[]={0,1,0,-1};
	
class StepsConstruct {
public:
	int dist[50][50];
	char parent[50][50];

	string construct(vector <string>, int);
	void dobfs(vector <string> board);
	
};

string StepsConstruct::construct(vector <string> board, int k) {
	int m = board.size(),n=board[0].size();
	memset(dist,-1,sizeof(dist));
	if(board[0][0]=='#')
	return "";
	if(board[board.size()-1][board[0].size()-1]=='#')
	return "";
	dobfs(board);
	if(dist[m-1][n-1]==-1)
	return "";
	
	if(dist[m-1][n-1]>k)
	return "";
	string str="";
	int x=m-1,y=n-1;
	while(x!=0 || y!=0){
		if(parent[x][y]=='R'){
			str=str+"R";
			y--;	
			continue;
		}
		if(parent[x][y]=='L'){
			y++;
			str=str+"L";
			continue;
		}
		if(parent[x][y]=='U'){
			x++;
			str=str+"U";
			continue;
		}
		if(parent[x][y]=='D'){
			x--;
			str=str+"D";
			continue;
		}
	}
	reverse(str.begin(),str.end());
	int length = str.size();
	if(length==k)
	return str;
	if(( k - length)%2!=0)
	return "";
	length=(k-length)/2;
	cout<<length<<endl;
	if(parent[m-1][n-1]=='D'){
	for(int i = 1 ; i<=length ; i++)
	str+="UD";
	return str;
	}
		if(parent[m-1][n-1]=='U'){
	for(int i = 1 ; i<=length ; i++)
	str+="DU";
	return str;
	}
		if(parent[m-1][n-1]=='L'){
	for(int i = 1 ; i<=length ; i++)
	str+="RL";
	return str;
	}
		if(parent[m-1][n-1]=='R'){
	for(int i = 1 ; i<=length ; i++)
	str+="LR";
	return str;
	}
}

void StepsConstruct::dobfs(vector <string> board){
	int m=board.size(),n=board[0].size();
	queue< pair<int,int> > q;
	dist[0][0]=0;
	parent[0][0]='*';
	q.push(make_pair(0,0));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==m-1 && y==n-1)
		return ;
		for(int i = 0 ; i < 4 ; i++){
			int a = x+dx[i];
			int b = y+dy[i];
			if( a <0 || a >=m || b <0 || b>=n ||board[a][b]=='#')
			continue; 
			if(dist[a][b]==-1){
				dist[a][b]=dist[x][y]+1;
				q.push(make_pair(a,b));
				if(i==0)
				parent[a][b]='U';
				else if(i==1)
				parent[a][b]='R';
				else if(i==2)
				parent[a][b]='D';
				else
				parent[a][b]='L';
			}
		}
	}
	
}


double test0() {
	string t0[] = {"...",
 ".#.",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "DDRR";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"...",
 ".#.",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "DDRRUULLDDRR";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"...#.",
 "..#..",
 ".#..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"..#",
 "#.#",
 "..#",
 ".#.",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 6;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {".#...",
 ".#.#.",
 ".#.#.",
 ".#.#.",
 "...#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 16;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "DDDDRRUUUURRDDDD";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"#.", 
 ".."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	StepsConstruct * obj = new StepsConstruct();
	clock_t start = clock();
	string my_answer = obj->construct(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include<utility>
#include<cstring>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

class TheGridDivTwo {
public:
	int find(vector <int> x, vector <int> y, int k) {
		
		vector< vector<bool> > visited(2001, vector<bool>(2001,false) );
		int max = 1000;
		for(int i = 0; i < x.size() ; i++){
			x[i]+=1000;
			y[i]+=1000;
			visited[x[i]][y[i]]=true;
			if(x[i]>max)
			max=x[i];
		}
		
		
		if(max==1000)
		return k;
		
		if(k==0)
		return 0;
		
		
		queue<int> q;
		q.push(1000);
		q.push(1000);
		q.push(0);
		int outreach=-99999;
		int localans=1000;
		while(!q.empty()){
			int a = q.front(); q.pop();
			int b = q.front(); q.pop();
			int path = q.front(); q.pop();
			if(path<=k){
				if(a>localans)
				localans=a;
			}
			
			if(path == k)
			continue;
			
			for(int i = 0 ; i<4 ; i++){
				int x1 = a+dx[i];
				int y1 = b+dy[i];
				if(x1 <0 || x1>2000 || y1 <0 || y1 >2000 || visited[x1][y1]!=false)
				continue;
				int local = path+1;
				if(x1==max){
					outreach=(local);
					break;
				}
				visited[x1][y1]=true;
				q.push(x1);
				q.push(y1);
				q.push(local);
					
			}
			if(outreach!=-99999)
			break;
		}
		if(outreach!=-99999)
		return k-outreach+max-1000;
		
		return localans-1000;
	}
};

bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	TheGridDivTwo *obj;
	int answer;
	obj = new TheGridDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-2,-1,0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-1,0,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-1,1,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0.clear() /*{}*/;
	p1.clear() /*{}*/;
	p2 = 1000;
	p3 = 1000;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,0,0,-1,-1,-2,-2,-3,-3,-4,-4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-1,1,-2,2,-3,3,-4,4,-5,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 47;
	p3 = 31;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}

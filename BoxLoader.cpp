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

using namespace std;


class BoxLoader {
public:
	int mostItems(int x, int y, int z, int a, int b, int c) {
		int res = 0;
		if(x>=a && y >=b && z >=c)
		res=max(res,(x/a) * (y/b)*(z/c));
		if(x>=a && y >=c && z >=b)
		res=max(res,(x/a) * (y/c)*(z/b));
		if(x>=b && y >=a && z >=c)
		res=max(res,(x/b) * (y/a)*(z/c));
		if(x>=b && y >=c && z >=a)
		res=max(res,(x/b) * (y/c)*(z/a));
		if(x>=c && y >=b && z >=a)
		res=max(res,(x/c) * (y/b)*(z/a));
		if(x>=c && y >=a && z >=b)
		res=max(res,(x/c) * (y/a)*(z/b));
		return res;		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	BoxLoader *obj;
	int answer;
	obj = new BoxLoader();
	clock_t startTime = clock();
	answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	int p6;
	
	{
	// ----- test 0 -----
	p0 = 100;
	p1 = 98;
	p2 = 81;
	p3 = 3;
	p4 = 5;
	p5 = 7;
	p6 = 7560;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	p1 = 10;
	p2 = 10;
	p3 = 9;
	p4 = 9;
	p5 = 11;
	p6 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 201;
	p1 = 101;
	p2 = 301;
	p3 = 100;
	p4 = 30;
	p5 = 20;
	p6 = 100;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 913;
	p1 = 687;
	p2 = 783;
	p3 = 109;
	p4 = 93;
	p5 = 53;
	p6 = 833;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 6;
	p1 = 5;
	p2 = 4;
	p3 = 3;
	p4 = 2;
	p5 = 1;
	p6 = 20;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

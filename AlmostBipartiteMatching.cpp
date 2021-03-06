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


class AlmostBipartiteMatching {
public:
	int maxMatching(int nA, int nB, vector <int> edgesA, vector <int> edgesB) {
		
		if((nA%2==0 && nB%2==0 )||(nA %2!=0 && nB%2==0) || (nA%2==0 && nB%2!=0))
		return ((nA+nB)/2 ) ;
		for(int i = 0 ; i <edgesA.size() ; i++)
		if(edgesA[i]%2==0 && edgesB[i]%2==0)
		return ((nA+nB)/2 );
		return ((nA+nB)/2 )-1;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	AlmostBipartiteMatching *obj;
	int answer;
	obj = new AlmostBipartiteMatching();
	clock_t startTime = clock();
	answer = obj->maxMatching(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 3;
	int t2[] = {0,1,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,1,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	int t2[] = {0,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = 6;
	int t2[] = {0,0,2,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2,4,5,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 13;
	p1 = 16;
	int t2[] = {5,2,6,2,7,2,7,6,2,6,1,3,0,10,12,11,10};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {7,3,10,12,0,0,3,4,7,2,5,2,14,15,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 14;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
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

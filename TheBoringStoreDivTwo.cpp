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


class TheBoringStoreDivTwo {
public:
	string find(string J, string B) {
		
		int maxlength=-1;
		string ans="";
		
		for(int length1 = 1 ; length1 <=J.size()-1 ; length1++){
			for(int i= 0 ; i<=J.size()-length1 ; i++){
				string cut1 = J.substr(i,length1);
				int limit1 = i;
				int limit2 = i+length1-1;
				for(int length2 = 1 ; length2 <= J.size()-length1 ; length2++){
					for(int j = 0 ; j<=J.size()-length2 ; j++){
						if(J[j]!=J[i])
						continue;
						if(j>limit2 || j+length2-1 < limit1){
							string cut2 = J.substr(j,length2);
							for(int length3 = 1 ; length3 <= B.size()-1 ; length3++){
								for(int k= 0 ; k<=B.size()-length3 ; k++){
									string cut3 = B.substr(k,length3);
									int limit3 = k;
									int limit4 = k+length3-1;
									int length4 = length1+length3-length2;
									if(length4<1 || length4 > B.size())
									continue;
									for(int l = 0 ; l<=B.size()-length4 ; l++){
										if(l>limit4 || l+length4-1 <limit3){
											string cut4= B.substr(l,length4);
											if(cut1!="" && cut2!="" && cut3!="" && cut4!=""){
												string temp1=cut1+cut3;
												string temp2=cut2+cut4;
												if(temp1.compare(temp2)==0){	
													if(maxlength<(int)temp1.size()){
														maxlength=temp1.size();
														ans=temp1;
														continue;
													}
													if(maxlength==(int)temp1.size() && ans.compare(temp1)>0){
														ans=temp1;
													}
												}
											}

										}
										
									}
								}
							}
							
						}
					}
				}
			}
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	TheBoringStoreDivTwo *obj;
	string answer;
	obj = new TheBoringStoreDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	string p0;
	string p1;
	string p2;
	
	{
	// ----- test 2 -----
	p0 = "aab";
	p1 = "cbc";
	p2 = "abc";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
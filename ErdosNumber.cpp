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


class ErdosNumber {
public:
	
	vector <string> calculateNumbers(vector <string> publications) {
		
			vector<string> authors;
			vector<string>::iterator it;
			vector<int> adj[101];
			
		authors.push_back("ERDOS");
		for(int i = 0 ; i < publications.size() ;i++){
			int j=0;
			vector<int> temp;
			for(int k = 0 ; k<publications[i].size() ;){
				if(publications[i][k]!=' ' && k!=publications[i].size()-1)
				{
					k++;
					continue;
				}
				if(k==publications[i].size()-1)
				k++;
				string str=publications[i].substr(j,k-j);
				cout<<str<<endl;
				it=find(authors.begin(),authors.end(),str);
				int index;
				if(it==authors.end()){
					authors.push_back(str);
					index=authors.size()-1;
				}
				else{
					index=it-authors.begin();	
				}
				k++;
				temp.push_back(index);
				j=k;
			}
			for(int k = 0 ; k<temp.size() ;k++){
				for(int j = 0; j<temp.size()  ; j++)
				if(j!=k){
					adj[temp[k]].push_back(temp[j]);
					adj[temp[j]].push_back(temp[k]);
				}
			}
		}
		
		vector<int> erdosNo(101,-1);
		queue<int> q;
		q.push(0);
		erdosNo[0]=0;
		authors[0]="ERDOS 0";
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(int i = 0 ; i<adj[x].size();i++){
				int y=adj[x][i];
				if(erdosNo[y]==-1){
					erdosNo[y]=erdosNo[x]+1;
					q.push(y);
					authors[y]=authors[y]+" "+std::to_string(erdosNo[y]);
				}
			}
		}
		sort(authors.begin(),authors.end());
		return authors;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ErdosNumber *obj;
	vector <string> answer;
	obj = new ErdosNumber();
	clock_t startTime = clock();
	answer = obj->calculateNumbers(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	
	vector <string> p0;
	vector <string> p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"ERDOS"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ERDOS 0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"KLEITMAN LANDER","ERDOS KLEITMAN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ERDOS 0","KLEITMAN 1","LANDER 2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"ERDOS A","A B","B AA C"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"A 1","AA 3","B 2","C 3","ERDOS 0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"ERDOS B","A B C","B A E","D F"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"A 2","B 1","C 2","D","E 2","ERDOS 0","F"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"ERDOS KLEITMAN","CHUNG GODDARD KLEITMAN WAYNE","WAYNE GODDARD KLEITMAN","ALON KLEITMAN","DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"ALON 2","CHUNG 2","DEAN 2","ERDOS 0","GODDARD 2","KLEITMAN 1","STURTEVANT 2","WAYNE 2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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

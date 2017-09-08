#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int calculate(vector<int> got, vector<int> exp, int final){
	int total_obtained=0;
	int total_marks=0;
	for(int i = 0 ; i < got.size() ; i++){
	total_obtained+=got[i];
	total_marks+=exp[i];	
	}
	int needed = ceil(((total_marks+final)*65)/100);
	if(needed > final + total_obtained)
	return -1;
	return ( needed - total_obtained);
}

int main(){
	int n,final;
	cin>>n;
	
	vector<int> got(n);
	vector<int> exp(n);
	for(int i=0 ;i < got.size() ; i++)
	cin>>got[i];
	for(int i = 0 ; i < exp.size() ; i++)
	cin>>exp[i];
	cin>>final;
	cout<<calculate(got,exp,final)<<endl;
}

#include<bits/stdc++.h>

using namespace std;

double func(int vel[],int con[],int fuel,int n){
	double ans = 0;
	for(int i = 0 ; i < n ; i++){
		double min = (60 *fuel*1.0)/con[i];
		double hour = min*1.0/60;
		double dist = vel[i]*hour*1.0;
		ans=max(ans,dist);
	}
	return ans;
}

int main(){
	int vel[]={5, 10, 20, 40, 80, 160};
	int con[]={1000, 2500, 6250, 8000, 9500, 20000};
	int fuel=47832;
	double ans = func(vel,con,fuel,6);
	cout<<ans<<endl;
}

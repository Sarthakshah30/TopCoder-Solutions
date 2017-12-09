#include<bits/stdc++.h>

using namespace std;

string func(string str){
	for(int i = 0 ; i < str.size() ; i++){
		if(str[i]=='Z'){
			if(i+1 < str.size() && str[i+1]=='E'){
				if(i+2 < str.size() && str[i+2]=='E'){
					if((i==0 || str[i-1]==' ')&&(i+2==str.size()-1 || str[i+3]==' ')){
						str[i+2]='D';
					}
				}
			}
		}
	}
	return str;
}

int main(){
	string str = "ZEE ZEE ZED ZEDS ZEE ZEES";
	string res = func(str);
	cout<<res<<endl;
}



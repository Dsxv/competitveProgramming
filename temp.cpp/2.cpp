#include <bits/stdc++.h>
using namespace std ;

#define int long long

string solve(string& k){
	string a , b ;
	for(int i = 0 ; i < k.size() - 1 ; i++) {
			if(k.substr(i,2) == "ru") {
				a = k.substr(0,i) ;
				b = k.substr(i+2) ;
				break ;
			}
	}
	return a + ".ru/" + b ;
}

char* address(char* input1) {
	string s = "" ;
	while(*input1) {
		s += (*input1) ;
		input1++ ;
	}
	string ans ;
	if(s.substr(0,3) == "ftp"){
		string k = s.substr(3) ;
		ans = "ftp://" + solve(k) ;
	}else{
		string k = s.substr(4);
		ans = "http://" + solve(k) ;
	}
	char* res = new char[ans.size() + 1] ;
	strcpy(res,ans.c_str()) ;
	return res ;
}
int32_t main(){
	string s ;
	cin >> s ;
	char input1[s.size() + 1] ;
	strcpy(input1,s.c_str()) ;
	char* ch  = address(input1) ;
	while(*ch) cout << *(ch++) ;
	return 0 ;
}


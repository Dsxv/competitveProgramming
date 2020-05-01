#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		if(s.size() <= 2){
			cout << "YES\n" ;
		} else {
			string k = s.substr(1,(int)s.size()-2) ;
			string a = k + s.back() + s.substr(0,1)  ;
			string b = s.back() + s.substr(0,1) + k;
			cout << (a==b?"YES\n":"NO\n") ;
		}
	}
	return 0 ;
}


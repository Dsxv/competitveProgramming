#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(string a , string b){
	if(a.size() < b.size()) return 0 ;
	for(int i = 0 ; i < b.size() ; i++){
		if(a[i] != b[i]) return 0 ; 
	}
	return 1 ;
}

int32_t main(){
	int x , y ;
	cin >> x >> y ;
	if(x%y == 0) {
		cout << x ;
		return 0 ;
	}
	int cur = y ;
	string s = to_string(x) ;
	while(1){
		string p = to_string(cur) ;
		if(ok(p,s)) {
			cout << cur ;
			return 0 ;
		}
		cur += y ;
	}
	return 0 ;
}


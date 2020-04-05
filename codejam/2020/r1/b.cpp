#include <bits/stdc++.h>
using namespace std ;

#define int long long

string add(int x){
	if(x == 0) return "" ;
	if(x < 0){
		return string(-x,'(') ;
	}
	return string(x,')') ;
}

void solve(int t){
	string s ;
	cin >> s ;
	string ans = "" ;
	int f = 0;
	for(auto i : s){
		ans += add(f-(i-'0')) ;
		ans += i ;
		f = i - '0' ;
	}
	ans += add(f) ;
	cout << "Case #"<<t<<": " ;
	cout << ans << endl ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}



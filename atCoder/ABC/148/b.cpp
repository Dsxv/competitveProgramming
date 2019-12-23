#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	string s , t ;
	cin >> s >> t ;
	string ans = "" ;
	for(int i = 0 ; i < n ; i++) ans += s[i] , ans += t[i] ;
	cout << ans ;
	return 0 ;
}


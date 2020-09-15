#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s , t ;
	cin >> s >> t ;
	int ans = 0 ;
	for(int i = 0 ; i < s.size() ; i++)
		ans += s[i] != t[i] ;
	cout << ans ;
	return 0 ;
}


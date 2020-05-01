#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	string s ;
	cin >> s ;
	int n = s.size() ;
	int x = 0 ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		x = ( x*10 + (s[i] - '0') ) % 2019 ;
		ans += mp[x] ;
		mp[x]++ ;
	}
	cout << ans ;
	return 0 ;
}


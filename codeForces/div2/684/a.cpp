#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , c0 , c1 , h ;
		cin >> n >> c0 >> c1 >> h ;
		string s ; cin >> s ;
		int x = min(c0 , c1 + h) ;
		int y = min(c1 , c0 + h) ;
		int ans = 0 ;
		for(auto i : s){
			if(i == '0') ans += x ;
			else ans += y ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


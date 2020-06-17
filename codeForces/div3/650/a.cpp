#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s ;
		string ans = "" ;
		ans += s.front() ;
		for(int i = 1 ; i < s.size() - 1 ; i += 2){
			ans += s[i] ;
		}
		ans += s.back() ;
		cout << ans << '\n' ;
	}
	return 0 ;
}


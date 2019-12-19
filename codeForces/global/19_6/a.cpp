#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		string s ;
		cin >> s;
		bool f = false ;
		int ev = 0 ;
		int ans = 0 ;
		for(auto i : s) {
			if((i-'0')%2 == 0) ev++ ;
			f += i == '0' ;
			ans += i -'0' ;
		}
		if(f && ans%3 == 0 & ev > 1){
			cout << "red\n" ;
		} else {
			cout << "cyan\n" ;
		}
	}
	return 0 ;
}


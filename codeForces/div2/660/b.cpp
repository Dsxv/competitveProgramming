#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int cnt = (n+3) / 4 ;
		cout << string(n-cnt,'9') + string(cnt , '8') << '\n' ;
	}
	return 0 ;
}


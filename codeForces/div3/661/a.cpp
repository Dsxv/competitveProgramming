#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[101] = {} ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			a[x]++ ;
		}
		int ans = 0 ;
		bool active = false ;
		for(int i = 1 ; i < 101 ; i++){
			if(a[i] == 0 && active) {
				ans++ ;
				active = false ;
			}
			if(a[i]) active = true ;
		}
		ans += active ;
		cout << (ans <= 1 ? "YES\n" : "NO\n") ;
	}
	return 0 ;
}


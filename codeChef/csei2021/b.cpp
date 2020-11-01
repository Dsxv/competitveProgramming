#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ; 
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a , a + n) ;
		int mn = INT_MAX ;
		for(int i = k - 1 ; i < n ; i++){
			mn = min(mn , a[i] - a[i - k + 1]) ;
		}
		cout << mn << '\n' ;
	}
	return 0 ;
}


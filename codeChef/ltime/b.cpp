#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string s ;
		cin >> s ;
		int a[n] = {0} ;
		a[0] = (s[0]!=s[1]) ;
		for(int i = 1 ; i < n ; i++){
			a[i] = a[i-1] + (s[i]!=s[i+1]) ;
		}
		int ans = a[k-1] ;
		for(int i = k ; i < n-1 ; i++){
			ans += a[i] - a[i-k] ;
		}
		cout << ans << endl ;
	}
	return 0 ;
}


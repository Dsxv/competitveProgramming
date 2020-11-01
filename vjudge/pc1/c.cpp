#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int suf[n+1][n+1] = {} ;
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = 0 ; j <= n ; j++){
				suf[i][j] += suf[i+1][j] ;
			}
			if(i) suf[i-1][a[i]]++ ;
		}
		int nx[n+1] ;
		for(int i = 0 ; i <= n ; i++) nx[i] = n ;
		for(int i = n - 1 ; i >= 0 ; i--){
			for(int j = 0 ; j <= n ; j++){
				suf[i][j] += suf[nx[a[i]]][j] ;
			}
			nx[a[i]] = i; 
		}
		int ans = 0 ;
		for(int i = 0 ; i < n ; i++){
			int l = i + 1 ;
			for(int j = i + 1 ; j < n ; j++){
				while(l < n && (l <= j || (a[l] != a[i])) ) l++ ;
				ans += suf[l][a[j]] ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


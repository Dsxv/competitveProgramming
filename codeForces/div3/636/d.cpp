#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int ps[2*k + 2] = {} ;
		map<int,int> mp ;
		for(int i = 0 ; i < n / 2 ; i++){
			int l = min(a[i] , a[n-i-1]) ;
			int r = max(a[i] , a[n-i-1]) ;
			ps[l+1]++ ; 
			ps[r+k+1]-- ;
			mp[l+r]++ ;
		}
		int ans = INT_MAX ;
		int sum = 0 ;
		for(int i = 0 ; i <= 2*k ; i++){
			sum += ps[i] ;
			ans = min(ans , sum - mp[i] + (n/2-sum)*2) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


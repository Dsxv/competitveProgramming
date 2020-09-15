#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ; cin >> n >> k ;
		int l1 , r1 ;
		int l2 , r2 ;
		cin >> l1 >> r1 >> l2 >> r2 ;
		if(l2 < l1){
			swap(l2 , l1) ;
			swap(r2 , r1) ;
		}
		int cost = max(0LL , l2 - r1) ;
		int intr = max(0LL , min(r1,r2) - l2) ;
		int ans = LLONG_MAX ;
		for(int i = 1 ; i <= n ; i++){
			int regionable = max(r2,r1) - l1 - intr ;
			int kd = k - i*intr ;
			int mval = max(0LL , min(kd , regionable*i)) + max(0LL , (kd - regionable*i)*2) ;
			ans = min(ans , cost*i + mval) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k , x , y ;
		cin >> n >> k >> x >> y ;
		int suf[n] = {} , a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a,a+n,greater<int>()) ;
		if(a[0] <= k){
			cout << 0 << '\n' ;
			continue ;
		}
		for(int i = n - 1 ; i >= 0 ; i--){
			suf[i] = a[i] ;
			if(i < n - 1){
				suf[i] += suf[i+1] ;
			}
		}
		int ans = INT_MAX ;
		if((suf[0]+n-1)/n <= k){
			ans = y ;
		}
		for(int i = 0 ; i < n ; i++){
			if(a[i] <= k){
				if(a[i] <= 1){
						ans = min(ans , i*x) ;
				} else {
						ans = min(ans , i*x + y) ;
				}
			}
			if((suf[i]-a[i] + n - 1) / n <= k) {
				ans = min(ans , (i+1)*x + y) ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


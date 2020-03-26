#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	pair<int,int> p[n] ;
	for(int i = 0 ; i < n ; i++) cin >> p[i].first ;
	for(int i = 0 ; i < n ; i++) cin >> p[i].second ;
	for(int i = 0 ; i < n ; i++) {
		a[i] = p[i].first - p[i].second ;
	}
	sort(a,a+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		if(a[i] <= 0){
			x = n - (upper_bound(a,a+n,-a[i]) - a) ;
		}
		else x = (n-i-1) ;
		ans += x ;
	}
	cout << ans ;
	return 0 ;
}


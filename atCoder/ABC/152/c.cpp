#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first ;
		a[i].second = i ;
	}
	sort(a,a+n) ;
	int mn = a[0].second ;
	int ans = 1 ;
	for(int i = 1 ; i < n ; i++){
			ans += (a[i].second < mn) ;
			mn = min(mn,a[i].second) ;
	}
	cout << ans ;
	return 0 ;
}


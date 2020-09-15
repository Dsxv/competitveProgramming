#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5  + 10;
int a[N] ;
int n , s ;

bool ok(int x ){
	vector<int> v(n) ;
	for(int i = 0 ; i < n ; i++){
		v[i] = a[i] + (i+1)*x ;
	}
	int mn = 1e18 ;
	int cur = 0 ;
	for(int i = 0 ; i < x ; i++) cur += v[i] ;
	mn = min(cur , mn) ;
	for(int i = x ; i < n ; i++){
		cur -= v[i-x] ;
		cur += v[i] ;
		mn = min(cur , mn) ;
	}
	return mn <= s ;
}

int32_t main(){
	cin >> n >> s ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int lo = 1 , hi = n ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(ok(mid)){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


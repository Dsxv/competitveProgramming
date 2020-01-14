#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int* a , int n){
	int x = *max_element(a,a+n) ;
	if(x <= 0) return 0 ;
	int c = 0 , m = 0 ;
	for(int i = 0 ; i < n ; i++){
		c += a[i] ;
		if(c < 0) c = 0 ;
		m = max(m,c) ;
	}
	return m ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int f = a[0] ;
		int sum = accumulate(a,a+n,0LL) ;
		a[0] = 0 ;
		int x = solve(a,n) ;
		a[0] = f , a[n-1] = 0 ;
		int y = solve(a,n) ;
		a[0] = 0 ;
		int z = solve(a,n) ;
		if(sum <= max({x,y,z})){
			cout << "NO\n" ;
		} else {
			cout << "YES\n" ;
		}
	}
	return 0 ;
}


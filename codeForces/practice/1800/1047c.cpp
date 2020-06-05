#include <bits/stdc++.h>
using namespace std ;

const int N = 2e7 ; 
int a[N] ;
int v[N] ;
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int gc = 0 ;
	int mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		gc = __gcd( gc , x) ;
		mx = max(mx , x) ;
		a[x]++ ;
	}
	int ans = n ;
	for(int i = gc + 1 ; i < mx + 1 ; i++){
		if(v[i]) continue ;
		int sum = 0 ;
		for(int j = i ; j < mx + 1 ; j += i){
			sum += a[j] ;
			v[j] = true ;
		}
		ans = min(ans , n - sum) ;
	}
	if(ans == n){
		cout << -1 ;
		return 0 ;
	}
	cout << ans ;
	return 0 ;
}


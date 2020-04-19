#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , int* a , int n , int d){
	for(int i = 0 ; i < n ; i++){
		x = ((x + a[i] - 1 ) / a[i])*a[i] ;
	}
	return x <= d ;
}

void solve(int t){
	int n , d ;
	cin >> n >> d ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int lo = 1 , hi = d ;
	int ans = 1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,a,n,d)) {
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << "Case #"<<t<<": "<< ans << '\n' ;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}



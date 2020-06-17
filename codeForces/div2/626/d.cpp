#include <bits/stdc++.h>
using namespace std ;

#define int long long

int bs(int i , int x , int * a , int n){
	// maximum index such that sum <= x
	int lo = i + 1 , hi = n - 1 ;
	int ans = i ;
	int val = a[i] ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(a[mid] + val <= x){
			ans = mid ;
			lo = mid + 1 ;
		} else {
			hi = mid - 1 ;
		}
	}
	return ans ;
}

bool check(int k , int* a , int n){
	int b[n] ;
	for(int i = 0 ; i < n ; i++){
		b[i] = a[i] % ( 1LL << ( k + 1) ) ;
	}
	sort(b,b+n) ;
	int ans = 0 ;
	for(int i = 0 ; i < n - 1 ; i++){
		int cnt = 0 ;
		cnt += bs(i,(1LL<<k) - 1, b , n) - bs(i,-1,b,n) ;
		cnt += bs(i,(1LL<<(k+1)) - 1 + (1LL<<(k)) , b , n) - bs(i , (1LL<<(k+1)) - 1 , b , n) ;
		ans += (n-i-1) - cnt ;
	}
	return ans&1 ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < 25 ; i++){
		ans |= check(i,a,n)<<i ;
	}
	//cout << check(0,a,n) ;
	cout << ans ;
	return 0 ;
}


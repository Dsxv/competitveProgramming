#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , int * a , int n , int k){
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(cnt&1){
			if(a[i] <= x) cnt++ ;
		} else {
			cnt++ ;
		}
	}
	if(cnt >= k) return true ;
	cnt = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(cnt&1) cnt++ ;
		else {
			if(a[i] <= x) cnt++ ;
		}
	}
	return cnt >= k ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int lo = 1 , hi = *max_element(a,a+n) ;
	int ans = -1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,a,n,k)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


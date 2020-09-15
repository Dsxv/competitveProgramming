#include <bits/stdc++.h>
using namespace std ;

#define int long long

int check(int x , int* a , int n , int k){
	int cnt = 0 ;
	for(int i = 0 ; i < x ; i++){
		cnt += a[i] ;
	}
	if(cnt + k >= x) return 1; 
	for(int i = x ; i < n ; i++){
		cnt -= a[i-x] ;
		cnt += a[i] ;
		if(cnt + k >= x) return 1 ;
	}
	return 0 ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	string s ; cin >> s ;
	for(int i = 0 ; i < n ; i++) {
		a[i] = s[i] - '0' ;
	}
	int lo = 1 , hi = n ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid , a , n , k)){
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


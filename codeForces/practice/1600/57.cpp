#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] , b[n];
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	for(int i = 0 ; i < n ; i++){
		cin >> b[i] ;
	}
	int presum[n+1] = {} ;
	for(int i = 0 ; i < n ; i++){
		presum[i] = b[i] ;
		if(i) presum[i] += presum[i-1] ;
	}
	presum[n] = 1e15 ;
	int ans[n] = {} ;
	int diff[n+1] = {} ;
	for(int i = 0 ; i < n ; i++){
		int lo = i , hi = n ;
		int prev = 0 ;
		if(i) prev = presum[i-1] ;
		int id = i ;
		while(lo <= hi) {
			int mid = (lo + hi) / 2 ;
			if((presum[mid] - prev) > a[i]){
				id = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		diff[i]++ ;
		diff[id]-- ;
		if(id == 0){
			ans[id] += a[i] ;
		} else {
			ans[id] += a[i] - (presum[id-1] - prev) ;
		}
	}
	int x =  0 ;
	for(int i = 0 ; i < n ; i++) {
		x += diff[i] ;
		cout << x*b[i] + ans[i] << " " ;
	}
	return 0 ;
}


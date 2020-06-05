#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	int a[2*n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		a[n+i] = a[i] ;
	}
	int pre[2*n + 1] = {} ;
	int sum[2*n + 1] = {} ;
	for(int i = 0 ; i < 2*n + 1 ; i++){
		sum[i] = (a[i]*(a[i]+1)) / 2 ;
		pre[i] += a[i] ;
		if(i){
			sum[i] += sum[i-1] ;
			pre[i] += pre[i-1] ;
		}
	}
	int mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		int lo = i , hi = 2*n - 1 ;
		int ans = i ;
		int l = 0 ;
		if(i) l = pre[i-1] ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if((pre[mid] - l) <= x){
				ans = mid ;
				lo = mid + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		int s = 0 ;
		if(i) s = sum[i-1] ;
		if(x < (pre[ans] - l)){
			mx = max(x*(a[i] - x + 1 + a[i]) / 2 , mx) ;
		} else if((pre[ans] - l) == x){
			mx = max(mx , sum[ans] - s) ;
		} else {
			int rem = x - (pre[ans] - l) ;
			int csum = sum[ans] - s + rem*(rem+1) / 2;
			int d = min(a[i]-1 , a[ans+1] - rem) ;
			int dsum = csum - d*(d+1)/2 + d*(rem+1 + rem + d) / 2 ;
			mx = max({mx , dsum , csum}) ;
		}
	}
	cout << mx ;
	return 0 ;
}


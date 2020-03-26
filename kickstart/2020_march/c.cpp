#include <bits/stdc++.h>
using namespace std ;

//#define int long long

bool check(int x , int* a , int n , int k){
	for(int i = 1 ; i < n ; i++){
		if((a[i] - a[i-1]) <= x){
			continue ;
		}
		int dif = a[i] - a[i-1] ;
		k -= (dif+x-1)/x - 1;
	}
	return k >= 0;
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int x = 1 ; x <= t ; x++) {
		int n , k ;
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int mx = 0 ;
		for(int i = 1 ; i < n ; i++){
			mx = max(mx,a[i]-a[i-1]) ;
		}
		int lo = 1 , hi = mx ;
		int ans = -1 ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(check(mid,a,n,k)){
				ans = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		printf("Case #%d: %d\n",x,ans) ;
	}
	return 0 ;
}


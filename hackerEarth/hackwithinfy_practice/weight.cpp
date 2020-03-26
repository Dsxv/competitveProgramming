#include <bits/stdc++.h>
using namespace std ;

#define int long long


bool check(int x , int* a , int n, int m){
	int sum = 0 ;
	int id = 0;
	for(int i = 0 ; i < n ; i++){
		if(sum + a[i] <= x){
			sum += a[i] ;
		} else {
			id++ ;
			sum = a[i] ;
		}
		if(id >= m) return 0 ;
	}
	return 1 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int lo = *max_element(a,a+n) , hi = accumulate(a,a+n,0LL) ;
		int ans = hi ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(check(mid,a,n,m)){
				hi = mid - 1 ;
				ans = mid ;
			} else {
				lo = mid + 1 ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


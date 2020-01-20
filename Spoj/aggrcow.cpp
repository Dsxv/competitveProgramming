#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int mid , int c ,  int* a , int n){
	int l = a[0] ;
	for(int i = 1 ; i < c ; i++){
		int x = lower_bound(a,a+n,l+mid)-a ;
		if(x == n) return false ;
		l = a[x] ;
	}
	return true ;
}

int32_t main(){
	int t ;
	cin >>t ;
	while(t--){
		int n , c ;
		cin >> n >> c ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) {
			cin >> a[i] ;
		}
		sort(a,a+n) ;
		int lo = 0 , hi = 1e9 ;
		int ans ;
		while(lo <= hi){
			int mid = (lo + hi) / 2 ;
			if(check(mid,c,a,n)){
				lo = mid + 1 ;
				ans = mid ;
			} else {
				hi = mid - 1 ;
			}
		}
		//cout << check(2,c,a,n);
		cout << ans << '\n' ;
	}
	return 0 ;
}


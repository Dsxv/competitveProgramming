#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x ,int k , pair<int,int>* p , int n){
	for(int i = n - 1 ; i >= 0 ; i--){
		if(i!=n-1) x = p[i+1].first + x - p[i].first - 1 ;
		k -= x;
		if(k <= 0) return 1 ;
	}
	return 0 ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k;
		int a[n] = {};
		pair<int,int> p[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].first ;
			p[i].second = i ;
		}
		sort(p,p+n) ;
		int lo = 0 , hi = k ;
		int ans = 0 ;
		while(lo <= hi){
			int mid = (lo+hi)/2 ;
			if(check(mid,k,p,n)){
				ans = mid ;
				hi = mid - 1 ;
			} else {
				lo = mid + 1 ;
			}
		}
		int x = ans ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(i!=n-1) x = min(k,p[i+1].first + x - p[i].first - 1) ;
			a[p[i].second] = x ;
			k -= x;
			if(k == 0) break ;
		}
		for(auto i : a) cout << i << " " ;
		cout << endl ;
	}

	return 0 ;
}


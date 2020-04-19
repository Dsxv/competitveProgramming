#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int x , pair<int,int>* a , int n , int l){
	for(int i = 0 ; i < n ; i++){
		int y = (l/a[i].second)*a[i].first ;
		if(x < y){ // low cash
			return false ;
		} else {
			if(((l + a[i].second - 1)/a[i].second)*a[i].first <= x) {
				return true ;
			} else {
				x -= y ;
				l %= a[i].second ;
			}
		}
		if(!l) return true ;
	}
	return x >= 0;
}
				
int32_t main(){
	int n , l ;
	cin >> n >> l ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first ;
		a[i].second = 1<<i ;
	}
	sort(a,a+n,[](pair<int,int> a , pair<int,int> b){
			return a.first*b.second < a.second*b.first ;
		}) ;
	int lo = 1 , hi = 1e18;
	int ans = 1 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,a,n,l)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


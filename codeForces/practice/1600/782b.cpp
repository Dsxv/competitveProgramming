#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int inf = 1e18 ;

bool check(double x , pair<double , double>* a , int n){
	x /= 1e7 ;	
	double l = -inf , r = inf ;
	for(int i = 0 ; i < n ; i++){
		l = max(a[i].first - x*a[i].second , l) ;
		r = min(a[i].first + x*a[i].second , r) ;
	}
	return l <= r ;
}

int32_t main(){
	int n ;
	cin >> n ;
	pair<double , double> p[n] ;
	for(int i = 0 ; i < n ; i++) cin >> p[i].first ;
	for(int i = 0 ; i < n ; i++) cin >> p[i].second ;
	int lo = 0 , hi = 1e18 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid , p , n)){
			hi = mid - 1 ;
			ans = mid ;
		} else {
			lo = mid + 1 ;
		}
	}
	cout << fixed << setprecision(7) <<  ans / (1e7)  ;
	return 0 ;
}


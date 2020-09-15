#include <bits/stdc++.h>
using namespace std ;

#define int long long

double check(pair<int,int>* a , int n , double x){
	double mn = 1e18 , mx = 0 ;
	for(int i = 0 ; i < n ; i++){
		double d = a[i].first*x + a[i].second ;
		mn = min(d , mn) ;
		mx = max(d , mx) ;
	}
	return mx - mn ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].first >> a[i].second ;
	}
	double lo = 0 , hi = k ;
	double ans = 0 ;
	double eps = 1e-9; 
	while((hi-lo) > eps){
		double mid1 = lo + (hi-lo) / 3 ;
		double mid2 = hi - (hi-lo) / 3 ;
		double fx1 = check(a,n,mid1) , fx2 = check(a,n,mid2) ;
		if(fx1 > fx2){
			lo = mid1 ;
		} else {
			hi = mid2 ;
		}
		ans = fx1 ;
	}
	ans = check(a,n,lo) ;
	cout << fixed << setprecision(6) << ans ;
	return 0 ;
}


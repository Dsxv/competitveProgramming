#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int INF = 5e4 + 10 ;

int power(int a , int n){
	int ans = 1 ;
	for(int i = 0 ; i < n ; i++){
		ans *= a ;
	}
	return ans ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	function<int(int)> check = [&] ( int x ){
		int val = 0 ;
		for(int i = 0 ; i < n ; i++){
			val += power(abs(x-a[i]) , k) ;
		}
		return val ;
	} ;

	int lo = -INF , hi = INF ;
	int ans = 0 ;
	while((hi - lo) > 3){
		int mid1 = lo + (hi-lo) / 3 ;
		int mid2 = hi - (hi-lo) / 3 ;
		int f1 = check(mid1) , f2 = check(mid2) ;
		if(f1 > f2) {
			lo = mid1 ;
		} else {
			hi = mid2 ;
		}
	}
	vector<pair<int,int>> v ;
	for(int i = lo ; i <= hi ; i++){
		v.push_back({check(i) , i}) ;
	}
	sort(v.begin() , v.end() , [&](pair<int,int> a , pair<int,int> b){
			if(a.first != b.first) return a.first < b.first ;
			return a.second < b.second ;
			}) ;
	cout << v.begin()->second ;
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	vector<int> v ;
	int a[] = {3,5,7} ;
	for(int i = 0 ; i < 3 ; i++){
		int x = a[i] ;
		while(x < 1e10){
			v.push_back(x) ;
			x *= a[i] ;
		}
	}
	set<int> s ;
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = i + 1 ; j < v.size() ; j++){
			s.insert(v[i] + v[j]) ;
		}
	}
	int t ;
	cin >> t ;
	while(t--){
		int n , d , i;
		cin >> n >> d >> i;
		auto it = s.lower_bound(n) ;
		int ans = LLONG_MAX ;
		if(it != s.end()){
			ans = (*it - n)*i ;
		} 
		if(it != s.begin()){
			it-- ;
			ans = min(ans , (n - *it)*d) ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


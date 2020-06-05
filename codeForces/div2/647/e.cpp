#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n , p ;
		cin >> n >> p ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		if(p == 1){
			cout << (n&1) << '\n' ;
			continue ;
		}
		sort(a,a+n) ;
		vector<pair<int,int>> v ;
		v.push_back({a[0],1}) ;
		for(int i = 1 ; i < n ; i++){
			if(v.back().first == a[i]) v.back().second++ ;
			else v.push_back({a[i] , 1}) ;
		}
		int ans = 0 ;
		for(int i = n - 1 ; i >= 0 ; ){
			if(v[i].second == 0){
				i-- ;
				continue ;
			}
			if(v[i].second >= 2){
				v[i].second -= 2 ;
				continue ;
			}
			int sum = 0 ;
			int j = i - 1;
			int cur = 1 ;
			while(j >= 0){
					int count = v[j].second/val(p,i - j + 1) ;
					if(count > cur){ 
						v[j].second -= cur*val(p,i-j+1) ;
					} else {
						if(j){
							v[j-1].second += (v[j].second%(i-j+1))*
		}
		cout << ans << '\n';
	}
	return 0 ;
}


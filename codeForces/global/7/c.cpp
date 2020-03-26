#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 998244353 ;

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	map<int,int> mp ;
	int sum = 0 ;
	for(int i = n ; i > n - k ; i--){
		mp[i] = 1 ;
		sum += i ;
	}
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	if(n == 1){
		cout << 1 << " " << 1 ;
		return 0 ;
	}
	vector<int> d ;
	for(int i = 0 ; i < n ; i++){
		if(mp[a[i]]) d.push_back(i) ;
	}
	int ans = 1 ;
	for(int i = 1 ; i < d.size() ; i++){
		ans = (ans*(d[i]-d[i-1])) % mod ;
	}
	cout << sum << " " << ans  ;
	return 0 ;
}


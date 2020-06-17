#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mv = 1e14 + 10 ;

int power(int a , int n){
	int ans = 1 ;
	for(int i = 1 ; i <= n ; i++){
		ans *= a ;
	}
	return ans ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	vector<int> v ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	if(k == 1){
		v.push_back(1) ;
	} else if(k == -1){
		v.push_back(1) ;
		v.push_back(-1) ;
	} else {
		for(int i = 0 ; i < 50 ; i++){
			if(abs(power(k,i)) > mv){
				break ;
			}
			v.push_back(power(k,i)) ;
		}
	}
	map<int,int> mp ;
	mp[0] = 1; 
	int s = 0 , ans = 0;
	for(int i = 0 ; i < n ; i++){
		s += a[i] ;
		for(auto j : v){
			if(mp.count(s-j)) ans += mp[s-j] ;
		}
		mp[s]++ ;
	}
	cout << ans ;
	return 0 ;
}


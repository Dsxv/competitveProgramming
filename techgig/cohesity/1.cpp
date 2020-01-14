#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(map<int,int>& mp , vector<int>& v){
	for(auto i : v) mp[i]++ ;
}

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> v1(n) , v2(m) , v3(k) ;
	for(int i = 0 ; i < n ; i++) cin >> v1[i] ;
	for(int i = 0 ; i < m ; i++) cin >> v2[i] ;
	for(int i = 0 ; i < k ; i++) cin >> v3[i] ;
	for(int i = n - 2 ; i >= 0 ; i--){
		v1[i] += v1[i+1] ;
	}
	for(int i = m - 2 ; i >= 0 ; i--){
		v2[i] += v2[i+1] ;
	} 
	for(int i = k - 2 ; i >= 0 ; i--){
		v3[i] += v3[i+1] ;
	}
	map<int,int> mp ;
	solve(mp , v1) ;
	solve(mp , v2) ;
	solve(mp , v3) ;
	int mx = 0 ;
	for(auto i : mp){
		if(i.second == 3) mx = max(mx,i.first) ;
	}
	cout << mx ;
	return 0 ;
}


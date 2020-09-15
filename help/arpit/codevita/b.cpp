#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n){
	int l = sqrt(n) ;
	int mn = 1 ;
	for(int i = 2 ; i <= l ; i++){
		if(n%i) continue ;
		if(i*i == n){
			mn = max(mn , i) ;
		} else {
			mn = max({mn , i , n / i}) ;
		}
	}
	return mn ;
}

int32_t main(){
	int n , m , cnt = 0;
	cin >> n >> m ;
	vector<int> b ;
	b.push_back(m) ;
	map<int,int> mp = {{n,0}} ;
	while(n > 1){
		int x = solve(n) ;
		mp[x] = ++cnt ;
		n = x ;
	}
	while(m > 1){
		int x = solve(m) ;
		b.push_back(x) ;
		m = x ;
	}
	int ans = INT_MAX ;
	for(int i = 0 ; i < (int)b.size() ; i++){
		if(mp.count(b[i])) ans = min(ans , mp[b[i]] + i) ;
	}
	cout << ans ;
	return 0 ;
}


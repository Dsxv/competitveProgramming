#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;
int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2 ) ;
	x = (x*x) % mod ;
	if(n&1)  x = (x*a) % mod ;
	return x ;
}

int solve(int ans , int nn , int pp){
	ans = (ans*nn) % mod ;
	ans = ( ((ans*modexp(pp , mod - 2)) % mod)*-1 + mod * mod ) % mod ;
	return ans ;
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	vector<pair<int,int>> v; 
	int z = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		if(x < 0){
			v.push_back({-x,1}) ;
		} else if(x > 0){
			v.push_back({x,0}) ;
		} else {
			z = 1 ;
		}
	}
	if(v.size() < k){
		cout << 0 ;
		return 0 ;
	}
	sort(v.begin() , v.end() , greater<pair<int,int>>()) ;
	int cnt = 0 ;
	int ans = 1 ;
	for(int i = 0 ; i < k ; i++){
		cnt += v[i].second ;
		int f = 1 ;
		if(v[i].second) f = -1 ;
		ans = (ans*v[i].first*f + mod*mod) % mod ;
	}
	if(cnt%2 == 0){
		cout << ans ;
		return 0 ;
	}
	int pp = -1 , pn = -1 ;
	int np = -1 , nn = -1 ;
	for(int i = k-1 ; i >= 0 ; i--){
		if(v[i].second && pn == -1) {
			pn = v[i].first ;
		}
		if(!v[i].second && pp == -1){
			pp = v[i].first ;
		}
	}
	for(int i = k ; i < n ; i++){
		if(v[i].second && nn == -1){
			nn = v[i].first ;
		}
		if(!v[i].second && np == -1){
			np = v[i].first ;
		}
	}
	bool x = (~nn) && (~pp) ;
	bool y = (~np) && (~pn) ;
	if(x && y){
		if(nn*pn > pp*np){
			ans = solve(ans , nn , pp) ;	
		} else {
			ans = solve(ans , np , pn) ;
		}
	} else if(x){
		ans = solve(ans , nn , pp) ;
	} else if(y){
		ans = solve(ans , np , pn) ;
	} else if(z){
		ans = 0 ;
	} else {
		ans = 1 ;
		for(int i = n - 1 ; i >= (n-k) ; i--){
			int f = 1 ;
			if(v[i].second) f = -1 ;
			ans = (ans * v[i].first * f + mod*mod) % mod ;
		}
	}
	cout << ans ;
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
constexpr int mod = 1e9 + 7 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2) ;
	x = (x * x) % mod ;
	if(n & 1) x = (x * a) % mod ;
	return x ;
}

int fac[N] , sum[N] ;

int gs(int x){
	if(x < 0) return 0 ;
	return sum[x] ;
}

int ncr(int n , int rem){
	if(n < rem || rem < 0 || n < 0) return 0 ;
	int x = fac[n] * modexp(fac[n - rem] , mod - 2) ;
	x %= mod ;
	x *= modexp(fac[rem] , mod - 2) ;
	return x ;
}

int solve(int l , int r , int rem){
	int n = gs(r) - gs(l - 1) ;
	return ncr(n , rem) ;
}

int32_t main(){
	fac[0] = 1 ;
	for(int i = 1 ; i < N ; i++){
		fac[i] = (fac[i - 1] * i ) % mod ;
	}
	int t ;
	cin >> t ;
	while(t--){
		int ans = 0 ;
		int n , m , k ;
		cin >> n >> m >> k ;
		vector<pair<int,int>> v ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		sort(a , a + n) ;
		v.push_back({a[0] , 1}) ;
		for(int i = 1 ; i < n ; i++) {
			if(v.back().first == a[i]) v.back().second++ ;
			else v.push_back({a[i] , 1}) ;
		}
		for(int i = 0 ; i < v.size() ; i++){
			if(i) sum[i] += sum[i - 1] ;
			sum[i] += v[i].second ;
		}
		sum[v.size()] = sum[v.size() - 1] ;
		for(int i = 0 ; i < v.size() - 1 ; i++){
			int lo = i + 1 , hi = v.size() - 1 ;
			int id = v.size() ;
			while(lo <= hi){
				int mid = lo + hi >> 1 ;
				if(v[mid].first > (v[i].first + k)){
					id = mid ;
					hi = mid - 1 ;
				} else {
					lo = mid + 1 ;
				}
			}
			if(id == v.size() || v[id].first > v[i].first + k) id-- ;
			for(int j = 1 ; j <= v[i].second ; j++){
				int x = ncr(v[i].second , j) ;
				ans += (x * solve(i + 1 , id , m - j))  ;
			}
		}
		ans = (ans + ncr(v.back().second , m)) ;
		for(int i = 0 ; i < v.size() + 1 ; i++) sum[i] = 0 ;
		cout << ans << '\n' ;
	}
	return 0 ;
}


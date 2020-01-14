#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 20 ;
const int mod = 1e9 + 7 ;
int fact[N] ;

int modexp(int a, int n){
	if(n == 0) return 1 ;
	if(n == 1 ) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x)%mod; 
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int solve(int n){
	int a[2*n] ;
	map<int,int> mp ;
	int ans = 0 ;
	for(int i = 0 ; i < 2* n ; i++) {
		cin >> a[i] ;
		ans += a[i] ;
		mp[a[i]]++ ;
	}
	if(ans%(n+1)) return 0 ;
	ans /= (n+1) ;
	if(mp[ans] >= 2) {
		if(mp[ans] == 2) mp.erase(ans) ;
		else mp[ans] -= 2 ;
		vector<int> v ;
		for(auto i : mp){
			int x = i.second ;
			while(x--){
				v.push_back(i.first) ;
			}
		}
		mp.clear() ;
		sort(v.begin(),v.end()) ;
		int sz = v.size() ;
		int pr = 0 ;
		bool z = false ;
		for(int i = 0 ; i < n - 1 ; i++){
			int pre = v[i] ;
			int suf = v[sz-i-1] ;
			if(pre+suf == ans){
				pr += (pre != suf) ;
			} else {
				z = 1 ;
				break ;
			}
			mp[pre]++ ;
		}
		if(z) return 0 ;
		int val = (modexp(2,pr)*fact[n-1]) % mod ;
		for(auto i : mp){
			int inv  = modexp(fact[i.second],mod-2) ;
			val = (val*inv) % mod ;
		}
		return val ;
	}
	return 0 ;
}
		

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	fact[0] = 1 ;
	for(int i = 1 ; i < N ; i++) 
		fact[i] = (fact[i-1]*i) % mod ;
	
	while(t--){
		int n ; cin >> n ;
		cout << solve(n) << '\n' ;
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int modexp(int a , int n ,int mod){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a , n / 2 , mod) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int solve(int x){
	if(!x) return 0 ;
	return 1 + solve(x%__builtin_popcount(x)) ;
}

int32_t main(){
	int n;
	cin >> n ;
	string s ;
	cin >> s; 
	int cnt = count(s.begin() , s.end() , '1') ;
	if(cnt == 0){
		for(auto i : s) cout << 1 << '\n' ;
		return 0 ;
	}
	if(cnt == 1){
		if(s.back() == '1'){
			for(int i = 0 ; i < n - 1 ; i++) cout << 2 << '\n' ;
			cout << 0 << '\n' ;
		} else {
			for(int i = 0 ; i < n - 1 ; i++){
				if(s[i] == '1') cout << 0 << '\n' ;
				else cout << 1 << '\n' ;
			}
			cout << 2 << '\n' ;
		}
		return 0 ;
	}
	int b = 0 , c = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x = s[i] - '0' ;
		b += x*modexp(2 , n-i-1, cnt+1) ;
		c += x*modexp(2 , n-i-1, cnt-1) ;
		b %= (cnt+1) ;
		c %= (cnt-1) ;
	}
	for(int i = 0 ; i < n ; i++){
		int x = s[i] - '0' ;
		int val ;
		if(x){
			val = (c - modexp(2 , n-i-1 , cnt-1) + cnt - 1 ) % (cnt-1) ;
		} else {
			val = (b + modexp(2 , n-i-1 , cnt+1)) % (cnt + 1) ;
		}
		cout << solve(val) + 1 << '\n' ;
	}

	return 0 ;
}


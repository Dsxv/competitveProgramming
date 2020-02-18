#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int modpow(int a, int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int val = modpow(a,n/2) ;
	val = (val*val) % mod ;
	if(n&1) {
		val = (val*a) % mod ;
		return val ;
	} else{
		return val ;
	}
}

void solve(){
	int n ; string temp ;
	cin >> n >> temp ;
	string s = "*" ;
	s += temp ;
	int a[n+2] = {0} ;
	for(int i = 1 ; i <= n ; i++){
		if(s[i] == ')') a[i] = a[i-1] - 1 ;
		if(s[i] == '(') a[i] = a[i-1] + 1 ;
		else continue ;
	}
	int val = n+3 ;
	for(int i = 1 ; i <= n ; i++){
		a[i] += val ;
	}
	int state[105+2*n] = {0} ;
	int cn  = 0 , pr = 0 ;
	for(int i = n ; i >= 1 ; i--){
		state[a[i]] = state[a[i]-2] ;
		if(s[i] == ')'){
			state[a[i]] = (state[a[i]] + n - i + 1) % mod ;
			pr = state[a[i]] ;
			cn = (cn + pr) % mod ;
		} else if(s[i] == '*'){
			cn = (cn+pr) % mod ;
			continue ;
		} else {
			pr = state[a[i]] ;
			cn = (cn + pr) % mod ;
		}
	}
	//cout << cn << endl ;
	cout << (modpow((n*(n+1)/2)%mod,mod-2)*cn) % mod << '\n' ;
}
		

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		solve() ;
	}
	return 0 ;
}


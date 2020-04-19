#include <bits/stdc++.h>
using namespace std ;
#define int long long

int n , m ;
const int N = 2e5 + 10 ;
int a[N] , b[N] ;

void init(string &s , string &t){
	s = "." + s + "." ;
	for(int i = 0 , l = 0 ; i < n + 2 ; i++){
		if(l < m) {
			if(s[i] == t[l]) {
				l++ ;
			}
		}
		a[i] = l ;
	}
	for(int i = n + 1 , l = m - 1 , count = 0 ; i >= 0 ; i--){
		if(l >= 0){
			if(s[i] == t[l]) l-- , count++ ;
		}
		b[i] = count ;
	}
}


bool check(int x){
	for(int i = 1 ; i <= n-x+1 ; i++){
		if((a[i-1] + b[i+x]) >= m) {
			return true ;
		}
	}
	return false ;
}

int32_t main(){
	string s ;
	string t ;
	cin >> s >> t ;
	n = s.size() ;
	m = t.size() ;
	init(s,t) ;
	int lo = 0 , hi = n-1 ;
	int ans = 0 ;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid)){
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


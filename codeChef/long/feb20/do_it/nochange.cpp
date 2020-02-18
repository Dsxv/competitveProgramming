#include <bits/stdc++.h>
using namespace std ;

#define int long long

void nope(){
	cout << "NO\n" ;
}

void solve(){
	int n , p ;
	int val = -1 ;
	cin >> n >> p ;
	int count[n] = {0} , a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++){
		if(p%a[i] != 0) {
			val = i; break ;
		}
	}
	if(val == -1){
		int x1 = -1 , x2 = -1 ;
		for(int i = 0 ; i < n - 1 ; i++){
			int val2 = __gcd(a[i],a[i+1]) ;
			if((a[i] != 1) && val2 != a[i]){
				x1 = i ;
				x2 = i + 1 ;
			}
		}
		if(x1 == -1 || x2 == -1){
			nope() ;
		} else {
			if(a[x1] < a[x2]){
				x1 ^= x2 ;	x2 ^= x1 ;
				x1 ^= x2 ;
			}
			count[x1] = (p-1)/a[x1] ;
			int to_add = p ;
			p -= a[x1]*count[x1] ;
			count[x2] = (to_add + a[x2] - 1) / (a[x2]) ;
			cout << "YES ";
			for(int i = 0 ; i < n ; i++) cout << count[i] << " ";
			cout << '\n' ;
		}
	} else {
		count[val] = (p+a[val]-1)/a[val] ;
		cout << "YES ";
		for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
		cout << '\n' ;
	}
}


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		solve() ;
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 4e3 + 1 ;
int a[N] ;
int fact[N] = {} ;
int32_t main(){
	int n , p ;
	cin >> n >> p ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		a[x]++ ;
	}
	int pre[N] = {} ;
	for(int i = 1 ; i < N ; i++){
		pre[i] = pre[i-1] + a[i] ;
	}
	vector<int> ans ;
	for(int x = 1 ; x < N ; x++){
		int val = 1 ;
		for(int i = 0 ; i < n ; i++){
			if(pre[x+i] < i) {val = 0; break ; }
			val = (val*(pre[x+i] - i)) % p ;
		}
		if(val%p) ans.push_back(x) ;
	}
	cout << ans.size() << '\n' ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}


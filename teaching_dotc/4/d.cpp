#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 10 ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n; 
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	int q ;
	cin >> q ;
	while(q--){
		int l , r , g ;
		cin >> l >> r >> g ;
		l-- , r-- ;
		vector<int> v(N) ;
		for(int i = l ; i <= r ; i++) v[a[i]]++ ;
		vector<int> ans(N) ;
		for(int i = 1 ; i < N ; i++){
			for(int j = i*2 ; j < N ; j += i){
				v[i] += v[j] ;
			}
			int c = v[i] ;
			ans[i] =  c*(c-1)*(c-2) / 6 ;
		}
		for(int i = N ; i >= 1 ; i--){
			for(int j = i*2 ; j < N ; j += i){
				ans[i] -= ans[j] ;
			}
		}
		cout << ans[g] << '\n' ;
	}
	return 0 ;
}


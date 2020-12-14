#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 + 5 ;
int a[N] , pre[N] ;
set<int> s ;

int sum(int l ,int r){
	return pre[r] - pre[l - 1] ;
}

void solve(int l , int r){
	if(l > r) return ;
	while(l < r && !a[l]) l++ ;
	while(l < r && !a[r]) r-- ;
	s.insert(sum(l,r)) ;
	if(l == r) return ;
	int mid = (l + r) / 2 ;
	solve(l , mid) ;
	solve(mid + 1 , r) ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		s.clear() ;
		int n , q ;
		cin >> n >> q ;
		for(int i = 0 ; i < N ; i++) a[i] = pre[i] = 0 ; 
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			a[x]++ ;
		}
		for(int i = 1 ; i < N ; i++) pre[i] = pre[i - 1] + i * a[i] ;
		int l = 0 , r = N - 1 ;
		solve(l,r) ;
		while(q--){
			int x ; 
			cin >> x ;
			if(s.count(x)) cout << "Yes\n" ;
			else cout << "No\n" ;
		}
	}
	return 0 ;
}


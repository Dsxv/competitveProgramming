#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 10 ;

int a[N] ;
int prem[N] , pre[N] ;

int32_t main(){
	int n , q , m ;
	cin >> n >> q >> m ;
	vector<pair<int,int>> v(q) ;
	int i = 0 ;
	while(q--){
		int l , r ;
		cin >> l >> r ;
		v[i++] = {l,r} ;
		a[l] += 1 ;
		a[r+1] -= 1 ;
	}
	int sum = 0 ;
	for(int i = 1 ; i < N ; i++){
		sum += a[i] ;
		a[i] = sum ;
	}
	for(int i = 1 ; i < N  ; i++){
		pre[i] = (a[i] == (m+1)) + pre[i-1];
		prem[i] = (a[i] == m) + prem[i-1] ;
	}
	int mx = 0 ;
	for(auto i : v){
		int l = i.first , r = i.second ;
		mx = max( mx , (prem[N-1] - prem[r] + prem[l-1]) + (pre[r] - pre[l-1])) ;
	}
	cout << mx ;
	return 0 ;
}


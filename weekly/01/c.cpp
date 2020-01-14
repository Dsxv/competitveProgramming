#include <bits/stdc++.h>
using namespace std ;

#define int long long
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	pair<int,int> p[n] , v[n] ;
	for(int i = 0 ; i < n ; i++){
		int x , y ; cin >> x >> y ;
		v[i].first = x ; v[i].second = y ;
		p[i].first = x - y ;
		p[i].second = i ;
	}
	sort(p,p+n) ;
	int pre[n] , suf[n] ;
	vector<int> ans(n) ;
	pre[0] = v[p[0].second].first ;
   	suf[n-1] = v[p[n-1].second].second ;
	for(int i = 1 ; i < n ; i++) pre[i] = v[p[i].second].first + pre[i-1] ;
	for(int i = n-2 ; i >= 0 ; i--) suf[i] = suf[i+1] + v[p[i].second].second ;
	for(int i = 0 ; i < n ; i++){
		if(i != n-1) {
			ans[p[i].second] += suf[i+1] + (n-i-1)*v[p[i].second].first ;
		}
		if(i != 0){
			ans[p[i].second] += pre[i-1] + i*v[p[i].second].second ;
		}
	}
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		int t = min(v[f].first+v[s].second , v[f].second + v[s].first) ;
		ans[f] -= t ;
		ans[s] -= t ;
	}
	for(auto i : ans) cout << i << " " ;
	return 0 ;

}


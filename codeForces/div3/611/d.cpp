#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ; 
	cin >> n >> m ;
	set<int> s ;
	map<int,int> mp ;
	int a[n] ;
	queue<pair<int,int>> q ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		mp[a[i]] = 1 ;
	}
	int ans = 0 ;
	sort(a,a+n) ;
	for(int i = 0 ; i < n ; i++){
		int x = a[i]-1 ;
		int y = a[i]+1 ;
		if(!mp.count(x)) {
			q.push({x,1}) ;
			mp[x] = 1 ;
			s.insert(x) ;
			ans++ ;
		}
		if(s.size() == m) break ;
		if(!mp.count(y)){
			q.push({y,1}) ;
			mp[y] = 1 ;
			s.insert(y) ;
			ans++ ;
		}
		if(s.size() == m) break ;
	}

	while(s.size() < m){
		int x = q.front().first - 1 , y = q.front().first + 1 ;
		int d = q.front().second ;
		q.pop() ;
		if(!mp.count(x)) {
			ans += d + 1;
			q.push({x,d+1}) ;
			mp[x] = 1 ;
			s.insert(x) ;
		}
		if(s.size() == m) break ;
		if(!mp.count(y)){
			ans += d+1 ;
			q.push({y,d+1}) ;
			mp[y] = 1 ;
			s.insert(y) ;
		}
	}
	cout << ans << '\n' ;
	for(auto i : s) cout << i << " " ;
	return 0 ;
}


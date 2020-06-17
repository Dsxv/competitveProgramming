#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int x[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] ;
	}
	queue<pair<int,int>> q ;
	map<int,int> visited ;
	for(int i = 0 ; i < n ; i++){
		q.push({x[i] , 1}) ;
		visited[x[i]] = 1 ;
	}
	int ans = 0 ;
	vector<int> v ;
	while(v.size() < m){
		int f = q.front().first ;
		int d = q.front().second ;
		q.pop() ;
		if(!visited.count(f-1)){
			q.push({f-1,d+1}) ;
			v.push_back(f-1) ;
			ans += d ;
			visited[f-1] = 1 ;
		}
		if(v.size() == m) break ;
		if(!visited.count(f+1)) {
			q.push({f+1,d+1}) ;
			v.push_back(f+1) ;
			visited[f+1] = 1 ;
			ans += d ;
		}
	}
	cout << ans << endl ;
	for(auto i : v) cout << i << " " ;
	return 0 ;
}


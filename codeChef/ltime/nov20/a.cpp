#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ; 
		cin >> n ;
		int f[n] , c[n] ;
		for(int i = 0 ; i < n ; i++) cin >> f[i] ;
		for(int i = 0 ; i < n ; i++) cin >> c[i] ;
		priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
		int cur = 0 ;
		int ans = 0 ;
		while(cur < n){
			pq.push({c[cur] , cur}) ;
			int id = pq.top().second ;
			while(f[id] == 0){
				pq.pop() ;
				id = pq.top().second ;
			}
			ans += pq.top().first ;
			cur++ ;
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


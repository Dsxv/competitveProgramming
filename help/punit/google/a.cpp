#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool ok(int x , int* a , int* b , int n , int c){
	deque<pair<int , int>> q ;
	int sum = 0 ;
	for(int i = 0 ; i < x ; i++){
		while(q.size() && q.back().second <= b[i]){
			q.pop_back() ;
		
		q.push_back({i , b[i]}) ;
		sum += a[i] ;
	}
	if((q.front().second + sum*x) <= c) return 1 ;

	for(int i = x ; i < n ; i++){
		while(q.size() && q.back().second <= b[i]){
			q.pop_back() ;
		}
		sum -= a[i-x] ;
		sum += a[i] ;
		while(q.size() && q.front().first <= (i - x)) q.pop_front() ;
		q.push_back({i , b[i]}) ;
		if((q.front().second + sum*x) <= c) return 1; 
	}
	return 0 ;
}


int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t; 
	cin >> t ;
	while(t--){
		int n , c ;
		cin >> n >> c ;
		int a[n] , b[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		for(int i = 0 ; i < n ; i++) cin >> b[i] ;
		int lo = 1 , hi = n ;
		int ans = 0 ;
		while(lo <= hi){
			int mid = lo + hi >> 1 ;
			if(ok(mid , a , b , n , c)){
				ans = mid ;
				lo = mid + 1 ;
			} else {
				hi = mid - 1 ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}


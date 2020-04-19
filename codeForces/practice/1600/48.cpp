#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k  ;
	cin >> n >> k ;
	pair<int,int> a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].second >> a[i].first ;
	}
	sort(a,a+n) ;
	priority_queue<int, vector<int> , greater<int>> pq ;
	int ans = 0 ;
	int sum = 0 ;
	for(int i = n - 1 ; i >= 0 ; i--){
		pq.push(a[i].second) ;
		sum += a[i].second ;
		if(pq.size() > k){
			sum -= pq.top() ;
			pq.pop() ;
		}
		ans = max(ans, sum*a[i].first) ;
	}
	cout << ans ;
	return 0 ;
}


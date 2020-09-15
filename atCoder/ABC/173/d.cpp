#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n; 
	priority_queue<pair<int,pair<int,int>>> pq ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	sort(a,a+n,greater<int>()) ;
	pq.push({a[1] , {a[0] , a[1]}}) ;
	pq.push({a[1] , {a[0] , a[1]}}) ;
	int ans = a[0] ;
	for(int i = 2 ; i < n ; i++){
		auto x = pq.top() ;
		pq.pop() ;
		ans += x.first ;
		pq.push({a[i] , {a[i] , x.second.first}}) ;
		pq.push({a[i] , {a[i] , x.second.second}}) ;
	}
	cout << ans ;
	return 0 ;
}


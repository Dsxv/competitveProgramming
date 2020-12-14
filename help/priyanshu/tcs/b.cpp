#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	if(n < 2){
		cout << "Invalid Input" ;
		return 0 ;
	}
	priority_queue<int> pq ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) {
		int x ;
		cin >> x ;
		a[i] = x ;
		pq.push(x) ;
		if(pq.size() > 2) pq.pop() ;
	}
	if(count(a , a + n , a[0]) == n){
		cout << "Equal" ;
		return 0 ;
	}
	int x = pq.top() ; pq.pop() ;
	cout << pq.top() << " " << x ;
	return 0 ;
}


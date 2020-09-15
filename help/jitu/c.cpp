#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k , m  ;
	cin >> n >> k >> m;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vector<int> v ;
	for(int i =	m ; i <= m + k ; i++) v.push_back(a[i]) ;
	if(v.size()%2){
		cout << (v.front()^v.back()) ;
	} else {
		int x = 0 ;
		for(auto i : v) x ^= i ;
		cout << x ;
	}
	return 0 ;
}


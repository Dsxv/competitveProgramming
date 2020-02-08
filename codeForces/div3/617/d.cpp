#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , a , b , k ;
	cin >> n >> a >> b >> k ;
	int count = 0 ;
	vector<int> v; 
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		x %= (a+b) ;
		if(x == 0) x = a+b ;
		if(x <= a) count++ ;
		else v.push_back(x-a) ;
	}
	sort(v.begin(),v.end()) ;
	for(auto i : v) {
		int val = ceil((double)i/a) ;
		k -= val ;
		if(k < 0) break ;
		else count++ ;
	}
	cout << count ;
	return 0 ;
}


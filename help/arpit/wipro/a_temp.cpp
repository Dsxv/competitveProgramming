#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	vector<int> v = { 5 , 1 , 2 , 3 , 7 , 6} ;
	sort(v.begin() + 2 , v.end()) ;
	for(auto i : v) cout << i << " " ;
	cout << endl ;
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<int> solve(int x){
	vector<int> v ;
	while(x >= 9){
		v.push_back(9) ;
		x -= 9 ;
	}
	if(x) v.push_back(x) ;
	reverse(v.begin(),v.end()) ;
	return v ;
}

int32_t main(){
	int n ;
	cin >> n; 
	vector<vector<int>> v ;
	for(int i = 0 ; i < n ; i++){
		int x ; cin >> x ;
		v.push_back(solve(x)) ;
	}
	for(auto i : v){
		for(auto j : i) cout << j ;
		cout << '\n' ;
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

istream & operator >>(istream& is , vector<int>& v){
	int n; 
	cin >> n ;
	v.resize(n) ;
	for(int i = 0 ; i < n ; i++) cin >> v[i] ;
}

ostream & operator << (ostream &os , vector<int>& v){
	for(auto i : v) cout << i << " " ;
	cout << '\n' ;
}


int32_t main(){
	vector<int> v , t ;
	cin >> v ;
	cout << v ;
	return 0 ;
}


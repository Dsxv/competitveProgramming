#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve2( pair<int,int> a , pair<int,int> b){


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b , c , p , q , r ;
		cin >> a >> b >> c >> p >> q >> r ;
		if(a == p){
			cout << solve2({b,q} , {c,r}) ;
		} else if(b == q){
			cout << solve2({a,p} , {c,r}) ;
		} else if(c == r){
			cout << solve2({c,r} , {a,p}) ;
		} else {
			// 0 case done , 2 pairs cases done
		}
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

const double pi = acos(-1) ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		if(n == 2){
			cout <<fixed << setprecision(7) <<  1 << endl ;
			continue ;
		} else {
			cout << fixed << setprecision(7) <<  1.0/tan(pi/n) << endl ;
		}
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int  t = 1 ;
	while(t--){
		int n;  cin >> n ;
		double r = 0 ;
		while(n){
			r += (1.0/(double)n) ;
			n-- ;
		}
		cout << fixed << setprecision(9) << r ;
		cout << endl ;
	}
	return 0 ;
}


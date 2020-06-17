#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ; cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		int n = i;
		int f = (n*n)*(n*n - 1) / 2 ;
		int s = 2*(n-1)*(n-2) ;
		cout << f - 2*s << '\n';
	}
	return 0 ;
}


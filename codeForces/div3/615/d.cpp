#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int q , m ;
	cin >> q >> m ;
	int a[m] = {} ;
	int k = -1 , ind = 0 ;
	while(q--){
		int x ; cin >> x ;
		a[x%m]++ ;
		while(a[ind] > k) {
			ind = (ind+1)%m ;
			if(ind == 0) k++ ;
		}
		cout << ind + k*m << '\n' ;
	}
	return 0 ;
}


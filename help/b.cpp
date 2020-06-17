#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int i , n ;
	int * p ;
	i = 2 ;
	p = new (nothrow) int[i] ;
	if(p == 0){
		cout << "Eroor" ;
	} else {
		for(n = 0 ; n < i ; n++){
			p[n] = 5 ;
		}
		for(n = 0 ; n < i ; n++){
			cout << p[n] ;
		}
		delete [] p ;
	}
	return 0 ;
}


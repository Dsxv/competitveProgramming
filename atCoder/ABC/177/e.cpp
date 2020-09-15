#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 5 ;
int a[N] ;
int32_t main(){
	int gc = 0 ;
	int n;  cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x = 0 ; cin >> x ;
		a[x]++ ;
		gc = __gcd(gc , x) ;
	}
	if(gc > 1){
		cout << "not coprime" ;
	} else {
		bool found = true; 
		for(int i = 2 ; i < N ; i++){
			int cnt = 0 ;
			for(int j = i ; j < N ; j += i){
				cnt += a[j] ;
			}
			if(cnt > 1){
				found = false ;
				break ;
			}
		}
		if(!found){
			cout << "setwise coprime" ;
		} else {
			cout << "pairwise coprime" ;
		}
	}
	return 0 ;
}


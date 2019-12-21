#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e5 + 20 ;

int pf[N] ;

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
		int l = sqrt(a[i]) ;
		set<int> s ;
		if(a[i]%2 == 0){
			s.insert(2) ;
			while(a[i]%2 == 0) a[i] /= 2 ;
		}
		for(int j = 3 ; j <= l ; j +=2){
			if(a[i]%j == 0) {
				s.insert(j) ;
				while(a[i]%j == 0) a[i]/= j ;
			}
		}
		if(a[i] > 2) s.insert(a[i]) ;
		int mv = 0 ;
		for(auto j : s) mv = max(mv , pf[j]) ;
		for(auto j : s) pf[j] = mv + 1; 
	}
	cout << max(1LL, *max_element(pf,pf+n+1)) ;
	return 0 ;
}


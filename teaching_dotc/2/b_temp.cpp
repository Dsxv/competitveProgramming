#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	// any element x : will occur exactly once
	// let's say element x is stored at index p[x] 
	// f and s
	// f will have to check 0 ... p[x]
	// s will have to check p[x] ... n - 1 (right to left) 
	// i.e., f will have to check p[x] + 1 times
	// s will have to check n - p[x] times
	int n ; cin >> n ;
	int p[n] ;
	// p[i] tells index at which i is stored
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		p[x-1] = i;
	}
	int m ; cin >> m ;
	int f = 0 , s = 0 ;
	while(m--){
		int x ; cin >> x ;
		x-- ;
		f += p[x] + 1;
		s += n - p[x] ;
	}
	cout << f << " " << s ;
	return 0 ;
}


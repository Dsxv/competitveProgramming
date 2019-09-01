#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	int n;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int best = 0 , l = 0 ;
	for(int i = 1 ; i < n  ; i++){
		if(a[i] > a[i-1]) l = i ;
		best = max(best,i-l) ;
	}
	cout << best ;
	return 0 ;
}


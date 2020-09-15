#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	for(int n = 1 ; n <= 8 ; n++){
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		a[i] = i+1 ;
	}
	int cnt = 0 ;
	do{
		int grp = 1 ;
		int cur = a[n-1] ;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(a[i] < cur) grp++ ;
			cur = min(a[i] , cur) ;
		}
		cnt += grp ;
	} while(next_permutation(a , a+n)) ;
	cout << cnt << " "  ;
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n+2] = {} ;
	int p[n+2] = {} ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		a[x]++ ;
		p[x]++ ;
	}
	int mn = 0 , mx = 0 ;
	for(int i = 0 ; i <= n ;){
		if(a[i]){
			a[i+1] += min(1LL , a[i] - 1) ;
			i++ ;
			continue ;
		}
		int x = i ;
		i++ ;
		while(i <= n && a[i] == 1){
			i++ ;
		}
		if(i > n) break ;
		if(!a[i]) continue ;
		a[x]++ ; a[i]-- ;
	}
	for(int i = 0 ; i <= (n+1) ; i++){
		mx += (bool) a[i] ;
	}
	for(int i = 1 ; i <= n ; i++){
		if(!p[i]) continue ;
		mn++ ;
		i += 2 ;
	}
	cout << mn << " " << mx ;
	return 0 ;
}


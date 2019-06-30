#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second
const int N = 1e6 + 1 ;

int bs(pii* a , int n , int x) {
	int l = 0 , r = n-1 , mid ;
	if(x <= a[0].f) return 0 ;
	while(l < r ){
		mid = (l+r)/2 ;
		if(a[mid].f < x) l = mid + 1 ;
		if(a[mid].f == x) return mid ; //ret index+1 as ret from 0
		if(a[mid].f > x) r = mid - 1 ;
	}
	return mid + 1 ; //same
}


int32_t main(){
	int n ;
	cin >> n ;
	pii a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i].f >> a[i].s ;
	}
	sort(a,a+n) ;
	int dp[n] ;
	dp[0] = 1 ;
	for(int i = 1 ; i < n ; i++){
		int p = bs(a,n,a[i].f-a[i].s) ;
		dp[i] = max(dp[i-1] , 1 + p) ;
	}
	cout << dp[n-1] ;
	return 0 ;
}


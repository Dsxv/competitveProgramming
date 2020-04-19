#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e5 + 10 ;
map<int,int> cost[N] ;

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
		int x = a[i] ; 
		int count = 0 ;
		while(x){
			cost[x][count]++ ;
			x /= 2 ;
			count++ ;
		}
		cost[0][count]++ ;
	}
	int ans = INT_MAX ;
	for(int i = 0 ; i < N ; i++){
		int val = 0 , count = 0 ;
		for(auto j : cost[i]){
			if(count + j.second < k) {
				count += j.second ;
				val += j.second*j.first ;
			} else {
				val += (k-count)*j.first ;
				count = k ;
			}
		}
		if(count == k) ans = min(ans,val) ;
	}
	cout << ans ;
	return 0 ;
}


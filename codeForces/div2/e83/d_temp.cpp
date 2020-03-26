#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int * a,  int n){
	int pivot = 0;
	int ind = -1 ;
	for(int i = 1 ; i < n - 1;  i++){
		if(a[i] >= a[i+1] && a[i] >= a[i-1]){
			ind = i ;
			pivot++ ;
		}
	}
	if(pivot == 1) {
		map<int,int> mp ;
		for(int i = 0 ; i <= pivot ; i++){
			if(mp.count(a[i])) return 0 ;
			mp[a[i]]++ ;
		}
		int cnt = 0 ;
		for(int i = pivot+1 ; i < n ; i++){
			cnt += mp.count(a[i]) ;
		}
		return cnt == 1 ;
	}
	return false ;
}

int solve(int* a , int n , int m , int i = 0 ){
	if(i == n){
		return check(a,n) ;
	}
	int ans = 0 ;
	for(int j = 1 ; j <= m ; j++){
		a[i] = j ;
		ans += solve(a,n,m,i+1) ;
	}
	return ans ;
}

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	cout << solve(a,n,m) ;
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

pair<int,int> gf(int n){
	vector<int> v ;
	while(n){
		v.push_back(n%10) ;
		n/=10 ;
	}
	return {v.back(),v[0]} ;
}

int32_t main(){
	int a[11][11] = {} ;
	int n ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i++){
		pair<int,int> p = gf(i) ;
		a[p.first][p.second]++ ;
	}
	int ans = 0 ;
	for(int i = 1 ; i <= 10 ; i++){
		for(int j = 1 ; j <= 10 ; j++){
			ans += a[i][j]*a[j][i] ;
		}
	}
	cout << ans ;
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[m] ;
	for(int i = 0 ; i < m ; i++){
		cin >> a[i] ;
	}
	int suf[m] = {} ;
	for(int i = m - 1 ; i >= 0 ; i--){
		suf[i] = a[i] ;
		if(i < (m-1)) {
			suf[i] += suf[i+1] ;
		}
	}

	int ans[m] ;
	memset(ans, -1 , sizeof(ans)) ;
	int x = -1 ;
	bool found = true ;
	for(int i = 0 ; i < m;  i++){
		if(i + a[i] > n){
			found = false ;
		}
		if(i + suf[i] < n) {
			x = i ;
			break ;
		}
		ans[i] = i ;
	}
	if(x == -1 && found){
		for(int i = 0 ; i < m ; i++) cout << ans[i] + 1 << " " ;
		return 0 ;
	}
	if(!x || !found){
		cout << -1 ;
		return 0 ;
	}
	int id = x;
	while((suf[x] + id) != n) id++ ;
	for(int i = x ; i < m ; i++){
		ans[i] = id ;
		for(int j = 0 ; j < a[i] ; j++) id++ ;
	}
	assert(id == n);
	for(int i = 0 ; i < m ; i++) cout << ans[i] + 1 << " ";
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m , k ;
	cin >> n >> m >> k ;
	vector<int> v[n] ;
	int mxt[n] ;
	memset(mxt , -1 , sizeof(mxt)) ;
	bool a[n] ;
	k-- ;
	a[k] = 1 ;
	int t = 1 ;
	mxt[k] = t ;
	for(int i = 0 ; i < m ; i++){
		int x , y ;
		cin >> x >> y ;
		x-- , y-- ;
		if(a[x]){
			a[y] = 1 ;
			mxt[y] = t ;
			a[x] = 0 ;
		} else if(a[y]){
			a[x] = 1 ;
			mxt[x] = t ;
			a[y] = 0 ;
		}
		v[x].push_back(t) ;
		v[y].push_back(t) ;
		t++ ;
	}
	for(int i = 0 ; i < n ; i++){
		if(~mxt[i]){
			int val = v[i].end() - upper_bound(v[i].begin() , v[i].end() , mxt[i]) ;
			cout << val << " ";
		} else {
			cout << -1 << " " ;
		}
	}
	return 0 ;
}


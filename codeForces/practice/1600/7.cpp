#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	vector<int> v[n] ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		if(a[f] > a[s]){
			v[f].push_back(a[s]) ;
		} else {
			v[s].push_back(a[f]) ;
		}
	}
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += accumulate(v[i].begin(),v[i].end(), 0LL) ;
	}
	cout << sum ;
	return 0 ;
}


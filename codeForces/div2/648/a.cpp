#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int c[m] = {} ;
		int r[n] = {} ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				int x ;
				cin >> x ;
				r[i] += x ;
				c[j] += x ;
			}
		}
		int count = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(!r[i] && !c[j]){
					count++ ;
					r[i]++ ;
					c[j]++ ;
				}
			}
		}
		cout << (count%2?"Ashish\n":"Vivek\n") ;
	}
	return 0 ;
}


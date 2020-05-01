#include <bits/stdc++.h>
using namespace std ;

#define int long long

bool check(int* a , int* col , int n){
	bool found = 0 ;
	for(int i = 1 ; i < n - 1 ; i++){
		found |= a[i] == a[i-1] ;
		col[i] ^= found ;
	}
	return found ;
}
			

int32_t main(){
	int q ;
	cin >> q ;
	while(q--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		int c = 0 ;
		int col[n] ;
		memset(col , -1 , sizeof(col)) ;
		col[0] = 0 ;
		for(int i = 1 ; i < n - 1 ; i++){
			if(a[i] != a[i-1]){
				c ^= 1 ;
			}
			col[i] = c ;
		}
		if(n == 2){
			col[1] = a[0] != a[1] ;
		}
		if(n > 2){
			if(col[0] == col[n-2] || check(a,col,n)){
				col[n-1] = col[0]^1 ;
			} else {
				if(a[n-1] == a[0]) col[n-1] = col[0] ;
				else if(a[n-1] == a[n-2]) col[n-1] = col[n-2] ;
				else {
					col[n-1] = 2 ;
				}
			}
		}
		if(count(a,a+n,a[0]) == n) for(auto &i : col) i = 0 ;
		set<int> s(col,col+n); cout << s.size() << '\n' ;
		for(int i = 0 ; i < n ; i++) cout << col[i] + 1 << ' ' ;
		cout << '\n' ;
	}


	return 0 ;
}


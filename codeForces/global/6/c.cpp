#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int r , c; 
	cin >> r >> c ;
	int a[r] , b[c] ;
	if(r == 1 && c == 1){
		cout << 0 ;
		return 0 ;
	}
	if(r == 1){
		for(int i = 0 ; i < c ; i++) cout << i + 2 << " " ;
		return 0 ;
	}
	if(c == 1){
		for(int i = 0 ; i < r ; i++) cout << i + 2  << '\n' ;
		return 0 ;
	}
	for(int i = 0 ; i < r ; i++) a[i] = i + 1 ;
	for(int i = 0 ; i < c ; i++) b[i] = i + 1 + r ;
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cout << a[i]*b[j] << " " ;
		}
		cout << '\n' ;
	}
	return 0 ;
}


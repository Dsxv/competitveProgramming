#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[10] ;
	int ind = 1 ;
	for(int i = 1 ; i <= 9 ; i++) {
	 	cin  >> a[i] ;
		if(a[i] <= a[ind]) ind = i ; 
	}
	int pmax = n/a[ind] ;
	if(pmax == 0){
		cout << -1 ; return 0 ;
	}
	string s(pmax,ind+'0') ;
	int rem = n%a[ind] ;
	for(int j = 0 ; j < pmax ; j++){
		for(int i = 9 ; i > ind ; i--){
			if(rem - a[i] + a[ind] >= 0) {
				s[j] = (i + '0');
				rem += a[ind] - a[i] ;
				break ;
			}
		}
	}
	cout << s ;
	return 0 ;
}


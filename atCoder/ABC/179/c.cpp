#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e6 + 10 ;
int val[N] ;
int32_t main(){
	for(int i = 1 ; i < N ; i++){
		for(int j = i ; j < N ; j += i){
			val[j]++ ;
		}
	}
	int n;
	cin >> n ;
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++) sum += val[i] ;
	cout << sum ;
	return 0 ;
}


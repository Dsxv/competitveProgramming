#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	for(int i = 0 ; i < n; i++) cin >> a[i] ;
	int sum = accumulate(a,a+n,0LL) ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		if(4*m*a[i] >= sum){
			count++ ;
		}
	}
	cout << (count >= m? "Yes":"No") ;
	return 0 ;
}


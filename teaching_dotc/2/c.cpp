#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[105] = {} ;
	while(m--){
		int x ;
		cin >> x ;
		a[x]++ ;
	}
	sort(a,a+105,greater<int>()) ;
	for(int d = 100 ; d >= 1 ; d--){
		int cnt = 0 ;
		for(int i = 0 ; i < 105 ; i++){
			cnt += a[i] / d ;
		}
		if(cnt >= n) {
			cout << d ;
			return 0 ;
		}
	}
	cout << 0 ;
	return 0 ;
}


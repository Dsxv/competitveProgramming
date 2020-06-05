#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 1e6 + 10 ;
int pre[N] ;
int32_t main(){
	int a , b , c , d ;
	cin >> a >> b >> c >> d ;
	for(int i = a ; i <= b ; i++){
		pre[i+b] += 1 ;
		pre[i+c+1] -= 1 ;
	}
	int sum = 0 ;
	for(int i = 0 ; i < N ; i++){
		sum += pre[i] ;
		pre[i] = sum ;
	}
	for(int i = N - 2 ; i >= 0 ; i--){
		pre[i] += pre[i+1] ;
	}
	int ans = 0 ;
	for(int i = c ; i <= d ; i++){
		ans += pre[i+1] ;
	}
	cout << ans ;
	return 0 ;
}


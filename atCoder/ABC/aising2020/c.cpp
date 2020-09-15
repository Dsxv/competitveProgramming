#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n){
	int l = sqrt(n) ;
	int cnt = 0 ;
	for(int i = 1 ; i <= l ; i++){
		for(int j = 1 ; j <= l ; j++){
			int c = n - i*i - j*j - i*j ;
			if(c <= 0) continue ;
			double d = (i+j)*(i+j) + 4*c ;
			int x = sqrt(d) ;
			if(abs(x*x -d) <= 1e-10){
				x -= (i+j) ;
				if((x > 0) && (x%2 == 0)){
					cnt++ ;
				}
			}
		}
	}
	return cnt ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n;
	cin >> n; 
	for(int i = 1 ; i <= n ; i++){
		cout << solve(i) << '\n' ;
	}
	cout << '\n' ;
	return 0 ;
}


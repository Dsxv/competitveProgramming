#include <bits/stdc++.h>
using namespace std ;

#define int long long

int __lcm(int a , int b){
	return a*b / __gcd(a,b) ;
}

int32_t main(){
	int t; 
	cin >> t ;
	while(t--){
		int n;
		cin >> n ;
		if(n%2 == 0){
			cout << n / 2 << " " << n / 2 << '\n' ;
		} else {
			int l = sqrt(n) ;
			int mval = INT_MAX ;
			int x = 1 ;
			for(int i = 1 ; i <= l ; i++){
				if(n%i) continue ;
				else {
					if(__lcm(i , n - i) < mval){
						mval = __lcm(i , n - i) ;
						x = i ;
					}
					if(i == 1) continue ;
					if(__lcm(n/i , n - n/i) < mval){
						mval = __lcm(n/i , n - n/i) ;
						x = n/i ;
					}
				}
			}
			cout << x << " " << n - x << '\n' ;
		}
	}
	return 0 ;
}


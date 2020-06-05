#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define double long double
double solve(int h , int c , int ta){
	double xh = (ta + 1) / 2 ;
	double xc = xh - 1 ;
	return (xh*h + xc*c) / ta ;
}

int32_t main(){
	int tc ;
	cin >> tc ;
	while(tc--){
		double h , c , t ;
		cin >> h >> c >> t ;
		if(t == h){
			cout << 1 << '\n' ;
			continue ;
		}
		if(t <= (c+h)/2){
			cout << 2 << '\n' ;
		}else{
			int i = (c-t) / (h + c - 2*t) ;
			i = 2*i - 1 ;
			double minval = abs(t-h) ;
			int ans = 1 ;
			for(int j = i - 6; j <= i + 6 ; j += 2){
				if(j <= 2) continue ;
				double x = abs(t-solve(h,c,j)) ;
				if(x < minval){
					ans = j ;
					minval = x ;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0 ;
}



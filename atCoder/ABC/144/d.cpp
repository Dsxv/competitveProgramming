#include <bits/stdc++.h>
using namespace std ;

const double pi = acos(-1) ;

int32_t main(){
	double a , b , x ;
	cin >> a >> b >> x ;
	x /= a;
	double ans ;
	if(a*b/2 < x){
		ans = atan(2*(a*b-x)/(a*a)) ;
	}else{
		ans = atan((b*b)/(2*x)) ;
	}
	cout << fixed << setprecision(10) << (ans*180)/pi ;
	return 0 ;
}


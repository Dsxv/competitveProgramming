#include <bits/stdc++.h>
using namespace std ;

#define int long long

const long double pi = acos(-1) ;

class state{
	public :
	long double x , y ;
	int phi ;
	state(){
		x = 0 , y = 0 , phi = 0 ;
	}
	state(long double a , long double b , int c){
		x = a , y = b , phi = c ;
	}
} ;

void rotate_this(long double & x , long double & y , int phi){
	long double theta = (phi*pi)/3 ;
	long double x1 = x*cos(theta) + y*sin(theta) ;
	long double y1 = -x*sin(theta) + y*cos(theta) ;
	if(x1 > 0 && x1 < 1e-10) x1 = 0 ;
	if(y1 > 0 && y1 < 1e-10) y1 = 0 ;
	x = x1 , y = y1 ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t , n , q ;
	cin >> t ;
	while(t--){
		int n , q ;
		cin >> n >> q ;
		string s ;
		cin >> s;
		s = "x" + s ;
		state a[n+1] ;	
		for(int i = 1 ; i <= n ; i++){
			int d = a[i-1].phi + (s[i]-'0') ;
			long double theta = ((d%6)*(pi))/3 ;
			a[i].x = a[i-1].x + cos(theta) ;
			a[i].y = a[i-1].y + sin(theta) ;
			a[i].phi = d%6 ;
		}
		while(q--){
			int l , r ;
			cin >> l >> r ;
			long double x = a[r].x - a[l-1].x , y = a[r].y - a[l-1].y ;
			rotate_this(x,y,a[l-1].phi) ;
			cout << fixed << setprecision(8) <<  x <<" "<<y << '\n' ;
		}
	}
	return 0 ;
}


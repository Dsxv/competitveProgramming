#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct pts{
	int x , y ;
} ;

int32_t main(){
		int n ;
		cin >> n;
		pts p[n] ;
		for(int i = 0 ; i < n ; i++) cin >> p[i].x >> p[i].y ;
		bool check = true ;
		if(n%2) check = false ;
		for(int i = 0 , j = n/2 ; i < n / 2 - 1 ; j++,i++){
			if(!check) break ;
			int fx = p[i+1].x - p[i].x , fy = p[i+1].y - p[i].y ;
			int cx = p[j].x , cy = p[j].y ;
			cx -= fx ; cy -= fy ;
			if(cx != p[j+1].x || cy != p[j+1].y){
				check = false ;
				break ;
			}
		}
		if(check){
			cout << "YES\n" ;
		} else {
			cout << "NO\n" ;
		}
		
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct pt{
	int x , y , d ;
} ;

bool check(pt a , pt b){
	return a.d < b.d ;
}

string gets(int x , int y){
	string ans = "" ;
	for(int i = 0 ; i < x ; i++) ans += "R" ;
	for(int i = 0 ; i < y ; i++) ans += "U" ;
	return ans ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		pt p[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> p[i].x >> p[i].y ;
			p[i].d = (p[i].x + p[i].y) ;
		}
		sort(p,p+n,check) ;
		pt r ; r.x = 0 , r.y = 0 ;
		bool check = true ;
		string ans = "" ;
		for(int i = 0 ; i < n ; i++){
			if(r.x <= p[i].x && r.y <= p[i].y){
				ans += gets(p[i].x-r.x,p[i].y-r.y) ;
				r.x = p[i].x , r.y = p[i].y ;
			} else {
				check = false ;
			}
		}
		if(check) cout <<"YES\n" << ans << endl ;
		else cout << "NO\n" ;
	}
	return 0 ;
}


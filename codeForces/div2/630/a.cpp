#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a , b , c, d ;
		cin >> a >> b >> c >> d ;
		int x , y , x1 , y1 , x2 , y2 ;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2 ;
		if(x1 == x2){
			if(a || b){
				cout << "No\n" ;
				continue ;
			}
		}
		if(y1 == y2){
			if(c || d){
				cout << "No\n" ;
				continue ;
			}
		}
		if((x-x1+b) < a){
			cout << "No\n" ;
		} else if((x2-x+a) < b){
			cout << "No\n" ;
		} else if((y-y1+d) < c){
			cout << "No\n" ;
		} else if((y2-y+c) < d){
			cout << "No\n" ;
		} else {
			cout << "Yes\n" ;
		}
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

int sum(int n) {
	return n*(n+1)/2 ;
}
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int l , r ;
		cin >> l >> r;
		int s = sum(r) - sum(l-1) ;
		vector<pair<int,int>> power(35,{0,0}) ;
		int i = 0 ;
		for(int i = 0 ; (1LL<<i) <= r ; i++){
			int x = (r - (1<<i))/(2<<i) , y = ((l-1) - (1<<i))/(2<<i) ;
			if(x < 0) x = 0 ;
			if(y < 0) y = 0 ;
			int x1 = r/(1<<i) , y1 = (l-1)/(1<<i);
			if(x1 != 0 && y1 == 0) power[i].first = 1 ;
			power[i].second = x-y ;
		}
		//for(int i = 0 ; i < 20 ; i++) 
			//cout << i << " " << power[i].first << ' ' << power[i].second << endl ;
		for(int i = 0 ; i < 33 ; i++) {
			if(power[i].first == 1) {
				s -= (1<<i) ;
				s-- ;
			}
			s -= (1LL<<i)*(power[i].second) ;
		}
		cout << s << '\n' ;
	}
		
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long
int na , nb , nc ;
int pa , pb , pc ;
int r ;

int check(int x , int a , int b , int c){
	int sum = max(0LL,(a*x - na)*pa) + max(0LL , (b*x - nb)*pb) + max(0LL , (c*x - nc)*pc) ;
	return sum <= r ;
}

int32_t main(){
	string s ;
	cin >> s ;
	int a  = 0, b = 0 , c = 0;
	for(auto i : s){
		a += i == 'B' ;
		b += i == 'S' ;
		c += i == 'C' ;
	}
	cin >> na >> nb >> nc >> pa >> pb >> pc >> r ;
	int lo = 0 , hi = 1e13 ;
	int ans = -1 ;
	//cout << check(2,a,b,c) << endl;
	while(lo <= hi){
		int mid = (lo + hi) / 2 ;
		if(check(mid,a,b,c)) {
			lo = mid + 1 ;
			ans = mid ;
		} else {
			hi = mid - 1 ;
		}
	}
	cout << ans ;
	return 0 ;
}


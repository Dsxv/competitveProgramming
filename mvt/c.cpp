#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int x ;
	cin >> x ;
	for(int t = 1 ; t <= x ; t++){
		string s ;
		cin >> s;
		int count = 0 ;
		int a[4] = {} ;
		for(auto i : s){
			if(i == 'I'){
				if(a[0]){
					assert(a[1] == 0) ;
					a[1]++ ;
				} else {
					a[0]++ ;
				}
			}
			if(i == 'i'){
				if(a[2]){
					assert(a[3] == 0) ;
					a[3]++ ;
				} else {
					a[2]++ ;
				}
			}
			if(i == 'O'){
				if(a[0] || a[3]){
					if(a[0]){
						count++ ;
						a[0]-- ;
					} else {
						a[3]--;
					}
				} else {
					assert(a[2]) ;
					a[2]-- ;
				}
			}
			if(i == 'o'){
				if(a[1] || a[2]){
					if(a[1]){
						a[1]-- ;
					} else {
						a[2]-- ;
					}
				} else {
					assert(a[0]) ;
					a[0]-- ;
				}
			}
		}
		printf("Case #%d: %d\n",t,count) ;
	}
	return 0 ;
}


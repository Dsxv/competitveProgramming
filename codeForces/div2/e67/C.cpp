#include <bits/stdc++.h>
using namespace std ;

using pii = pair<int,int> ;
using pll = pair<long,long> ;
using umpii = unordered_map<int,int> ;
using mpii = map<int,int> ;

#define f first
#define s second

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n] ;
	memset(a,-1,sizeof(a)) ;
	while(m--){
		int t , l , r ;
		cin >> t >> l >> r ;
			l-- , r-- ;
			if(!found) continue ;
		if(t){
			if(ndec(a,l,r)){
				
			}else{
				found =false ;
			}
		}else{
			if(dec(a+l,a+r,check1)){
			}else{
				found = false ;
			}
		}
	}
	if(!found){
		cout << "NO";
	}else{
		cout << "YES" ;
		for(int i = 0 ; i < n ; i++) cout << a[i] <<" " ;
	}
	return 0 ;
}


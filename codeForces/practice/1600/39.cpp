#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , q ;
	cin >> n >> q ;
	int ts = 0 ;
	set<int> a[n+1] = {} ;
	int dt = 0 ;
	queue<pair<int,int>> qr ;
	for(int j = 0 ; j < q ; j++){
		int t , x ;
		cin >> t >> x ;
		if(t == 1){
			a[x].insert(j) ;
			qr.push({x,j}) ;
			ts++ ;
		} else if(t == 2){
			ts -= a[x].size() ;
			a[x].clear() ;
		} else {
			if(x > dt){
				for(int i = dt ; i < x ; i++){
					int ind = qr.front().first , fr = qr.front().second  ;
					qr.pop() ;
					if(a[ind].count(fr)){
						a[ind].erase(fr) , ts-- ;
					}
				}
				dt = x ;
			}
		}
		cout << ts << endl ;
	}

	return 0 ;
}


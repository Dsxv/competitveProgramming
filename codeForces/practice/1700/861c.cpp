#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m;
	int a[n][m] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
		}
	}
	int x = *min_element(a[0],a[0]+m) ;
	vector<pair<string,pair<int,int>>> v ;
	bool ok = false ;
	int cnt = 0 ;
	int bc = INT_MAX ;
	for(int k = 0 ; k <= x ; k++){
		vector<pair<string,pair<int,int>>> tpv; 
		int temp[n][m] ;
		bool found = true ;
		cnt = 0 ;
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				temp[i][j] = a[i][j] - (a[0][j] - k) ;
			}
			if(count(temp[i],temp[i]+m,temp[i][0]) != m || temp[i][0] < 0) found = false ;
			else {
				tpv.push_back({"row",{temp[i][0],i}}) ;
				cnt += temp[i][0] ;
			}
		}
		if(!found){
			tpv.clear() ;
		} else {
			for(int j = 0 ; j < m ; j++){
				tpv.push_back({"col",{a[0][j]-k,j}}) ;
				cnt += a[0][j] - k ;
			}
			tpv.push_back({"row",{k,0}}) ;
			cnt += k ;
			ok = true ;
			if(cnt < bc){
				v = tpv;
				bc = cnt ;
			}
		}
	}
	if(!ok){
		cout << -1 ;
		return 0 ;
	}
	cout << bc << endl ;
	for(auto i : v){
		for(int j = 0 ; j <  i.second.first ; j++){
			cout << i.first << " " << i.second.second + 1 << '\n' ;
		}
	}
		
	return 0 ;
}
for(int i = 0 ; i < n ; i++){
	cout << i << " " ;
}

cout << endl ;

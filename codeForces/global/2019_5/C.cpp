#include <bits/stdc++.h>
using namespace std ;

using ll = long long ;



class points{
	public :
	int x , y , z , ind ;
} ;

bool solve(points a , points b){
	return a.z < b.z ;
}

int main(){

	map<int,map<int,vector<points>>> pts ;
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		points a ;
		cin >> a.x >> a.y >> a.z ;
		a.ind = i + 1 ;
		pts[a.x][a.y].push_back(a) ;
	}
	int ans = -1;
	for(auto first_map : pts){
		int old = - 1 ;
		for(auto second_map : first_map.second){
			vector<points>& v = second_map.second ;
			sort(v.begin() , v.end() , solve) ;
			for(int i = 0 ; i < v.size() - 1; i += 2 ){
				cout << v[i].ind <<" "<< v[i+1].ind << '\n' ;
			}
			if(v.size() % 2){
				if(old != -1){
					cout << v[v.size()-1].ind <<" " << old << '\n';
					old = -1 ;
				}else{
					old = v[v.size()-1].ind ;
				}
			}
		}
		if(old != -1){
			if(ans == -1) ans = old ;
			else {
				cout << old << " " << ans << '\n' ;
				ans = -1 ;
			}
		}
	}
	return 0 ;
}


#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int inf = INT_MAX ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int t ;
	cin >> t ;
	while(t--) {
		int n ;
		cin >> n ;
		map<int,int> mp[n] ;
		int edges[n-1] , vertex[n] ;
		int curdeg[n] = {};
		for(int i =  0 ; i < n - 1 ; i++){
			int f ,s , v;
			cin >> f >> s >> v ;
			f-- , s-- ;
			edges[i] = v ;
			mp[f][s] = 0 ;
			mp[s][f] = 0 ;
		}
		multiset<pair<int,int>> s ;
		// first element is deg
		// second element is index 
		for(int i = 0 ; i < n ; i++){
			s.insert({mp[i].size(),i}) ;
			curdeg[i] = mp[i].size() ;
		}
		sort(edges,edges+n-1) ;
		for(int i = 0 ; i < n ; i++){
			cin >> vertex[i] ;
		}
		sort(vertex,vertex+n) ;
		int count = 0 ;
		int j = 0 ;
		for(int i = 0 ; i < n ; i++){
			int deg = s.begin()->first , start = s.begin()->second ;
			//printf("deg : %lld , start : %lld \n",deg,start) ;
			int counter = j ;
			bool ok = true ;
			for(auto e : mp[start]){
				if(e.second == 0) {
					if(vertex[i] < edges[counter]) {
						ok = false ;
						break ;
					}
					counter++ ;
				}
			}
			if(!ok){
				count++ ; continue  ;
			}

			s.erase(s.begin()) ;
			for(auto e : mp[start]){
				if(e.second == 0) {
					int sc = e.first ;
					mp[start][sc] = edges[j] ; 
					mp[sc][start] = edges[j++] ;
					int d = curdeg[sc] ;
					curdeg[sc]-- ;
					s.erase({d,sc}) ;
					s.insert({d-1,sc}) ;
				}
			}
			//cout << "looped\n" ;
			//for(int k = 0 ; k < n ; k++){
				//for(auto j : mp[k]) 
					//cout <<k <<" "<< j.first <<" : " << j.second << endl ; 
			//}
		}
		
		cout << count << '\n' ;
	}
	return 0 ;
}



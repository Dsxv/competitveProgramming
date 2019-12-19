#include <bits/stdc++.h>
using namespace std ;

#define int long long

int s1(vector<int>& a , int n , int x){
	int lo = 0 , hi = n-1 ;
	while(lo <= hi){
		int mid = (lo + hi ) / 2 ;
		if(a[mid] < x) {
			return 1 ;
		} else {
			hi = mid - 1 ;
		}
	} 
	return 0 ;
}

int solve(vector<pair<int,int>>& v , int n ){
	vector<int> st , en ;
	for(auto i : v) {
		st.push_back(i.first) ;
		en.push_back(i.second) ;
	}
	sort(st.begin(),st.end() , [](int a , int b){ return a < b ; }) ;
	sort(en.begin() , en.end() , [](int a , int b) { return a < b ;}) ;
	int count = 0 ;
	int ans = INT_MAX ;
	int i = 0 , j = 0 ;
	//int x = 
	//int c1 = s1(en,n,x) ;
	//int c2 = (st.end()) - upper_bound(st.begin(),st.end(),x) ;
	
	while(i < n && j < n){
		int x ;
		if(st[i] < en[j]) {
			x = st[i++] ; count++ ;
		} else {
			x = en[j++] ; count-- ;
		}
		int c1 = s1(en,n,x) ; // pts ending before x
		int c2 = (st.end()) - upper_bound(st.begin(),st.end(),x) ;
		// pts ending after x
		int k2 = upper_bound(st.begin(),st.end(),x) - 
				lower_bound(st.begin(),st.end(),x) ; // pts starting at x
		int k1 = upper_bound(en.begin(),en.end(),x) -
				lower_bound(en.begin(),en.end(),x) ; // pts ending at x

		//cout <<x <<":"<< c1 << " " << c2 <<" " << k1 << " " << k2 << endl ;
		if((c1+c2)*(c1+k1)*(c2+k2) == 0) continue ;
		if(c1 == 0){
			ans = min(ans,count+k2) ; // can't remove left pts srry :(
		}
		else if(c2 == 0){
			ans = min(ans,count+k1) ; // can't remove right pts srry :(
		} else{
			ans = min(ans , count + min(k1,k2)) ;
		}
	}
	if(ans == INT_MAX) return -1 ;
	else return ans ;
}

			

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<pair<int,int>> v(n) ;
		for(int i = 0 ; i < n ; i++) 
			cin >> v[i].first >> v[i].second ;
		cout << solve(v,n) ;
		cout << '\n' ;
	}
	return 0 ;
}


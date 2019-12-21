#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(string & a , map<string,int> & mp){
	for(int i = 0 ; i < a.size() ; i++){
		if(a.size() % (i+1) == 0) {
			string temp = a.substr(0,i+1) ;
			string check = "";
			for(int j = 0 ; j < a.size()/(i+1) ; j++)
				check += temp ;
			//cout << i << " " << check << " " << a.size() << endl ;
			if(check == a) mp[temp]++ ;
		}
	}
}

int32_t main(){
	string a , b ;
	cin >> a >> b ;
	map<string,int> mp ;
	solve(a,mp) ;
	solve(b,mp) ;
	int count = 0 ;
	for(auto i : mp) count += i.second == 2 ;
	cout << count ;
	return 0 ;
}


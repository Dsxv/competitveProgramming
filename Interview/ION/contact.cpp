#include <bits/stdc++.h>
using namespace std ;

#define int long long

vector<vector<int>> g ;

class Person{
	public :
		string phone , name ;
		Person(){
		}
		Person(string p , string n){
		}
} ;

int getIndex(Person &p){
	return mp[p.phone] ;
}

// visited = { A , B , C , D , E  } ;

void solve(int currentPerson , vector<string>& phoneContacts){
	visited[currentPerson] = 1 ;
	phoneContacts.push_back(p[currentPerson].name) ;

	for(auto person : g[x]){
		// persons that have  
		if(visited[person]) continue ;
	   // D is called 
		solve(person , phoneContacts) ;
	}
}

int32_t main(){
	unordered_map<string,int> mp ;
	int n; 
	g.resize(n) ;
	for(int i = 0 ; i < n ; i++){
		Person p ;
		cin >> p.phone ;
		int numberofContacts ;
		cin >> numberofContacts ;
		for(int i = 0 ; i < numberofContacts ; i++){
			Person temp ;
			cin >> temp.phone ;
		}
	}
	vector<string> phoneContacts ;
	vector<int> visited(n) ;
	solve(getIndex(p) , phoneContacts) ;
	for(auto i : phoneContacts) cout << i << " " ;
	return 0 ;
}


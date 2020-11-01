#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Queue{
	stack<int> st1 , st2 ;
	//st1 -> main stack
	Queue(){
	}
	void push(int data){
		st1.push(data) ;
	}

	int pop(){
		if(st1.empty()){
			cout << "Invalid" ;
			return -1 ;
		}
		while(st1.size()){
			st2.push(st1.top()) ;
			st1.pop() ;
		}
		// now I know that the top element is bottom most element of st1
		int data = st2.top() ;
		st2.pop() ;
		while(st2.size()){
			st1.push(st2.top()) ;
			st2.pop() ;
		}
		return data ;
	}
} ;

int32_t main(){
	Queue q ;
	int n ; cin >> n ;
	while(n--){
		int t ;
		cin >> t ; // tells type of operation 
		if(t == 1){ // push element
			int x ;
			cout << "Enter element :" ; cin >> x ;
			q.push(x) ;
		} else {
			cout << "Popped element :" ;
			cout << q.pop() << endl ;
		}
	}
	return 0 ;
}


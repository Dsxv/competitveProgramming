#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Node{
	Node *next ;
	int data ;
	Node(int x){
		next = NULL ;
		data = x ;
	}
} ;

void print(Node *head){
	Node *cur = head ;
	while(cur){
		cout << cur->data << " " ;
		cur = cur->next ;
	}
	cout << endl ;
}

Node* helper(Node* head , int val){
    Node dummy(-1) ;
    dummy.next = head ;
    Node *prev = &dummy , *cur = &dummy;
    
    while(cur->next){
        if(cur->next->data == val){
            Node *l1 = prev->next , *l2 = prev->next->next ;
            Node *r1 = cur->next , *r2 = cur->next->next ;
            if(l2 == r1){
                l1->next = r2 ;
                r1->next = l1 ;
                prev->next = r1 ;
				cur = r1 ;
            } 
			//else {
                //prev->next = r1 ; cur->next = l1 ;
                //l1->next = r2 ; r1->next = l2 ;
            //}
            prev = prev->next ;
        }
        cur = cur->next ;
    }
    
    // prev->next = helper(prev->next , 1) ;
    return dummy.next ;
}

Node* insert(Node* head){
	int x ; cin >> x ;
	Node *temp = new Node(x) ;
	if(!head){
		head = temp ;
		return head;
	}
	Node *cur = head ;
	while(cur->next) cur = cur->next ;
	cur->next = temp ;
	return head ;
}


int32_t main(){
	Node *head = NULL ;
	int n ; 
	cin >> n ;
	while(n--){
		head = insert(head) ;
	}
	head = helper(head , 0) ;
	print(head) ;
	return 0 ;
}


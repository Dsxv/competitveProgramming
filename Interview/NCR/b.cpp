#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct Node{
	int data ;
	Node *next ;
	Node(int x){
		data = x ;
		next = NULL ;
	}
} ;

Node *insert(Node *head , int x){
	if(head == NULL) {
		head = new Node(x) ;
		return head ;
	}
	Node *cur = head ;
	while(cur->next){
		cur = cur->next ;
	}
	cur->next = new Node(x) ;
	return head ;
}

Node *mergeList(Node *head1 , Node *head2){
	if(!head1) return head2 ;
	if(!head2) return head1 ;
	if(head1->data < head2->data){
		head1->next = mergeList(head1->next , head2) ;
		return head1 ;
	} else {
		head2->next = mergeList(head1 , head2->next) ;
		return head2 ;
	}
}

Node *sortLinkedList(Node *head){
	if(head == NULL || head->next == NULL) return head ;
	Node dummy(-1) ;
	dummy.next = head ;
	Node *fast = &dummy , *slow = &dummy ; 
	while(fast && fast->next){
		fast = fast->next->next ;
		slow = slow->next ;
	}
	Node *temp = slow->next ; // starting for 2nd linked list
	slow->next = NULL ;
	return mergeList(sortLinkedList(head) , sortLinkedList(temp)) ;
}

void print(Node *head){
	while(head){
		cout << head->data << " " ;
		head = head->next ;
	}
	cout << endl ;
}

Node *removeDuplicates(Node *head){
	Node* newHead = head ;
	Node* cur = head->next ;
	while(cur){
		Node *temp = cur->next ;
		if(newHead->data == cur->data){
			delete cur ;
		} else {
			newHead->next = cur ;
			newHead = cur ;
		}
		cur = temp ;
	}
	return head ;
}

int32_t main(){
	int ar[10] = {1 , 3 , 2 , 5 , 2 , 7 , 1 , 3 , 6 , 6} ;
	Node *head = NULL ;
	int n = 10 ;
	for(int i = 0 ; i < n ; i++){
		head = insert(head , ar[i]) ;
	}
	
	head = sortLinkedList(head) ;

	cout << "Before Duplicate Removal : " ;
	
	print(head) ;
	// now I have a sorted linked list
	// 1 , 2 , 2 , 3 , 5 , 5 , 7 , 7
	head = removeDuplicates(head) ;
	// answer
	cout << "After " ;
	print(head) ;
	return 0 ;
}


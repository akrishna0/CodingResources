#include<iostream>
using namespace std;
#include "node.cpp"

node *takeinput(){
	int data;
	cin>>data;
	node *head = NULL;
	while(data != -1){
		node *newnode = new node(data);
		if(head == NULL){
			head = newnode;
		}else{
			node *temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newnode;
		}
		cin>>data;
	}
	return head;
}

node *takeinput2(){
	int data;
	cin>>data;

	node *head = NULL;
	node *tail = NULL;

	while(data != -1){
		node *newnode = new node(data);

		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = tail->next;
		}
		cin>>data;
	}
	return head;
}

void print(node *head){
	node *temp = head;
	while(temp != NULL){
		cout<< temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

node * insertElement(node* head ,int i, int data){
	node * newnode = new node(data);

	if(i == 0){
		newnode->next = head;
		head = newnode;
		return head;
	}

	int count = 0;
	node *temp = head;
	while(temp != NULL && count < i-1){
		temp = temp->next;
		count++;
	}
	if(temp != NULL){
	newnode->next = temp->next;
	temp->next = newnode;
	}
	return head;
}

node * deleteElement(node *head,int i){

	if(i == 0){
		node *temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	int count = 0;
	node *temp = head;
	while(temp != NULL && count < i-1){
		temp = temp->next;
		count++;
	}
	if(temp != NULL){
	node * hold = temp->next;
	temp->next = hold->next;
	delete hold;
	}
	return head;

}

node* insertRecursively(node *head,int i, int data){
	if(head == NULL)return NULL;

	if(i == 0){
		node *newnode =  new node(data);
		newnode->next = head;
		head = newnode;
		return head;
	}else{
                node* x = insertRecursively(head->next, i-1, data);
		 head->next = x;
	}
	return head;
}

node * deleteRecursively(node* head, int i){
	if(head == NULL) return NULL;

	if(i == 0){
		node *temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	else{
		node * x = deleteRecursively(head->next, i-1);
		head->next = x;

	}
	return head;
}

int midOfLinkedList(node* head){
	if(head == NULL)return 0;

	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}

node* mergeSort(node* h1, node* h2){
	node* fH = NULL;
	node* fT = NULL;
	if(h1 == NULL && h2 != NULL){
		return h2;
	}else if(h1 != NULL && h2 == NULL){
		return h1;
	}

	if(h1->data < h2->data){
		fH = h1;
		fT = h1;
		h1 = h1->next;
	}else{
		fH = h2;
		fT = h2;
		h2 = h2->next;
	}
	while(h1 != NULL && h2 != NULL){
		if(h1->data < h2->data){
			fT->next = h1;
			fT = h1;
			h1 = h1->next;
		}else{
			fT->next = h2;
			fT = h2;
			h2 = h2->next;
		}
	}

	if(h1 != NULL){
		if(fH == NULL){
			fH = h1;
			fT = h1;
		}
		fT->next = h1;

	}
	else if(h2 != NULL){
		if(fH == NULL){
			fH = h2;
			fT = h2;
		}
		fT->next = h2;
	}
	return fH;
}

node * mergesortLL(node* head){
	if(head == NULL || head->next == NULL)
		return head;

	node *slow = head;
	node *fast = head->next;
       while(fast != NULL && fast->next != NULL){
	       slow  = slow->next;
	       fast = fast->next->next;
       }
         node * h2 = slow->next;
	      slow->next = NULL;

       node* head1 = mergesortLL(head);
       node* head2 = mergesortLL(h2);

      return  mergeSort(head1,head2);

}

node* reverseLL(node* head){
	if(head == NULL || head->next == NULL)
		return head;

	node* small = reverseLL(head->next);

	node* temp = small;
        while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;

	return small;
}

class Pair{
	public:
	node* head;
	node* tail;
};

Pair reverseLinkedList(node* head){
	if(head == NULL || head->next == NULL){
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}

	Pair small = reverseLinkedList(head->next);

	small.tail->next = head;
	head->next = NULL;

	Pair ans;
	ans.head = small.head;
	ans.tail = head;

	return ans;
}

node* reverseLLBetter(node* head){
	return reverseLinkedList(head).head;
}

int main(){
	node *head = takeinput2();

	node* h =reverseLLBetter(head);
	print(h);
}

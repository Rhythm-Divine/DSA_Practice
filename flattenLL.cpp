 #include<bits/stdc++.h>
 using namespace std;
 
  struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

    
      Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* l1=new Node(0);
        Node* head=l1;
        while(list2 && list1){
        if(list1->data<=list2->data){
            l1->bottom=list1;
            l1=l1->bottom;
            list1=list1->bottom;
        }else{
            l1->bottom=list2;
            l1=l1->bottom;
            list2=list2->bottom;
        }
        }
        while(list1){
             l1->bottom=list1;
            l1=l1->bottom;
            list1=list1->bottom;
        }
        while(list2){
            l1->bottom=list2;
            l1=l1->bottom;
            list2=list2->bottom;
        }
        return head->bottom;
    }
Node *flatten(Node *root)
{
   if(!root){
       return NULL;
   }
   if(!root->next){
       return root;
   }
   root->next=flatten(root->next);
   root=mergeTwoLists(root,root->next);
   return root;
   
}
int main(){
     Node *l1=new Node(5);
    Node *l2=new Node(10);
    Node *l3=new Node(19);
    Node *l4=new Node(28);

    l1->next=l2;
    l2->next=l3;
    l3->next=l4;
    l4->next=NULL;

    Node *l1b1=new Node(7);
    Node *l1b2=new Node(8);
    Node *l1b3=new Node(30);
    l1->bottom=l1b1;
    l1->bottom->bottom=l1b2;
    l1->bottom->bottom->bottom=l1b3;

     Node *l2b1=new Node(20);
    l2->bottom=l2b1;

     Node *l3b1=new Node(22);
     Node *l3b2=new Node(50);
   
    l3->bottom=l3b1;
    l3->bottom->bottom=l3b2;

    Node *l4b1=new Node(35);
    Node *l4b2=new Node(40);
    Node *l4b3=new Node(45);
    l4->bottom=l4b1;
    l4->bottom->bottom=l4b2;
    l4->bottom->bottom->bottom=l4b3;
    
    Node *ans=flatten(l1);

    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->bottom;
    }
  
}


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100

void create_stake();

void create_ll();
struct node_ll *insert_ll_first(struct node_ll *start);
struct node_ll *insert_ll_n(struct node_ll *start);
struct node_ll *insert_ll_end(struct node_ll *start);
void display_ll(struct node_ll* start);
int search_ll_index(struct node_ll *start);
int get_ll_element(struct node_ll *start);
struct node_ll* delete_ll_start(struct node_ll *start);
struct node_ll* delete_ll_end(struct node_ll *start);
struct node_ll* del_ll_n(struct node_ll *start);
void display_ll_reverse(struct node_ll *start);
struct node_ll* reverse_ll(struct node_ll *start);

void create_BST();
struct BST_node* insert(struct BST_node *root, int data);
void preorder(struct BST_node *root);
void inorder(struct BST_node *root);
void postorder(struct BST_node *root);
struct BST_node* BST_find(struct BST_node* root, int data);
struct BST_node* BST_delete(struct BST_node* root, int data);
struct BST_node* BST_findMax(struct BST_node* root);

void create_array();
int insert_array(int arr[]);
void display_array(int arr[],int size);
int linear_search(int arr[],int size);
int binary_search(int arr[],int size);
void bubble_sort(int arr[], int size);
int delete_array(int arr[],int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void quick_sort(int arr[],int p, int r);
int quicksort_partition(int arr[], int p, int r);
void merge(int arr[],int p, int q, int r);
void merge_sort(int arr[], int p, int r);
//===================================================Stack=========================================================

/*
struct stack{
	int top;
	int max;
	int data[10];
};

void push(struct stack *s){
	int num;
	system("cls");
	printf("\nEnter a number to insert: ");
	scanf("%d",&num);
	if(s->top<=10)
		s->data[++(s->top)];
	else
		printf("\nOverFlow");
}

int pop(struct stack *s){
	int num;
	if(s->top==-1){
		printf("\nUnderflow");
	}
	else{
		num = s->data[(s->top)--];
	}
	return num;
}

int peek(struct stack *s){
	int num;
	if(s->top==-1){
		printf("\nUnderflow");
	}
	else{
		num = s->data[s->top];
		printf("\npeeked:%d",s->data[s->top]); getch();
	}
	return num;
}



void create_stack(){
	struct stack s;
	int choice;
	char con='y';
	s.top=-1; s.max=10;
	
	while(con=='y'||con=='Y'){
		system("cls");
		printf("\t1:Push into stack");
		printf("\t2:Pop from stack");
		printf("\t3:peek the stack");
		
		printf("\nEnter your choice:"); scanf("%d",&choice);
		switch(choice){
			case 1: push(&s);
					break;
			case 2: pop(&s);
					break;
			case 3: peek(&s);
					break;
			default: printf("\nInvalid choice"); break;
		}	
	}
	
}
*/
//================================================ End of stack ====================================================================

/*
//==================================================Linked List====================================================

struct node_ll{
	int data;
	struct node_ll* next;
};


//delete nth element from linked list
struct node_ll* del_ll_n(struct node_ll *start){
	int index,i;
	struct node_ll *trav=start;
	system("cls");
	printf("\nEneter the index: "); scanf("%d",&index);
	if(index=0){
		start = delete_ll_start(start);
	}
	for(i=0;i<index-1;i++){
		trav=trav->next;
	}
	trav->next=(trav->next)->next;
	
	return start;
}


//reverse linked list
struct node_ll* reverse_ll(struct node_ll *start){
	struct node_ll *pre, *nxt, *current;
	pre=NULL;
	nxt=start; current=start;
	while(current!=NULL){
		nxt=current->next;
		current->next=pre;
		pre=current;
		current=nxt;
	}
	start= pre;
	return start;

//	struct node_ll *temp;
//	if(start->next==NULL){
//		return start;
//	}
//	reverse_ll(start->next);
//	(start->next)->next=temp;
//	temp=NULL;	
}

//display linked list in reverse

void display_ll_reverse(struct node_ll *start){
	struct node_ll *temp=start;
	if(temp->next!=NULL){
		display_ll_reverse(temp->next);		
	}
	printf("%d ",temp->data);
}

//Delete fro end
struct node_ll* delete_ll_end(struct node_ll *start){
	struct node_ll *trav = start;
	struct node_ll *t;
	if(start==NULL){
		printf("\nUnderflow");
	}
	if(trav->next==NULL){
		start=NULL;
	}
	while(trav->next!=NULL){
		t=trav;
		trav=trav->next;
	}
	t->next=NULL;
	return start;
}
//Delete Linked ist from start
struct node_ll* delete_ll_start(struct node_ll *start){
	if(start==NULL){
	}
	else{
		start = start->next;
	}
	return start;
}

//Get element at particular index
int get_ll_element(struct node_ll *start){
	int num,index,i;
	system("cls");
	printf("\nEnter a index element to return: ");
	scanf("%d",&index);
	struct node_ll *trav = start;
	
	for(i=0;i<index;i++){
		trav=trav->next;
		if(trav==NULL){
			printf("\nCould not find data"); getch();
		}
		
	}
	printf("\nElement found at index %d: %d",index,trav->data); getch();
}

//search index of specified element
int search_ll_index(struct node_ll *start){
	int num,index=0;
	system("cls");
	printf("\nEnter a number to search");
	scanf("%d",&num);
	
	struct node_ll *trav = start;
	while(trav!=NULL){
		if(trav->data==num){
			printf("\nFound %d at index:%d",num,index); getch();
			return index;
		}
		else{
			trav=trav->next;
			index++;
		}
		if(trav==NULL){
			printf("\n%d does not exist",num); getch();
		}
	}
}
//Add element in linked list at end
struct node_ll *insert_ll_end(struct node_ll *start){
	int num;
	system("cls");
	printf("\nEnter a number to insert at last position ");
	scanf("%d",&num);
	
	struct node_ll *temp = (struct node_ll *)malloc(sizeof(struct node_ll));
	temp->data=num;
	temp->next=NULL;
	if(start==NULL){
		start=temp;
	}
	else{
		struct node_ll *trav;
		trav = start;
		while(trav->next!=NULL){
			trav=trav->next;
		}
		trav->next=temp;
	}
	return start;
}

//Display linked list
void display_ll(struct node_ll* start){
	system("cls");
	if(start==NULL){
		printf("List is empty\n");
	}
	else{
		struct node_ll *temp = (struct node_ll *)malloc(sizeof(struct node_ll));
		temp=start;
		printf("Linked list: [ ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("]");
	}
	printf("\nPress Enter to return"); getch();
}

struct node_ll *insert_ll_n(struct node_ll *start){
	int pos, num,i;
	system("cls");
	printf("\nEnter the postion"); scanf("%d",&pos);
	struct node_ll *trav;
	trav = start;
	
	for(i=1;i<=pos;i++){
		if(pos==1){
			start=insert_ll_first(start);
		}
		if(i==pos-1){
			printf("\nEnter the number to add"); scanf("%d",&num);
			struct node_ll *temp = (struct node_ll *)malloc(sizeof(struct node_ll));
			temp->data=num;
			temp->next=trav->next;
			trav->next=temp;
		}
		else if(trav==NULL){
			printf("\nInvalid index");getch();
			break;
		}
		trav=trav->next;
	}
	return start;
}

struct node_ll *insert_ll_first(struct node_ll *start){
	int num;
	system("cls");
	printf("\nEnter a number to insert at first position ");
	scanf("%d",&num);
	
	struct node_ll *temp = (struct node_ll *)malloc(sizeof(struct node_ll));
	temp->data=num;
	
	if(start==NULL){
		temp->next=NULL;
		start=temp;
	}
	else{
	temp->next=start;	
	start=temp;	
	}
	
	
	return start;
}

void create_ll(){
	char con='y';
	int choice;
	struct node_ll *start = NULL;
	
	while(con=='y'||con=='Y'){
		system("cls");
		printf("Select operation for linked list\n");
		printf("\t1:Insert at first");
		printf("\t2:Insert at n postion");
		printf("\t3:Insert at End\n");
		printf("\t4:Display the List");
		printf("\t5:Search an element");
		printf("\t6:Find the nth element\n");
		printf("\t7:Delete from begning");
		printf("\t8:Delete from End");
		printf("\t9:Delete nth element\n");
		printf("\t10:Display in reverse order");
		printf("\t11: Reverse the list\n");
		printf("\t100: Back to main menu.");
		
		printf("\nSelect a data structure to create: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: start = insert_ll_first(start);
					break;
			
			case 2: start = insert_ll_n(start);
					break;	
			case 3: start = insert_ll_end(start);
					break;		
			case 4: display_ll(start);		
					break;
			case 5: search_ll_index(start);
					break;
			case 6: get_ll_element(start);
					break;
			case 7: start=delete_ll_start(start);
					break;
			case 8: start=delete_ll_end(start);
					break;
			case 9: start=del_ll_n(start); 
					break;		
			case 10: system("cls"); 
					 printf("Linked list in reverse order: \n[ "); 
					 display_ll_reverse(start); 
					 printf("]");
					 getch();
					break;
			case 11: start=reverse_ll(start);
						break;
			case 100:
						return;
					
		}	
	}
}

*/
//===================================================End of Linked List=================================================


/*
//================================================== Binary Search Tree ================================================

struct BST_node{
	int data;
	struct BST_node *left;
	struct BST_node *right;
};


struct BST_node* BST_findMax(struct BST_node* root){
	while(root->right!=NULL)
		root=root->right;
	return root;	
}
struct BST_node* BST_delete(struct BST_node* root, int data){
	if	(root==NULL){
		printf("\nNot Found");
		
	}
		
	else if(data<root->data){
		root->left=BST_delete(root->left,data);
	}
	else if(data>root->data){
		root->right=BST_delete(root->right,data);
	}
	else{
		if(root->right && root->left){
			struct BST_node *temp;
			temp= BST_findMax(root->left);
			root->data=temp->data;
			root->left=BST_delete(root->left,temp->data);
		}
		else{
			struct BST_node *del=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right==NULL)
				root=root->left;
			free(del);
		}
	}
	return (root);
}

struct BST_node* BST_find(struct BST_node* root, int data){
	if(root==NULL){
		printf("Element not found");
		return NULL;
	}
	else if(data<root->data){
		root=BST_find(root->left,data);
	}
	else if(data>root->data){
		root=BST_find(root->right,data);
	}
	return root;
}

void postorder(struct BST_node *root){
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void inorder(struct BST_node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(struct BST_node *root){
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

struct BST_node* insert(struct BST_node *root, int data){
	struct BST_node *temp = (struct BST_node *)malloc(sizeof(struct BST_node));
	temp->data = data;
		
	if(root==NULL){
		root=temp;
		temp->left=NULL;
		temp->right=NULL;
	}
	else if(data<root->data){
		root->left=insert(root->left, data);
	}
	else{
		root->right=insert(root->right,data);
	}
	return root;		
}


void create_BST(){
	char con = 'y';
	int data;
	int choice;
	struct BST_node *root=NULL;
	
	while(con =='y'||con=='Y'){
		system("cls");
		printf("\t1:Insert");
		printf("\t2:Find");
		printf("\t3:Delete\n");
		printf("\t4:Preorder View");
		printf("\t5:Inorder view");
		printf("\t6:Postorder view\n");
		printf("\t7:Level Order view");
		printf("\t8:Breadth First Search");
		printf("\t9:Depth First Search\n");
		printf("\t100: Return to main menu");
		
		printf("\nSelect a data structure to create: ");
		scanf("%d",&choice);
		
		switch(choice){
		case 1:
				printf("\nEnter a  number to add: "); scanf("%d",&data);
				root = insert(root,data);
				break;
		case 2: 
				printf("\nEnter a number to search: "); scanf("%d",&data);
				struct BST_node *search_node;
				search_node = BST_find(root,data);
				if(search_node){
					printf("\nFound %d",search_node->data);	
				}
				getch();
				break;
		
		case 3: printf("\nEnter a number to delete: "); scanf("%d",&data);
				root=BST_delete(root,data);	
				break;
						
		case 4: 
				printf("\nPreorder traversal: ");
				preorder(root); 
				getch();
				break;

		case 5: 
				printf("\nIneorder traversal: ");
				inorder(root); 
				getch();
				break;
		
		case 6: 
				printf("\nIneorder traversal: ");
				postorder(root); 
				getch();
				break;
						
		default: printf("Wrong Choice, Press any key to continue"); getch();
				break;
		}
	}
}
//======================================== End of binary Search Tree ==================================================
*/

//========================================= ARRAYS ====================================================================

int delete_array(int arr[],int size){
	int index,i;
	index=linear_search(arr,size);
	for(i=index;i<size;i++){
		arr[i]=arr[i+1];
	}
	size--;
	return size;
}

//Merge Sort
void merge_sort(int arr[], int p, int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void merge(int arr[],int p, int q, int r){
	int size1=q-p, size2=r-q-1;
	int arr1[size1+1], arr2[size2+1];
	int i,j,k;
	for(i=0;i<=size1;i++){
		arr1[i]=arr[p+i];
	}
	for(j=0;j<=size2;j++){
		arr2[j]=arr[q+j-1];
	}
	arr1[size1+1]=9999;
	arr2[size2+1]=9999;
	i=0;j=0;
	for(k=p;k<r;k++){
		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
		}
		else{
			arr[k]=arr2[j];
			j++;
		}
	}
}

//QUick Sort 
int quicksort_partition(int arr[], int p, int r){
	int i,j,pivot_value,temp;
	i=p-1;
	pivot_value=arr[r];
	for(j=p;j<=r-1;j++){
		if(arr[j]<=pivot_value){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return (i+1);
}

void quick_sort(int arr[],int p, int r){
	int q;
	if(p<r){
		q=quicksort_partition(arr,p,r);
		quick_sort(arr,p,q-1);
		quick_sort(arr,q+1,r);
	}
}

void insertion_sort(int arr[], int size){
	int i,j,temp;
	for(i=1;i<=size;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && temp<arr[j] ){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}

void selection_sort(int arr[], int size){
	int k=0,i,min,temp;
	while(k<=size-1){
		for(i=k,min=k;i<=size-1;i++){
			if(arr[i]<arr[min]){
				min=i;
			}
		}
		temp=arr[k];
		arr[k]=arr[min];
		arr[min]=temp;
		k++;
		
	}
}

void bubble_sort(int arr[], int size){
	int round,j,temp;
	for(round=0;round<size-1;round++){
		for(j=0;j<size-1-round;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int binary_search(int arr[],int size){
	int i,data,low,high,mid;
	system("cls");
	printf("\nEnter the key to search"); scanf("%d",&data);
	
	low=0; 
	high=size-1;
	printf("\n\t%d",high);
	while(high>=low){
		mid=(low+high)/2;
		if(data==arr[mid]){
			printf("\nFound %d at position %d",data,mid+1);
			getch();
			return;	
		}
		else if(data<arr[mid])
			high=mid-1;
		else if(data>arr[mid])
			low=mid+1;
	}
	printf("\nSeacrh unsuccesfull"); 
	getch();
	return mid;
}

int linear_search(int arr[],int size){
	int i,data;
	system("cls");
	printf("\nEnter the value"); scanf("%d",&data);
	for(i=0;i<size;i++){
		if(data==arr[i]){
			printf("\n%d found at %d positon",i+1);
			return i;	
		}		
	}

}

void display_array(int arr[],int size){
	int i;
	printf("Array: [ ");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}	
	printf("]");
}

int insert_array(int arr[]){
	int size,i;
	system("cls");
	printf("\nEnter the length is list"); scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nEnter element for index %d: ",i);
		scanf("%d",&arr[i]);
	}
	printf("\nArray Created");
	return size;
}

void create_array(){
	char con='y';
	int choice,size;
	int arr[100];
	while(con=='y'||con=='Y'){
		system("cls");
		printf("======== Select operation for Array========\n");
		printf("\t1:Insert");
		printf("\t2:Linear Search");
		printf("\t3:Binary Search\n");
		printf("\t4:Display");
		printf("\t5:Delete");
		printf("\t6:Sort\n");
		printf("\t7:Selection sort");
		printf("\t8:Insertion Sort");
		printf("\t9:Quick Sort\n");
		printf("\t10:");
		printf("\t11:\n");
		printf("\t100:");
		
		printf("\nSelect a data structure to create: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: size=insert_array(arr);
					getch();
					break;
			case 2: linear_search(arr,size);
					getch();
					break;	
			case 3: binary_search(arr,size);
					getch();
					break;		
			case 4: display_array(arr,size);
					getch();
					break;
			case 5: size = delete_array(arr,size);
					break;
			case 6: bubble_sort(arr,size);
					break;
			case 7: selection_sort(arr,size);
					break;
			case 8: insertion_sort(arr,size);
					break;
			case 9: quick_sort(arr,0,size-1);
					break;	
			case 10: merge_sort(arr,0,size-1);
					break;	
			case 100: main();
						return;
					
		}	
	}
}
//=========================================End of Arrays ==============================================================


//========================================== Heap=====================================================================

void build_heap(int arr[], int size);
void max_heapify(int arr[], int i, int heap_size);
int extract_max_heap(int arr[], int heap_size);
int increase_key_value(int arr[], int size);
int increase_key(int arr[], int size, int i, int value);

void heap_sort(int arr[], int size){
	int temp;
	build_heap(arr,size);
	temp=arr[0];
	arr[0]=arr[size];
	arr[size]=temp;
	size--;
	if(size>0)
		heap_sort(arr,size);
}

int increase_key(int arr[], int size, int i, int value){
	int temp,parent_index;
	if(i>size){
		printf("underflow");
		return 0;
	}
	if(arr[i]>value){
		printf("\nValue already larger.");
		return i;
	}
	arr[i]=value;
//	max_heapify(arr,0,size-1);			NOt OPTIOMAL
	parent_index=(i-1)/2; 
	while( arr[parent_index]<arr[i] && i>0 ){
			temp=arr[parent_index];
			arr[parent_index]=arr[i];
			arr[i]=temp;
			
			i=parent_index;
			parent_index=(i-1)/2;
	}

}

int increase_key_value(int arr[], int size){
	int value,i;
	printf("\nEnter the index to increase: ");
	scanf("%d",&i);
	printf("\nEnter the new value: ");
	scanf("%d",&value);
	increase_key(arr,size,i,value);
}

int extract_max_heap(int arr[], int heap_size){
	int max;
	max=arr[0];
	arr[0]=arr[heap_size];
	max_heapify(arr,0,heap_size);
	return arr[0];
}

void max_heapify(int arr[], int i, int heap_size){
	int left_child_index, right_child_index, largest,temp;
	left_child_index = (2*i)+1;
	right_child_index= (2*i)+2;
	if(left_child_index<=heap_size && arr[left_child_index]>=arr[i])
		largest = left_child_index;
	else
		largest = i;
	if(right_child_index<=heap_size && arr[right_child_index]>=arr[largest])
		largest=right_child_index;
	
	if(largest!=i){
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,largest,heap_size);
	}
}

void build_heap(int arr[], int size){
	int heap_size,i;
	heap_size=size;
	for(i=(heap_size-1)/2; i>=0;i--){
		max_heapify(arr,i,heap_size);
	}
}

void create_heap(){
	char con='y';
	int choice,size;
	int arr[100];
	while(con=='y'||con=='Y'){
		system("cls");
		printf("======== Select operation for heap========\n");
		printf("\t1:Create array");
		printf("\t2:Build Heap");
		printf("\t3:Display\n");
		printf("\t4:Extract_max_heap");
		printf("\t5:Increase Key");
		printf("\t6:Heap Sort\n");
		printf("\t7:");
		printf("\t8:");
		printf("\t9:\n");
		printf("\t10:");
		printf("\t11:\n");
		printf("\t100:");
		
		printf("\nSelect a data structure to create: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: size=insert_array(arr);
					getch();
					break;
			case 2: build_heap(arr,size-1);
					break;
			case 3: display_array(arr,size);
					getch();
					break;
			case 4: extract_max_heap(arr,size-1);
					break;	
			case 5: increase_key_value(arr,size);
					break;
			case 6: heap_sort(arr,size-1);
					break;
			case 100: main();
						return;
		}	
	}
}

//========================================== End of Heap ===========================================================

int main(){
	char con = 'y';
	int choice;

	while(con =='y'||con=='Y'){
		system("cls");
		printf("\t1:Linked list");
		printf("\t\t2:Stack");
		printf("\t\t3:Binary Search Tree\n");
		printf("\t4:Array Operations");
		printf("\t5:Heap");
		printf("\t6:\n");
		printf("\t7:");
		printf("\t8:");
		printf("\t9:\n");
		printf("\t10:");
		printf("\t11:");
		printf("\t12:\n");
		printf("\tM:");
		
		printf("\nSelect a data structure to create: ");
		scanf("%d",&choice);
		
		switch(choice){
//		case 1 : create_ll();
				break;
//		case 2: create_stack();
				break;
//		case 3: create_BST();
				break;
		case 4:	create_array();
				break;
		case 5: create_heap();
				break;
		default: printf("ooops");
				break;
		}
	}
}

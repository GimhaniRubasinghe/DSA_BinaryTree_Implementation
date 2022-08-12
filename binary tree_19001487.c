
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left_child;
	struct node *right_child;
};

struct node* new_node(int x){//a function to create a new node
	struct node *p;
	p = malloc(sizeof(struct node));
	p->data = x;
	p->left_child = NULL;
	p->right_child = NULL;
	return p;
}

struct node* insert(struct node* root,int x){//a function to insert data into the binary tree
	if(root==NULL){
		return new_node(x);
	}
	else if(x > root->data){
		root->right_child =  insert(root->right_child,x);
	}
	else{
		root->left_child = insert(root->left_child,x);
	}
	return root;
}

struct node* search(struct node* root,int x){//a function to search value in binary tree
	if(root==NULL){
		printf("Value is not there\n");
	}
	else if(root->data==x){
		printf("Value is there\n");
	}
	else if(x > root->data){
		return search(root->right_child,x);
	}
	else{
		return search(root->left_child,x);
	}
}

struct node* Findmin(struct node* root){//a function to find minimum value
	if (root->left_child != NULL){
		return Findmin(root->left_child);
	}
	else{
		return root;
	}
}

struct node* Delete(struct node *root, int x)// funnction to delete a node
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = Delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = Delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else{
            struct node *temp =Findmin(root->right_child);
            root->data = temp->data;
            root->right_child=Delete(root->right_child, temp->data);
        }
    }
    return root;
}

void printtree(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        printtree(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        printtree(root->right_child);// visiting right child
    }
}

int main(){
	int option,val;
	struct node* root=NULL;
	printf("\n*********************Options**********************\n");
	printf("1)Insert a new node\n");
	printf("2)Search a value from binary tree\n");
	printf("3)Delete a node\n");
	printf("4)Find the minimum value of binary list\n");
	printf("5)Print the binary tree\n");
	printf("6)Exit");
	
	
	
	do{
		printf("\nEnter the option : ");//user can choose option from options
		scanf("%d",&option);
		switch(option){
			case 1: printf("Enter the value you want to insert : ");//insert value to binary tree
					scanf("%d",&val); 
					root = insert(root,val); 
					printf("Value inserted\n");
					break;
			case 2: printf("Enter the value you want to search : ");//search value from binary tree
					scanf("%d",&val);
					search(root,val);
					break;
			case 3: printf("Enter the value you want to delete : ");//delete value from tree
					scanf("%d",&val); 
					root = Delete(root,val); 
					printf("Node is deleted");
					break;
			case 4: 
					root = Findmin(root);//find min value
					printf("Minimum value is %d",root->data);
					break;
			case 5: printtree(root);
					break;
			case 6: printf("EXIT");//exit from program
					exit(0);
			default: printf("Incorrect option. Please try again\n");//to inform user to entered option is not there
		}
	}while(option != 6);
	
	
}


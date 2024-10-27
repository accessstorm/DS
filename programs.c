//stack adt using array
#include<stdio.h>

#define N 5
int stack[N];
int top=-1;

void push()
{
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        item=stack[top];
        top--;
    }
    printf("%d\n",item);
}

void peek()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d\n",stack[top]);
    }
}

void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }
}

void main()
{
    int ch;
   
    do
    {
        printf("Enter choice for operation: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            display();
            break;
            default:
            printf("Invalid choice");
        }
    }while(ch!=0);
   
}
//end
















//infix to postfix expression
#include<stdio.h>
#include<ctype.h>
char stack[100]; 
int top = -1; 
void push(char x) 
{ 
stack[++top] = x; 
} 
char pop() 
{ 
if(top == -1) 
return -1; 
else 
return stack[top--]; 
} 
int priority(char x) 
{ 
if(x == '(') 
return 0; 
if(x == '+' || x == '-') 
return 1; 
if(x == '*' || x == '/') 
return 2; 
return 0; 
} 
int main() 
{ 
char exp[100]; 
char *e, x; 
printf("Enter the expression : "); 
scanf("%s",exp); 
printf("\n"); 
e = exp; 
while(*e != '\0') 
{ 
if(isalnum(*e)) 
printf("%c ",*e); 
else if(*e == '(') 
push(*e); 
else if(*e == ')') 
{ 
while((x = pop()) != '(') 
printf("%c ", x); 
} 
else 
{ 
while(priority(stack[top]) >= priority(*e)) 
printf("%c ",pop());
push(*e); 
} 
e++; 
} 
while(top != -1) 
{ 
printf("%c ",pop()); 
}return 0; 
} 
//end
















//linear queue adt using array
#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void display() {
    int i;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("%d\n", queue[front]);
    }
}

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front++;
        }
    }
}

int main() {
    int ch, value;
    do {
        printf("Enter the choice: 1:Enqueue, 2:Dequeue, 3:Peek, 4:Display, 0:Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting.....\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch != 0);
    return 0;
}

//end






















//circular queue adt using array
#include<stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void display()
{
int i=front;
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
       printf("queue is:");
while(i!=rear)
{
 printf("%d", queue[i]);
i=(i+1)%N;
        
}
       printf("%d", queue[rear]); 
    }
}

void enqueue(int x)
{
    if ((rear+1)%N==front)
{
        printf("overflow");
}
    
       else if (front == -1 && rear == -1)
{
            front = rear = 0;
        queue[rear] = x;
}
   else
{
rear=(rear+1)%N;
 queue[rear] = x;

    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("%d",queue[front]);
        front=(front+1)%N;
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("%d",queue[front]);
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("Enter choice (1: Enqueue, 2: Dequeue, 3: Peek, 4: Display, 0: Exit): ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
    
    return 0;
}

//end











//stack adt using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

  struct node *top=0;

void push(int x)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->link=top;
    top=new_node;
    
}

void pop()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        
        printf("STACK is empty");
    }
    else
    {
        printf("%d",top->data);
        top=top->link;
        free(temp);
    }
    
    
}

void peek()
{
    if(top==0)
    {
        printf("STACK is Empty");
    }
    else
    {
        printf("The top most element in the Stack is: %d",top->data);
    }
    
}

void display()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("Stack is empty");
    }

    else
    {
        
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->link;
        }
    }
}


int main()
{
    struct node *top=0;
    int ch,x;
    do
    {
    printf("\nEnter choise:\n1:push, 2:pop(), 3:peek(), 4:display():");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
           printf("Enter value to push:");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        
        default:
            printf("\nInvalid Input\n");
    }
    }while(ch!=0);
}
//end












//binary search tree using adt
#include<stdio.h>
#include<stdlib.h>
struct BstNode
{
    int  data;
    struct BstNode* left;
    struct BstNode* right;
};
struct BstNode* root=NULL;
struct BstNode* insert(struct BstNode* root,int x)
{
struct BstNode* temp=(struct BstNode*)malloc(sizeof(struct BstNode));
      temp->data=x;
      temp->left=temp->right=NULL;
      if(root==NULL)
        root=temp;
        else if(root->data>=x)
            root->left=insert(root->left,x);
        else
            root->right=insert(root->right,x);
            return root;
}
int search(struct BstNode* root,int data)
{
    if(root==NULL)
         return 0;
else if(root->data == data) {
        return 1;}
    else if(root->data>=data)
   return search(root->left,data);
    else
    return search(root->right,data);
 }

int main()
{
root = insert(root, 15);
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 05);
root = insert(root, 30);
root = insert(root, 25);

while(1)
{
    int n,l,k;
   printf("press 1 for continue and press 2 for end  ");
   scanf("%d",&k);
   if(k==1)
   {
printf("enter the value for searching \n");
scanf("%d",&n);
if(search(root,n)==1)
    printf("found in\n");
else
    printf("not found in\n");
   }
else
break;
}
}
//end

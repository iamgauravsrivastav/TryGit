#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

//create
//display
//counting
//sum of all elements
//find max-element
//searching
//improve searching move to head
//insert new node on existing ll 1-before first node,2-at any given position
//insert in a sorted ll
//Deleting from ll
//check ll sorted or not
//remove Duplicate from the ll
//
struct Node
{
    int data;
    struct Node *next;

}*First=NULL;

void Create(int a[],int Size)
{
    Node *temp,*Last;
    First=new Node;
    First->data=a[0];
    First->next=NULL;
    Last=First;

    for(int i=1;i<=Size;i++)
    {
        temp=new Node;
        temp->data=a[i];
        temp->next=NULL;
        Last->next=temp;
        Last=temp;
    }
}

void Display(Node *temp)
{

 //   temp=new Node;
    while(temp)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int Counting(Node *temp)
{
    int i=0;
    while(temp)
    {
        i++;
        temp=temp->next;
    }
    return(i);
}

int Sum_Elements(Node *temp)
{
    int sum=0;
    while(temp)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    return(sum);

}

int Find_max_element(Node *temp)
{
    int Max=-32768;
    while(temp)
    {


        if(Max < temp->data)
            Max=temp->data;
             temp=temp->next;
    }
    return(Max);
}
int Searching(Node *temp,int key)
{
    while(temp)
    {
        if(temp->data==key)
            return key;
        temp=temp->next;
    }
}

Node *improve_searching(Node *temp,int key)
{
    Node *tail=NULL;

   //temp=p;
    while(temp)
    {
        tail=temp;
        if(key==temp->data)
        {
            tail->next=temp->next;
            temp->next=First;
            First=temp;
            return temp;
        }
        tail=temp;
        temp=temp->next;
    }
    return NULL;
}

void Insert_node(Node *p,int index,int val)
{
    Node *temp;
    if(index<0 || index > Counting(First))
    return;
     temp=new Node;//allocating the memory
    temp->data=val;
    if(index==0)
    {
        temp->next=First;
        First=temp;

    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
            temp->next=p->next;
            p->next=temp;
        }

    }
}

void Insert_last(Node *temp,int val)
{
    Node *Last;
    temp= new Node;
    temp->data=val;
    temp->next=NULL; // here my new last node is ready

    if(First==NULL)
    {
        First=Last=temp;
    }
    else
        {
            while(temp)
            {
                temp=temp->next;
                Last=temp;
            }
        Last->next=temp;
        Last=temp;

        }
}
void Sort_insert(Node *p,int val)
{
    Node *temp,*tail=NULL;
    temp=new Node;
    temp->data=val;
    temp->next=NULL;
    if(First==NULL)
    {
        First=temp;
    }
    else
    {
        while(p && p->data<val)
        {
            tail=p; //tail pointer shifting one position and temp pointer shifting again
            p=p->next;
        }
        if(p==First)
        {
            temp->next=First;
            First=temp;
        }
        else
        {
        temp->next=tail->next;
        tail->next=temp;
        }

    }

}


int main()
{
    struct Node *t;
    int a[]={10,20,30,50,60};
    Create(a,4);
  // Display(First);
   // cout<<endl;
  // int total=Counting(First);
   // cout<<"Number of elements="<<total<<endl;
    //int element=Sum_Elements(First);
    //cout<<"sum of all the elements="<<element<<endl;

    //int Max_element=Find_max_element(First);
    //cout<<"Maximum elements="<<Max_element<<endl;
    //int Search=Searching(First,45);
    //cout<<"Searching elements="<<Search<<endl;

      //Insert_node(First,0,100);

     // Insert_last(First,60);
     Sort_insert(First,5);
      Display(First);
   // t=improve_searching(First,45);
    //if(t)
      //  cout<<"Fast searching="<<t->data;
   // else
     //   cout<<"idk";
    //cout<<"Searching elements="<<improve_search<<endl;


    return 0;
}







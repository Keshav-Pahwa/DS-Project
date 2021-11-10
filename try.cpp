#include <iostream>
#include <stdlib.h>
#include <string >
using namespace std;
struct node       
{
   string name , number;
   node *next;
};   
node *head = NULL , *newnode , *temp;
int len = 0 ;
void C_node ()
{
    newnode = new node;         // used for entering name
    cout<<"Enter Name ";
    cin>>newnode->name;
    cout<<"Enter number ";        // used for entering number
    cin>>newnode->number;
    newnode->next = NULL;
    if(head == NULL)               // if there are no contact details
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next= newnode;
        temp = newnode;
    }
}
void display ()   // for displaying contacts
{
    if(head == NULL)                // if there are no contact details
    {
        cout<<"Contact list is Empty "<<endl;
    }
    else
    {
        node *trav = head ;
        while (trav != NULL)            // if the the traversal node has not reached the end
        {
            cout<<"\nFull Name "<<trav->name<<endl;             // printing out the details
            cout<<"Phone Number "<<trav->number<<endl;
            trav= trav->next;
            len++;
        }
        cout<<"Total contacts in the list = "<<len<<endl;       // printing out length of the list
    }
}
void search_contact ()          // to search a contact
{
    node *search_node = head;
    string search;
    cout<<"Enter your desired contact you want to search ";
    cin>>search;                  // take input string to be searched from the user
    bool found = false;         // a variable found is kept to check whether the number is found or not
    if(head == NULL)            // if there are no contact details
    {
        cout<<"\nList is Empty "<<endl;
    }
    else
    {
        while (search_node != NULL)             // if the the traversal node has not reached the end
        {
            if(search == search_node->name || search == search_node->number)            // check whether the number or name is present in the directory or not
            {
                cout<<"\nFull name: "<<search_node->name<<endl;                 // printing out the details
                cout<<"Phone number: "<<search_node->number<<endl;
                found =true;
                break;
            }
            search_node = search_node->next;
        }
    }
    if(!found)
    {
        cout<<"Desired contact not fount "<<endl;
    }

}
void at_given ()            //deletion function
{
    int pos ;
    node *next_node;
    temp = head;
    cout<<"Enter your desired position from where you want to delete contact "<<endl;
    cin>>pos;
    if(head == NULL)            // if there are no contact details
    {
        cout<<"List is Empty "<<endl;
    }
    else if (pos > len)
    {
        cout<<"Invalid Position "<<endl;
    }
    else if(pos == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        cout<<"Contact has been deleted "<<endl;
    }
    else
    {
        for (int i = 1 ; i<pos ; i++)
        {
            temp = temp->next;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        delete next_node;
        cout<<"Contact has been deleted "<<endl;
    }
}
void clear_all ()           // delete all contacts
{
    if(head == NULL)
    {
        cout<<"List is Empty "<<endl;
    }
    else
    {
        temp = head ;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout<<"\nALL contact list has been deleted "<<endl;
    }
}
void menu ()            // print out the menu
{
    cout<<"Enter 1 to add contact "<<endl;
    cout<<"Enter 2 to display all contact "<<endl;
    cout<<"Enter 3 to search contact "<<endl;
    cout<<"Enter 4 to delete contact from where you want "<<endl;
    cout<<"Enter 5 to clear All record "<<endl;
}
int main ()
{
    int op;
    while (true )
    {
        menu();
        cin>>op;
        switch (op)
        {
        case 1:
            C_node();
            break;
        case 2:
            len = 0;
            display();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            at_given();
            break;
        case 5:
            clear_all();
            break;
        default:
            cout<<"Invalid Option "<<endl;
        }
    }
}

#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    string name;
    int value;
    Node* next;
};


void add_first_elem(Node* &head){

    Node* tmp = new Node;

    cout << "Enter name: ";
    cin >> tmp->name;

    cout << "Enter value: ";
    cin >> tmp->value;

    tmp->next = NULL;

    head = tmp;

    cout << "Added" << endl;

    return;
}

void add_elem(Node* head){
    Node* tmp = new Node;
    Node* curr = head;

    cout << "Enter name: ";
    cin >> tmp->name;

    cout << "Enter value: ";
    cin >> tmp->value;

    tmp->next = NULL;

    while (curr->next != NULL){
        curr = curr->next;
    }

    curr->next = tmp;

    return;
}

void add_elem_after_by_name(Node* head){
    Node* tmp;
    Node* elem = new Node;
    Node* after;

    cout << "What name we need to find?: ";
    string rname;
    cin >> rname;

    cout << "Enter name: ";
    cin >> elem->name;

    cout << "Enter value: " ;
    cin >> elem->value;

    tmp = head;
    while(tmp->name != rname){
        if (tmp->next == NULL){
            return;
        }
        tmp = tmp->next;
    }

    if (tmp->name == rname){
        after = tmp->next;
        elem->next = after;
        tmp->next = elem;
        cout << "Added" << endl;
    }
}

void add_elem_before_by_name(Node* &head){
    Node* elem = new Node;
    Node* tmp;
    Node* prev;

    cout << "What name we need to find?: ";
    string rname;
    cin >> rname;

    cout << "Enter name: ";
    cin >> elem->name;

    cout << "Enter value: ";
    cin >> elem->value;

    tmp = head;

    if (tmp->name == rname){
        elem->next = tmp;
        head = elem;
        return;
    }

    prev = tmp;
    tmp = tmp->next;

    while (tmp->name != rname){
        if(tmp->next == NULL){
            return;
        }
        prev = prev->next;
        tmp = tmp->next;
    }

    if (tmp->name == rname){
        elem->next = tmp;
        prev->next = elem;
        cout << "Added" << endl;
        return;
    }
}

void print_list(Node* head){
    Node* tmp = head;

    while (tmp != NULL){
        cout << "Name: " << tmp->name << " Value: " << tmp->value << endl;
        tmp = tmp->next;
    }

    return;
}

void del_elem_by_name(Node* &head){
    Node* tmp = head;
    Node* prev;

    cout << "What name we need to find?: ";
    string rname;
    cin >> rname;

    if (tmp->name == rname){
        head = head->next;
        delete tmp;
        return;
    }

    prev = tmp;
    tmp = tmp->next;

    while (tmp->name != rname){
        if (tmp->next == NULL){
            cout << "End. Didn't find elem";
            return;
        }
        prev = prev->next;
        tmp = tmp->next;
    }

    if (tmp->name == rname){
        prev->next = tmp->next;
        delete tmp;
        return;
    }
}


int main(){
    Node* head = NULL;

    while(true){
        cout << "What do you want to do?:\n1) Add first element.\n2) Add element."
        "\n3) Add after element with name.\n4) Add before element with name\n"
        "5) Delete element with name\n6) Find element and Print it. Search by value." << endl << "Enter number: ";
        int choice;
        cin >> choice;

        switch (choice){
            case 1:
                add_first_elem(head);
                break;
            case 2:
                add_elem(head);
                break;
            case 3:
                add_elem_after_by_name(head);
                break;
            case 4:
                add_elem_before_by_name(head);
                break;
            case 5:
                del_elem_by_name(head);
                break;
            case 6:
                print_list(head);
                break;
            default:
                break;
        }


        string c_bool;
        cout << "Do you want to continue?\nEnter (Y)es or (N)o: ";
        cin >> c_bool;
        if (c_bool == "N"){
            break;
        }
    }



    return 0;
}
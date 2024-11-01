// DynamicListCircle 01.10.24.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


typedef struct Nodes {
    Nodes* next;
    int data;
    Nodes* pred;
} Node;

void PrintList(Node* head) {

    Node* temp = head;
    if (not(head == nullptr)) {
        while (not(temp->next == head)) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << temp->data << " " << "\n";
    }
    else std::cout << "Head is nullptr" << "\n";
}



void AddNode(Node* &head, int newElem) {
    bool IsAdded = false;
    Node* temp = head;
    Node* addElem = new Node;
    addElem->data = newElem;
    if (not(head== nullptr)) {
        while (not(temp->next == head)) {

            if ((temp->data <= newElem) && (((temp->next)->data) >= newElem) && IsAdded == false) {

                temp->next->pred = addElem;
                addElem->next = temp->next;
                temp->next = addElem;
                addElem->pred = temp;
                IsAdded = true;
                break;
            }

            temp = temp->next;
        }
        if ((temp == head) && (temp->data <= newElem) && IsAdded == false) {

            addElem->pred = temp;
            addElem->next = temp;
            temp->pred = addElem;
            temp->next = addElem;

        }
        else if ((temp->data <= newElem) && (IsAdded == false)) {
            addElem->pred = temp;
            addElem->next = temp->next;
            temp->next->pred = addElem;
            temp->next = addElem;

        }
        else if ((temp->data > newElem) && (temp->next->data >= newElem) && (IsAdded == false)) {

            addElem->pred = temp;
            addElem->next = temp->next;
            temp->next->pred = addElem;
            temp->next = addElem;
            head = addElem;

        }
    }
    else cout << "List is deleted" << endl;
}
void special(Node* &head, int max, int elem) {

    if (elem < max) {
        if (head == nullptr) {
            head = new Node;
            head->data = elem;
            head->next = head;
            head->pred = head;
        }
        else AddNode(head, elem);
    }
    else {
        do{
            if (head == nullptr) {
                head = new Node;
                head->data = max;
                head->next = head;
                head->pred = head;
            }
            else { AddNode(head, max); }
            elem -= max;
        } while (elem > max);
        AddNode(head, elem);
    }
}

void DeleteBeforeElem(Node*& head, int elem) {
    bool IsDelete = false; 
    Node* temp = head;
    Node* deletedEl = temp;
    if (not(head == nullptr)) {
        while (not(temp->next == head)) {

            if (temp == head && temp->next->data == elem) {

                deletedEl = temp;
                if (not(temp->data == temp->next->data)) IsDelete = true;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                temp = temp->next;
                deletedEl->pred = nullptr;
                head = temp;
                deletedEl->next = nullptr;
                delete(deletedEl);

            }
            else if (not(temp == head) && (temp->next->data == elem)) {
                deletedEl = temp;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                temp = temp->next;
                deletedEl->next = nullptr;
                deletedEl->pred = nullptr;

                delete(deletedEl);

            }

            else { temp = temp->next; }
        }
        if ((temp == head) && (temp->data == elem)) {
            deletedEl = temp;
            deletedEl->next = nullptr;
            deletedEl->pred = nullptr;
            delete(deletedEl);

        }
        else if (not(temp == head) && (temp->next->data == elem) && IsDelete == false) {
            deletedEl = temp;
            temp->next->pred = temp->pred;
            temp->pred->next = temp->next;
            deletedEl->next = nullptr;
            deletedEl->pred = nullptr;
            delete(deletedEl);

        }
    }
    else cout << "List is deleted" << endl;
    
    
}

void Search(Node* head,int elem) {
    if (not(head == nullptr)) {
        bool IsThere = false;
        int count = 1;
        Node* temp = head;
        while (not(temp->next == head)) {
            if (temp->data == elem) {
                std::cout << count << " ";
                IsThere = true;
            }
            count += 1;
            temp = temp->next;
        }
        if (temp->data == elem) {
            std::cout << count << " ";
            IsThere = true;
        }
        if (IsThere == false) std::cout << "No elements";
        std::cout << endl;
    }
    else cout << "List is deleted" << endl;
}

void Difference(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
    bool isHead1 = true;
    bool isHead2 = true;
    if (not(head1 == nullptr)) {
        if (not(head2 == nullptr)) {
            do
            {
                if (temp1->data < temp2->data && isHead2 == true) {
                    cout << temp1->data << " ";
                    temp1 = temp1->next;
                    isHead1 = false;
                }
                else if (temp1->data == temp2->data && isHead2 == true) {
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    isHead1 = false;
                    if (temp2 == head2)isHead2 = false;
                }
                else if (temp1->data > temp2->data && isHead2 == true) {
                    do
                        temp2 = temp2->next;

                    while (temp1->data > temp2->data && not(temp2 == head2));
                    if (temp2 == head2)isHead2 = false;

                }
                else {
                    cout << temp1->data << " ";
                    temp1 = temp1->next;
                }
            
        }
            while (isHead1 == true || not(temp1 == head1));

        }
        else PrintList(head1);
    }
    else cout << "List is deleted" << endl;
    
}


Node* CreateList(int number_list) {
    
    Node* head = nullptr;
    Node* temp = head;
        std::cout << "How many elements are there in the list" << number_list << " ? Answer : ";
        int count;
        cin >> count;
        if (count < 1) head = nullptr;
        else {
            for (int i = 1; i <= count; i++) {
                std::cout << "Enter element # " << i << ": ";
                int elem,max;
                cin >> max;
                cin >> elem;
                special(head,max,elem);
                /*while (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    std::cout << "Enter again: ";
                    cin >> elem;
                }*/
                /*if (i == 1)
                {   
                    head->data = elem;
                    head->next = head;
                    head->pred = head;
                    temp = head;
                }
                else {
                    
                }*/
                std::cout << endl;
            }
        }
  return head;
}
void DeleteAll(Node *&head) {

    if (not(head == nullptr)) {
        Node* temp = head;
        Node* deletedEl = temp;
        while (not(temp->next == head))
        {
            deletedEl = temp;
            temp->next->pred = temp->pred;
            temp->pred->next = temp->next;
            temp = temp->next;
            deletedEl->pred = nullptr;
            head = temp;
            deletedEl->next = nullptr;
            delete(deletedEl);
        }

        deletedEl = temp;
        deletedEl->next = nullptr;
        deletedEl->pred = nullptr;
        head = nullptr;
        delete(deletedEl);

        std::cout << "List is deleted" << endl;
    }
    else cout << "List is deleted yet" << endl;
   
}

void DeleteAllNeededElem(Node*& head, int elem) 
{
    bool IsDelete = false;
    Node* temp = head;
    Node* deletedEl = temp;
    if (not(head == nullptr)) {
        while (not(temp->next == head)) {

            if (temp == head && temp->data == elem) {

                deletedEl = temp;
                if (not(temp->data == temp->next->data)) IsDelete = true;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                temp = temp->next;
                deletedEl->pred = nullptr;
                head = temp;
                deletedEl->next = nullptr;
                delete(deletedEl);

            }
            else if (not(temp == head) && (temp->data == elem)) {
                deletedEl = temp;
                temp->next->pred = temp->pred;
                temp->pred->next = temp->next;
                temp = temp->next;
                deletedEl->next = nullptr;
                deletedEl->pred = nullptr;

                delete(deletedEl);

            }

            else { temp = temp->next; }
        }
        if ((temp == head) && (temp->data == elem)) {
            deletedEl = temp;
            deletedEl->next = nullptr;
            deletedEl->pred = nullptr;
            delete(deletedEl);

        }
        else if (not(temp == head) && (temp->data == elem) && IsDelete == false) {
            deletedEl = temp;
            temp->next->pred = temp->pred;
            temp->pred->next = temp->next;
            deletedEl->next = nullptr;
            deletedEl->pred = nullptr;
            delete(deletedEl);

        }
    }
    else cout << "List is deleted" << endl;


}



Node* head1;
Node* head2;
int main() {
    /*bool IsWorking = true;
    int data, elem;*/

    head1 = CreateList(1);
    PrintList(head1);

    /*head1 = CreateList(1);
    head2 = CreateList(2);*/

    /*while (IsWorking) {

        std::cout << "If ADD ELEMENT IN 1 LIST- enter 1" << endl;
        std::cout << "If DELETE ELEMENT IN 1 LIST- enter 2" << endl;
        std::cout << "If ADD ELEMENT IN 2 LIST- enter 3" << endl;
        std::cout << "If DELETE ELEMENT IN 2 LIST- enter 4" << endl;
        std::cout << "If SEARCH ELEMENT IN 1 LIST - enter 5" << endl;
        std::cout << "If SEARCH ELEMENT IN 2 LIST- enter 6" << endl;
        std::cout << "If DIFFERENCE - enter 7" << endl;
        std::cout << "If DELETE ALL 1 LIST - enter 8" << endl;
        std::cout << "If DELETE ALL 2 LIST - enter 9" << endl;
        std::cout << "If CREATE 1 LIST - enter 10" << endl;
        std::cout << "If CREATE 2 LIST - enter 11" << endl;
        std::cout << "If Delete elements - enter 12" << endl;
        std::cout << "If EXIT - enter 13" << endl;
        cin >> data;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            std::cout << "Enter again: ";
            cin >> data;
        }

        switch (data)
        {
        case 1:
            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            AddNode(head1, elem);
            PrintList(head1);
            break;
        case 2:

            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            DeleteBeforeElem(head1, elem);
            PrintList(head1);

            break;
        case 3:

            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            AddNode(head2, elem);
            PrintList(head2);
            
            break;
        case 4:

            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            DeleteBeforeElem(head2, elem);
            
            PrintList(head2);
            break;
        case 5:
            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            Search(head1, elem);
            break;
        case 6:
            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            Search(head2, elem);
            break;
        case 7:
            Difference(head1,head2);
            break;
        case 8:
            DeleteAll(head1);
            break;
        case 9:
            DeleteAll(head2);
            break;
        case 10:
           
            head1 = CreateList(1);
            break;
        case 11:
           
            head2 = CreateList(2);
            break;
        case 12:
            cin >> elem;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                std::cout << "Enter again: ";
                cin >> elem;
            }
            DeleteAllNeededElem(head1,elem);
            break;
        case 13:
            IsWorking = false;
            std::cout << "Work is finished.";
            break;
        default:
            break;
        }
    }*/
}
  

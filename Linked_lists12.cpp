#include <iostream>
#include <queue>
#include <vector>
#include<locale>
using namespace std;

struct Node {
    int data;
    Node* next; 
    Node* down; 
    Node(int x) : data(x), next(nullptr), down(nullptr) {}
};


Node* flatten(Node* head) {
    if (!head) return nullptr;

    auto comp = [](Node* a, Node* b) { return a->data > b->data; };
    priority_queue<Node*, vector<Node*>, decltype(comp)> pq(comp);

    
    Node* curr = head;
    while (curr) {
        pq.push(curr);
        curr = curr->next;
    }

    Node* dummy = new Node(0); 
    Node* tail = dummy;

    while (!pq.empty()) {
        Node* node = pq.top();
        pq.pop();

        tail->next = node; 
        tail = node;

        
        if (node->down) {
            pq.push(node->down);
        }
    }

    tail->next = nullptr;
    Node* result = dummy->next;
    delete dummy;
    return result;
}


void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data;
        if (curr->next) cout << " - ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    
    Node* head = new Node(5);
    Node* n10 = new Node(10);
    Node* n19 = new Node(19);
    Node* n28 = new Node(28);

    
    head->next = n10;
    n10->next = n19;
    n19->next = n28;

    
    head->down = new Node(7);
    head->down->down = new Node(8);
    head->down->down->down = new Node(30);

    n10->down = new Node (20);

    n19->down = new Node(22);
    n19->down->down = new Node(50);

    n28->down = new Node(35);
    n28->down->down = new Node(40);
    n28->down->down->down = new Node(45);
    
    Node* flattened = flatten(head);

    
    cout << "После сплющивания: ";
    printList(flattened);
    
    /*for (int i = 0; i < sizeof(flattened); i++) {
        cout << flattened[i] << " ";
    }*/
    while (flattened) {
        Node* temp = flattened;
        flattened = flattened->next;
        delete temp;
    }

    return 0;
}

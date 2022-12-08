#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value, degree;
    Node *child, *sibling, *parent;

    Node(int key) {
        this->value = key;
        this->degree = 0;
        this->child = this->sibling = this->parent = NULL;
    }
};

Node* mergeNodes(Node* b1, Node* b2) {
    if(b1->value > b2->value) {
        swap(b1, b2);
    }

    b2->parent = b1;
    b2->sibling = b1->child;
    b1->child = b2;
    b1->degree++;

    return b1;
}

list<Node*> adjust(list<Node*> heap) {
    if(heap.size() <= 1) return heap;

    list<Node*>::iterator it1, it2, it3;
    it1 = it2 = it3 = heap.begin();

    it2++;
    it3 = it2;
    if(heap.size() > 2) it3++;

    while(it1 != heap.end()) {
        if(it2 == heap.end()) it1++;
        else if((*it1)->degree < (*it2)->degree) {
            it1++;
            it2++;
            if(it3 != heap.end()) it3++;
        } else if(it3 != heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree) {
            it1++;
            it2++;
            it3++;
        } else if((*it1)->degree == (*it2)->degree) {
            *it1 = mergeNodes(*it1, *it2);
            it2 = heap.erase(it2);
            if(it3 != heap.end()) it3++;
        }
    }

    return heap;
}

list<Node*> mergeOperation(list<Node*> heap1, list<Node*> heap2) {
    list<Node*> newHeap;
    list<Node*>::iterator it1 = heap1.begin();
    list<Node*>::iterator it2 = heap2.begin();

    while(it1 != heap1.end() && it2 != heap2.end()) {
        if((*it1)->degree <= (*it2)->degree) {
            newHeap.push_back(*it1);
            it1++;
        } else {
            newHeap.push_back(*it2);
            it2++;
        }
    }

    while(it1 != heap1.end()) {
        newHeap.push_back(*it1);
        it1++;
    }

    while(it2 != heap2.end()) {
        newHeap.push_back(*it2);
        it2++;
    }

    newHeap = adjust(newHeap);
    
    return newHeap;
}

list<Node*> insertOperation(list<Node*> heap, int key) {
    Node* newNode = new Node(key);
    list<Node*> newTree;
    newTree.push_back(newNode);
    
    heap = mergeOperation(newTree, heap);
    return heap;
}

Node* getMinimum(list<Node*> heap) {
    list<Node*>::iterator it = heap.begin();
    Node* min = *it;

    while(it != heap.end()) {
        if((*it)->value < min->value) {
            min = *it;
        }
        it++;
    }

    return min;
}

Node* getKey(int key, Node* node) {
    while(node) {
        if(node->value == key) return node;

        Node* val = getKey(key, node->child);
        if(val) return val;
        
        node = node->sibling;
    }
    return NULL;
}

list<Node*> decreaseKey(int key, int newVal, list<Node*> heap) {
    list<Node*>::iterator it;
    it = heap.begin();

    Node* keyNode;

    while(it != heap.end()) {
        keyNode = getKey(key, *it);
        if(keyNode) break;
        it++;
    }

    if(keyNode) {
        keyNode->value = newVal;

        while(keyNode->parent && keyNode->value < keyNode->parent->value) {
            int temp = keyNode->parent->value;
            keyNode->parent->value = keyNode->value;
            keyNode->value = temp;

            keyNode = keyNode->parent;
        }
    }

    return heap;
}

Node* extractMinimum(list<Node*>& heap) {
    Node* minKey = getMinimum(heap);

    list<Node*> tempHeap;
    Node* node = minKey->child;

    while(node) {
        tempHeap.push_front(node);
        node = node->sibling;
        tempHeap.front()->sibling = NULL;
    }

    list<Node*>::iterator it;
    it = heap.begin();

    while(it != heap.end()) {
        if(*it == minKey) {
            heap.erase(it);
            break;
        }
        it++;
    }

    heap = mergeOperation(tempHeap, heap);

    return minKey;
}

list<Node*> deleteOperation(list<Node*> heap, int key) {
    heap = decreaseKey(key, INT_MIN, heap);
    extractMinimum(heap);

    return heap;
}

void printTree(Node *node) {
    while(node) {
        cout<<node->value<<" ";
        printTree(node->child);
        node = node->sibling;
    }
}

void printHeap(list<Node*> heap) {
    list<Node*>::iterator it;
    it = heap.begin();

    cout<<"Binomial Heap: ";
    while(it != heap.end()) {
        printTree(*it);
        it++;
    }
    cout<<endl;
}

int main() {
    list<Node*> heap;

    while(true) {
        char ch;
        int keyValue, newKeyValue;

        cout<<"A.Insert Key"<<endl;
        cout<<"B.Delete Key"<<endl;
        cout<<"C.Get Minimum Key"<<endl;
        cout<<"D.Extract Minimum Key"<<endl;
        cout<<"E.Decrease Key"<<endl;
        cout<<"F.Print Binomial Heap"<<endl;
        cout<<"G.Exit"<<endl;
        cout<<endl<<"Select Option: ";
        cin>>ch;

        switch (ch)
        {
        case 'A':
            cout<<"Enter key value: ";
            cin>>keyValue;
            heap = insertOperation(heap, keyValue);
            printHeap(heap);
            break;

        case 'B':
            cout<<"Enter key value to delete: ";
            cin>>keyValue;
            heap = deleteOperation(heap, keyValue);
            printHeap(heap);
            break;

        case 'C':
            cout<<"Minimum Key Value: "<<getMinimum(heap)->value<<endl;
            break;

        case 'D':
            cout<<"Minimum Key Value: "<<extractMinimum(heap)->value<<endl;
            printHeap(heap);
            break;

        case 'E':
            cout<<"Enter old key value: ";
            cin>>keyValue;
            cout<<"Enter new key value: ";
            cin>>newKeyValue;
            if(newKeyValue > keyValue)
                cout<<"New key value should not be greater than old key value"<<endl;
            else
                heap = decreaseKey(keyValue, newKeyValue, heap);
            printHeap(heap);
            break;

        case 'F':
            printHeap(heap);
            break;

        case 'G':
            exit(0);
            break;
        
        default:
            break;
        }

        cout<<endl;
    }

    return 0;
}
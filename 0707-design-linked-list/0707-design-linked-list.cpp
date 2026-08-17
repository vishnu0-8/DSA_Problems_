class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;

        Node(int value) {
            val = value;
            next = nullptr;
        }
    };
    Node* head;
    MyLinkedList() { head = nullptr; }

    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr)
                return -1;
            temp = temp->next;
        }
        if (temp == nullptr)
            return -1;
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                if (temp == nullptr)
                    return;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteAtIndex(int index) {

        if (head == nullptr) {
            return;
        }

        if (index == 0) {
            head = head->next;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {

            if (temp == nullptr) {
                return;
            }

            temp = temp->next;
        }

    
        if (temp == nullptr || temp->next == nullptr) {
            return;
        }

        temp->next = temp->next->next;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
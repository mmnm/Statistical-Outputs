#include <iostream>
#include <string>
#include <vector>

struct EduLinkedListNode {
    int data;
    EduLinkedListNode *next;
    EduLinkedListNode(int d) : data(d), next(nullptr) {}
};

EduLinkedListNode* RemoveNthLastNode(EduLinkedListNode *head, int n) {
    // Step 1: We will move the end pointer n positions and initialize the two pointers
    EduLinkedListNode *endElem = head;
    EduLinkedListNode *startElem = head;

    // Base cases
    if(head == nullptr) {
        return head;
    }
    // Base cases: If only 1 element and N = 1
    if(n == 1 && head->next == nullptr) {
        delete head;
        return nullptr;
    }
    
    int counter = n;
    while(endElem != nullptr && counter > 0) {
        // Special case, endElem is last Elem
        if(endElem->next == nullptr) {
            // Max band, startElem is the one to be deleted
            head = startElem->next;
            delete startElem;
            return head;
        }
        counter--;
        endElem = endElem->next;
    }
    // Now we found the position of two ptr band at least n wide
    // this position marks the two ptr band - sliding window
    // move startElem and endElem together till endElem is pointing 
    // to last element

    while(endElem != nullptr && endElem->next != nullptr) {
        startElem = startElem->next;
        endElem = endElem->next;
    }
    // startElem->next is the one to be deleted
    endElem = startElem->next;
    startElem->next = startElem->next->next;
    delete endElem;

    return head;
}

class EduLinkedList {
public:
    EduLinkedListNode *head;
    EduLinkedList() : head(nullptr) {}
    EduLinkedList(EduLinkedListNode *h) : head(h) {}
    
    void InsertNodeAtHead(EduLinkedListNode *node) {
        if (head != nullptr) {
            node->next = head;
            head = node;
        } else {
            head = node;
        }
    }

    void CreateLinkedList(std::vector<int> &vec) {
        for (int i = vec.size() - 1; i >= 0; i--) {
            EduLinkedListNode *node = new EduLinkedListNode(vec[i]);
            InsertNodeAtHead(node);
        }
    }

    std::string ToString() {
        std::string result = "[";
        EduLinkedListNode *temp = head;
        while (temp != nullptr) {
            result += std::to_string(temp->data);
            temp = temp->next;
            if (temp != nullptr) {
                result += ",";
            }
        }
        result += "]";
        return result;
    }
};

void TraverseLinkedList(EduLinkedListNode* head) {
    EduLinkedListNode* current = head; 
    while (current != nullptr) {
        std::cout << current->data << "-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void TestRemoveNthLastNode() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5},  // General case
        {1},              // Single element
        {1, 2},           // Two elements
        {1, 2, 3},        // Three elements
    };
    std::vector<int> nValues = {2, 1, 1, 3};
    std::vector<std::vector<int>> expectedResults = {
        {1, 2, 3, 5},     // Removing 2nd from last
        {},               // Removing 1st from last (single element case)
        {2},              // Removing 1st from last in two element case
        {2, 3},           // Removing 3rd from last in three element case
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        EduLinkedList list;
        list.CreateLinkedList(testCases[i]);
        std::cout << "Original list: " << list.ToString() << std::endl;
        list.head = RemoveNthLastNode(list.head, nValues[i]);
        std::cout << "List after removing " << nValues[i] << "th last node: " << list.ToString() << std::endl;
        std::cout << "Expected result: ";
        for (int val : expectedResults[i]) {
            std::cout << val << "-> ";
        }
        std::cout << "nullptr" << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}

int main() {
    TestRemoveNthLastNode();
    return 0;
}

// 21.Merge two sorted linked lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

ListNode* readListFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }

    std::string line;
    if (!std::getline(file, line)) {
        std::cerr << "Error reading line from file" << std::endl;
        return nullptr;
    }

    std::istringstream iss(line);
    int value;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (iss >> value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    file.close();
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* h;
    
    if (list1 && list2) {
        if (list1->val <= list2->val) {
            h = new ListNode(list1->val);
            list1 = list1->next;
        }
        else {
            h = new ListNode(list2->val);
            list2 = list2->next;
        }
    }
    else {
        if (list1) {
            h = list1;
        }
        if (list2) {
            h = list2;
        }
        return h;
    }
    
    ListNode* tail = h;

    while (list1 || list2) {
        ListNode* newNode = nullptr;

        if (list1 && list2) {
            if (list1->val < list2->val) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }
            
            tail->next = newNode;
            tail = tail->next;
        }
        else {
            if (list1) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            }

            if (list2) {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            tail->next = newNode;
            tail = tail->next;
        }
    }

    return h;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void main() {    
    ListNode* list = readListFromFile("data.txt");
    ListNode* list2 = readListFromFile("data2.txt");
    
    ListNode* merged = mergeTwoLists(list, list2);
    printList(merged);

    return;
}


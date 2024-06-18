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
    ListNode* h = nullptr;
    ListNode* tail = nullptr;

    while (iss >> value) {
        ListNode* newNode = new ListNode(value);
        if (!h) {
            h = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    file.close();
    return h;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // check one of the ll is not empty 
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    // new ll start
    ListNode* head;

    // choose starting node
    if (list1->val <= list2->val) {
        head = list1;
        list1 = list1->next;
    }
    else {
        head = list2;
        list2 = list2->next;
    }

    // new ll tail (current node)
    ListNode* tail = head;

    while (list1 || list2) {

        if (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1; // add node to new ll
                tail = tail->next; // move tail to end of new ll
                list1 = list1->next; // pop node from list1
            }
            else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        else {
            // remainder of the longer list
            if (list1) {
                tail->next = list1;
                list1 = nullptr;
            }

            if (list2) {
                tail->next = list2;
                list2 = nullptr;
            }
        }
    }

    return head;
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


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    double value;
    struct Node *next;
};

struct Node *makeNumbers(int N);
void printNumbers(struct Node *head);
int getLength(struct Node *head);
struct Node *sortNumbers(struct Node *head);
struct Node *swapNode(struct Node *prev, struct Node *ptr);

struct Node *makeNumbers(int N) {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    struct Node *head = nullptr;
    struct Node *current = nullptr;

    for (int i = 0; i < N; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->value = static_cast<double>(rand()) / RAND_MAX * 100.0; // Random double value
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode; // First node
            current = head;
        } else {
            current->next = newNode; // Link new node
            current = newNode; // Move to new node
        }
    }
    return head; // Return the head of the list
}

void printNumbers(struct Node *head) {
    struct Node *ptr = head;
    while (ptr != nullptr) {
        cout << ptr->value << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}

int getLength(struct Node *head) {
    int length = 0;
    struct Node *ptr = head;
    while (ptr != nullptr) {
        length++;
        ptr = ptr->next;
    }
    return length;
}

struct Node *sortNumbers(struct Node *head) {
    if (head == nullptr) return head;

    struct Node *sorted = nullptr;

    // Insert each node into sorted linked list
    struct Node *current = head;
    while (current != nullptr) {
        struct Node *next = current->next; // Store next for the next iteration
        if (sorted == nullptr || sorted->value >= current->value) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node *temp = sorted;
            while (temp->next != nullptr && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; // Move to next node
    }
    return sorted; // Return the new head of sorted list
}

struct Node *swapNode(struct Node *prev, struct Node *ptr) {
    if (prev == nullptr || ptr == nullptr) return ptr;

    prev->next = ptr->next;
    ptr->next = prev;

    return ptr; // Return the new head of the swapped section
}
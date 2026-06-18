/*
- Finds the middle node of a linked list.
- Uses two pointers so the list is traversed in linear time.
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }
};

ListNode *buildList(const vector<int> &arr);
ListNode *middleNode(ListNode *head);

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = buildList(values);
    ListNode *mid = middleNode(head);

    cout << "Middle value: " << mid->val << endl;
    return 0;
}

ListNode *buildList(const vector<int> &arr)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int x : arr)
    {
        ListNode *newNode = new ListNode(x);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/*
- Merges two sorted linked lists into one sorted linked list.
- Uses a dummy node to keep the merge logic simple and correct.
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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2);

int main()
{
    vector<int> l1 = {1, 4, 6};
    vector<int> l2 = {2, 3, 5};

    ListNode *list1 = buildList(l1);
    ListNode *list2 = buildList(l2);
    ListNode *head = mergeTwoLists(list1, list2);

    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    tail->next = (list1 != nullptr) ? list1 : list2;
    return dummy->next;
}

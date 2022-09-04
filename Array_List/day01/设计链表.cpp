
#include<iostream>
#include<vector>
using namespace std;



class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(NULL){}
    };
    int size;
    ListNode* head;

    MyLinkedList() {
        size = 0;
        head = new ListNode(0);
    }
    
    int get(int index) {
        ListNode* p = head;
        if(index < size && index >= 0){
            for(int i = 0;i < index + 1;i++){
                p = p->next;
            }
            if(p == NULL)
                return -1;
            else
                return p->val;
        }
        else
            return -1;
    }
    
    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = head->next;
        head->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* p = head;
        while(p->next != NULL){
            p = p->next;
        }
        ListNode* temp = new ListNode(val);
        p->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0)
            addAtHead(val);
        else if(index <= size){
            ListNode* p = head;
            for(int i = 0;i < index;i++){
                p = p->next;
            }
            ListNode* temp = new ListNode(val);
            temp->next = p->next;
            p->next = temp;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= 0 && index < size){
            ListNode* p = head;
            for(int i = 0;i < index;i++){
                p = p->next;
            }
            ListNode *temp = p->next;
            p->next = p->next->next;
            delete temp;
            size--;
        }
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

int main(){

}
class MyLinkedList {
public:
    class Node{
        public:
        int val;
        Node* next;
        Node(int a):val(a),next(NULL){}
    };
    Node* head;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=new Node(0);
        size=0;
    }
    void show(){
        Node *tmp=head;
        cout<<size<<":";
        while(tmp->next!=NULL){
                tmp=tmp->next;
            cout<<tmp->val<<",";
        }
        cout<<endl;
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // show();
        if(index>=size) return -1;
        Node *tmp=head->next;
        while(index>=0){
            if(tmp==NULL)
                return -1;
            if(index==0) return tmp->val;
            index--;
            tmp=tmp->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* p=head->next;
        head->next=new Node(val);
        // cout<<head->next->val;
        head->next->next=p;
        size++;
        return ;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *tmp=head;
        while(tmp->next!=NULL){
            tmp=tmp->next;    
        }
        tmp->next=new Node(val);
        size++;
        return ;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==size){
            addAtTail(val);
            return ;
        }
        if(index>size){
            return ;
        }
        Node *tmp=head;
        while(index>0){
            index--;
            tmp=tmp->next;
        }
        Node *t=tmp->next;
        tmp->next=new Node(val);
        tmp->next->next=t;
        size++;
        return ;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size) return ;
        if(index<0) return ;
        Node *tmp=head;
        while(index>0){
            index--;
            tmp=tmp->next;
        }
        if(tmp->next==NULL){
         show();
            
        }
        tmp->next=tmp->next->next;
        size--;
        return ;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
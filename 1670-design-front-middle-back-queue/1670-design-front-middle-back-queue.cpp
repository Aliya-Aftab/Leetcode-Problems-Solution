class FrontMiddleBackQueue {
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    Node* mid;
    int size;

public:
    FrontMiddleBackQueue() {
        head = tail = mid = nullptr;
        size = 0;
    }

    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = mid = newNode;
            size++;
            return;
        }
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++; // Update size to New Size

        // Rule: Even size -> Mid shifts Left
        if (size % 2 == 0) {
            mid = mid->prev;
        }
    }

    void pushMiddle(int val) {
        if (size == 0) {
            pushFront(val);
            return;
        }

        Node* newNode = new Node(val);
        
        // Logic: Insert based on OLD size (before increment)
        // If Old Size is Odd (1,3): Insert BEFORE mid.
        if (size % 2 == 1) {
            newNode->next = mid;
            newNode->prev = mid->prev;
            if (mid->prev) mid->prev->next = newNode;
            else head = newNode;
            mid->prev = newNode;
        } 
        // If Old Size is Even (2,4): Insert AFTER mid.
        else {
            newNode->prev = mid;
            newNode->next = mid->next;
            if (mid->next) mid->next->prev = newNode;
            mid->next = newNode;
        }

        size++; 
        mid = newNode; // The new node always becomes the median
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = mid = newNode;
            size++;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++; // Update size to New Size

        // Rule: Odd size -> Mid shifts Right
        if (size % 2 == 1) {
            mid = mid->next;
        }
    }

    int popFront() {
        if (size == 0) return -1;

        int val = head->val;
        Node* temp = head;

        if (size == 1) {
            head = tail = mid = nullptr;
            size--;
            delete temp;
            return val;
        }

        head = head->next;
        head->prev = nullptr;
        size--; // Update size to New Size

        // Rule: If New Size is Odd, Mid shifts Right
        // (Because we removed from the Left, shifting center Right)
        if (size % 2 == 1) {
            mid = mid->next;
        }

        delete temp;
        return val;
    }

    int popMiddle() {
        if (size == 0) return -1;
        if (size <= 2) return popFront(); // Size 1 & 2 handled safely by popFront

        int val = mid->val;
        Node* toDelete = mid;
        
        // Stitch neighbors (safe because size > 2 implies mid is not head/tail)
        mid->prev->next = mid->next;
        mid->next->prev = mid->prev;

        size--; // Update size to New Size

        // Rule: 
        // If New Size is Even (was Odd 3->2): Mid shifts Left (Prev)
        // If New Size is Odd (was Even 4->3): Mid shifts Right (Next)
        if (size % 2 == 0) {
            mid = mid->prev;
        } else {
            mid = mid->next;
        }

        delete toDelete;
        return val;
    }

    int popBack() {
        if (size == 0) return -1;

        int val = tail->val;
        Node* temp = tail;

        if (size == 1) {
            head = tail = mid = nullptr;
            size--;
            delete temp;
            return val;
        }

        tail = tail->prev;
        tail->next = nullptr;
        size--; // Update size to New Size

        // Rule: If New Size is Even, Mid shifts Left
        // (Because we removed from the Right, shifting center Left)
        if (size % 2 == 0) {
            mid = mid->prev;
        }

        delete temp;
        return val;
    }
};
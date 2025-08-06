struct Node {
    int key, value, cnt; // cnt = frequency
    Node *next, *prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
        next = prev = nullptr;
    }
};


/* ───────────── Doubly Linked List for each frequency ───────────── */
struct List {
    int size;
    Node *head;
    Node *tail;

    List() {
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Add node just after head
    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // Remove a specific node
    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache {
    unordered_map<int, Node*> keyNode;             // key → node
    unordered_map<int, List*> freqListMap;         // freq → DLL of nodes
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    // Updates a node's frequency list
    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        // If this list was the min freq and is now empty, increment minFreq
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        node->cnt++; // increase frequency

        // Move node to new freq list
        List* newList = new List();
        if (freqListMap.find(node->cnt) != freqListMap.end()) {
            newList = freqListMap[node->cnt];
        }

        newList->addFront(node);
        freqListMap[node->cnt] = newList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            // If key exists, update value and frequency
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                // Evict LFU node from minFreq list (from the end = least recently used)
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;

                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            // Insert new node into frequency 1 list
            List* listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            Node* newNode = new Node(key, value);
            listFreq->addFront(newNode);
            freqListMap[minFreq] = listFreq;
            keyNode[key] = newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
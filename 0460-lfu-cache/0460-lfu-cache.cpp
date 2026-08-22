class LFUCache {
public:

    class Node {
    public:
        int key;
        int value;
        int freq;

        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;

            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> mpp;

    // Every frequency has its own DLL
    unordered_map<int, Node*> freqHead;
    unordered_map<int, Node*> freqTail;

    int capacity;
    int minFreq;

    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    // Create dummy head and tail for a frequency
    void createList(int freq) {
        if(freqHead.find(freq) == freqHead.end()) {
            freqHead[freq] = new Node(-1, -1);
            freqTail[freq] = new Node(-1, -1);

            freqHead[freq]->next = freqTail[freq];
            freqTail[freq]->prev = freqHead[freq];
        }
    }

    // Delete node from its current DLL
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node after head of its frequency DLL
    void insertAfterHead(Node* node) {
        int freq = node->freq;

        node->next = freqHead[freq]->next;
        freqHead[freq]->next->prev = node;

        freqHead[freq]->next = node;
        node->prev = freqHead[freq];
    }

    // Increase frequency of a node
    void increaseFreq(Node* node) {

        int oldFreq = node->freq;

        // Remove from old frequency list
        deleteNode(node);

        // If old frequency list becomes empty
        if(freqHead[oldFreq]->next == freqTail[oldFreq]) {
            if(minFreq == oldFreq) {
                minFreq++;
            }
        }

        // Increase frequency
        node->freq++;

        // Create new frequency list if needed
        createList(node->freq);

        // Put node at front of new frequency list
        insertAfterHead(node);
    }

    int get(int key) {

        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        // Getting the key means it is used once more
        increaseFreq(node);

        return node->value;
    }

    void put(int key, int value) {

        // If capacity is 0
        if(capacity == 0) {
            return;
        }

        // Key already exists
        if(mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            node->value = value;

            // put() also increases frequency
            increaseFreq(node);

            return;
        }

        // Cache is full
        if(mpp.size() == capacity) {

            // Remove the least recently used node
            // from the minimum frequency list
            Node* node = freqTail[minFreq]->prev;

            mpp.erase(node->key);

            deleteNode(node);

            delete node;
        }

        // Create new node
        Node* node = new Node(key, value);

        mpp[key] = node;

        // New node always has frequency 1
        createList(1);

        insertAfterHead(node);

        // Minimum frequency becomes 1
        minFreq = 1;
    }
};
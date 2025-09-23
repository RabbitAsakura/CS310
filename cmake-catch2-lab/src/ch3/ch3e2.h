#ifndef CH3E2_H
#define CH3E2_H

class ItemType{
    public:
        int key;
        ItemType(){
            key = 0;
        }
        ItemType(int k): key(k){}
            int compareTo(ItemType& other)
            {
                if(key == other.key){
                    return 0;
                }
                return key < other.key ? -1 : 1;
            }
};

struct NodeType{
    ItemType item;
    NodeType* next;
};

class UnsortedList{
    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
    public:
        UnsortedList(){
            listData = nullptr;
            length = 0;
            currentPos = nullptr;
        }

        ~UnsortedList(){
            NodeType* tempPtr;
            while(listData != nullptr){
                tempPtr = listData;
                listData = listData->next;
                delete tempPtr;
            }
        }

        void Insert(ItemType item){
            NodeType* location = new NodeType;
            location->item = item;
            location->next = listData;
            listData = location;
            length++;
        }

        void DeleteItem(ItemType item){
            currentPos = listData;
            if(currentPos && currentPos->item.compareTo(item) == 0){
                listData = currentPos->next;
                delete currentPos;
                length--;
            }

            while(currentPos && currentPos->next){
                if(currentPos->next->item.compareTo(item) == 0){
                    NodeType* tempPtr = currentPos->next;
                    currentPos->next = tempPtr->next;
                    delete tempPtr;
                    length--;
                }
                currentPos = currentPos->next;
            }
        }

        bool isFull(){
            
        }

};


#endif
class ItemType
{
    public:
        int key;
        ItemType(){
            key = 0;
        }
        ItemType(int k): key(k){}
        
        int CompareTo(ItemType& other){

            if(key == other.key)
            {
                return 0;
            }else if(key < other .key)
            {
                return -1;
            }
            else{
                return 1;
            }
        }
};

class UnsortedList{
    private:
        int capacity;
        ItemType* data;
        int length = 0;
        int currentPos = -1;

    public:
        UnsortedList(int MAX_ITEMS = 100){
        capacity = MAX_ITEMS;
        data = new ItemType[capacity];
        length = 0;
        currentPos = -1;
    }

        void Insert(ItemType item){
            if(length < MAX_ITEMS){
                data[length++] = item;
            }
        }

        int Length() const{
            return length;
        }

        bool isEmpty(){
            return length == 0;
        }

        bool isFull(){
            return length == MAX_ITEMS;
        }

        void ResetList(){
            currentPos = -1;
        }

        void DeleteItem(ItemType item){
            for(int i = 0; i < length; i++){
                if(data[i].CompareTo(item) == 0){
                    for(int j = i; j< length-1; j++){
                        data[j] = data[j+1];
                    }
                    length--;
                    return;
                }
            }
        }

        void DisplayInReverse(){
            for(int i = length-1; i >= 0; i--){
                std::cout << data[i].key << " ";
            }
        }
};
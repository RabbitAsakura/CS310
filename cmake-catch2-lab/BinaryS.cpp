//Jakobe McPhail
//11/11/25


struct TreeNode
{
    int info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType
{
    private:
        TreeNode *root;
    public:
        TreeType() : root(nullptr) {}

        ~TreeType() {}

        bool GetItem(int item)
        {
            bool found = false;
            Retrieve(root, item, found);
            return found;
        }

        void Retrieve(TreeNode *node, int item, bool &found)
        {
            if(node == nullptr)
            {
                found = false;
            }
            else if(item < node->info)
            {
                Retrieve(node->left, item, found);
            }
            else if(item > node->info)
            {
                Retrieve(node->right, item, found);
            }
            else
            {
                found = true;
            }
        }

        bool GetItemItr(int item)
        {
            node = root;
            while(node != nullptr && item != node->info)
            {
                node = item < node->info ? node->left : node->right;
            }
            return node != nullptr;
        }

        void PutItem(int item)
        {
            Insert(root, item);
        }

        void Insert(TreeNode *&node, int item)
        {
            if(node == nullptr)
            {
                node = new TreeNode;
                node->info = item;
                node->left = nullptr;
                node->right = nullptr;
            }
            else if(item < node->info)
            {
                Insert(node->left, item);
            }
            else
            {
                Insert(node->right, item);
            }
        }

};
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

        bool GetItemRec(int item)
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
            TreeNode* node = root;
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

        void DeleteItem(int item) { DeleteNode(root, item);}
        
        void DeleteNode(TreeNode* node, int item)
        {
            if(node == nullptr)
            {
                return;
            }
            if(item < node->info)
            {
                DeleteNode(node->left, item);
            }
            else if(item > node->info)
            {
                DeleteNode(node->right, item);
            }
            else
            {
                if(node->left == nullptr && node->right == nullptr)
                {
                    delete node;
                    node = nullptr;
                }
                else if (node->left == nullptr)
                {
                    TreeNode* temp = node->right;
                    node = node->right;
                    delete temp;
                }
                else
                {
                    TreeNode* temp = node->right;
                    while(temp->left != nullptr)
                    {
                        temp = temp->left;
                    }
                    node->info = temp->info;
                    DeleteNode(node->right,temp->info);
                }
            }
        }

};
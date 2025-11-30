//Jakobe McPhail
//11/27/25
//Data Structures
#include <iostream>
#include "avltree.h"



int main()
{
    AVLTree obj;
    int choice, val;
    do
    {
      std::cout << "Choose what you will like to do: ";
      std::cout << "Select from 1-6, Press 0 to exit." << std::endl;
      std::cout << "1. Insert" << std::endl;
      std::cout << "2. Search" << std::endl;
      std::cout << "3. Delete" << std::endl;
      std::cout << "4. Display" << std::endl;
      std::cout << "5. Height" << std::endl;
      std::cout << "6. Clear" << std::endl;
      std::cout << "0. Exit" << std::endl;

      std::cin >> choice;
      TreeNode *node = new TreeNode;

      switch(choice)
      {
        case 0:
            std::cout << "Goodbye!";
            break;
        case 1:
            std::cout << "What value would you like to insert: ";
            std::cin >> val;
            node->value = val;
            obj.root = obj.insert(obj.root, node);
            std::cout << std::endl;
            break;
        case 2:
            std::cout << "Enter value to search in the tree: ";
            std::cin >> val;
            node = obj.Recursive(obj.root, val);
            if(node != NULL)
            {
                std::cout << "Value Found!" << std::endl;
            }
            else
            {
                std::cout << "Value Not Found!" << std::endl;
            }
            break;
        case 3:
            std::cout << "Enter value to delete in the tree: ";
            std::cin >> val;
            node = obj.Recursive(obj.root, val);
            if(node != NULL)
            {
                obj.root = obj.deleteNode(obj.root, val);
                std::cout << "Value Deleted!" << std::endl;
            }
            else
            {
                std::cout << "Value Not Found!" << std::endl;
            }
            break;
        case 4:
            obj.display(obj.root, 5);
            std::cout << std::endl;
            std::cout << "Pre-Order: ";
            obj.Preorder(obj.root);
            std::cout << std::endl;
            std::cout << "In-Order: ";
            obj.Inorder(obj.root);
            std::cout << std::endl;
            std::cout << "Post-Order: ";
            obj.Postorder(obj.root);
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Height: " << obj.height(obj.root);
            std::cout << std::endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            std::cout << "Enter a number: " << std::endl;
      }
    } while (choice != 0);
    
}
#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

#include<queue>
#include "elem_types.h"

template <class T>
class BStree{
    public:
    struct node{
        T value;
        node *left;
        node *right;
    }*root;
    private:
        // SETTERS:
        struct node *newnode(T data) {
            struct node *temp = new node;
            temp->value = data;
            temp->left = nullptr;
            temp->right = nullptr;
            return temp;
        }

        node* LL_rotate(node *parent){ // For right-heavy case
            node *temp = parent->right;
            parent->right = temp->left;
            temp->left = parent;
            return temp;
        }

        node* RR_rotate(node *parent){ // For left heavy case
            node *temp = parent->left;
            parent->left = temp->right;
            temp->right = parent;
            return temp;
        }

        node* LR_rotate(node *parent){ // For right heavy case
            parent->left = LL_rotate(parent->left);
            return RR_rotate(parent);
        }

        node* RL_rotate(node *parent){ // For left heavy case
            parent->right = RR_rotate(parent->right);
            return LL_rotate(parent);
        }

        node* Balance(node* temp){

        int bal_factor = Get_diff(temp);
            if (bal_factor > 1){
                if (Get_diff(temp->left) > 0)
                    temp = RR_rotate(temp);
                else
                    temp = LR_rotate(temp);
            }
            else if (bal_factor < -1){
                if (Get_diff(temp->right) > 0)
                    temp = RL_rotate(temp);
                else
                    temp = LL_rotate(temp);
            }
        return temp;
        }

        node *Insert_At(T item, node *temp){
            if (temp == nullptr){
                temp = newnode(item);
            }
            else if (item < temp->value){
                temp->left = Insert_At(item, temp->left);
            }
            else if (item > temp->value){
                temp->right = Insert_At(item, temp->right);
            }
            temp = Balance(temp);

            return temp;
        }

        void Destroy_Tree(node *temp){
            if(temp != nullptr){
                Destroy_Tree(temp->left);
                Destroy_Tree(temp->right);
                delete temp;
            }
        }

        // GETTERS:
        int Get_height_util(node *temp){
            int h = 0;
            if (temp != nullptr){
                int l_height = Get_height_util(temp->left);
                int r_height = Get_height_util(temp->right);
                int max_height = std::max(l_height, r_height);
                h = max_height + 1;
            }
            return h;
        }

        int Get_diff(node *temp){
            int l_height = Get_height_util(temp->left);
            int r_height = Get_height_util(temp->right);
            int diff = l_height - r_height;
            return diff;
        }

        T Get_data(node *temp){
            return temp->value;
        }

        node *Find_min(node *Min){
            node *temp = Min;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            return temp;
        }

        node *Search_At(T item, node *temp){

            if(temp != nullptr){
                if(item == temp->value){
                    return temp;
                }
                if(temp->value > item){
                    return Search_At(item, temp->left);
                }
                else{
                    return Search_At(item, temp->right);
                    }
                }
            else{
                return nullptr;
            }
        }

        void inorder_print(node *temp){
            if(temp != nullptr){
                inorder_print(temp->left);
                std::cout << temp->value << ", ";
                inorder_print(temp->right);
            }
        }

        void postorder_print(node *temp){
            if(temp != nullptr){
                postorder_print(temp->left);
                postorder_print(temp->right);
                std::cout << temp->value << ", ";
            }
        }

        void preorder_print(node *temp){
            if(temp != nullptr){
                std::cout << temp->value << ", ";
                preorder_print(temp->left);
                preorder_print(temp->right);
            }
        }

        void Display(node *temp, int level){
            int i;
            if (temp != nullptr){

                Display(temp->right, level + 1);
                std::cout << "\n";
                if (temp == root){
                    std::cout << "Root -> ";
                }
                for (i = 0; i < level && temp != root; i++){
                    std::cout << "        ";
                }
                std::cout << temp->value;
                Display(temp->left, level + 1);
            }
        }

        node *Map_util(T (*Func)(T), node *temp){
            if(temp == nullptr){
                return nullptr;
            }
            T map_item = Func(temp->value);

            std::cout << "Map_item is: " << map_item << std::endl;

            node *Map_node = newnode(Func(temp->value));

            Map_node->left = Map_util(Func, temp->left);
            Map_node->right = Map_util(Func, temp->right);

            Map_node = Balance(Map_node);
            return Map_node;
        }

        node *Where_util(bool (*Cond)(T), node *temp){
            if(temp == nullptr){
                return nullptr;
            }
            node *Where_node = new node;
            if(Cond(temp->value)){
                Where_node = newnode(temp->value);
            }
            Where_node->left = Where_util(Cond, temp->left);
            Where_node->right = Where_util(Cond, temp->right);

            Where_node = Balance(Where_node);
            return Where_node;
        }

        node *Reduce_util(T (*Func)(T, T), node *temp, T &Red_item){
            if(temp == nullptr){
                return nullptr;
            }

            node *Red_node = new node;

            Red_node = newnode(temp->value);
            Red_item = Func(Red_item, temp->value);

            Red_node->left = Reduce_util(Func, temp->left, Red_item);
            Red_node->right = Reduce_util(Func, temp->right, Red_item);

            return Red_node;
        }

    public:
        // CONSTRUCTORS:
        BStree(){
            root = nullptr;
        }
        ~BStree(){
            Destroy_Tree();
        }

        node* Delete_At(T item, node* Ref){
            node *temp;
            if (Ref == nullptr){
                return nullptr;
            }
            // Search for the element
            else if (item < Ref->value)
                Ref->left = Delete_At(item, Ref->left);

            else if (item > Ref->value)
                Ref->right = Delete_At(item, Ref->right);

            // Element has 2 children
            else if (Ref->left && Ref->right){
                temp = Find_min(Ref->right);
                Ref->value = temp->value;
                Ref->right = Delete_At(Ref->value, Ref->right);
            }
            // Element has 1 or 0 child
            else {
                temp = Ref;
                if (Ref->left == nullptr){
                    Ref = Ref->right;
                }
                else if(Ref->right == nullptr){
                    Ref = Ref->left;
                }
                delete temp;
            }
            if (Ref == nullptr){
                return Ref;
            }
            // Balance the tree
            Ref = Balance(Ref);
        }

        void Insert_Item(T item){
            root = Insert_At(item, root);
        }
        node *Search_Item(T item){
            return this->Search_At(item, root);
        }
        void Delete_Node(T item){
            std::cout << "Deleting node: " << item << std::endl;
            root = Delete_At(item, root);
        }
        void Inorder_Print(){
            this->inorder_print(root);
            std::cout << "\n";
        }
        void Postorder_Print(){
            this->postorder_print(root);
            std::cout << "\n";
        }
        void Preorder_Print(){
            this->preorder_print(root);
            std::cout << "\n";
        }
        BStree<T> *Extract_Subtree(T Value){
            BStree<T> *temp = new BStree<T>();
            temp->root = this->Search_Item(Value);
            return temp;
        }

        int Get_height(){
            return Get_height_util(root);
        }

        void Display_tree(){
            Display(root, 1);
        }

        BStree<T> *Map(T (*Func)(T)){
            BStree<T> *Map_tree = new BStree<T>();
            Map_tree->root = this->Map_util(Func, root);
            return Map_tree;
        }

        BStree<T> *Where(bool (*Cond)(T)){
            BStree<T> *Where_tree = new BStree<T>();
            Where_tree->root = this->Where_util(Cond, root);
            return Where_tree;
        }

        T Reduce(T (*Func)(T, T)){
            T Red_item=0;
            if(Func == reduce_product){
                Red_item = 1;
            }
            this->Reduce_util(Func, root, Red_item);
            return Red_item;
        }
};

BStree<char> *String_to_tree(std::string input){
    BStree<char> *temp = new BStree<char>();
    int len = input.length();
    for(int i=0; i<len; i++){
        temp->Insert_Item(input[i]);
    }
    return temp;
}

#endif // BINARY_TREE_H_INCLUDED

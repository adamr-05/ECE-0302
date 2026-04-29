#include "BinarySearchTree.hpp"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = nullptr;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& tree_to_copy)
{
    root = nullptr;
    Node<KeyType, ItemType>** this_tree_root = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.node_to_copy = tree_to_copy.root;
    rootvar.this_node_address = this_tree_root;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_node_to_copy = currentvar.node_to_copy;
        Node<KeyType, ItemType>** curr_this_node_address = currentvar.this_node_address;

        if (curr_node_to_copy == nullptr)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_node_to_copy->key;
        temp->data = curr_node_to_copy->data;
        temp->left = nullptr;
        temp->right = nullptr;
        *curr_this_node_address = temp; // assigns value using this node address

        // push left subtree
        stackvar<KeyType, ItemType> left_subtree_root;
        left_subtree_root.node_to_copy = curr_node_to_copy->left;
        left_subtree_root.this_node_address = &((*curr_this_node_address)->left); 
        s.push(left_subtree_root);

        // push right subtree
        stackvar<KeyType, ItemType> right_subtree_root;
        right_subtree_root.node_to_copy = curr_node_to_copy->right;
        right_subtree_root.this_node_address = &((*curr_this_node_address)->right);
        s.push(right_subtree_root);
    }
}


template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(BinarySearchTree<KeyType, ItemType> tree_to_copy)
{
    swap(tree_to_copy);
    return *this;
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::swap(BinarySearchTree<KeyType, ItemType>& tree_to_swap)
{
    std::swap(root, tree_to_swap.root);
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != nullptr) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = nullptr;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    bool found = search(key, curr, curr_parent);

    if (!found)
    {
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = key;
        temp->data = item;
        temp->left = nullptr;
        temp->right = nullptr;

        if (isEmpty())
        {
            root = temp;
            return true;
        }

        if (key < curr->key)
        {
            curr->left = temp;
        }
        else
        {
            curr->right = temp;
        }
        
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty() const
{
    return (root == nullptr);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item) const
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    bool found = search(key, curr, curr_parent);

    if (found) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false;

    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    bool found = search(key, curr, curr_parent);

    if (found)
    {
        if (curr->left == nullptr && curr->right == nullptr)
        {   
            if (curr_parent == nullptr)
            {   
                delete curr;
                root = nullptr;
                return true;
            }
            else
            {
                if (curr_parent->left == curr)
                {
                    curr_parent->left = nullptr;
                }
                else
                {
                    curr_parent->right = nullptr;
                }
                delete curr;
                return true;
            }
        }

        else if (curr->left == nullptr)
        {   
            if (curr_parent == nullptr)
            {
                root = curr->right;
                delete curr;
                return true;
            }
            else
            {
                if (curr_parent->right == curr)
                {
                    curr_parent->right = curr->right;
                }
                else
                {
                    curr_parent->left = curr->right;
                }
                delete curr;
                return true;
            }
        }

        else if (curr->right == nullptr)
        {
            if (curr_parent == nullptr)
            {
                root = curr->left;
                delete curr;
                return true;
            }
            else
            {
                if (curr_parent->left == curr)
                {
                    curr_parent->left = curr->left;
                }
                else
                {
                    curr_parent->right = curr->left;
                }
                delete curr;
                return true;
            }
        }

        else
        {   
            Node<KeyType, ItemType>* inorder;
            Node<KeyType, ItemType>* inorder_parent;
            inorder_successor(curr, inorder, inorder_parent);

            curr->data = inorder->data;
            curr->key = inorder->key;

            if (inorder_parent->left == inorder)
            {
                inorder_parent->left = inorder->right;
            }
            else
            {
                inorder_parent->right = inorder->right;
            }
            delete inorder;
            return true;
        }
    }

    return false; 
}


template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(KeyType arr[], int arr_size) {

    for (int i=0; i<arr_size; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[i] == arr[j])
            {
                throw std::logic_error("Duplicates found in array!!!11!1!1!");
            }
        }
    }

    for (int i=0; i<arr_size; i++)
    {
        insert(arr[i], arr[i]);
    }

    std::stack<Node<KeyType, ItemType>*> s;
    Node<KeyType, ItemType>* current = root;
    int i = 0;

    while (current != nullptr || !s.empty())
    {
        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        arr[i] = current->key;
        i++;

        current = current->right;
    }
}


template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder_successor(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& inorder, Node<KeyType, ItemType>*& inorder_parent)
{
    inorder_parent = curr;
    inorder = curr->right;
    while (inorder != nullptr && inorder->left != nullptr) {
        inorder_parent = inorder;
        inorder = inorder->left;
    }
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr,
    Node<KeyType, ItemType>*& curr_parent) const
{
    curr = root;
    curr_parent = nullptr;

    if (isEmpty())
        return false;
    
    while (true) {
        if (key == curr->key) {
            return true;
        } 
        if (key < curr->key) {
            if (curr->left != nullptr) {
                curr_parent = curr;
                curr = curr->left;
            } else {
                return false;
            }
        } else {
            if (curr->right != nullptr) {
                curr_parent = curr;
                curr = curr->right;
            } else {
                return false;
            }
        }
    }
}
#include "bst.h"

BSTree::BSTree(){
    this->root = nullptr;
}

BSTree::~BSTree(){
    destroy(root);
}

// public insert
void BSTree::insert(int num) {
    root = insert(root, num);
}

// private insert
Node* BSTree::insert(Node* node, int num) {
    if (node == nullptr) {
        return new Node(num);
    }

    if (num < node->data) {
        node->left_child = insert(node->left_child, num);
    }
    else if (num > node->data) {
        node->right_child = insert(node->right_child, num);
    }

    return node;
}

// public height
int BSTree::height(){
    return height(root);
}

// private height
int BSTree::height(Node* node) {
    if (node == nullptr) {
        return -1;
    }

    int left_height = height(node->left_child);
    int right_height = height(node->right_child);

    if (left_height > right_height) {
        return left_height + 1;
    }
    
    return right_height + 1;
}

// public preorder
void BSTree::preorder(std::ostream& os) {
    preorder(root, os);
    os << std::endl;
}

// private preorder
void BSTree::preorder(Node* node, std::ostream& os) {
    if (node) {
        os << node->data << " ";
        preorder(node->left_child, os);
        preorder(node->right_child, os);
    }
}

// public inorder
void BSTree::inorder(std::ostream& os) {
    inorder(root, os);
    os << std::endl;
}

// private inorder
void BSTree::inorder(Node* node, std::ostream& os) {
    if (node) {
        inorder(node->left_child, os);
        os << node->data << " ";
        inorder(node->right_child, os);
    }
}

// public postorder
void BSTree::postorder(std::ostream& os) {
    postorder(root, os);
    os << std::endl;
}

// private postorder
void BSTree::postorder(Node* node, std::ostream& os) {
    if (node) {
        postorder(node->left_child, os);
        postorder(node->right_child, os);
        os << node->data << " ";
    }
}

// public destroy
void BSTree::destroy() {
    destroy(root);
    root = nullptr;
}

// private destory
void BSTree::destroy(Node* node) {
    if (node) {
        destroy(node->left_child);
        destroy(node->right_child);
        delete node;
    }
}

// public search
bool BSTree::search(int num) {
    Node* current = root;

    while (current) {
        if (current->data == num) {
            return true;
        }
        else if (num < current->data) {
            current = current->left_child;
        }
        else {
            current = current->right_child;
        }
    }

    return false;
}

// public remove
void BSTree::remove(int num) {
    root = remove(root, num);
}

// private remove
Node* BSTree::remove(Node* node, int num) {
    if (node == nullptr) {
        return node;
    }

    if (num < node->data) {
        node->left_child = remove(node->left_child, num);
    }
    else if (num > node->data) {
        node->right_child = remove(node->right_child, num);
    }
    else {
        if (node->left_child == nullptr) {
            Node* temp = node->right_child;
            delete node;
            return temp;
        }
        else if (node->right_child == nullptr) {
            Node* temp = node->left_child;
            delete node;
            return temp;
        }

        Node* temp = node->right_child;

        while (temp && temp->left_child != nullptr) {
            temp = temp->left_child;
        }

        node->data = temp->data;
        node->right_child = remove(node->right_child, temp->data);
    }

    return node;
}
///AST=Write a C program to construct an abstract syntax tree for following statement a+a*(b-c)+(b-c)*d


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char value[10];
    struct ASTNode *left, *right;
} ASTNode;

// Helper function to create a new node
ASTNode* createNode(const char* val, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    strcpy(node->value, val);
    node->left = left;
    node->right = right;
    return node;
}

// Inorder traversal (prints structure of tree)
void inorder(ASTNode* root, int depth) {
    if (root == NULL) return;
    inorder(root->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("%s\n", root->value);
    inorder(root->left, depth + 1);
}

int main() {
    // Constructing AST manually for: a + a * (b - c) + (b - c) * d
    ASTNode* b = createNode("b", NULL, NULL);
    ASTNode* c = createNode("c", NULL, NULL);
    ASTNode* a1 = createNode("a", NULL, NULL);
    ASTNode* a2 = createNode("a", NULL, NULL);
    ASTNode* d = createNode("d", NULL, NULL);

    ASTNode* b_min_c1 = createNode("-", b, c);
    ASTNode* b_min_c2 = createNode("-", createNode("b", NULL, NULL), createNode("c", NULL, NULL)); // Separate instance

    ASTNode* a_mul_bminc = createNode("*", a1, b_min_c1);
    ASTNode* bminc_mul_d = createNode("*", b_min_c2, d);

    ASTNode* left_add = createNode("+", a2, a_mul_bminc);
    ASTNode* root = createNode("+", left_add, bminc_mul_d);

    printf("Inorder Traversal of AST:\n");
    inorder(root, 0);

    return 0;
}

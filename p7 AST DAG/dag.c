///.Write a C program to construct a DAG for following statement a+a*(b-c)+(b-c)*d


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DAGNode {
    char value[10];
    struct DAGNode *left, *right;
} DAGNode;

// Helper function to create or reuse subexpressions
DAGNode* createNode(const char* val, DAGNode* left, DAGNode* right) {
    DAGNode* node = (DAGNode*)malloc(sizeof(DAGNode));
    strcpy(node->value, val);
    node->left = left;
    node->right = right;
    return node;
}

// Print the DAG structure (inorder with depth)
void printDAG(DAGNode* root, int depth) {
    if (root == NULL) return;
    printDAG(root->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("%s\n", root->value);
    printDAG(root->left, depth + 1);
}

int main() {
    // Shared subexpressions reused
    DAGNode* a = createNode("a", NULL, NULL);
    DAGNode* b = createNode("b", NULL, NULL);
    DAGNode* c = createNode("c", NULL, NULL);
    DAGNode* d = createNode("d", NULL, NULL);

    // Shared subexpression (b - c)
    DAGNode* b_min_c = createNode("-", b, c);

    DAGNode* a_mul_bminc = createNode("*", a, b_min_c);
    DAGNode* bminc_mul_d = createNode("*", b_min_c, d);
    DAGNode* left_add = createNode("+", a, a_mul_bminc);
    DAGNode* root = createNode("+", left_add, bminc_mul_d);

    printf("Inorder Traversal of DAG:\n");
    printDAG(root, 0);

    return 0;
}

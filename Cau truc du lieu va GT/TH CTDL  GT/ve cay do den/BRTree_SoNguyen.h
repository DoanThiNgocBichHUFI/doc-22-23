#ifndef BRTree_SoNguyen_h
#define BRTree_SoNguyen_h

#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
using namespace std;

/* Khai báo kiểu dữ liệu của Node */
typedef int ItemType;

/* Khai báo thuộc tính color */
enum EColor { RED, BLACK };

/* Khai báo cấu trúc node */
struct BRTNode
{
	int Info;
	EColor Color;
	BRTNode *Left, *Right, *Parent;
};

/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTree
{
	BRTNode *Root;
};
//==================================================
BRTNode* createBRTNode(ItemType x);
void set_Color(int colorBackground, int colorText);
void showTNode(BRTNode *p);
void initBRTree(BRTree &brt);

void swapColors(EColor &color1, EColor &color2);
void swapInfos(ItemType &info1, ItemType &info2);

void showBRTree_PreOrder(BRTNode *root);
void showBRTree_InOrder(BRTNode *root);
void showBRTree_PostOrder(BRTNode *root);

void levelOrder(BRTNode *root);
void showLevelOrder(BRTNode *root);

void iterativePreOrder(BRTNode *root);
void showPreOrder(BRTNode *root);
void iterativeInOrder(BRTNode *root);
void showInOrder(BRTNode *root);
void iterativePostOrder(BRTNode *root);
void showPostOrder(BRTNode *root);

BRTNode* BRTInsert(BRTNode* root, BRTNode *pNew);
void rotateLeft(BRTNode *&root, BRTNode *&p);
void rotateRight(BRTNode *&root, BRTNode *&p);
void fixViolation(BRTNode *&root, BRTNode *&p);
void insert(BRTNode *&root, ItemType Info);

bool isOnLeft(BRTNode *p);
bool hasRedChild(BRTNode *p);
BRTNode *findUncle(BRTNode *p);
BRTNode *findSibling(BRTNode *p);
BRTNode *findSuccessor(BRTNode *p);
void fixDoubleBlack(BRTNode *&root, BRTNode *p);
BRTNode *BSTReplace(BRTNode *p);
void deleteNode(BRTNode *&root, BRTNode *pDelete);
BRTNode *search(BRTNode *root, ItemType x);
void deleteByInfo(BRTNode *&root, ItemType x);

#endif
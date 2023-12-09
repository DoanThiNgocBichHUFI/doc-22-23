#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct TNode
{//Định nghĩa kiểu dữ liệu cho 1 nút của cây nhị phân là TNode
	int Info;
	TNode* Left;
	TNode* Right;
};
struct BTree
{//Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
	TNode* Root;
};
//tạo nút
TNode* CreateTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat");
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
//tao cây rỗng
void InitBTree(BTree &bt)
{
	bt.Root = NULL;
}
//hiện node
//void ShowTNode(TNode* T)
//{
//	printf("%4d", T->Info);
//}
//thêm một nút
int InsertTNode(TNode* &root, TNode* p)
{
	if (p == NULL)
		return 0; //Thực hiện không thành công
	if (root == NULL) //Cây rỗng, nên thêm vào gốc
	{
		root = p;
		return 1; //Thực hiện thành công
	}
	if (root->Left == NULL)
		InsertTNode(root->Left, p); //Them ben trai
	else if (root->Right == NULL)
		InsertTNode(root->Right, p); //Them ben phai
	else
	{
		int x = rand() % 2;
		if (x == 0)
			InsertTNode(root->Left, p);
		else
			InsertTNode(root->Right, p);
	}
	return 1; //Thực hiện thành công
}
//tạo cây tự nhập
void CreatBTree(BTree &bt)
{
	int n, x;
	TNode* p;
	InitBTree(bt);
	cout << "Nhap n: ";
	cin >> n;
	cout << "nhap gia tri nut";
	for (int i = 0; i<n; i++)
	{
		cin >> x;
		p = CreateTNode(x);
		InsertTNode(bt.Root, p);
	}

}

void CreatBTreeAuto(BTree &bt)
{
	int n, x;
	TNode* p;
	InitBTree(bt);
	cout << "Nhap n: ";
	cin >> n;
	cout << "nhap gia tri nut";
	
	srand((unsigned)time(NULL));
	for (int i = 0; i<n; i++)
	{
		x = rand() % 99;
		p = CreateTNode(x);
		InsertTNode(bt.Root, p);
	}

}

//them nut p vào trái nut t

int InsertTNodeLeft(TNode* &T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0; //Thực hiện không thành công
	if (T->Left != NULL)
		return 0; //Đã tồn tại nút con trái của T
	T->Left = p;
	return 1; //Thực hiện thành công
}
//chèn nút p bên phải T
int InsertTNodeRight(TNode* &T, TNode* p)
{
	if (T == NULL || p == NULL)
		return 0; //Thực hiện không thành công
	if (T->Right != NULL)
		return 0; //Đã tồn tại nút con phải của T
	T->Right = p;
	return 1; //Thực hiện thành công
}
TNode* FindTNode(TNode* root, int x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root;
	TNode* p = FindTNode(root->Left, x);
	if (p != NULL)
		return p;
	else
		return FindTNode(root->Right, x);
}

void NLR(TNode *root){
	if (!root)
		return;
	printf("%d ", root->Info);
	NLR(root->Left);
	NLR(root->Right);
}

int demNode(TNode *root){

	int dem = 0;
	if (!root)
		return 0;
	dem++;
	dem += demNode(root->Left);
	dem += demNode(root->Right);
	return dem;
}

int tongNode(TNode *root){
	int tong = 0;
	if (!root)
		return 0;
	tong += root->Info;
	tong += tongNode( root->Left);
	tong += tongNode(root->Right);
	return tong;
}

void showNode(TNode *root){
	if (!root)
		return;
	printf("%d ", root->Info);
	showNode(root->Left);
	showNode(root->Right);
}

void lietKeLa(TNode *root){
	if (!root)
		return;
	if (!root->Left && !root->Right){
		printf("%d ", root->Info);
		showNode(root->Left);
		showNode(root->Right);
	}
}


// tim chieu cao
int highTree(TNode *root){
	int hl, hr;
	if (!root)
		return 0;
	hl = highTree(root->Left);
	hr = highTree(root->Right);
	if (hl > hr)
		return hl + 1;
	else
		return hr + 1;
}
// xoa toan bo cay
void delTree(TNode *root){
	if (!root)
		return;
	delTree(root->Left);
	delTree(root->Right);
	delete root;
}

int Max(TNode *root){
	int maxl, maxr, max;
	if (!root->Left && !root->Right)
		return root->Info;
	
	maxl = Max(root->Left);
	maxr = Max(root->Right);
	max = root->Info;
	max = max > maxl ? max : maxl;
	max = max > maxr ? max : maxl;
	return max;
}

void LNR(TNode *root)
{
	if (!root)
		return;
	LNR(root->Left);
	printf("%3d", root->Info);
	LNR(root->Right);
}

int demNodeNutLa(TNode *root){

	int dem = 0;
	if (!root)
		return 0;
	if (!root->Left && !root->Right){
		dem++;
	}
	dem += demNodeNutLa(root->Left);
	dem += demNodeNutLa(root->Right);
	return dem;
}

int demNodeCo2con(TNode *root){

	int dem = 0;
	if (!root)
		return 0;
	if (root->Left && root->Right){
		dem++;
	}
	dem += demNodeCo2con(root->Left);
	dem += demNodeCo2con(root->Right);
	return dem;
}

int demNodeCo1con(TNode *root){

	int dem = 0;
	if (!root)
		return 0;
	if ((!root->Left && root->Right) || (root->Left && !root->Right)){
		dem++;
	}
	dem += demNodeCo1con(root->Left);
	dem += demNodeCo1con(root->Right);
	return dem;
}

int sumTNodeOneChild(TNode *root){
    int KQ=0;
    if(root == NULL)
        return 0;
    if(root->Left != NULL && root->Right != NULL)
        KQ += root->Info;
    KQ += sumTNodeOneChild(root->Left);
    KQ += sumTNodeOneChild(root->Right);
    return KQ;
}

int sumTNodeTwoChild(TNode *root){
    int KQ=0;
    if(root == NULL)
        return 0;
    if(root->Left != NULL && root->Right != NULL)
        KQ += root->Info;
    KQ += sumTNodeTwoChild(root->Left);
    KQ += sumTNodeTwoChild(root->Right);
    return KQ;
}

void Menu()
{
	cout << "---------------MENU--------------\n";
	cout << "1. Tao cay tu nhap.\n";
	cout << "2. Tao cay tu mang co san.\n";
	cout << "3. Tao cay tu dong.\n";
	cout << "4. Duyet cay.\n";
	cout << "5. Them nut x ben trai nut y.\n";
	cout << "6. Them nut x ben phai nut y.\n";
	cout << "7. Dem so nut cay.\n";
	cout << "8. Tim mot nut X.\n";
	cout << "9. Liet ke nut la > X.\n";
	cout << "10. Dem so nut la,so nut co 1 con...\n";
	printf("\n 11. Tim max.\n");
	cout << "---------------------------------\n";
}

void process(){
    int chon;
    int a[]= (10,20,45,6,8, 79,54,69,30,9);
    BTree bt;
    TNode *p, *q;
    int x;
    bt.Root= NULL;
    do{
        Menu();
		do
		{
			printf("\nBan hay chon mot chuc nang (0->10): ");
			scanf("%d", &chon);

            switch(chon){
                case 1:
                    CreatBTree(bt);
                    printf("\n Xuat cay NLR: ");
                    NLR(bt.Root);
                    printf("\n");
                    break;
                case 2:
                    CreatBTreeAuto(bt);
                    NLR(bt.Root);
                    printf("\n");
                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:
                    printf("\n Nhap nut T can them ben trai: ");
                    cin >> x;
                    q = FindTNode(bt.Root, x);
                    printf("\n Nhap gia tri nut can them: ");
                    cin >> x;
                    p = CreateTNode(x);
                    if (InsertTNodeLeft(q, p)){
                        printf("\n Duyet cay NLR: ");
                        NLR(bt.Root);
                        printf("\n");
                    } else
                    printf("\n Khong the them.\n");

                    break;
                case 6:
                    printf("\n Nhap nut can them ben phai: ");
                    cin >> x;
                    q = FindTNode(bt.Root, x);
                    printf("\n Nhap gia tri nut can them: ");
                    cin >> x;
                    p = CreateTNode(x);
                    if (InsertTNodeRight(q, p)){
                        printf("\n Duyet cay NLR: ");
                        NLR(bt.Root);
                        printf("\n");
                    } else
                    printf("\n Ko the them.");
                    break;
                case 7:
                    showNode(bt.Root);
                    printf("\n So nut cua cay: %d\n", demNode(bt.Root));
                    break;
                case 8:
                    break;
                case 9:
                                                                                                                                                                     
                    break;
                case 10:

                    printf("\n So nut la: %d\n", demNodeNutLa(bt.Root));
                    printf("\n So nut 1 con: %d\n", demNodeCo1con(bt.Root));
                    printf("\n So nut co 2 con: %d\n", demNodeCo2con(bt.Root));
                    printf("\n Tong so nut: %d", tongNode(bt.Root));

                    //printf("\n Tong so nut la: %d", );
                    break;
                case 11:
                    //showNode(bt.Root);
                    NLR(bt.Root);
                    printf("\n Tim max: %d", Max(bt.Root));
                    break;
            }
		} while (chon < 0 || chon > 11);


    }while(chon !=0);
}

int main()
{
	process();
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <stack>
using namespace std;
struct TNode
{ // Định nghĩa kiểu dữ liệu cho 1 nút của cây nhị phân là TNode
    int Info;
    TNode *Left;
    TNode *Right;
};
struct BTree
{ // Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
    TNode *Root;
};
TNode *CreateTNode(int x)
{
    TNode *p = new TNode;
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
void ShowTNode(TNode *T)
{
    printf("%4d", T->Info);
}
// tạo cây rỗng
void InitBTree(BTree &bt)
{
    bt.Root = NULL;
}
// chèn nút p bên trái T
void InsertTNode(TNode *&root, TNode *p)
{
    if (p == NULL)
        return;       // Thực hiện không thành công
    if (root == NULL) // Cây rỗng, nên thêm vào gốc
    {
        root = p;
        return; // Thực hiện thành công
    }
    if (root->Info == p->Info)
        return;
    if (p->Info < root->Info)
        InsertTNode(root->Left, p); // Them ben trái
    else
        InsertTNode(root->Right, p); // Thực hiện thành công
}
void CreatBTree(BTree &bt)
{
    int n, x;
    TNode *p;
    InitBTree(bt);
    printf("Nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("nhap gia tri nut %d: ", i);
        scanf("%d", &x);
        p = CreateTNode(x);
        InsertTNode(bt.Root, p);
    }
}
// duyet theo chieu rong
void BreadthNLR(TNode *root)
{
    if (root == NULL)
        return;
    queue<TNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TNode *p;
        p = q.front();
        q.pop();
        ShowTNode(p);
        if (p->Left != NULL)
            q.push(p->Left);
        if (p->Right != NULL)
            q.push(p->Right);
    }
}
void DepthNLR(TNode *root)
{
    stack<TNode *> q;
    TNode *p;
    q.push(root);
    while (!q.empty())
    {
        p = q.top();
        q.pop();
        ShowTNode(p);
        if (p->Right != NULL)
            q.push(p->Right);
        if (p->Left != NULL)
            q.push(p->Left);
    }
}
TNode *FindTNode(TNode *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->Info == x)
        return root;
    else if (root->Info > x)
        return FindTNode(root->Left, x);
    else
        return FindTNode(root->Right, x);
}

TNode *FindTNodeTheMang(TNode *&p)
{                        // Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
    TNode *f = p;        // 30
    TNode *q = p->Right; // 35
    while (q->Left != NULL)
    {
        f = q;         // Lưu nút cha của q
        q = q->Left;   // q qua bên trái//
    }                  //
    p->Info = q->Info; // Tìm được phần tử thế mạng cho p là q
    if (f == p)        // Nếu cha của q là p
        f->Right = q->Right;
    else
        f->Left = q->Right;
    return q; // trả về nút q là nút thế mạng cho p
}
int DeleteTNodeX(TNode *&root, int x)
{                     // Hàm xóa nút có giá trị là x
    if (root == NULL) // Khi cây rỗng
        return 0;     // Xóa không thành công
    if (root->Info > x)
        return DeleteTNodeX(root->Left, x);
    else if (root->Info < x)
        return DeleteTNodeX(root->Right, x);
    else
    { // rootInfo = x, tìm nút thế mạng cho root
        TNode *p = root;
        if (root->Left == NULL) // khi cây con không có nhánh trái
        {
            root = root->Right;
            delete p;
        }
        else if (root->Right == NULL) // khi cây con không có nhánh phải
        {
            root = root->Left;
            delete p;
        }
        else
        { // khi cây con có cả 2 nhánh, chọn min của nhánh phải để thế mạng
            TNode *q = FindTNodeTheMang(p);
            delete q; // Xóa nút q là nút thế mạng cho p
        }
        return 1; // Xóa thành công
    }
}

void createTreeArray(BTree &bt, int a[], int n)
{
    int i, x;
    for (i = 0; i < n; i++)
    {
        x = a[i];
        InsertTNode(bt.Root, CreateTNode(x));
    }
}

void CreatBTreeAuto(BTree &bt)
{
    int n, x;
    TNode *p;
    InitBTree(bt);
    cout << "Nhap n: ";
    cin >> n;
    cout << "nhap gia tri nut";

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        x = rand() % 99;
        p = CreateTNode(x);
        InsertTNode(bt.Root, p);
    }
}

void LNR(TNode *root)
{
    if (!root)
        return;
    LNR(root->Left);
    printf("%3d", root->Info);
    LNR(root->Right);
}

void RNL(TNode *root)
{
    if (!root)
        return;
    RNL(root->Right);
    printf("%3d", root->Info);
    RNL(root->Left);
}

int demNodeX_Y(TNode *root, int x, int y)
{

    int dem = 0;
    if (!root)
        return 0;
    if (root->Info > x && root->Info < y)
    {
        dem++;
    }
    dem += demNodeX_Y(root->Left, x, y);
    dem += demNodeX_Y(root->Right, x, y);
    return dem;
}

int demNodeNhoHonX(TNode *root, int x)
{
    int dem = 0;
    if (!root)
        return 0;
    if (root->Info < x)
        dem++;
    dem += demNodeNhoHonX(root->Left, x);
    dem += demNodeNhoHonX(root->Right, x);
    return dem;
}

int demNodeLonHonX(TNode *root, int x)
{
    int dem = 0;
    if (!root)
        return 0;
    if (root->Info > x)
        dem++;
    dem += demNodeNhoHonX(root->Left, x);
    dem += demNodeNhoHonX(root->Right, x);
    return dem;
}

int demMucK(TNode *root, int k)
{
    int dem = 0;
    if (!root)
        return 0;
    if (k == 0)
        dem++;
    k--;
    dem += demMucK(root->Left, k);
    dem += demMucK(root->Right, k);
    return dem;
}

int demSoNutLaMucK(TNode *root, int k)
{
    int dem = 0;
    if (!root)
        return 0;
    if (k == 0 && (!root->Left && !root->Right))
        dem++;
    k--;
    dem += demSoNutLaMucK(root->Left, k);
    dem += demSoNutLaMucK(root->Right, k);
    return dem;
}

void showNodeMucK(TNode *root, int k)
{
    if (!root)
        return;
    if (k == 0)
        printf("%3d", root->Info);
    k--;
    showNodeMucK(root->Left, k);
    showNodeMucK(root->Right, k);
}

void showNodeLaMucK(TNode *root, int k)
{
    if (!root)
        return;
    if (k == 0 && (!root->Left && !root->Right))
        printf("%3d", root->Info);
    k--;
    showNodeLaMucK(root->Left, k);
    showNodeLaMucK(root->Right, k);
}

void createBTree_FromFile(BTree &bt, char fileName[])
{
    FILE *f;
    f = fopen(fileName, "rt");
    if (!f)
        return;
    int n;
    fscanf(f, "%d", &n);
    int x;
    InitBTree(bt);
    for (int i = 1; i <= n; i++)
    {
        fscanf(f, "%d", &x);
        TNode *p = CreateTNode(x);
        InsertTNode(bt.Root, p);
    }
    fclose(f);
}

void Menu()
{
    cout << "\n---------------MENU--------------\n";
    cout << "1. Tao cay tu mang.\n";
    cout << "2. Tao cay doc file.\n";
    cout << "3. Tao cay tu dong.\n";
    cout << "4. Duyet cay.\n";
    cout << "5. Duyet theo chieu rong.\n";
    cout << "6. Them nut x .\n";
    cout << "7. Xuat cac nut theo chieu giam dan.\n"; // giảm RNL còn tăng LNR
    cout << "8. Tim mot nut X.\n";
    cout << "9.Xoa nut X.\n";
    cout << "10. Dem so co gia tri >x,<x, trong khoang [x,y]\n";
    cout << "11. Nut Min, Max: \n";
    cout << "12. Xuat noi dung nut muc k,nut la muc k: \n";
    cout << "13. Dem so nut muc k,nut la muc k: \n";
    cout << "14. Tong Am - Duong: \n";
    cout << "15. Phan tu gan nut X nhat, Phan tu xa X nhat\n";
    cout << "16. Dem so nut cua cay\n";
    cout << "17. Dem SNT,soCP,soHH: \n";
    cout << "18. Tong SNT,SCP, SHH: \n";
    cout << "19. Xoa cay:\n";
    cout << "20. Chieu cao cay\n";
    cout << "---------------------------------\n";
}
void Process()
{
    int Chon, n;
    int a[] = {40, 20, 45, 6, 7, 79, 54, 64, 30, 9};
    n = 10;
    BTree bt;
    TNode *p;
    int x, y, k;
    bt.Root = NULL;
    do
    {
        Menu();
        do
        {
            printf("\nBan hay chon mot chuc nang (0->10): ");
            scanf_s("%d", &Chon);
        } while (Chon < 0 || Chon > 20);
        switch (Chon)
        {
        case 1:
            createTreeArray(bt, a, n);
            BreadthNLR(bt.Root);
            break;
        case 2:
            // CreatBTree(bt);
            // BreadthNLR(bt.Root);

            break;
        case 3:
            CreatBTreeAuto(bt);
            BreadthNLR(bt.Root);
            break;
        case 4:
        case 5:
        case 6:
            printf("\n Nhap pt can them: ");
            scanf("%d", &x);
            InsertTNode(bt.Root, CreateTNode(x));
            printf("\n Duyet cay theo chieu rong: ");
            BreadthNLR(bt.Root);
            break;
        case 7:
            printf("\n Xuat cay theo chieu giam dan: ");
            RNL(bt.Root);
            printf("\n Xuat cay theo chieu tang dan: ");
            LNR(bt.Root);
            break;
        case 8:
            printf("\n Nhap gia tri can tim: ");
            scanf("%d", &x);
            if (FindTNode(bt.Root, x) != NULL)
                printf("\n Tim thay: %d", x);
            else
                printf("\n Khong tim thay: %d", x);
            break;
        case 9:
            printf("\n Nhap pt can xoa: ");
            scanf("%d", &x);
            DeleteTNodeX(bt.Root, x);
            printf("\n Duyet cay theo chieu rong: \n");
            BreadthNLR(bt.Root);
            break;
        case 10:
            printf("\n So pt nho hon x: ");
            printf("\n Nhap x, y: ");
            scanf("%d", &x);
            scanf("%d", &y);
            printf("\n So pt nho hon x: ");
            printf("\n %d", demNodeNhoHonX(bt.Root, x));
            printf("\n So pt lon hon x: ");
            printf("\n %d", demNodeLonHonX(bt.Root, x));
            printf("\n So pt lon hon x va nho hon y la: ");
            printf("%d", demNodeX_Y(bt.Root, x, y));
            break;
        case 11:
            // printf("\n Gia tri max: %d", timMax(bt.Root));
            break;
        case 12:
            printf("\n Nhap muc k: ");
            scanf("%d", &k);
            printf("\n Xuat nut muc k: ");
            showNodeMucK(bt.Root, k);
            printf("\n Xuat nut la muc k: ");
            showNodeLaMucK(bt.Root, k);
            break;
        case 13:
            printf("\n Nhap muc k: ");
            scanf("%d", &k);
            printf("\n So nut muc k: %d", demMucK(bt.Root, k));
            printf("\n So nut cua nut la muc k: %d", demSoNutLaMucK(bt.Root, k));
            break;
        case 14:
            break;
        case 15:
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        }
    } while (Chon != 0);
}
int main()
{
    Process();
}
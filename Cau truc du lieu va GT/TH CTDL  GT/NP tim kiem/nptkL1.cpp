

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<stack>
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
TNode* CreateTNode(int x)
{
	TNode* p = new TNode;
	if(p == NULL)
	{
		printf("khong du bo nho de cap phat");
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
void ShowTNode(TNode* T)
{
	printf("%4d", T->Info);
}
//tạo cây rỗng
void InitBTree(BTree &bt)
{ 
	bt.Root = NULL;
}
//chèn nút p bên trái T
void InsertTNode(TNode* &root, TNode* p)
{
	//if(p == NULL)
	//	return 0; //Thực hiện không thành công
	if(root == NULL) //Cây rỗng, nên thêm vào gốc
	{
		root = p;
		return ; //Thực hiện thành công
	}
	if(root->Info==p->Info)
		return ;
	if(p->Info<root->Info)
		InsertTNode(root->Left, p); //Them ben trái
	else
		InsertTNode(root->Right,p);	 //Thực hiện thành công
}
void CreateBTreeFromArray(BTree &bt, int a[])
{//Ham tao cay NPTK tu mang a
	InitBTree(bt);
	for(int i = 0; i < 10; i++)
	{
		TNode* p = CreateTNode(a[i]);
		InsertTNode(bt.Root, p);
	}
}
void CreatBTree(BTree &bt)
{
	int n,x;
	TNode* p;
	InitBTree(bt);
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("nhap gia tri nut");
	for(int i=0;i<n;i++)
	{
			scanf("%d",&x);
			p=CreateTNode(x);
			InsertTNode(bt.Root,p);
	}
	
}
void CreateBTree_Automatic(BTree &bt)
{
	int n;
	int x;
	printf("cho biet nut cua cay: ");
	scanf_s("%d", &n);
	InitBTree(bt);
	srand((unsigned)time(NULL));//Tạo số mới sau mỗi lần thực hiện
	for(int i = 1; i <= n; i++)
	{
		x = (rand()%199)-99 ; //Tạo 1 số ngẫu nhiên trong [-99, 99]
		TNode* p = CreateTNode(x);
		InsertTNode(bt.Root, p);
	}
}
TNode *Maxam(TNode *root)
{
	TNode *p=root;
	if(root->Info<0)
	{
		while(p->Right!=NULL&&p->Info<0)
			p=p->Right;
		return p;
	}
	else
	{
			while(p->Left!=NULL&&p->Info<0)
			p=p->Left;
				return p;
	}
}
//đoc file 
void taoDSTuFileText(BTree &bt, char fileName[])
{
	FILE *f = fopen(fileName, "r+");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	int x;
	InitBTree(bt);
	int n;
	fscanf(f,"%d",&n);
	//SNode *p;
	//while (!feof(f))
	for(int i=0;i<n;i++)
	{
		fscanf(f, "%d", &x);
		//TNode* p = CreateTNode(x);
		InsertTNode(bt.Root,CreateTNode(x));
	}
	fclose(f);
}
//duyet cay NLR
void NLR(TNode* root)
{
	if(root == NULL) return;
	printf("%4d", root->Info);
	NLR(root->Left);
	NLR(root->Right);
}
//duyet cay LNR
void LNR(TNode* root)
{
	if(root == NULL) 
		return;
	LNR(root->Left);
	printf("%4d", root->Info);
	LNR(root->Right);
}
//duyet cay LRN
void LRN(TNode* root)
{
	if(root == NULL) 
		return;
	LRN(root->Left);
	LRN(root->Right);
	printf("%4d", root->Info);
}
void NRL(TNode* root)
{
	if(root == NULL) return;
	printf("%4d", root->Info);
	NRL(root->Right);
	NRL(root->Left);
}
void RNL(TNode* root)
{
	if(root == NULL) return;
	RNL(root->Right);
	printf("%4d", root->Info);
	RNL(root->Left);
}
void RLN(TNode* root)
{
	if(root == NULL) return;
	RLN(root->Right);
	RLN(root->Left);
	printf("%4d", root->Info);
}
//duyet theo chieu rong
void BreadthNLR(TNode *root)
{
	if(root==NULL)
		return;
	queue <TNode *> q;
	q.push(root);
	while(!q.empty())
	{
		TNode *p;
		p=q.front();
		q.pop();
		ShowTNode(p);
		if(p->Left!=NULL)
			q.push(p->Left);
		if(p->Right!=NULL)
			q.push(p->Right);

	}

}
void BreadthNRL(TNode *root)
{
	if(root==NULL)
		return;
	queue <TNode *> q;
	q.push(root);
	while(!q.empty())
	{
		TNode *p;
		p=q.front();//nhận giá trị nút trên cùng
		q.pop(); //xóa giá trị trên cùng
		ShowTNode(p);
		if(p->Right!=NULL)
			q.push(p->Right);
		if(p->Left!=NULL)
			q.push(p->Left);

	}

}
void DepthNLR(TNode *root) 
{
	stack<TNode *>q;
	TNode *p;
	q.push(root);
	while (!q.empty()) 
	{
		p =q.top();
		q.pop();
		ShowTNode(p);
		if (p->Right != NULL) 
			q.push(p->Right);
		if(p->Left!=NULL)
			q.push(p->Left);
		
	}
}
//void depthLNR(TNode *root)
//{
//	TNode *p;
//	while(root)
//	{
//		if(root->Left==NULL)
//		{
//			printf("%d  ",root->Info);
//			root=root->Right;
//		}
//		else
//		{
//			p=root->Left;
//			while(p->Right&& p->Right!=root)
//			{
//				p=p->Right;
//			}
//			if(
//		}
//
//	}
//}
TNode* FindTNode(TNode* root, int x)
{
	if(root == NULL) 
		return NULL;
	if(root->Info == x) 
		return root;
	else if(root->Info > x)
		return FindTNode(root->Left, x);
	else
		return FindTNode(root->Right, x);
}

TNode* FindTNodeTheMang(TNode* &p)
{//Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
	TNode* f = p;//30
	TNode* q = p->Right;//35
	while(q->Left != NULL)
	{
		f = q; //Lưu nút cha của q 
		q = q->Left; //q qua bên trái//
	} //
	p->Info = q->Info; //Tìm được phần tử thế mạng cho p là q
	if(f == p) //Nếu cha của q là p
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q; //trả về nút q là nút thế mạng cho p
}
int DeleteTNodeX(TNode* &root, int x)
{//Hàm xóa nút có giá trị là x
	if(root == NULL) //Khi cây rỗng
		return 0; //Xóa không thành công
	if(root->Info > x)
		return DeleteTNodeX(root->Left, x);
	else if(root->Info < x)
		return DeleteTNodeX(root->Right, x);
	else
	{ //rootInfo = x, tìm nút thế mạng cho root
		TNode* p = root;
		if(root->Left == NULL) //khi cây con không có nhánh trái
		{
			root = root->Right;
			delete p;
		}
		else if(root->Right == NULL) //khi cây con không có nhánh phải
		{
			root = root->Left;
			delete p;
		}
		else
		{//khi cây con có cả 2 nhánh, chọn min của nhánh phải để thế mạng
			TNode* q = FindTNodeTheMang(p);
			delete q; //Xóa nút q là nút thế mạng cho p
		}
	return 1; //Xóa thành công
	}
}
int DemNodeLonhonx(TNode *root,int x)
{
	int KQ=0;
	if(root==NULL)
		return 0;
	if(root->Info>x)
		KQ++;
	KQ+=DemNodeLonhonx(root->Left,x);
	KQ+=DemNodeLonhonx(root->Right,x);
	return KQ;
}
int DemNodeNhohonx(TNode *root,int x)
{
	int KQ=0;
	if(root==NULL)
		return 0;
	if(root->Info<x)
		KQ++;
	KQ+=DemNodeNhohonx(root->Left,x);
	KQ+=DemNodeNhohonx(root->Right,x);
	return KQ;
}
int DemNodechan(TNode *root)
{
	int KQ=0;
	if(root==NULL)
		return 0;
	if(root->Info%2==0)
		KQ++;
	KQ+=DemNodechan(root->Left);
	KQ+=DemNodechan(root->Right);
	return KQ;
}
int DemNodelonhonXnhohonY(TNode *root,int x,int y)
{
	int KQ=0;
	if(root==NULL)
		return 0;
	if(root->Info>x && root->Info<y)
		KQ++;
	KQ+=DemNodelonhonXnhohonY(root->Left,x,y);
	KQ+=DemNodelonhonXnhohonY(root->Right,x,y);
	return KQ;
}
void ShowTNodeOfLevelK(TNode *root, int k)
{
	if(!root) 
		return;
	if(k == 0) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNodeOfLevelK(root->Left, k); //đệ quy trái
	ShowTNodeOfLevelK(root->Right, k);//đệ quy phải
}
void ShowTNodeIsLeafOfLevelK(TNode *root, int k)
{
	if(!root) 
		return;
	if(k == 0 && !root->Left && !root->Right) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
	ShowTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
}
void ShowTNode1conOfLevelK(TNode *root, int k)
{
	if(!root) 
		return;
	if(k == 0 && ((!root->Left &&root->Right) || (root->Left&&!root->Right))) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNode1conOfLevelK(root->Left, k); //đệ quy trái
	ShowTNode1conOfLevelK(root->Right, k);//đệ quy phải
}
void ShowTNode2conOfLevelK(TNode *root, int k)
{
	if(!root) 
		return;
	if(k == 0 && root->Left && root->Right) //đến mức cần tìm
		printf("%4d", root->Info);
	k--; //Mức k giảm dần về 0
	ShowTNode2conOfLevelK(root->Left, k); //đệ quy trái
	ShowTNode2conOfLevelK(root->Right, k);//đệ quy phải
}
int countTNodeOfLevelK(TNode *root, int k)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(k == 0) //đến mức cần tìm
		KQ++;
	k--; //Mức k giảm dần về 0
	KQ+=countTNodeOfLevelK(root->Left, k); //đệ quy trái
	KQ+=countTNodeOfLevelK(root->Right, k);//đệ quy phải
	return KQ;
}
int countTNodeIsLeafOfLevelK(TNode *root, int k)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(k == 0 && !root->Left && !root->Right) //đến mức cần tìm
		KQ++;

	k--; //Mức k giảm dần về 0
	KQ+=countTNodeIsLeafOfLevelK(root->Left, k); //đệ quy trái
	KQ+=countTNodeIsLeafOfLevelK(root->Right, k);//đệ quy phải
	return KQ;
}
int countTNode1conOfLevelK(TNode *root, int k)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(k == 0 && ((!root->Left &&root->Right) || (root->Left&&!root->Right))) //đến mức cần tìm
		KQ++;
	k--; //Mức k giảm dần về 0
	KQ+=countTNode1conOfLevelK(root->Left, k); //đệ quy trái
	KQ+=countTNode1conOfLevelK(root->Right, k);//đệ quy phải
	return KQ;
}
int countTNode2conOfLevelK(TNode *root, int k)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(k == 0 && root->Left && root->Right) //đến mức cần tìm
		KQ++;
	k--; //Mức k giảm dần về 0
	KQ+=countTNode2conOfLevelK(root->Left, k); //đệ quy trái
	KQ+=countTNode2conOfLevelK(root->Right, k);//đệ quy phải
	return KQ;
}
int sumNodeAm(TNode *root)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(root->Info<0)
		KQ+=root->Info;
	KQ+=sumNodeAm(root->Left); //đệ quy trái
	KQ+=sumNodeAm(root->Right);//đệ quy phải
	return KQ;
}
int sumNodeDuong(TNode *root)
{
	int KQ=0;
	if(!root) 
		return 0;
	if(root->Info>0)
		KQ+=root->Info;
	KQ+=sumNodeDuong(root->Left); //đệ quy trái
	KQ+=sumNodeDuong(root->Right);//đệ quy phải
	return KQ;
}
int TNodeMax(TNode* root)
{ //Ham tim nut co gia tri lon nhat cua cay
	TNode* p = root;
	while(p->Right != NULL)
		p = p->Right;
	return (p->Info);
}
int TNodeMin(TNode* root)
{ //Ham tim nut co gia tri lon nhat cua cay
	TNode* p = root;
	while(p->Left != NULL)
		p = p->Left;
	return (p->Info);
}
int minDistance(TNode* root, int x)
{
	if(!root)
		return -1;
	int min = root->Info;
	int mindis = abs(x - min);
	while(root != NULL)
	{
		if(root->Info == x)
			return x;
		if(mindis > abs(x - root->Info))
		{
			min = root->Info;
			mindis = abs(x - min);
		}
		if(x > root->Info)
			root = root->Right;
		else
			root = root->Left;
	}
	return min;
}
int maxDistance(TNode* root, int x)
{
	if(!root)
		return -1;
	TNode* minleft=root;
	while(minleft->Left != NULL)
		minleft = minleft->Left;
	TNode* maxRight = root;
	while(maxRight->Right != NULL) //Tìm nút phải nhất
		maxRight = maxRight->Right;
	int dis1 = abs(x - minleft->Info);
	int dis2 = abs(x - maxRight->Info);
	if(dis1 > dis2)
		return minleft->Info;
		else
			return maxRight->Info;
}
int SNT(int x)
{
	if(x<2)
		return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
void XoaSNT(TNode* &root)
{
	if(root)
	{
		XoaSNT(root->Left);
		XoaSNT(root->Right);
		if(SNT(root->Info))
			DeleteTNodeX(root,root->Info);
		

	}
}
int SCP(int x)
{
	for(int i=2;i*i<=x;i++)
		if(i*i==x)
			return 1;
	return 0;
}
//so hoan hảo là tong63cac1 ước = chinh no
int SHH(int n)
{
	int sum = 0;//khai bao biem sum
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum==n) 
		return 1; // tra ve true
    return 0;
}
int STV(int n)
{
	int sum = 0;//khai bao biem sum
    for(int i=1;i<=n/2;i++){
        if(n%i==0) 
            sum+=i;
    }
    if(sum>n) 
		return 1; // tra ve true
    return 0;
}
void ShowSNT(TNode* root)
{
	int KQ=0;
	if(!root)
		return ;
	else
	{
		if(SNT(root->Info))
			printf("%4d", root->Info);
		ShowSNT(root->Left);
		ShowSNT(root->Right);
	}

		
}
void ShowsoHH(TNode* root)
{
	
	if(!root)
		return ;
	else
	{
		if(SHH(root->Info))
			printf("%4d", root->Info);
		ShowsoHH(root->Left);
		ShowsoHH(root->Right);
	}

		
}
void ShowsoTV(TNode* root)
{
	if(!root)
		return;
	else
	{
		if(STV(root->Info))
			printf("%4d",root->Info);
		ShowsoTV(root->Left);
		ShowsoTV(root->Right);
	}
	
		
}
void ShowSCP(TNode* root)
{

	if(!root)
		return ;
	else
	{
		if(SCP(root->Info))
			printf("%4d",root->Info);
		ShowSCP(root->Left);
		ShowSCP(root->Right);
	}
	
		
}
int sumSNT(TNode* root)
{
	int KQ=0;
	if(!root)
		return 0;
	else
	{
		if(SNT(root->Info))
			KQ+=root->Info;
		KQ+=sumSNT(root->Left);
		KQ+=sumSNT(root->Right);
	}
	return KQ;
}
int sumSCP(TNode* root)
{
	int KQ=0;
	if(!root)
		return 0;
	else
	{
		if(SCP(root->Info))
			KQ+=root->Info;
		KQ+=sumSCP(root->Left);
		KQ+=sumSCP(root->Right);
	}
	return KQ;
}
int sumSHH(TNode* root)
{
	int KQ=0;
	if(!root)
		return 0;
	else
	{
		if(SHH(root->Info))
			KQ+=root->Info;
		KQ+=sumSHH(root->Left);
		KQ+=sumSHH(root->Right);
	}
	return KQ;
}
int sumSTV(TNode* root)
{
	int KQ=0;
	if(!root)
		return 0;
	else
	{
		if(STV(root->Info))
			KQ+=root->Info;
		KQ+=sumSTV(root->Left);
		KQ+=sumSTV(root->Right);
	}
	return KQ;
}
int Hightree(TNode* root)
{
	if(root==NULL)
		return 0;
	int hl=Hightree(root->Left);
	int hr=Hightree(root->Right);
	if(hl>hr)
		return (hl+1);
	else
		return (hr+1);
}
void DestroyTree(TNode* root)
{
	if(root)
	{
		DestroyTree(root->Left);
        DestroyTree(root->Right);
        delete root;
    }
}
void xoa(TNode* &root)
{
	if(root)
	{
		
		xoa(root->Left);
		xoa(root->Right);
		if(root->Info>50)
			DeleteTNodeX(root,root->Info);
	}

}
void Menu()
{
	cout<<"---------------MENU--------------\n";
	cout<<"1. Tao cay tu mang.\n";
	cout<<"2. Tao cay doc file.\n";
	cout<<"3. Tao cay tu dong.\n";
	cout<<"4. Duyet cay.\n";
	cout<<"5. Duyet theo chieu rong.\n";
	cout<<"6. Them nut x .\n";
	cout<<"7. Xuat cac nut theo chieu giam dan.\n";//giảm RNL còn tăng LNR
	cout<<"8. Tim mot nut X.\n";
	cout<<"9.Xoa nut X.\n";
	cout<<"10. Dem so co gia tri >x,<x, trong khoang [x,y]\n";
	cout<<"11. Nut Min, Max: \n";
	cout<<"12. Xuat noi dung nut muc k,nut la muc k: \n";
	cout<<"13. Dem so nut muc k,nut la muc k: \n";
	cout<<"14. Tong Am - Duong: \n";
	cout<<"15. Phan tu gan nut X nhat, Phan tu xa X nhat\n";
	cout<<"16. Dem so nut cua cay\n";
	cout<<"17. Dem SNT,soCP,soHH: \n";
	cout<<"18. Tong SNT,SCP, SHH: \n";
	cout<<"19. Xoa cay:\n";
	cout<<"20. Chieu cao cay\n";
	cout<<"---------------------------------\n";
}
void Process()
{
	int Chon;
	int a[]={40,20,45,6,7,79,54,64,30,9};
	BTree bt;
	TNode *p;
	int x;
	bt.Root=NULL;
	do
	{
		Menu();
		do
		{
			printf("\nBan hay chon mot chuc nang (0->10): ");
			scanf_s("%d", &Chon);
		}while(Chon < 0 || Chon > 20);
		switch(Chon)
		{
			case 1: 
				CreatBTree(bt);
				cout<<"Duyet theo NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 2:
				taoDSTuFileText(bt,"data.txt");
				cout<<"Duyet theo NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 3:
				CreateBTree_Automatic(bt);
				cout<<"Duyet theo NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 4:
				cout<<"Duyet cay NLR: ";
				NLR(bt.Root);
				cout<<"\nDuyet cay NLR: ";
				DepthNLR(bt.Root);
				cout<<endl;
				cout<<"Duyet cay LNR: ";
				LNR(bt.Root);
				cout<<endl;
				cout<<"Duyet cay LRN: ";
				LRN(bt.Root);
				cout<<endl;
				cout<<"Duyet cay NRL: ";
				NRL(bt.Root);
				cout<<endl;
				cout<<"Duyet cay RNL: ";
				RNL(bt.Root);
				cout<<endl;
				cout<<"Duyet cay RLN: ";
				RLN(bt.Root);
				cout<<endl;
			case 5:
				cout<<"Duyet cay theo chieu rong NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				cout<<"Duyet cay theo chieu rong NRL: ";
				BreadthNRL(bt.Root);
				cout<<endl;
			case 6:
				cout<<"Nhap gia tri can them: ";
				cin>>x;
				InsertTNode(bt.Root,CreateTNode(x));
				cout<<"Duyet cay theo chieu rong NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 7:
				cout<<"Nhap gia tri can tim: ";
				cin>>x;
				if(FindTNode(bt.Root,x)!=NULL)
					cout<<"Tim thay: "<<x<<endl;
				else
					cout<<"Khong tim thay: "<<x<<endl;
				break;
			case 8:
				cout<<"Nhap gia tri can xoa: ";
				cin>>x;
				DeleteTNodeX(bt.Root,x);
				cout<<"Duyet cay theo chieu rong NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 9:
				cout<<"Xuat theo chieu giam dan: ";
				RNL(bt.Root);
				cout<<endl;
				cout<<"Xuat theo chieu tang dan: ";
				LNR(bt.Root);
				cout<<endl;
				break;
			case 10:
				cout<<"So phan tu nho hon X la: ";
				cout<<DemNodeNhohonx(bt.Root,50)<<endl;
				cout<<"So phan tu lon hon X la: ";
				cout<<DemNodeLonhonx(bt.Root,50)<<endl;
				cout<<"So phan tu lon hon X va nho hon Y  la: ";
				printf("%d",DemNodelonhonXnhohonY(bt.Root,50,100));//<<endl;
				break;
			case 11:
				cout<<"Phan tu nho nhat: "<<TNodeMin(bt.Root)<<endl;
				cout<<"Phan tu lon nhat: "<<TNodeMax(bt.Root)<<endl;
				break;
			case 12:
				cout<<"so nut muc k: "<<countTNodeOfLevelK(bt.Root,2)<<endl;
				cout<<"La: ";
				ShowTNodeOfLevelK(bt.Root,2);
				cout<<endl;
				cout<<"so nut la muc k: "<<countTNodeIsLeafOfLevelK(bt.Root,2)<<endl;
				cout<<"La: ";
				ShowTNodeIsLeafOfLevelK(bt.Root,2);
				cout<<endl;
				cout<<"so nut 1con muc k: "<<countTNode1conOfLevelK(bt.Root,2)<<endl;
				cout<<"La: ";
				ShowTNode1conOfLevelK(bt.Root,2);
				cout<<endl;
				cout<<"so nut 2con muc k: "<<countTNode2conOfLevelK(bt.Root,2)<<endl;
				cout<<"La: ";
				ShowTNode2conOfLevelK(bt.Root,2);
				cout<<endl;
				break;
			case 13:
				cout<<"Tong nut am: "<<sumNodeAm(bt.Root)<<endl;
				cout<<"Tong nut duong: "<<sumNodeDuong(bt.Root)<<endl;
				break;
			case 14:
				cout<<"nhap gia tri can tim khoang cach gan nhat va xa nhat: ";
				cin>>x;
				cout<<"Khoang cach gan nhat: "<<minDistance(bt.Root,x)<<endl;
				cout<<"Khoang cach xa nhat: "<<maxDistance(bt.Root,x)<<endl;
				break;
			case 15:
				cout<<"cac so NT: ";
				ShowSNT(bt.Root);
				cout<<endl;
				cout<<"tong so nguyen to la: "<<sumSNT(bt.Root)<<endl;
				cout<<"cac so CP: ";
				ShowSCP(bt.Root);
				cout<<endl;
				cout<<"tong so chinh phuong la: "<<sumSCP(bt.Root)<<endl;
				cout<<"cac so HH: ";
				ShowsoHH(bt.Root);
				cout<<endl;
				cout<<"tong so hoan hao la: "<<sumSHH(bt.Root)<<endl;
				cout<<"cac so TV: ";
				ShowsoTV(bt.Root);
				cout<<endl;
				cout<<"tong so thinh vuong la: "<<sumSTV(bt.Root)<<endl;
			case 16:
				//xoa(bt.Root);
				XoaSNT(bt.Root);
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 17:
				cout<<"Nhap gia tri can xoa: ";
				cin>>x;
				printf("min khoang cach : %d",minDistance(bt.Root,x));
				break;
			case 18:
				p=Maxam(bt.Root);
				if(p)
					printf("%d",p->Info);
				break;
			case 19:
				DestroyTree(bt.Root);
				break;
		}
	}while(Chon != 0);
}
int main()
{
	Process();
}

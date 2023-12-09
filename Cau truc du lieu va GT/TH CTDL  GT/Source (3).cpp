#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<Windows.h>
#include<queue>
using namespace std;

typedef int ItemType;
enum EColor {RED,BLACK};
struct BTNode
{
	ItemType Info;
	EColor Color;
	BTNode *Left,*Right,*Parent;
};
struct BTree
{
	BTNode *Root;
};
BTNode* CreateTNode (ItemType x)
{
	BTNode *p=new BTNode;
	if(p==NULL)
	{
		cout<<"Khong the cap phat";
		return NULL;
	}
	p->Info=x;
	p->Color=RED;
	p->Left=NULL;
	p->Right=NULL;
	p->Parent=NULL;
	return p;
}
void setColor(int colorBackground,int colorText)
{
	HANDLE hColor=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor,colorBackground*16+colorText);
}
//hiện  nút
void ShowBTNode(BTNode *p)
{
	if(p->Color==RED)
		setColor(15,12);
	else if(p->Color==BLACK)
		setColor(15,0);
	printf("%4d",p->Info);
	setColor(0,7);
}
//tạo cây
void InitBTree(BTree &bt)
{
	bt.Root=NULL;
}
//hoan vi mau cùa 2 nút
void SwapColor(EColor &color1,EColor &color2)
{
	EColor tam=color1;
	color1=color2;
	color2=tam;
}
//hoan vị thông tin 2 nút
void SwapInfo(ItemType &Info1,ItemType &Info2)
{
	ItemType tam=Info1;
	Info1=Info2;
	Info2=tam;
}
//duyệt cây theo chiều rộng NLR
void  BreadthNLR(BTNode *root)
{
	if(root==NULL)
		return;
	queue<BTNode *>q;
	q.push(root);
	while(!q.empty())
	{
		BTNode *p=q.front();
		q.pop();
		ShowBTNode(p);
		if(p->Left!=NULL)
			q.push(p->Left);
		if(p->Right!=NULL)
			q.push(p->Right);
	}

}
//duyet cay theo chieu rong NRL
void BreadthNRL(BTNode *root)
{
	if(root==NULL)
		return;
	queue <BTNode *> q;
	q.push(root);
	while(!q.empty())
	{
		BTNode *p;
		p=q.front();
		q.pop();
		ShowBTNode(p);
		if(p->Right!=NULL)
			q.push(p->Right);
		if(p->Left!=NULL)
			q.push(p->Left);

	}

}
void ShowLevelOrder(BTNode *root)
{
	printf("\nIn theo thu tu cap :\n");
	if(root==NULL)
		printf("\nCay rong");
	else
		BreadthNLR(root);
}
//them nut vào cây đỏ đen
BTNode* BTInsert(BTNode* root,BTNode* pnew)
{
	if(root==NULL)
		return pnew;
	if(pnew->Info<root->Info)
	{
		root->Left=BTInsert(root->Left,pnew);
		root->Left->Parent=root;
	}
	else if(pnew->Info>root->Info)
	{
		root->Right=BTInsert(root->Right,pnew);
		root->Right->Parent=root;
	}
	return root;

}
//xoay nút trái
void RotateLeft(BTNode *&root,BTNode *&p)
{
	BTNode *pRight=p->Right;
	p->Right=pRight->Left;
	if(p->Right!=NULL)
		p->Right->Parent=p;
	pRight->Parent=p->Parent;
	if(p->Parent==NULL)
		root=pRight;
	else if(p==p->Parent->Left)
		p->Parent->Left=pRight;
	else
		p->Parent->Right=pRight;
	pRight->Left=p;
	p->Parent=pRight;
}
//xoay phải
void RotateRight(BTNode *&root,BTNode *&p)
{
	BTNode *pLeft=p->Left;
	p->Left=pLeft->Right;
	if(p->Left!=NULL)
		p->Left->Parent=p;
	pLeft->Parent=p->Parent;
	if(p->Parent==NULL)
		root=pLeft;
	else if(p==p->Parent->Left)
		p->Parent->Left=pLeft;
	else
		p->Parent->Right=pLeft;
	pLeft->Right=p;
	p->Parent=pLeft;
}
//cấu trúc lại sự cân bằng khi nút bị vi phạm
void fixViolation(BTNode *&root,BTNode *&p)
{
	BTNode *pParent=NULL;
	BTNode *pGrandParent=NULL;
	while((p!=root)&&(p->Color!=BLACK)&&(p->Parent->Color==RED))
	{
		pParent=p->Parent;
		pGrandParent=p->Parent->Parent;
		//trường hợp A: node cha của p là con trái của node cha của p
		if(pParent==pGrandParent->Left)
		{
			BTNode *pUncle=pGrandParent->Right;
			//trường hợp: 1 node chú của p là  node đỏkhi này chỉ cần đổi màu cho node đó thành đen
			if(pUncle!=NULL && pUncle->Color==RED)
			{
				pGrandParent->Color=RED;
				pParent->Color=BLACK;
				pUncle->Color=BLACK;
				p=pGrandParent;
			}
			else
			{
				//trường hợp 2: p là nut con phải của nut cha nó, ta thực hiện  xoay trái
				if(p==pParent->Right)
				{
					RotateLeft(root,pParent);
					p=pParent;
					pParent=p->Parent;
				}
				//trường hợp 3: p là con trái của node cha nó, thực hiện xoay phải
				RotateRight(root,pGrandParent);
				SwapColor(pParent->Color,pGrandParent->Color);
				p=pParent;
			}
		}
		//trường hợp B: node cha của p là con phải của node cha của node cha của p
		else
		{
			BTNode *pUncle=pGrandParent->Left;
			//trường hợp1: chú của p là node đỏ khi này chỉ cần đổi mau2cho node đó thành đen
			if(pUncle!=NULL && pUncle->Color==RED)
			{
			pGrandParent->Color=RED;
				pParent->Color=BLACK;
				pUncle->Color=BLACK;
				p=pGrandParent;
			}
			else
			{
				//trường hợp 2: p là con trái của node  cha nó, thực hiện xoay phải
				if(p==pParent->Left)
				{
					RotateRight(root,pParent);
					p=pParent;
					pParent=p->Parent;
				}
				//trường hợp 3: p là node con phải cua3 nod cha nó, thực hiện xoay trái
				RotateLeft(root,pGrandParent);
				SwapColor(pParent->Color,pGrandParent->Color);
				p=pParent;
			}
		}
	}
	root->Color=BLACK;
}
//thêm nút mới  với dữ liệu đã cho
void Insert(BTNode *&root,ItemType x)
{
	BTNode *pnew=CreateTNode(x);
	//thực hiện chèn
	root=BTInsert(root,pnew);
	//sửa lỗi qui tắc cây đỏ đen
	fixViolation(root,pnew);
}
//kiểm tra  nút ông bà
BTNode * Grandparent(BTNode *p)
{
	return p->Parent->Parent;
}

//kiểm tra nút con trai của cha
bool isOnLeft(BTNode *p)
{
	return p==p->Parent->Left;
}
//tìm nút chú của một nút
BTNode *findUncle(BTNode *p)
{
	if(p->Parent==NULL || p->Parent->Parent==NULL)
		return NULL;
	if(isOnLeft(p->Parent))
		//node chú phải
			return p->Parent->Parent->Right;
	else
		//node chú bên trái
		return p->Parent->Parent->Left;
}
//tìm nút anh em 
BTNode *findSibling(BTNode *p)
{
	//node anh rỗng nếu không tồn tại node cha
	if(p->Parent==NULL)
		return NULL;
	if(isOnLeft(p))
		return p->Parent->Right;
		return p->Parent->Left;
}
//di chuyển xuống  và i chuyển nút đã cho vào vị trí của nó
void moveDown(BTNode *p,BTNode *Parent)
{
	if(p->Parent!=NULL)
	{
		if(isOnLeft(p))
			p->Parent->Left=Parent;
		else
			p->Parent->Right=Parent;
	}
	Parent->Parent=p->Parent;
	p->Parent=Parent;

}
//tìm  nút không có con bên trái trong cây con của nút đã cho
BTNode *findSuccssor(BTNode *p)
{
	BTNode *tem=p;
	while(tem->Left!=NULL)
		tem=tem->Left;
	return tem;
}
//kiểm tra nút hiện tại có nút con là nút đỏ không
bool hasRedChild(BTNode *p)
{
	return (p->Left!=NULL && p->Left->Color==RED)||(p->Right!=NULL && p->Right->Color==RED);
}
//tìm  nút thế mạng cho nút bị xóa
BTNode *BTReplace(BTNode *p)
{
	//khi nut có 2 con
	if(p->Left!=NULL &&p->Right!=NULL)
		return findSuccssor(p->Right);
	//khi nút lá
	if(p->Left==NULL && p->Right==NULL)
		return NULL;
	//khi nút có 1 con
	if(p->Left!=NULL)
		return p->Left;
	else
		return p->Right;
}
void fixDoubleBlack(BTNode *&root,BTNode *p)
{
	//p là node gốc thì return
	if(p==root)
		return;
	BTNode *pSibling=findSibling(p);
	BTNode *pParent=p->Parent;
	if(pSibling==NULL)
	{
		//không có sibiling, màu đen kép được dẩy lên
		fixDoubleBlack(root,pParent);
	}
	else
	{
		if(pSibling->Color==RED)
		{
			//anh em màu đỏ
			pParent->Color=RED;
			pSibling->Color=BLACK;
			if(isOnLeft(pSibling))
			{
				//trường hợp left
				RotateRight(root,pParent);
			}
			else
				RotateLeft(root,pParent);
			fixDoubleBlack(root,p);
		}
		else
		{
			//anh em đen
			if(hasRedChild(pSibling))
			{
				//ít nhất một trẻ em màu đỏ
				if(pSibling->Left!=NULL && pSibling->Left->Color==RED)
				{
					if(isOnLeft(pSibling))
					{
						//left, left
						pSibling->Left->Color=pSibling->Color;
						pSibling->Color=pParent->Color;
						RotateRight(root,pParent);
					}
					else
					{
						//right - left
						pSibling->Left->Color=pParent->Color;
						RotateRight(root,pSibling);
						RotateLeft(root,pParent);
					}
				}
				else
				{
					if(isOnLeft(pSibling))
					{
							//left- right
						pSibling->Right->Color=pParent->Color;
						RotateLeft(root,pSibling);
						RotateRight(root,pParent);
					}
					else
					{
						//right -right
						pSibling->Right->Color=pSibling->Color;
						pSibling->Color=pParent->Color;
						RotateLeft(root,pParent);
					}
				}
				pParent->Color=BLACK;
			}
			else
			{
				//hai con đen
				pSibling->Color=RED;
				if(pParent->Color==BLACK)
					fixDoubleBlack(root,pParent);
				else
					pParent->Color=BLACK;
			}
		}
	}
}
//xóa nút bất kỳ
void deleteNode(BTNode *&root, BTNode *pDelete)
{
	BTNode *pReplace=BTReplace(pDelete);
	//đúng khi pReplce và pDelete đều đen
	bool flagDoubleBlack=((pReplace==NULL || pReplace->Color==BLACK) && (pDelete->Color==BLACK));
	BTNode *pParent=pDelete->Parent;
	if(pReplace==NULL)
	{
		//pReplace là NULL do đó pDelete là lá
		if(pDelete==root)
		{
		//pDelete là root, làm cho root là NULL
			root=NULL;
		}
		else
		{
			if (flagDoubleBlack)
			{
				//pReplace và pDelete đều đen
				//pDete là lá , sửa màu đen kép
				fixDoubleBlack(root,pDelete);
			}
			else
			{
				//pReplace hoặc pDelete là đỏ
				if(findSibling(pDelete)!=NULL)
					//node anh chị em không rỗng, làm cho nó màu đỏ
						findSibling(pDelete)->Color=RED;
			}
			//xóa delete khỏi cây
			if(isOnLeft(pDelete))
			{
				pParent->Left=NULL;
			}
			else
			{
				pParent->Right=NULL;
			}
		}
		delete pDelete;
		return;
	}
	if(pDelete->Left==NULL || pDelete->Right==NULL)
	{
		//pDelete có 1 con
		if(pDelete==root)
		{
			//gán giá trị cùa pReplace cho pDelete và xóa pReplace
			pDelete->Info=pReplace->Info;
			pDelete->Left=pDelete->Right=NULL;
			delete pReplace;
		}
		else
		{
			//tách node pDelete khỏi cây và di chuyển node pReplace lên
			if(isOnLeft(pDelete))
			{
				pParent->Left=pReplace;
			}
			else
			{
				pParent->Right=pReplace;
			}
			delete pDelete;
			pReplace->Parent=pParent;
			if(flagDoubleBlack)
			{
				//PReplace và pdelete đều đen sửa 2 màu đen ở Preplace
				fixDoubleBlack(root,pReplace);
			}
			else
			{
				//pReplace hoặc pDelete đỏ, màu pReplace đen
				pReplace->Color=BLACK;
			}
		}
		return;
	}
	//pDelete có 2 con, hoán đổi giá trị với nút thế mạng và đệ qui
	SwapInfo(pReplace->Info,pDelete->Info);
	deleteNode(root,pReplace);
}
BTNode *Search(BTNode *root, ItemType x)
{
	BTNode *tem=root;
	while(tem!=NULL)
	{
		if(x==tem->Info)
		{
			return tem;
		}
		else if(x<tem->Info)
		{
			tem=tem->Left;
		}
		else
			tem=tem->Right;
	}
	return NULL; //không tim thấy
}
void taoDSTuFileText(BTree &bt,char fileName[])
{
	FILE *f = fopen(fileName, "rt");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	ItemType x;
	//SNode *p;
	InitBTree(bt);
	int n;
	fscanf(f, "%d", &n);
	for (int i = 0; i < n;i++)
	{
		fscanf(f, "%d", &x);
	
		Insert(bt.Root,x);
	}
	fclose(f);
}
void CreateBTreeFromArray(BTree &bt, int a[])
{//Ham tao cay NPTK tu mang a
	InitBTree(bt);
	for(int i = 0; i < 10; i++)
	{
		Insert(bt.Root, a[i]);
	}
}
void NLR(BTNode* root)
{
	if(root == NULL) return;
	ShowBTNode(root);
	NLR(root->Left);
	NLR(root->Right);
}
//duyet cay LNR
void LNR(BTNode* root)
{
	if(root == NULL) 
		return;
	LNR(root->Left);
	ShowBTNode(root);
	LNR(root->Right);
}
//duyet cay LRN
void LRN(BTNode* root)
{
	if(root == NULL) 
		return;
	LRN(root->Left);
	LRN(root->Right);
	ShowBTNode(root);
}
void NRL(BTNode* root)
{
	if(root == NULL) return;
	ShowBTNode(root);
	NRL(root->Right);
	NRL(root->Left);
}
void RNL(BTNode* root)
{
	if(root == NULL) return;
	RNL(root->Right);
	ShowBTNode(root);
	RNL(root->Left);
}
void RLN(BTNode* root)
{
	if(root == NULL) return;
	RLN(root->Right);
	RLN(root->Left);
	ShowBTNode(root);
}

void Menu()
{
	cout<<"------------------MENU---------------------\n";
	cout<<"1. Tao cay tu mang.\n";
	cout<<"2. Tao cay bang cach doc du lieu tu file text\n";
	cout<<"3. Duyet cay 6 cach\n";
	cout<<"4. Duyet cay theo chieu rong\n";
	cout<<"5. Them 1 nut co gia tri x\n";
	cout<<"6. Xoa nut có gia tri X bat ky\n";
	cout<<"7. Tim nut co gia tri X tren cay\n";
	cout<<"8. Dem so nut do den\n";
	cout<<"9. Dem so nut do den o muc K\n";
	cout<<"10. tinh tong cac nut do den\n";
	cout<<"11. tinh tong cac nut do den muc k\n";
	cout<<"-------------------------------------------\n";
}
void Process()
{
	int Chon;
	int a[]={40,20,45,6,7,79,54,64,30,9};
	BTree bt;
	BTNode *p;
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
				CreateBTreeFromArray(bt,a);
				ShowLevelOrder(bt.Root);
				cout<<endl;
				break;
			case 2:
				taoDSTuFileText(bt,"data.txt");
				ShowLevelOrder(bt.Root);
				cout<<endl;
				break;
			case 3:
				cout<<"Duyet cay NLR: ";
				NLR(bt.Root);
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
				break;
			case 4:
				cout<<"Duyet cay theo chieu rong NLR: ";
				BreadthNLR(bt.Root);
				cout<<endl;
				cout<<"Duyet cay theo chieu rong NRL: ";
				BreadthNRL(bt.Root);
				cout<<endl;
				break;
			case 5:
				cout<<"Nhap gia tri can them: ";
				cin>>x;
				Insert(bt.Root,x);
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 6:
				cout<<"Nhap gia tri can xoa: ";
				cin>>x;
				p=Search(bt.Root,x);
				deleteNode(bt.Root,p);
				BreadthNLR(bt.Root);
				cout<<endl;
				break;
			case 7:
				cout<<"Nhap nut can tim: ";
				cin>>x;
				//p=CreateTNode(x);
				if(Search(bt.Root,x)!=NULL)
					cout<<"Tim thay: "<<x<<endl;
				else
					cout<<"Khong tim thay"<<endl;
				break;
			
		}
	}while(Chon != 0);
}
	int main()
{
    Process();
}
	
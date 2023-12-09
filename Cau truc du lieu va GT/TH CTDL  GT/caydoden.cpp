#include "btree.h"
//==================================================
BRTNode* createBRTNode(ItemType x)
{
	BRTNode* p = new BRTNode;
	if (p == NULL)
	{
		printf("\nKhong the cap phat nut moi!");
		getch();
		return NULL;
	}
	p->Info = x;		// Gán dữ liệu mới cho nút
	p->Color = RED;		// Gán màu đỏ (Red) mặc định
	p->Left = NULL;		// Chưa có nút con trái
	p->Right = NULL;	// Chưa có nút con phải
	p->Parent = NULL;	// Chưa có nút cha
	return p;
}
//==================================================
void set_Color(int colorBackground, int colorText) {
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
	/*	0 = Black       8 = Gray
	1 = Blue        9 = Light Blue
	2 = Green       A = Light Green
	3 = Aqua        B = Light Aqua
	4 = Red         C = Light Red
	5 = Purple      D = Light Purple
	6 = Yellow      E = Light Yellow
	7 = White       F = Bright White
	=> set_Color(X); -> X = a*16 + b, a (background) và b (character)
	*/
}
void showBRTNode(BRTNode *p)
{
	if (p->Color == RED)
		set_Color(15, 12);	//Light Red=12 (C), Bright White=15 (F)
	else if (p->Color == BLACK)
		set_Color(15, 0);	//Black=0, Bright White=15 (F)
	printf("%s  ", p->Info.Masach);
	printf("%s  ", p->Info.Tensach);
	printf("%s  ", p->Info.TenTG);
	printf("%d  ", p->Info.NamXB);
	printf("\n");
	set_Color(0, 7);		//Light Yellow=14 (E), Green=2
}
//==================================================
/* Initalize BRTree */
void initBRTree(BRTree &brt)
{
	brt.Root = NULL;
}

/* Hoán vị màu (Color) */
void swapColors(EColor &color1, EColor &color2)
{
	EColor temp = color1;
	color1 = color2;
	color2 = temp;
}

/* Hoán vị giá trị */
void swapInfos(ItemType &info1, ItemType &info2)
{
	ItemType temp = info1;
	info1 = info2;
	info2 = temp;
}
void LNR(BRTNode *root)
{
	if (root == NULL) return;

	LNR(root->Left);
	showBRTNode(root); //printf("%4d", root->Info);
	LNR(root->Right);
}
BRTNode* BRTInsert(BRTNode* root, BRTNode *pNew)
{
	/* Nếu cây trống thì trả về một BRTNode mới */
	if (root == NULL) return pNew;

	/* Nếu không thì tiếp tục duyệt xuống dưới cây */
	if (strcmp(pNew->Info.Masach,root->Info.Masach)==-1)
	{
		root->Left = BRTInsert(root->Left, pNew);
		root->Left->Parent = root;
	}
	else if (strcmp(pNew->Info.Masach,root->Info.Masach)==1)
	{
		root->Right = BRTInsert(root->Right, pNew);
		root->Right->Parent = root;
	}

	/* Trả về con trỏ BRTNode */
	return root;
}

/* Thuật toán xoay trái */
void rotateLeft(BRTNode *&root, BRTNode *&p)
{
	BRTNode *pRight = p->Right;

	p->Right = pRight->Left;

	if (p->Right != NULL)
		p->Right->Parent = p;

	pRight->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pRight;

	else if (p == p->Parent->Left)
		p->Parent->Left = pRight;

	else
		p->Parent->Right = pRight;

	pRight->Left = p;
	p->Parent = pRight;
}

/* Thuật toán xoay phải */
void rotateRight(BRTNode *&root, BRTNode *&p)
{
	BRTNode *pLeft = p->Left;

	p->Left = pLeft->Right;

	if (p->Left != NULL)
		p->Left->Parent = p;

	pLeft->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pLeft;

	else if (p == p->Parent->Left)
		p->Parent->Left = pLeft;

	else
		p->Parent->Right = pLeft;

	pLeft->Right = p;
	p->Parent = pLeft;
}

/* Sửa lại cấu trúc khi chèn BRTNode vào hoặc xóa node */
void fixViolation(BRTNode *&root, BRTNode *&pt)
{
	BRTNode *pParent = NULL;
	BRTNode *pGrandParent = NULL;

	while ((pt != root) && (pt->Color != BLACK) && (pt->Parent->Color == RED))
	{
		pParent = pt->Parent;
		pGrandParent = pt->Parent->Parent;

		/* Trường hợp A:
		node cha của pt là con trái của node cha của pt */
		if (pParent == pGrandParent->Left)
		{
			BRTNode *pUncle = pGrandParent->Right;

			/* Trường hợp: 1
			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
			if (pUncle != NULL && pUncle->Color == RED)
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				pt = pGrandParent;
			}

			else
			{
				/* Trường hợp: 2
				pt là node con phải của node cha nó ta thực hiện xoay trái */
				if (pt == pParent->Right)
				{
					rotateLeft(root, pParent);
					pt = pParent;
					pParent = pt->Parent;
				}

				/* Trường hợp: 3
				pt là con trái của node cha nó ta thực hiện xoay phải */
				rotateRight(root, pGrandParent);
				swapColors(pParent->Color, pGrandParent->Color);
				pt = pParent;
			}
		}

		/* Trường hợp: B
		node cha của pt là con phải của node cha của pt */
		else
		{
			BRTNode *pUncle = pGrandParent->Left;

			/* Trường hợp: 1
			node chú của pt là node đỏ khi này chỉ cần đổi màu cho node đó thành đen */
			if ((pUncle != NULL) && (pUncle->Color == RED))
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				pt = pGrandParent;
			}
			else
			{
				/* Trường hợp: 2
				pt là con trái của node cha nó ta thực hiện xoay phải */
				if (pt == pParent->Left)
				{
					rotateRight(root, pParent);
					pt = pParent;
					pParent = pt->Parent;
				}

				/* Trường hợp: 3
				pt là node con phải của node cha nó -> nên thực hiện xoay trái */
				rotateLeft(root, pGrandParent);
				swapColors(pParent->Color, pGrandParent->Color);
				pt = pParent;
			}
		}
	}

	root->Color = BLACK;
}

/* Chèn một node mới với dữ liệu đã cho */
void insert(BRTNode *&root, ItemType Info)
{
	BRTNode *pNew = createBRTNode(Info);

	/* Thực hiện chèn như bình thường */
	root = BRTInsert(root, pNew);

	/* Sửa lại lỗi của quy tắc cây đỏ đen */
	fixViolation(root, pNew);
}

/* Kiểm tra xem node hiện tại có phải là node con trái của node cha không */
bool isOnLeft(BRTNode *p)
{
	return p == p->Parent->Left;
}

/* Trả về con trỏ tới node chú (Uncle) */
BRTNode *findUncle(BRTNode *p) {
	// Nếu không có node cha hoặc node ông, thì không có node chú
	if (p->Parent == NULL || p->Parent->Parent == NULL)
		return NULL;

	if (isOnLeft(p->Parent))
		// node chú bên phải
		return p->Parent->Parent->Right;
	else
		// node chú bên trái
		return p->Parent->Parent->Left;
}

/* Trả về con trỏ cho node anh chị em */
BRTNode *findSibling(BRTNode *p) {
	// node anh rỗng nếu không tồn tại node cha 
	if (p->Parent == NULL)
		return NULL;

	if (isOnLeft(p))
		return p->Parent->Right;
	else
		return p->Parent->Left;
}

/* Tìm nút không có nút con bên trái trong cây con của nút đã cho */
BRTNode *findSuccessor(BRTNode *p) {
	BRTNode *temp = p;

	while (temp->Left != NULL)
		temp = temp->Left;

	return temp;
}

/* Kiểm tra có node hiện tại có node con là nút đỏ hay không */
bool hasRedChild(BRTNode *p) {
	return (p->Left != NULL && p->Left->Color == RED) ||
		(p->Right != NULL && p->Right->Color == RED);
}

/* Tìm nút thay thế nút đã xóa trong BST */
BRTNode *BSTReplace(BRTNode *p) {
	// Khi nút có 2 con
	if (p->Left != NULL && p->Right != NULL)
		return findSuccessor(p->Right);

	// Khi node lá 
	if (p->Left == NULL && p->Right == NULL)
		return NULL;

	// Khi node có một con
	if (p->Left != NULL)
		return p->Left;
	else
		return p->Right;
}

/* Xóa nút đã cho */
void deleteNode(BRTNode *&root, BRTNode *pDelete) {
	BRTNode *pReplace = BSTReplace(pDelete);

	// Đúng khi pReplace và pDelete đều đen
	bool flagDoubleBlack = ((pReplace == NULL || pReplace->Color == BLACK) && (pDelete->Color == BLACK));
	BRTNode *pParent = pDelete->Parent;

	if (pReplace == NULL) {
		// pReplace là NULL do đó pDelete là lá 
		if (pDelete == root) {
			// pDelete là root, làm cho root là NULL 
			root = NULL;
		}
		else {
			if (flagDoubleBlack) {
				// pReplace và pDelete đều đen
				// pDelete là lá, sửa màu đen kép tại pDelete 
				fixDoubleBlack(root, pDelete);
			}
			else {
				// pReplace hoặc pDelete là đỏ
				if (findSibling(pDelete) != NULL)
					// node anh chị em không rỗng, làm cho nó màu đỏ 
					findSibling(pDelete)->Color = RED;
			}

			// Xóa pDelete khỏi cây 
			if (isOnLeft(pDelete)) {
				pParent->Left = NULL;
			}
			else {
				pParent->Right = NULL;
			}
		}
		delete pDelete;
		return;
	}

	if (pDelete->Left == NULL || pDelete->Right == NULL) {
		// pDelete có 1 node con
		if (pDelete == root) {
			// pDelete là gốc, gán giá trị của pReplace cho pDelete và xóa pReplace 
			pDelete->Info = pReplace->Info;
			pDelete->Left = pDelete->Right = NULL;
			delete pReplace;
		}
		else {
			// Tách node pDelete khỏi cây và di chuyển node pReplace lên
			if (isOnLeft(pDelete)) {
				pParent->Left = pReplace;
			}
			else {
				pParent->Right = pReplace;
			}
			delete pDelete;
			pReplace->Parent = pParent;
			if (flagDoubleBlack) {
				// pReplace và pDelete đều đen, sửa hai màu đen ở pReplace 
				fixDoubleBlack(root, pReplace);
			}
			else {
				// pReplace hoặc pDelete đỏ, màu pReplace đen 
				pReplace->Color = BLACK;
			}
		}
		return;
	}

	// pDelete có 2 con, hoán đổi giá trị với nút kế nhiệm (thế mạng) và đệ quy 
	swapInfos(pReplace->Info, pDelete->Info);
	deleteNode(root, pReplace);
}

void fixDoubleBlack(BRTNode *&root, BRTNode *p) {
	// p là node gốc thì return
	if (p == root) return;

	BRTNode *pSibling = findSibling(p);
	BRTNode *pParent = p->Parent;
	if (pSibling == NULL) {
		// Không có sibiling, màu đen kép được đẩy lên 
		fixDoubleBlack(root, pParent);
	}
	else {
		if (pSibling->Color == RED) {
			// Anh chị em màu đỏ 
			pParent->Color = RED;
			pSibling->Color = BLACK;
			if (isOnLeft(pSibling)) {
				// trường hợp left 
				rotateRight(root, pParent);
			}
			else {
				// trường hợp right 
				rotateLeft(root, pParent);
			}
			fixDoubleBlack(root, p);
		}
		else {
			// Anh chị em đen 
			if (hasRedChild(pSibling)) {
				// Ist nhất 1 trẻ em màu đỏ 
				if (pSibling->Left != NULL && pSibling->Left->Color == RED) {
					if (isOnLeft(pSibling)) {
						// left left 
						pSibling->Left->Color = pSibling->Color;
						pSibling->Color = pParent->Color;
						rotateRight(root, pParent);
					}
					else {
						// right left 
						pSibling->Left->Color = pParent->Color;
						rotateRight(root, pSibling);
						rotateLeft(root, pParent);
					}
				}
				else {
					if (isOnLeft(pSibling)) {
						// left right 
						pSibling->Right->Color = pParent->Color;
						rotateLeft(root, pSibling);
						rotateRight(root, pParent);
					}
					else {
						// right right 
						pSibling->Right->Color = pSibling->Color;
						pSibling->Color = pParent->Color;
						rotateLeft(root, pParent);
					}
				}
				pParent->Color = BLACK;
			}
			else {
				// Hai con đen 
				pSibling->Color = RED;
				if (pParent->Color == BLACK)
					fixDoubleBlack(root, pParent);
				else
					pParent->Color = BLACK;
			}
		}
	}
}

/* Tìm kiếm một giá trị trên cây */
BRTNode *search(BRTNode *root, ItemType x) {
	BRTNode *temp = root;
	while (temp != NULL) {
		if (strcmp(x.Masach,temp->Info.Masach)==0) {
			return temp;
		}
		else if (strcmp(x.Masach,temp->Info.Masach)==-1) {
			temp = temp->Left;
		}
		else {
			temp = temp->Right;
		}
	}

	return NULL; //Không tìm thấy x trong cây
}
BRTNode *FindNode(BRTNode *root, char MS[]) {
	BRTNode *temp = root;
	while (temp != NULL) {
		if (strcmp(MS,temp->Info.Masach)==0) {
			return temp;
		}
		else if (strcmp(MS , temp->Info.Masach)==-1) {
			temp = temp->Left;
		}
		else {
			temp = temp->Right;
		}
	}

	return NULL; //Không tìm thấy x trong cây
}
BRTNode *FindNode1(BRTNode *root, char tentg[]) {
	if(root)
	{
		if (strcmp(tentg,root->Info.TenTG)==0) 
		{
			return root;
		}
		FindNode1(root->Left,tentg);
		FindNode1(root->Right,tentg);
	}
	return NULL; //Không tìm thấy x trong cây
}
void taoDSTuFileText(BRTree &bt, char fileName[])
{
	int n=0;
	ifstream in(fileName);
	initBRTree(bt);
	if(in)
	{
		in>>n;
		for(int i=1;i<=n;i++)
		{
			Sach S;
			in>>S.Masach;
			in>>S.Tensach;
			in>>S.TenTG;
			in>>S.NamXB;
			insert(bt.Root,S);
		}
	}
	in.close();
	
}
void xoa(BRTNode* &root, char tentg[])
{
	if(root)
	{
		xoa(root->Left,tentg);
		xoa(root->Right,tentg);
		if(strcmp(root->Info.TenTG,tentg)==0)
			deleteNode(root,root);
	}
}

void Process()
{
	int Chon;
	BRTree bt;
	BRTNode *p;
	int x;
	char a[30];
	bt.Root=NULL;
	do
	{
		
		do
		{
			printf("\nBan hay chon mot chuc nang (0->10): ");
			scanf_s("%d", &Chon);
		}while(Chon < 0 || Chon > 20);
		switch(Chon)
		{
			case 1:
				
				break;
			
				
		}
	}while(Chon != 0);
}

/* Hàm main để thực hiện kiểm tra kết quả */
void main()
{
	Process();	
}
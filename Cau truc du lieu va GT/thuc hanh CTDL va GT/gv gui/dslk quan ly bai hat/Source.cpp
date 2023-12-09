#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#define Max 100
using namespace std;
struct Baihat
{
	char tenBH[61];
	char tenTG[41];
	char tenCS[41];
	int thoiluong;
};
struct SNode
{
	Baihat Info; //Lưu thông tin của nút hiện hành.
	SNode* Next; //Con trỏ chỉ đến nút kế sau.
};
struct SList
{//Định nghĩa kiểu dữ liệu cho DSLK đơn SList
	SNode* Head; //Lưu địa chỉ nút đầu tiên trong SList
	SNode* Tail; //Lưu địa chỉ của nút cuối cùng trong SList
};

SNode* CreateSNode(Baihat x)
{
	SNode* p = new SNode;
	if(p==NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	} 
	p->Info = x;
	p->Next= NULL;
	return p;
}
void NhapBH(Baihat &x)
{
	
	printf("\nNhap ten bai hat: ");
	fflush(stdin);
	gets(x.tenBH);
	printf("\nNhap ten ca si: ");
	fflush(stdin);
	gets(x.tenCS);
	printf("\nNhap ten tac gia: ");
	fflush(stdin);
	gets(x.tenTG);
	printf("\nNhap thoi luong: ");
	fflush(stdin);
	//gets(x.thoiluong);
	scanf("%d",&x.thoiluong);
}
//Xuất nội dung của nút.
void ShowSNode(SNode* p)
{
	printf("%s ",p->Info.tenBH);
	printf("%s ",p->Info.tenCS);
	printf("%s ",p->Info.tenTG);
	printf("%d", p->Info.thoiluong);
}
//tạo List rỗng
void InitSList(SList &sl)
{ 
	sl.Head = NULL;
	sl.Tail = NULL;
}

//Kiểm tra danh sách rỗng.
int IsEmpty(SList sl)
{
	if(sl.Head == NULL)
		return 1; //Nếu danh sách rỗng
	else
		return 0; //Nếu danh sách không rỗng
}
//Duyệt danh sách.
void ShowSList(SList sl)
{
	system("cls");
	if(IsEmpty(sl) == 1)
	{
		printf("\nDanh sach rong");
		return;
	}
	printf("\nNoi dung cua danh sach la:\n");
	for(SNode* p = sl.Head; p!= NULL; p = p->Next)
	{
		ShowSNode(p);
		printf("\n");
	}
}
//Thêm nút p có giá trị x vào đầu danh sách.

void InsertHead(SList &sl, SNode *p)
{
	//SNode* p=CreateSNode(bh);
	if(p == NULL)
		return ; //Thực hiện không thành công
	if(IsEmpty(sl) == 1)
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	 //Thực hiện thành công
}
void InsertTail(SList &sl, SNode *p)
{
	//SNode *p=CreateSNode(bh);
	if(p == NULL)
		return ; //Thực hiện không thành công
	if(IsEmpty(sl) == 1)
	{
		sl.Head = sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	//Thực hiện thành công
}
//chèn new sau q
void  InsertAfter(SList &sl, SNode *q, SNode *newNode)
{
	if(q == NULL)
		return ; //Thực hiện không thành công
	newNode->Next = q->Next;
	q->Next = newNode;
	if(sl.Tail == q)
		sl.Tail = newNode;
	//return 1; //Thực hiện thành công
}

int len (SList L) 
{
	SNode *P=L.Head; //tao 1 Node P de duyet danh sach L
    int i=0; //bien dem
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; //tang bien dem
        P=P->Next; //cho P tro den Node tiep theo
    }
    return i; //tra lai so Node cua0 l
}

void DelHead(SList &sl)
{
	if(sl.Head==NULL)
		return;
	
		SNode *p=sl.Head;
		sl.Head=sl.Head->Next;
		delete p;
	
}
void DelTail(SList &sl)
{
	if(sl.Head==NULL)
		return;

	SNode *p,*r;
	p=sl.Head;
	r=sl.Tail;
	if(p==r) //danh ssach co 1 PT
	{		
		sl.Head=sl.Tail=NULL;
		delete p;
	}
	else
	{
		while(p->Next!=r)
			p=p->Next;
		p->Next=NULL;
		sl.Tail=p;
		delete r;
	}
}
void DelAfter(SList &sl, SNode *q)
{
	if(q==NULL)
	{
		printf("khong tim thay:");
		return;
	}
	SNode *p,*i;
	for(i=sl.Head;i!=NULL;i=i->Next)
		if(i==q)
		{
			if(sl.Tail==i->Next)
			{
				DelTail(sl);
				return;
			}
			else
			{
				p=i->Next;
				i->Next=i->Next->Next;
				delete p;
				return;
			}
		}
}
void DelBefore(SList &sl, SNode *q)
{
	if(q==NULL)
	{
		printf("khong tim thay:");
		return;
	}

	SNode *p,*i;
	for(i=sl.Head;i!=NULL;i=i->Next)
	{
		
		if(i->Next==q)
		{
			DelHead(sl);
			return;
		}
		if(i->Next->Next==q)
		{
			p=i->Next;
			//DelAfter(sl,i);
			//return;
			i->Next=i->Next->Next;
			delete p;
			return ;
		}
	}
}

void taoDSTuFileText(SList &sl, char* fileName)
{
	int n=0;
	ifstream in(fileName);
	InitSList(sl);
	if(in)
	{
		in>>n;
		for(int i=1;i<=n;i++)
		{
			SNode *p;
			Baihat bh;
			in>>bh.tenBH;
			in>>bh.tenCS;
			in>>bh.tenTG;
			in>>bh.thoiluong;
			p=CreateSNode(bh);
			InsertTail(sl,p);
		}
	}
	in.close();
	
}
void docfile(SList &l,char filename[])
{
	FILE *f=fopen(filename,"rt");
	if(!f)
		printf("Loi doc file");
	else
	{
		Baihat x;
		char b[5]="",a[5]="";
		int n;
		fscanf(f,"%[^\n]%*c",&b);
		n=atoi(b);
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%[^#]%*c%[^#]%*c%[^#]%*c%[^\n]%*c",&x.tenBH,&x.tenTG,&x.tenCS,&a);
			x.thoiluong=atoi(a);
			InsertTail(l,CreateSNode(x));
		}
	}

	fclose(f);
}

void docfile_ver2(SList &sl, char fileName[]){
	FILE *f= fopen(fileName,"rt");
	if(!f)
		printf("Loi doc file");
	else{
		int n;
		Baihat x;
		fscanf(f,"%d",&n);
		for(int i=0;i< n; i++){
			fscanf(f,"%[^#]%*c%[^#]%*c%[^#]%*c%[^\n]%*c",&x.tenBH,&x.tenTG,&x.tenCS,&x.thoiluong);
			InsertTail(sl,CreateSNode(x));
		}
	}
	fclose(f);
}

int Search (SList L, char x[]) //tim x trong danh sach
{
	SNode *P=L.Head; 
    int i=1;
	// while (P != NULL ) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    // {
	// 	if(strcmpi(P->Info.tenBH,x)==0)
	// 		break;
    //     P = P->Next;
    //     i++;
    // }
	
	while(P != NULL && strcmp(P->Info.tenBH,x) != 0){
		P= P->Next;
		i++;
	}

    if (P != NULL) 
		return i; //tra ve vi tri tim thay
    else 
		return 0; //khong tim thay
}



void delX(SList &sl, char x[]){
	int i=0;
	if(strcmp(sl.Head->Info.tenBH,x) ==0)
		DelHead(sl);
	else if(strcmp(sl.Tail->Info.tenBH,x) == 0)
		DelTail(sl);
	
}

void Del_k (SList &L, int k) //Xoa Node k trong danh sach
{
	SNode *P=L.Head;
    int i=1;
    if (k<1 || k>len(L)) printf("Vi tri xoa khong hop le !"); //kiem tra dieu kien
    else
    {
        if (k==1) 
		{	
			DelHead(L); //xoa vi tri dau tien
			//return;
		}
		else if(k==len(L))
		{
			DelTail(L);
			//return;
		}
        else //xoa vi tri k != 1
        {
            while (P != NULL && i !=k-1) //duyet den vi tri k-1
            {
                P=P->Next;
                i++;
            }
			//SNode *r=P->Next;
            P->Next = P->Next->Next;		//cho P tro sang Node ke tiep vi tri k
			//delete r;
			//return;
        }
    }
}

int TongThoiluong(SList sl)
{
	SNode *p;
	int Tong=0;
	if(sl.Head==NULL)
	{
		printf("sanh sach rong");
		return 0;
	}
	for(p=sl.Head;p!=NULL;p=p->Next)
		Tong+=p->Info.thoiluong;

}

void saptangTenBH(SList sl)
{
	SNode *i,*j;
	Baihat tam;
	for(i=sl.Head;i!=NULL;i=i->Next)
		for(j=i->Next;j!=NULL;j=j->Next)
			if(strcmp(i->Info.tenBH,j->Info.tenBH)==1)
			{
				tam=i->Info;
				i->Info=j->Info;
				j->Info=tam;
			}
}
void sapgiamTenCS(SList sl)
{
	SNode *i,*j;
	Baihat tam;
	for(i=sl.Head;i!=NULL;i=i->Next)
		for(j=i->Next;j!=NULL;j=j->Next)
			if(strcmp(i->Info.tenCS,j->Info.tenCS)==-1)
			{
				tam=i->Info;
				i->Info=j->Info;
				j->Info=tam;
			}
}
SNode* FindSNode(SList sl, char x[])
{
	if(IsEmpty(sl) == 1)
		return NULL;
	SNode* p = sl.Head;//aa=strupr(x),bbb=strupr(p->Info.TenBH)
	while( (p != NULL) && (strcmp(p->Info.tenBH,x) != 0))
		p = p->Next;
	return p; //có thể NULL: không tìm thấy, hoặc khác NULL: tìm thấy
}
void DuabaihatLD(SList &sl,char x[])
{
	SNode *p,*r;
	Baihat aa;
	p=FindSNode(sl,x);
	strcpy(aa.tenBH,p->Info.tenBH);
	strcpy(aa.tenCS,p->Info.tenCS);
	strcpy(aa.tenTG,p->Info.tenTG);
	aa.thoiluong=p->Info.thoiluong;
	r=CreateSNode(aa);
	if(p==NULL)
		printf("khong tim thay");
	else
	{
		
		if(p==sl.Tail)
			DelTail(sl);
		else
			Del_k(sl,Search(sl,x));//xoa p
		InsertHead(sl,r);
	}
}
void DelList(SList &sl)
{
	SNode *p;
	for(p=sl.Head;p!=NULL;p=p->Next)
	{
		DelHead(sl);
		p=sl.Head;
	}
	sl.Head=sl.Tail=NULL;
}
void Menu()
{
	printf("\n************MENU*******************");
	printf("\n0.Thoat chuong trinh");
	printf("\n1.Doc danh sach tu file");
	printf("\n2. In Danh sách");
	printf("\n3. Thoi luong nghe tat ca bai hat");
	printf("\n4. Them bai hat moi vao dau Danh sach");
	printf("\n5. Them bai hat moi vao cuoi Danh sach");
	printf("\n6. Xoa bai hat khoi danh sach");
	printf("\n7. Kiem tra bai hat X co trong danh sach");
	printf("\n8. Sap xep bai hat theo thu tu ten bai hat");
	printf("\n9. Sap xep bai hat theo thu tu giam dan theo ten ca si");
	printf("\n10.Dua bai hat len dau danh sach");
	printf("\n****************************");
}
void Process()
{
	SNode *p;
	int Chon,i;
	Baihat X;
	char x[Max];
	SList sl;
	InitSList(sl);
	do
	{
		Menu();
		do
		{
			printf("\nBan hay chon mot chuc nang (0->10): ");
			scanf("%d", &Chon);
		}while(Chon < 0 || Chon > 10);
		switch(Chon)
		{
			case 1:
				taoDSTuFileText(sl,"Data.txt");
				ShowSList(sl);
				break;
			case 2:
				docfile(sl,"filetext.txt");
				ShowSList (sl);
				break;
			case 3:
				printf("\n Tong thoi luong de nghe het cac bai hat: %d",TongThoiluong(sl));
				break;
			case 4:
				NhapBH(X);
				p=CreateSNode(X);
				InsertHead(sl,p);
				ShowSList(sl);
				break;
			case 5:
				NhapBH(X);
				p=CreateSNode(X);
				InsertTail(sl,p);
				ShowSList(sl);
				break;
			case 6:
				printf("\n nhap ten bai hat can xoa:");
				fflush(stdin);
				gets(x);
				Del_k(sl,Search(sl,x));
				ShowSList(sl);
				break;
			case 7:
				printf("\n nhap ten bai hat can tim:");
				fflush(stdin);
				gets(x);
				i=Search(sl,x);
				if(i>0)
				{
					printf("\nTim thay bai hat ");
					printf("\n Tai vi tri %d",i);
				}
				else
					printf("\n khong tim thay");
				break;
			case 8:
				saptangTenBH(sl);
				ShowSList(sl);
				break;
			case 9:
				sapgiamTenCS(sl);
				ShowSList(sl);
				break;
			case 10:
				printf("\n nhap ten bai hat can dua len dau:");
				fflush(stdin);
				cin>>x;
				DuabaihatLD(sl,x);
				ShowSList(sl);
				break;
		}
	}while(Chon != 0);
}
int main()
{
	Process();

}

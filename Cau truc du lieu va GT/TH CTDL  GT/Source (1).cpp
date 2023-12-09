#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
# define KEYSIZE 27
struct TD
{
	char TA[30];
	char TV[50];
};
typedef TD ItemType;
struct HashNode
{
	ItemType Key;
	HashNode* Next;
};
HashNode* bucket[KEYSIZE];

//hàm băm
int HashFuntion(int key)
{
	return key%KEYSIZE;
}
//phép toán khởi tạo
void InitBucket()
{
	for(int i=0;i<KEYSIZE;i++)
		bucket[i]=NULL;
}
//Thêm một node vào đầu bucket
void Push(int b, ItemType x)
{
	HashNode* p=new HashNode;
	p->Key=x;
	p->Next=bucket[b];
	bucket[b]=p;
}
//thêm vào bucket một node mới sau p
void InsertAfter(HashNode* p,ItemType k)
{
	if(p==NULL)
		printf("Khong them vao node moi");
	else
	{
		HashNode* q=new HashNode;
		q->Key=k;
		q->Next=p->Next;
		p->Next=q;
	}
}
//phép toán chèn khóa k vào danh sách liên kết
void Place(int b,ItemType k)
{
	HashNode* p,*q;
	q=NULL;
	for(p=bucket[b];p!=NULL && k.TA[0]>p->Key.TA[0];p=p->Next)
		q=p;
	if(q==NULL)
		Push(b,k);
	else
		InsertAfter(q,k);

}
//chèn phần tử có khóa k vào bảng băm
void Insert(ItemType k)
{
	int b=HashFuntion(k.TA[0]-65);
	Place(b,k);

}
//kiểm tra bucket rỗng
int IsEmptyBucket(int b)
{
	return (bucket[b]==NULL? 1:0);
}
//xóa nút ở đầu bucket
int pop(int b)
{
	HashNode* p;
	int k;
	if(IsEmptyBucket(b))
	{
		printf("Bucket %d rong, Khong xoa duoc",b);
		return 0;
	}
	p=bucket[b];
	k=p->Key.TA[0];
	bucket[b]=p->Next;
	delete p;
	return k;
	
}
//xóa nút ngay sau nút p
int DeleteAfter(HashNode* p)
{
	HashNode* q;
	int k;
	if(p==NULL || p->Next==NULL)
	{
		printf("\n khong xoa node duoc");
		return 0;
	}
	q=p->Next;
	k=q->Key.TA[0];
	p->Next=q->Next;
	delete q;
	return k;
}

void Remove(char k[]) {	
	HashNode *q, *p; 
	int b = HashFuntion(k[0]-65); 	//tìm vị trí trong bảng băm
	p = bucket[b]; //gán giá trị đầu tiên cuả phần từ thứ i trong bảng băm
	while(p != NULL && strcmp(p->Key.TA,k)!=0) 
	{
		q = p; 	
		p = p->Next; 	
	}
	if(p == NULL)
		printf("\n khong co nut co khoa %d", k); 
	else if(p == bucket[b]) 
		pop(b); 
	else	
		DeleteAfter(q);  //xoa nut
}

//xóa bucket trong bang băm
void ClearBucket(int b)
{
	HashNode *p,*q; //q nút truoc1, p nút sau
	q=NULL;
	p=bucket[b];
	while(p!=NULL)
	{
		q=p;
		p=p->Next;
		delete q;
	}
	bucket[b]=NULL;//khoi động lại bucket b
}
//xóa tất cả phần tử trong bảng băm
void CLear()
{
	for(int i=0;i<KEYSIZE;i++)
		ClearBucket(i);
}
//duyệt các phần tử trong bucket
void TraverseBucket(int b)
{
	HashNode* p=bucket[b];
	while(p!=NULL)
	{
		printf("[%s , %s ] -> ",p->Key.TA,p->Key.TV);
		p=p->Next;
	}
	if(!p)
		printf("null");
}
//duyệt toàn bộ  bảng băm
void Traverse()
{
	for(int  b=0;b<KEYSIZE;b++)
	{
		if(bucket[b]!=NULL)
		{
			printf("Bucket thu %d: ",b);
			TraverseBucket(b);
			printf("\n");
		}
	}

}
//tìm kiếm  một phần tử trong Bảng băm
HashNode* Search(char k[])
{
	int b=HashFuntion(k[0]-65);
	HashNode* p=bucket[b];
	while(p)
	{
		if(strcmp(p->Key.TA,k)==0)
			return p;
		p=p->Next;
	}
	return NULL;
}
void nhapdulieu()
{
	int n;
	ItemType x;	
	printf("Nhap so phan tu: ");
	scanf_s("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("nhap tu tieng anh %d: ",i);
		fflush(stdin);
		strupr(gets(x.TA));
		toupper(x.TA[0]);
		printf("nhap nghia tieng viet %d: ",i);
		fflush(stdin);
		gets(x.TV);
		Insert(x);
	}
}
void Docfile()
{
	FILE *f = fopen("data.txt", "r+");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	ItemType x;
	while(!feof(f))
	{
		fscanf(f, "%s%s", &x.TA,&x.TV);
		strupr(x.TA);
		Insert(x);
	}
	fclose(f);
}
void menu()
{
	printf("\n=====================================\n");
	printf("0. Thoat chuong trinh");
	printf("\n1. Tao bang bam tu nhap");
	printf("\n2. Tao bang bam tu file");
	printf("\n3. Xuat toan bo bang bam ra man hinh");
	printf("\n4. Tra tu dien");
	printf("\n5. Nhap vao gia tri can xoa");
	printf("\n6. Xoa toan bo tu  dien");
	printf("\n=====================================\n");
}
void process()
{
	int chon;
	char tim[30];
	HashNode* p;
	InitBucket();
	do {
		menu();
		printf("\nNhap vao lua chon: ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 0:
			exit(0);
			break;
		case 1:
			nhapdulieu();
			Traverse();
			break;
		case 2:
			Docfile();
			Traverse();
			break;
		case 3:
			Traverse();
			break;
		case 4:
			printf("NHap tu can tim: ");
			fflush(stdin);
			strupr(gets(tim));
			p=Search(tim);
			if(p)
				printf("%s  %s",p->Key.TA,p->Key.TV);
			else
				printf("khong tim thay:");
			break;
		case 5:
			printf("NHap tu can xoa: ");
			fflush(stdin);
			gets(tim);
			Remove(tim);
			break;
		}
	
	} while (chon != 0);
}


//==============================================
void main()
{
	process();
}
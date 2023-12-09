#include<stdio.h>
// #include<conio.h>

#define MAX 100

typedef int DATA;

struct Node{ // khai báo 1 node trong dslk đơn
    DATA info; // lưu thông tin của nút hiện hành
    Node *next; // con trỏ chỉ đến nút kế sau
};

struct SList // khai báo cấu trúc dslk đơn
{
    Node *head;
    Node *tail;
};

Node *createNode(int x){
    Node *p= new Node;
    if(p == NULL){
        printf("\n Khong du bo nho de cap phat.");
        getchar();
        return NULL;
    }
    p->info = x;
    p->next = NULL;
    return  p;
}

void initList(SList &l){
    l.head = l.tail = NULL;
}

// thêm đầu

void insertHead(SList &l, Node*p){
    if(p == NULL)
        return;
    if(l.head == NULL) // danh sach rong
        l.head= l.tail= p;
    else{
        p->next= l.head;
        l.head= p;
    }
}

void insertTail(SList &l, Node *p){
    if(p == NULL)
        return;
    if(l.head == NULL)
        l.head= l.tail= p;
    else{
        l.tail->next= p;
        l.tail= p;
    }
}

void createList(SList &l, int n){
    int x;
    initList(l);
    for(int i=0; i< n; i++){
        printf("\n Nhap pt thu %d: ",i+1);
        scanf("%d",&x);
        insertTail(l,createNode(x));
    }
}

void showList(SList l){
    for(Node *p= l.head; p != NULL; p= p->next)
        printf("%d\t",p->info);
}

void showList_while(SList l){
    Node *p= l.head;
    while(p != NULL){
        printf("%d\t",p->info);
        p= p->next;
    }
}

Node *search(SList l,int x){
    for( Node*p= l.head; p; p= p->next)
        if(p->info == x)
            return p;
    return NULL;
}

Node *search_while(SList l, int x){
    Node* p= l.head;
    while(p != NULL){
        if(p->info == x)
            return p;
        p= p->next;
    }
    return NULL;
}

void insertAfter(SList &l, Node *q,Node*p){
    if(p== NULL || q== NULL)
        return;
    else
        if(l.head == NULL)
            l.head= l.tail= p;
    else 
        if(q == l.tail)
            insertTail(l,p);
    else{
        p->next=  q->next;
        q->next = p;
    }
}

void insertBefore(SList &l,Node *q, Node *p){
    if(p == NULL || q== NULL)
        return;
    else    
        if(l.head == NULL)
            l.head= l.tail= p;
    else
        if(q== l.head)
            insertHead(l,p);
    else{
        Node *r= l.head;
        while(r->next != q)
            r= r->next;
            p->next = q;
            r->next= p;
    }
}

int search_x(SList l, int x){
    int i=0; 
    Node *p;
    p= l.head;
    while(p && p->info != x){
        p= p->next;
        i++;
    }
    if(p)
        return i+1;
    else   
        return -1;
}

void delHead(SList &l){
    if(l.head == NULL)
        return;
    else {
        Node *p= l.head;
        l.head = p->next;
        p->next= NULL;
        delete  p;
    }
}

void delTail(SList &l){
    if(l.head == NULL)
        return;
    else {
        Node *p= l.tail;
        // tìm node nằm trước tail
        Node* q= l.head;
        while(q ->next != l.tail)
            q= q->next;
        // cắt node tail rồi xóa
        l.tail= q;
        l.tail->next = NULL;
        delete p;
    }
}

int len_while(SList l){
    int dem =0;
    Node *p= l.head;
    while(p != NULL){
        dem++;
        p= p->next;
    }
    return dem;
}

void del_At(SList &l, int k){
    Node* p= l.head;
    int i=0; 
    if(k < 0 || k > len_while(l))
        printf("\n Vi tri xoa khong hop le.");
    else    
        if(k== 0)
            delHead(l);
    else 
        if(k == len_while(l)-1)
            delTail(l);
    else{
        while(p && i != k-1){
            p= p->next;
            i++;
        }
        Node *r= p->next;
        p->next = r->next;
    }
}

int searchChan(SList l){
    int i= 0;
}

void menu(){
    printf("\n____________Menu________");
    printf("\n 1. Them pt vao dau.");
    printf("\n 2. Them pt vao cuoi.");
    printf("\n 3.Tao danh sach.");
    printf("\n 4. Them vao sau q.");
    printf("\n 5. Them pt vao truoc node q.");
    printf("\n 6. Tim pt x: ");
    printf("\n 7. Kiem tra pt co hay ko .");
    printf("\n 8. Xoa pt dau dslk.");
    printf("\n 9. Xoa pt cuoi cung dslk.");
    printf("\n 10. Xoa node tai vi tri k trong danh sach.");
    printf("\n 11. Xoa cac pt chan.");

}

void process(){
    SList l;
    int chon, x,n;
    Node* p, *q;
    initList(l);

    do{
        menu();
        printf("\n Nhap so cua chuc nang ban can: ");
        scanf("%d",&chon);

        switch(chon){
            case 0:
                printf("\n 0. Program is stop.");
                break;
            case 1:
                printf("\n Nhap pt can them: ");
                scanf("%d",&x);
                p = createNode(x);
                insertHead(l,p);
                showList(l);
                break;
            case 2:
                printf("\n Nhap pt can them: ");
                scanf("%d",&x);
                p= createNode(x);
                insertTail(l,p);
                showList(l);
                break;
            case 3:
                printf("\n Nhap so pt cho danh sach: ");
                scanf("%d",&n);
                createList(l,n);
                showList_while(l);
                break;
            case 4:
                printf("\n Nhap pt can them: ");
                scanf("%d",&x);
                p= createNode(x);
                printf("\n Nhap gia tri nut q: ");
                scanf("%d",&x);
                q= search(l,x);
                insertAfter(l,q,p);
                showList(l);
                break;
            case 5:
                printf("\n Nhap pt can them: ");
                scanf("%d",&x);
                p= createNode(x);
                printf("\n Nhap gia tri nut q: ");
                scanf("%d",&x);
                q= search_while(l,x);
                insertBefore(l,q,p);
                showList(l);
                break;
            case 6:
                printf("\n Nhap pt can tim: ");
                scanf("%d",&x);
                printf("\n Pt %d xuat hien tai vi tri: %d",x,search_x(l,x));
                break;
            case 7:
                printf("\n Nhap pt can tim: "); scanf("%d",&x);
                if(search_while(l,x) == NULL)
                    printf("\n Phan tu KHONG co trong dslk don.");
                else 
                    printf("\n Phan tu co trong dslk don.");
                break;
            case 8:
                delHead(l);
                showList(l);
                break;
            case 9:
                delTail(l);
                showList(l);
                break;
            case 10:
                printf("\n Nhap vi tri can xoa: ");
                scanf("%d",&x);
                del_At(l,x);
                showList(l);
                break;

                
            default:
                printf("\n Khong co chuc nang nay.");
                break;
        }

    }while(chon != 0);

}

int main(){
    process();
    getchar();
}
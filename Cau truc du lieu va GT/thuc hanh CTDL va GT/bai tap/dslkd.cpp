#include<stdio.h>
#include<math.h>

typedef int DATA;

struct Node{
    DATA info;
    Node* next;
};

struct  SList
{
    Node* head;
    Node*tail;
};

Node* createNode(int x){
    Node*p= new Node;
    if(p == NULL){
        printf("Khong du bo nho de cap phat.");
        getchar();
    }
    
    p->info =x;
    p->next = NULL;
    return p;
}

void initList(SList &l){
    l.head = l.tail = NULL;
}

int len(SList l){
    int dem = 0;
    Node* p= l.head;
    while (p )
    {
        dem++;
        p= p->next;
    }
    return dem;
}
    
void insertHead(SList &l, Node*p){
    if(p == NULL)
        return;
    if(l.head == NULL)
        l.head = l.tail = p;
    else{
        p->next = l.head;
        l.head = p;
    }
}

void insertTail(SList &l, Node*p){
    if(p== NULL)
        return;
    if(l.head == NULL)
        l.head = l.tail = p;
    else{
        l.tail->next = p;
        l.tail =p;
    }
}

void showList(SList l){
    Node *p= l.head;
    while (p != NULL)
    {
        printf("%d",p->info);
        p= p->next;
    }
}
    
void createList(SList &l, int n){
    int x;
    initList(l);
    for(int i=0;i< n; i++){
        printf("Nhap pt thu %d: ",i+1);
        scanf("%d",&x);
        insertTail(l,createNode(x));
    }
}

Node *search(SList l, int x){
    Node* p= l.head;
    while (p == NULL)
    {
        if(p->info == x)
            return p;
        p= p->next;
    }
    return NULL;
}

int search_x(SList l,int x){
    int i=0;
    Node*p= l.head;
    while (p && p->info != x) // duyet ds co de khi tim thay hoac ket thuc ds
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else    
        return -1;
}

Node* search_X(SList l,int x){
    Node* i=0;
    Node*p= l.head;
    while (p && p->info != x) // duyet ds co de khi tim thay hoac ket thuc ds
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else    
        return NULL;
}

void insertAfter(SList &l, Node*q,Node* p){
    if( p == NULL || q== NULL)
        return;
    else if(l.head == NULL)
        l.head = l.tail = p;
    else if(q == l.tail)
        insertTail(l,p);
    else {
        p->next = q->next;
        q->next = p;
    }
}

void insertBefore(SList &l, Node*q, Node *p){
    if(p == NULL || q== NULL)
        return;
    else if(l.head == NULL)
        l.head = l.tail = p;
    else if(q == l.head)
        insertHead(l,q);
    else{
        Node* r= l.head;
        while(r->next != q)
            r= r->next;
        p->next = q;
        r->next = p;
    }
}

void delHead(SList &l){
    if(l.head == NULL)
        return;
    else{
        Node *p= l.head;
        l.head = p->next;
        p->next = NULL;
        delete p;
    }
}

void delTail(SList &l){
    if(l.head == NULL)
        return;
    else{
        Node *p= l.tail;
        // tim node ngay truoc tail
        Node* q= l.head;
        while (q->next != l.tail)
        {
            q= q->next;
            // cat node tail roi l va xoa
            l.tail = q;
            l.tail->next = NULL;
            delete p;
        }
        
    }
}

void del_At(SList  &l, int k){
    Node* p= l.head;
    int i=0;
    if(k <0 || k >len(l))
        printf("\n Vi tri xoa ko hop le.");
    else{
        if(k == 0)
            delHead(l); 
        else if(k == len(l)-1)
            delTail(l);
        else{
            while( p && i != k-1){ // duyt den vi tri k-1
                p = p->next;
                i++;
            }
            Node *r= p->next;
            p->next = r->next; // cho p tro sang node ke tiep vi tri k
        }
    }
}

void del_All_x(SList &l, int x){
    int vt;
    while ((vt= search_x(l,x)) >=0)
        del_At(l,vt);
}

int search_chan(SList l){
    int i=0;
    Node*p= l.head;
    while (p && p->info %2 !=0) // duyet ds co de khi tim thay hoac ket thuc ds
    {
        p = p->next;
        i++;
    }
    if(p)
        return i;
    else    
        return -1;
}

void dell_All_Chan(SList &l){
    int vt;
    while((vt = search_chan(l)) >= 0)
        del_At(l,vt);
}

void sapTang(SList l){
    Node *p,  * q;
    for(p= l.head; p; p=p->next)
        for(q= p->next; q; q= q->next)
            if(p->info > q->info){
                int tmp= p->info;
                p->info= q->info;
                q->info = tmp;
            }
}

int snt(int n){
    if( n <2)
        return 0;
    int i;
    for(i=2; i< n/2; i++)
        if(n %i == 0)
            return 0;
    return i;
}

int scp(int n){
    if(sqrt(n)== (int)sqrt(n))
        return 1;
    return 0;
}

int tongScp(SList l){
    int tong= 0;
    for(Node *p= l.head; p;p= p->next)
        if(scp(p->info))
            tong += p->info;
    return tong;
}

int demSNT(SList l){
    int dem = 0;
    for(Node *p= l.head; p; p= p->next)
        if(snt(p->info))
            dem++;
    return dem;
}

void docFile(SList &l, char fileName[]){
    FILE *f= fopen(fileName,"rt");
    if(!f)
        printf("Loi doc file.");
    else{
        int n, x;
        fscanf(f,"%d",&n);
        for(int i=0; i< n; i++)
            fscanf(f,"%d",&x);
            insertTail(l,createNode(x));
    }
    fclose(f);
}

void menu(){
    printf("1. Them pt vao dau: ");
    printf("2. Them pt vao cuoi: ");
    printf("3.Tao danh sach: ");
}

void process(){
    SList l;
    int n,x,chon;
    Node* p, *q;
    initList(l);
   

    do{
        printf("\n chon gia tri can tinh: ");
        scanf("%d",&chon);

        switch (chon)
        {
        case 1:
            printf("\n Nhap pt can them: ");
            scanf("%d",&x);
            p= createNode(x);
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
            printf("Nhap so pt cho danh sach:");
            scanf("%d",&n);
            createList(l,n);
            showList(l);
            break;
        case 4:
            printf("\n Nhap pt can tim trong ds: ");
            scanf("%d",&x);
            p= search(l,x);
            if(p)
                printf("\n Tim thay");
            else   
                printf("\n Ko tim thay");
            break;
        case 5:
            printf("\n Nhap gia tri can them:");
            scanf("%d",&x);
            p= createNode(x);
            printf("\n Nhap gia tri nut q:");
            scanf("%d",&x);
            q = search_X(l,x);
            insertAfter(l,q,p);
            showList(l);
            break;
        case 6:
            printf("\n Nhap gia tri can them:");
            scanf("%d",&x);
            p= createNode(x);
            printf("\n Nhap gia tri nut q:");
            scanf("%d",&x);
             q = search_X(l,x);
            insertBefore(l,q,p);
            showList(l);
            break;
        case 7:
            printf("\n Nhap gia tri can tim:");
            scanf("%d",&x);
            x= search_x(l,x);
            if( x >0)
                printf("\n Tim thay tai: %d",x);
            else
                printf("\n Ko tim thay.");
            break;
        case 8:
            printf("\n Nhap gia tri pt can them: ");
            scanf("%d",&x);
            p= createNode(x);
            printf("\n Nhap vi tri can them:");
            scanf("%d",&x);
            // insertAt(l,p,x);
            showList(l);
            break;
        case 9:
            delHead(l);
            showList(l);
            break;
        case 10:
            delTail(l);
            showList(l);
            break;
        case 11:
            printf("\n Nhap gia tri node q:");
            scanf("%d",&x);
            q= search(l,x);
            // delAfter(l,q);
            showList(l);
            break;
        case 12:
            printf("\n Nhap gia tri node q:");
            scanf("%d",&x);
            q= search(l,x);
            // delBefore(l,q);
            showList(l);
            break;
        case 13:
            printf("\n Nhap vi tri can xoa:");
            scanf("%d",&x);
            del_At(l,x);
            showList(l);
            break;
        case 14:
            printf("\n Nhap gia tri can xoa:");
            scanf("%d",&x);
            del_All_x(l,x);
            showList(l);
            break;
        case 15:
            dell_All_Chan(l);
            showList(l);
            break;

        default:
            break;
        }
    }while(chon != 0);
}
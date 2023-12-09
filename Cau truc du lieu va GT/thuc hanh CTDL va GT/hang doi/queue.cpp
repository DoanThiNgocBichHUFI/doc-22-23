#include<string>
#include<stdio.h>
#include<iostream>
#include<time.h>

using namespace std;

struct QNode{
    int Info;
    QNode *Next;
};

struct Queue{
    QNode *head;
    QNode *tail;
};

QNode* createQNode(int x)
{
    QNode*p= new QNode;
    if(p == NULL){
        printf("Ko du bo nho.");
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}

void initQueue(Queue &q){
    q.head= NULL;
    q.tail= NULL;
}

int isEmpty(Queue q){
    if(q.head == NULL)
        return 1;
    return 0;
}

void insertTail(Queue &q, int x){
    QNode *p= createQNode(x);
    if(isEmpty(q) == 1)
        q.head =p;
    else
        q.tail->Next = p;
        q.tail = p;
}

// lay va huy gia tri dau cua queue

int remove(Queue &q){
    int x;
    if(isEmpty(q) == 1)
        return 0;
    QNode*p= q.head;
    x= p->Info; // lay thong tin cua nut bi huy
    q.head = q.head->Next;
    // delete p;
    if(q.head == NULL)
        q.tail = NULL;
    return x;
}

// lay pt dau tien

int getHead(Queue q){
    if(isEmpty(q))
        return -1;
    return q.head->Info;
}

int getTail(Queue q){
    if(isEmpty(q))
        return 0;
    return q.tail->Info;
}

void delQueue(Queue &q){
    QNode *p= q.head;
    while(q.head != NULL){
        q.head = p->Next;
        delete p;
        p= q.head;
    }
    q.tail = NULL;
}

void showQueue(Queue q){
    QNode *node= q.head;
    if(q.head == NULL){
        cout<<"Kh co pt: "<< endl;
        return;
    }
    while(node != NULL){
        cout<< node->Info << ' ';
        node = node->Next;
    }
    cout<<endl;
}

void createQueue_Auto(Queue &q){
    int n;
    cout<< "Nhap n: ";
    cin>> n;
    initQueue(q);
    srand((unsigned)time(NULL));
    for(int i=0; i< n; i++){
        int x= (rand()%199) - 99; // toa ngau nhien doan -99 -> 99
        // int x= 5 + (rand()%96);
        insertTail(q,x);
    }
}

int lenQueue(Queue q){
    int i=0;
    if( q.head == NULL)
        return 0;
    for(QNode *p= q.head; p != NULL; p= p->Next)
        i++;
    return i;
}

void getTN(Queue &q, int k, int x)// ki la so tin nhan toi da
{
    if(q.head == NULL){
        insertTail(q,x);
        return;
    }
    for(QNode *p= q.head; p != NULL; p= p->Next) // kt xem x co trung gia tri voi node nao ko
        if(p->Info == x)
            return;
        if(lenQueue(q) < k) // k la so tin nhan qui dinh duoc luu
        {
            insertTail(q,x);
        }
        else{
            remove(q); // xoa vi tri dau Pop()
            insertTail(q,x);
        }
}

void getTNN(Queue &q, int n, int k){
    int a[100];
    cout<<"Nhap a[i]: ";
    for(int i= 0; i< n; i++){
        cin>> a[i];
        getTN(q,k,a[i]);
    }
}

void tronQ(Queue &q, Queue a, Queue b){
    initQueue(q);
}

void menu(){
    cout<<"________________Menu______________"<<endl;
    cout<<"0. Thoat chg trinh."<< endl;
    cout<<"1. Tao hang doi tu dong."<<endl;
    cout<<"2. Them pt vao cuoi hang doi."<< endl;
    cout<<"3. Xem gia tri pt dau."<< endl;
    cout<<"4.Xem gia tri pt cuoi."<<endl;
    cout<<"5.Lay mot pt ra khoi hang doi."<<endl;
    cout<<"6.Lay ra khoi hang doi toan bo noi dung."<<endl;
    cout<<"7. In hang doi."<<endl;
    cout <<"8. Nhap danh sach tin nhan: "<<endl;
    cout<<"9. Them tin nhan vao cuoi hang doi."<<endl;
}

void process(){
    Queue q;
    initQueue(q);
    int chon, x;
    int n,k;
    cout<<"So tin nhan toi da: ";
    cin>> k;
    do{
        menu();
        do{
            cout<<"nhan so de chon: ";
            cin >>chon;
        }while(chon < 0 || chon > 7);
        switch (chon)
        {
        case 1:
            createQueue_Auto(q);
            showQueue(q);
            break;
        case 2:
            cout<<"Nhap gia tri can them:";
            cin>> x;

            break;
        case 3:
            x= getHead(q);
            cout<<"Gia tri Head = "<< x <<endl;
            break;
        case 4:
            x= getTail(q);
            cout<<"Gia tri Tail= " << x<<endl;
            break;
        case 5:
            remove(q);
            showQueue(q);
            break;
        case 6:
            delQueue(q);
            showQueue(q);
            break;
        case 7:
            showQueue(q);
            break;
        // default:
        //     break;
        case 8:
            cout<<"Nhap so lg tin nhan:";
            cin >>n;
        }
    }while(chon != 0);
}
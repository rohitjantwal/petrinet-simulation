/*On my honour, I have neiter given nor received unauthorized aid on this asssignment*/
/*ROHIT JANTWAL*/
/*UFID 13514976*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void getins();
void getreg();
void getdm();
void disp0();
void setinb();
void setaib();
void setlib();
void setadb();

void setrdb();
void setreb1();
void setreb2();
void setrgf();

typedef struct node {
char data1[10];
char data2[10];
char data3[10];
char data4[10];
struct node* next;
}nd;
nd *startinm=NULL;

typedef struct inbn {
char data1[10];
char data2[10];
char data3[10];
char data4[10];
struct inbn* next;
}inb;
inb *startinb=NULL;

typedef struct aibn {
char data1[10];
char data2[10];
char data3[10];
char data4[10];
struct aibn* next;
}aib;
aib *startaib=NULL;

typedef struct libn {
char data1[10];
char data2[10];
char data3[10];
char data4[10];
struct libn* next;
}lib;
lib *startlib=NULL;

typedef struct adbn {
char data1[10];
int num1;
struct adbn* next;
}adb;
adb *startadb=NULL;

typedef struct rebn {
char data1[10];
int num1;
struct rebn* next;
}reb;
reb *startreb=NULL;

typedef struct node1 {
char data1[10];
int num1;
struct node1* next;
}nd1;
nd1 *start1=NULL;

typedef struct node2 {
int num1;
int num2;
struct node2* next;
}nd2;
nd2 *start2=NULL;

static int step = 1;

void getins()
{
FILE *source;
char text1[10],text2[10],text3[10],text4[10];

source = fopen("instructions.txt", "r");
struct node *nnode, *current;

if(source != NULL)
    {
    while(fscanf(source, "<%4[^,],%4[^,],%4[^,],%[^'>']>\n", text1, text2, text3, text4) !=EOF)
        {
        nnode = (struct node *)malloc(sizeof(struct node));
                    strcpy(nnode->data1, text1);
                    strcpy(nnode->data2, text2);
                    strcpy(nnode->data3, text3);
                    strcpy(nnode->data4, text4);

                    nnode->next= NULL;
                    if(startinm==NULL)
                    {
                        startinm=nnode;
                        current=nnode;
                    }
                    else{
                        current->next=nnode;
                        current=nnode;
                    }
        }
    }
else
    {
    fprintf(stdout, "Cannot open file.\n");
    exit(-1);
    }
fclose(source);

struct node *p1;
p1 = startinm;
  while(p1!=NULL)
   {
   p1=p1->next;
   }
}

void getreg(){
FILE *source;
char text[10];
int num;

source = fopen("registers.txt", "r");
struct node1 *nnode, *current;

if(source != NULL)
    {
    while(fscanf(source, "<%4[^,],%d>\n", text, &num) !=EOF)
        {
        nnode = (struct node1 *)malloc(sizeof(struct node1));
                    strcpy(nnode->data1, text);
                    nnode->num1= num;

                    nnode->next= NULL;
                    if(start1==NULL)
                    {
                        start1=nnode;
                        current=nnode;
                    }
                    else{
                        current->next=nnode;
                        current=nnode;
                    }
        }
    }

else
    {
    fprintf(stdout, "Cannot open file.\n");
    exit(-1);
    }
fclose(source);

struct node1 *p2;
p2 = start1;
  while(p2!=NULL)
   {
   p2=p2->next;
   }
}

void getdm(){
FILE *source;
int number1;
int number2;

source = fopen("datamemory.txt", "r");
struct node2 *nnode, *current;

if(source != NULL)
    {
    while(fscanf(source, "<%d,%d>\n", &number1, &number2) !=EOF)
        {
        nnode = (struct node2 *)malloc(sizeof(struct node2));

                    nnode->num1=number1;
                    nnode->num2= number2;

                    nnode->next= NULL;

                    if(start2==NULL)
                    {
                        start2=nnode;
                        current=nnode;
                    }
                    else{
                        current->next=nnode;
                        current=nnode;
                    }
        }
    }
else
    {
    fprintf(stdout, "Cannot open file.\n");
    exit(-1);
    }
fclose(source);

struct node2 *p3;
p3 = start2;

  while(p3!=NULL)
   {
   p3=p3->next;
   }
}


void setinb(){

    if(startinm!=NULL)
    {
    inb *nnode, *current;
    nd *temp;

    int i=0;
    nd1 *q1;
    q1 = start1;
    nd2 *q2;
    q2 = start2;
    int c=0,d=0,e=0;
    if(strcmp(startinm->data1,"ADD")==0||strcmp(startinm->data1,"SUB")==0){
    while(q1!=NULL){

       if(strcmp(startinm->data3,q1->data1)==0)
        {
            c=1;
        }
        if(strcmp(startinm->data4,q1->data1)==0)
        {
            d=1;
        }
        q1=q1->next;
       }q1=start1;
   }
    if(strcmp(startinm->data1,"LD")==0)
    {
         while(q1!=NULL){

       if(strcmp(startinm->data3,q1->data1)==0)
        {
            e=1;

        }
        q1=q1->next;
       }q1=start1;
   }

    if((c==1&&d==1)||((e==1)))
    {
        nnode = (inb *)malloc(sizeof(inb));
        strcpy(nnode->data1, startinm->data1);
        strcpy(nnode->data2, startinm->data2);
        strcpy(nnode->data3, startinm->data3);
        strcpy(nnode->data4, startinm->data4);

        nnode->next=NULL;
        if(startinb==NULL)
        {
            startinb=nnode;
            current=nnode;
        }
        else
        {
            current->next=nnode;
            current=nnode;
        }
       temp = startinm;
       startinm = startinm->next;
       free(temp);
       while(q1!=NULL){

            sscanf(startinb->data4, "%d", &i);

       if(strcmp(startinb->data3,q1->data1)==0)
        {
            sprintf(startinb->data3,"%ld",q1->num1);
        }
        if(strcmp(startinb->data4,q1->data1)==0)
        {
            sprintf(startinb->data4,"%ld",q1->num1);
        }

        q1=q1->next;

       }
    }
    else return;
    }
    else return;
}

void setaib(){
    if(startinb!=NULL)
    {
    if(((strcmp(startinb->data1,"ADD"))==0)||((strcmp(startinb->data1,"SUB"))==0)){
    aib *nnode, *current;
    inb *temp;

    {
        nnode = (aib *)malloc(sizeof(aib));
        strcpy(nnode->data1, startinb->data1);
        strcpy(nnode->data2, startinb->data2);
        strcpy(nnode->data3, startinb->data3);
        strcpy(nnode->data4, startinb->data4);

        nnode->next=NULL;
        if(startaib==NULL)
        {
            startaib=nnode;
            current=nnode;
        }
        else
        {
            current->next=nnode;
            current=nnode;
        }
       //temp = startinb;
       //startinb = startinb->next;
        startinb=NULL;
       //free(startinb);
    }
    }}
    else return;
}

void setreb1(){

    if(startaib!=NULL)
    {
    int i=0,j=0;
    reb *nnode, *current,*q;
    q=startreb;
    aib *temp;
    {
        nnode = (reb *)malloc(sizeof(reb));
        if(strcmp(startaib->data1,"ADD")==0){
            strcpy(nnode->data1, startaib->data2);
            sscanf(startaib->data3, "%d", &i);
            sscanf(startaib->data4, "%d", &j);
            nnode->num1=(i+j);
        }
        if(strcmp(startaib->data1,"SUB")==0){
            strcpy(nnode->data1, startaib->data2);
            sscanf(startaib->data3, "%d", &i);
            sscanf(startaib->data4, "%d", &j);
            nnode->num1=(i-j);
        }
        nnode->next=NULL;
        if(startreb==NULL)
        {
            startreb=nnode;
            current=nnode;
        }
        else
        {

        while(q->next!=NULL){
            q=q->next;
        }
        q->next=nnode;}
       //temp = startaib;
       //startaib = startaib->next;
        startaib=NULL;
       //free(temp);
    }
    }
    else return;
}

void setadb(){

    if(startlib!=NULL)
    {
    int i=0,j=0;
    adb *nnode, *current;
    lib *temp;
    {
        nnode = (adb *)malloc(sizeof(adb));
            strcpy(nnode->data1, startlib->data2);
            sscanf(startlib->data3, "%d", &i);
            sscanf(startlib->data4, "%d", &j);
            nnode->num1=(i+j);

        nnode->next=NULL;
        if(startadb==NULL)
        {
            startadb=nnode;
            current=nnode;
        }
        else
        {
            current->next=nnode;
            current=nnode;
        }
       startlib=NULL;
    }
    }
    else return;
}

void setreb2(){
    if(startadb!=NULL)
    {
    reb *nnode, *current,*q;
    q=startreb;
    adb *temp;

    nd2 *p2;
    p2 = start2;
    {
        nnode = (reb *)malloc(sizeof(reb));
        strcpy(nnode->data1, startadb->data1);

            nnode->num1=startadb->num1;

        nnode->next=NULL;
        while(p2!=NULL){
            if((nnode->num1)==(p2->num1)){
                nnode->num1=p2->num2;
            }
            p2=p2->next;
        }
        if(startreb==NULL)
        {
            startreb=nnode;
            current=nnode;
        }
        else
        {
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=nnode;}
       //temp = startadb;
       //startadb = startadb->next;
       //free(temp);
       startadb=NULL;
    }
    }
    else return;
}



void setlib(){

    if(startinb!=NULL)
    {
    lib *nnode, *current;
    inb *temp;

    {
        nnode = (lib *)malloc(sizeof(lib));
        strcpy(nnode->data1, startinb->data1);
        strcpy(nnode->data2, startinb->data2);
        strcpy(nnode->data3, startinb->data3);
        strcpy(nnode->data4, startinb->data4);

        nnode->next=NULL;
        if(startlib==NULL)
        {
            startlib=nnode;
            current=nnode;
        }
        else
        {
            current->next=nnode;
            current=nnode;
        }
       //temp = startinb;
       //startinb = startinb->next;
       //free(temp);
       startinb=NULL;
    }
    }
    else return;
}

void selectionsort()
{
    int i,j,k;
    struct node1 *p,*q,*temp;
    int n=0;

    p=start1;

    while(p!=NULL)
    {
        p=p->next;
        n++;
    }

    temp=(nd1 *)malloc(sizeof(nd1));
    p=start1;
    for(i=0;i<n-1;i++)
    {
        q=p->next ;

        for(j=i+1;j<n;j++)
        {
            if(strcmp(p->data1,q->data1)>0)
            {
                strcpy(temp->data1,p->data1);
                strcpy(p->data1,q->data1);
                strcpy(q->data1,temp->data1);

                temp->num1=p->num1;
                p->num1=q->num1;
                q->num1=temp->num1;
            }
            q=q->next ;
        }
        p=p->next;
    }
    //free(temp);
}


void setrgf(){
    if(startreb!=NULL){
    nd1 *nnode, *current,*q,*t1;
    reb *temp;
    q=start1;
    t1=start1;
    int count=0;

    {
        nnode = (nd1 *)malloc(sizeof(nd1));
        strcpy(nnode->data1,startreb->data1);
        nnode->num1=startreb->num1;
        nnode->next=NULL;

        while(q!=NULL){
       if(strcmp(nnode->data1,q->data1)==0)
        {
            q->num1=nnode->num1;
            count=1;
        }
        q=q->next;
       }
       q=start1;
       if(count==0){

        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=nnode;
        }
        startreb=startreb->next;

        selectionsort();

        //free(q);
    }
    }
    else return;
}
void setdisp(){
    nd *p1;
    nd1 *p2;
    nd2 *p3;
    reb *p4;
    p1=startinm;
    p2=start1;
    p3=start2;
    p4=startreb;
    FILE *source;

    source = fopen("simulation.txt", "a");
    fprintf(source,"\n\nSTEP %d: \nINM:",step);
    step++;
    if(startinm!=NULL){
    while(p1->next!=NULL)
    {
        fprintf(source,"<%s,%s,%s,%s>,", p1->data1, p1->data2, p1->data3, p1->data4);
        p1=p1->next;
    }
    fprintf(source,"<%s,%s,%s,%s>", p1->data1, p1->data2, p1->data3, p1->data4);
    }
    //fprintf(source,"<%s,%s,%s,%s>", p1->data1, p1->data2, p1->data3, p1->data4);

    fprintf(source,"\nINB:");
    if(startinb!=NULL)
    fprintf(source,"<%s,%s,%s,%s>", startinb->data1, startinb->data2, startinb->data3, startinb->data4);

    fprintf(source,"\nAIB:");
    if(startaib!=NULL)
    fprintf(source,"<%s,%s,%s,%s>", startaib->data1, startaib->data2, startaib->data3, startaib->data4);

    fprintf(source,"\nLIB:");
    if(startlib!=NULL)
    fprintf(source,"<%s,%s,%s,%s>", startlib->data1, startlib->data2, startlib->data3, startlib->data4);

    fprintf(source,"\nADB:");
    if(startadb!=NULL)
    fprintf(source,"<%s,%d>", startadb->data1, startadb->num1);

    fprintf(source,"\nREB:");
    if(startreb!=NULL){
    while(p4->next!=NULL){
        fprintf(source,"<%s,%d>,", p4->data1, p4->num1);
        p4=p4->next;
    }
    fprintf(source,"<%s,%d>", p4->data1, p4->num1);
    }
    fprintf(source,"\nRGF:");
    while(p2->next!=NULL)
    {
        fprintf(source,"<%s,%d>,", p2->data1,p2->num1);
        p2=p2->next;
    }
    fprintf(source,"<%s,%d>", p2->data1,p2->num1);

    fprintf(source,"\nDAM:");
    while(p3->next!=NULL)
    {
        fprintf(source,"<%d,%d>,", p3->num1,p3->num2);
        p3=p3->next;

    }
    fprintf(source,"<%d,%d>", p3->num1,p3->num2);

}

void disp0(){
    FILE *source;

    source = fopen("simulation.txt", "w");
    fprintf(source,"STEP 0:\nINM:");
    nd *p;
    p = startinm;
    nd1 *p1;
    p1 = start1;
    nd2 *p2;
    p2 = start2;
    while(p->next!=NULL)
    {
    fprintf(source,"<%s,%s,%s,%s>,", p->data1, p->data2, p->data3, p->data4);
    p=p->next;
    }
    fprintf(source,"<%s,%s,%s,%s>", p->data1, p->data2, p->data3, p->data4);
    p=startinm;

    fprintf(source,"\nINB:\nAIB:\nLIB:\nADB:\nREB:\nRGF:");

    while(p1->next!=NULL)
    {
        fprintf(source,"<%s,%d>,", p1->data1,p1->num1);
        p1=p1->next;
    }
    fprintf(source,"<%s,%d>", p1->data1,p1->num1);
    p1=start1;

    fprintf(source,"\nDAM:");
    while(p2->next!=NULL)
    {
        fprintf(source,"<%d,%d>,", p2->num1,p2->num2);
        p2=p2->next;
    }
    fprintf(source,"<%d,%d>", p2->num1,p2->num2);
    p2=start2;
}


int main(){
    getins();
    getreg();
    getdm();

    disp0();

    while(startinm!=NULL||startinb!=NULL||startaib!=NULL||startlib!=NULL||startadb!=NULL||startreb!=NULL){

        setrgf();
        setreb2(); //adb to reb
        setreb1(); //aib to reb
        setaib();
        setadb();
        setlib();
        setinb();
        setdisp();
        }
}
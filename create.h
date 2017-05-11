#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

/*This structure contains the details of the student*/
typedef struct student{
	int courseNum;									
	char fatherName[30];
	int interMarks;
	long int sroll;
	char studentName[30];
}STUDENT;

/*This structure contains the details of the courses and instructors*/
typedef struct course{
	int courseId;
	char courseName[5];
	char facultyName[20];
}COURSE;

/*This structure contains the details of the student roll number-courseId  */
typedef struct sclist{
	long int studroll;
	int Ccount;
	int cID[30];
	struct sclist *next;
}SCLIST;

/*This structure is for creating a binary tree which holds the details of all the students */
typedef struct stree{
	STUDENT *student;
	int level;
	struct stree *left,*right;
}STREE;

/*This structure is for creating a binary tree which holds the details about courses and instructors*/
typedef struct ctree{
	COURSE *course;
	int level;
	struct ctree *left,*right;
}CTREE;

/*This structure is to create a linked list of binary numbers*/
typedef struct binary {
	int num;
	struct binary *next;
}BINARY;

char cname[17][5],fac[25][20];

/*This function inserts the binary number obtained into a node */
BINARY* add(BINARY **curr, int n){
	BINARY *temp;
	temp=(BINARY*)malloc(sizeof(BINARY));
	temp->num=n;
	temp->next=*curr;
	return temp;
}

SCLIST* headptr=NULL;

/*This function gets a decimal number and generates binary numbers in the form of a linked list*/
BINARY* genBinary(int number,BINARY *bhead){
	int binary_num;
	while(number>0){
		binary_num=number%2;
		bhead =add(&bhead,binary_num);
		number/=2;
	}
	return 	bhead;
}

SCLIST *schead=NULL;
int flag=0;

/*This function ensures that randomly generated input does not repeat */
int inArray(int count, int input, int* array){
    int i = 0;
    for(i=0; i<count; i++){
        if(input == array[i]){
            return 1;
        }
    }
    return 0;
}

/*This function generates a random number and links the data in the form of a list*/
SCLIST *getNode(STREE *temp,int k,int m){
	SCLIST *nptr=NULL;
	nptr=(SCLIST*)malloc(sizeof(SCLIST));
	nptr->studroll=temp->student->sroll;
	nptr->Ccount=temp->student->courseNum;
	int j,A[30]={0},z,count1=0;
	int count=0;		
	for(j=1;j<=k;j++){
		nptr->cID[j]=rand() % m+1;
		while(inArray(j+1,nptr->cID[j], A) == 1){
            		nptr->cID[j] = rand() % m+1;
        	}
		A[j]=nptr->cID[j];
	}
	nptr->next=NULL;
	return nptr;	
}

/*Generates list consisting student-course details*/
SCLIST *generateList(SCLIST *sclist,STREE *temp,int i,int m){
	int j;
	int k=temp->student->courseNum;
	SCLIST *list=getNode(temp,k,m);
	if(sclist==NULL){
		sclist=list;
		schead=sclist;
		headptr=list;
	}
	else{
		while(sclist->next){
			sclist=sclist->next;
		}
		sclist->next=list;
	}
	return sclist;
}

/*Generates student Details and inserts them into a complete binary tree*/    
STREE *generateStudentDataSet(STREE *stree,int n,int m){
	STREE *temp=NULL,*head=NULL;
	BINARY *jump=NULL;
	BINARY *bhead=NULL;
	STUDENT *student;
	SCLIST *sclist=NULL;
	char c1,c2;
	char C1[10],C2[10];
	FILE *fp1,*fp2;
	fp1=fopen("name.txt","r");
	fp2=fopen("father.txt","r");
	int flag=0,count=0,i;
	for(i=1;i<=n;i++)
	{
		count=0;
		bhead=genBinary(i,bhead);
		jump=bhead;
		fscanf(fp1,"%s",C1);
		fscanf(fp2,"%s",C2);	
		int j=rand()%10;
		temp=(STREE*)malloc(sizeof(STREE));
		temp->student=(STUDENT*)malloc(sizeof(STUDENT));
		temp->student->courseNum=6+rand()%5;
		temp->student->interMarks=750+rand()%250;
		temp->student->sroll=201601000+i;
		strcpy(temp->student->fatherName,C2);
		strcpy(temp->student->studentName,C1);
		temp->left=NULL;
		temp->right=NULL;
		sclist=generateList(sclist,temp,i,m);       /*this function generates the student-course list*/
		jump=bhead;
		while(jump){
			if(stree==NULL){
				head=temp;
				stree=temp;
			}
			else{
				if(bhead->num==0){
					if(stree->left==NULL){
						stree->left=temp;
					}
					else{
						stree=stree->left;
					}
				}
				if(bhead->num==1 && count>0){
					if(stree->right==NULL){
						stree->right=temp;

					}
					else{
						stree=stree->right;
					}
				}
			}
			jump=jump->next;
			bhead=bhead->next;
			count++;
		}
		stree=head;
	}
	fclose(fp1);
	fclose(fp2);
	return head;
}

/*Prints the student details*/
void printStudentDetails(STREE *stree){
	STREE *tempo=NULL;
	tempo=stree;
	if(stree!=NULL)
	{
		printf("%9ld %20s %20s \t\t %3d \t %2d\n",stree->student->sroll,stree->student->studentName,stree->student->fatherName,stree->student->interMarks,stree->student->courseNum);
		printStudentDetails(stree->left);
		printStudentDetails(stree->right);
	}
	stree=tempo;
}

/*Generates course details and inserts them into a complete binary tree*/
CTREE *generateCourseDataSet(CTREE *ctree,int m){
	CTREE *temp=NULL,*chead=NULL;
	BINARY *jump=NULL;
	BINARY *bhead=NULL;
	COURSE *course;
	FILE *fc=fopen("course.txt","r");
	FILE *fc1=fopen("faculty.txt","r");
	int t=0,p=0;
	while(fscanf(fc,"%s",cname[t])>0){
		t++;	
	}
	fclose(fc);
	while(fscanf(fc1,"%s",fac[p])>0){
		p++;
	}
	fclose(fc1);
	int flag=0,count=0,i;
	
	for( i=1;i<=m;i++)
	{
		count=0;
		bhead=genBinary(i,bhead);
		jump=bhead;
		int j=rand()%10;
		temp=(CTREE*)malloc(sizeof(CTREE));
		temp->course=(COURSE*)malloc(sizeof(COURSE));
		temp->course->courseId=i;
		strcpy(temp->course->courseName,cname[i-1]);
		strcpy(temp->course->facultyName,fac[j]);
		temp->left=NULL;
		temp->right=NULL;
		jump=bhead;
		while(jump){
			if(ctree==NULL){
				chead=temp;
				ctree=temp;
			}
			else{
				if(bhead->num==0){
					if(ctree->left==NULL){
						ctree->left=temp;
					}
					else{
						ctree=ctree->left;
					}
				}
				if(bhead->num==1 && count>0){
					if(ctree->right==NULL){
						ctree->right=temp;
					}
					else{
						ctree=ctree->right;
					}
				}
			}
			jump=jump->next;
			bhead=bhead->next;
			count++;
		}
		ctree=chead;
	}
	return chead;
}

/*Prints the courseid coursename and instructor*/
void printCourseDetails(CTREE *ctree){
	CTREE *tempo=NULL;
	tempo=ctree;
	if(ctree!=NULL)
	{
		printf("%2d\t\t%5s\t%15s\n",ctree->course->courseId,ctree->course->courseName,ctree->course->facultyName);
		printCourseDetails(ctree->left);
		printCourseDetails(ctree->right);
	}
	ctree=tempo;
}

/*Prints the details of student ,his elected number of courses and course ID's*/
void printStudentCourseList(SCLIST *root){
	while(root!=NULL)
	{
		int count=root->Ccount,j;
		printf("%ld \t\t %d\t",root->studroll,count);
		for(j=1;j<=count;j++){
			printf("%d ",root->cID[j]);
		}
		printf("\n\n");
		root=root->next;
	}
}


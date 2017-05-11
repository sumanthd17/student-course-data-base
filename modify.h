/*structure to form linked list*/
typedef struct NODE {
	char Cname[10];
	struct NODE *next;
}NODE;
/*function to print details of student after entering roll number..*/
void UpdatedCourse(SCLIST *tempo,long int roll){
	int j;
	SCLIST *temp=tempo;
	while(temp){
		int count=temp->Ccount,j;
		if(temp->studroll==roll){
			printf("student Roll:%ld\nCourse count:%d\nCOURSE Id's:",temp->studroll,count);
			for(j=1;j<=count;j++){
				printf("%d ",temp->cID[j]);
			}printf("\n\n");
		break;
		}
		temp=temp->next;
	}
	return;
}
/*checks whether the entered roll no exists or not*/
long int CheckRoll(SCLIST *temp2,long int rollno){
	SCLIST *temp=temp2;
	int count,j;
	long int num;
	int flag=0;
	while(temp2){
		if(temp2->studroll==rollno){
			flag=1;
			break;
		}
		temp2=temp2->next;	
	}
	if(flag==1){
		return rollno;	
	}
	else{
		printf("->roll no you entered does not exist\n");
		printf("->please enter a valid roll no\n");
		scanf("%ld",&num);
		CheckRoll(temp,num);
	}		
}
/*checks for the criteria of not having more than 10 courses*/
int checkCourseA(SCLIST *ptemp ,long int roll){
	int nCourses;
	printf("->make sure the total courses won't be greater than 10\n");
	printf("->you can add atmost *%d* courses\n",10-ptemp->Ccount);
	printf("->number of courses you want to add\n");
	scanf("%d",&nCourses);
	if(nCourses>10-ptemp->Ccount){
		printf("->please enter number of courses less than or equal to %d\n",10-ptemp->Ccount);
		checkCourseA(ptemp,roll);
	}
	else{
		return nCourses;
	}
	
}
/*function that takes input of courses a student wants to add apart from existing courses*/
void AddCourses(STREE *stree,SCLIST *sclist,CTREE *ctree){
	int i;
	int nCourses;
	int count;
	int j;
	int a[10];
	long int roll,num=0;
	STREE *temp1 = stree;
	SCLIST *temp = sclist;
	SCLIST *temp2 = sclist;
	CTREE *temp3 = ctree;
	printf("Please Enter your roll number:");
	scanf("%ld",&roll);
	num=CheckRoll(temp2,roll);
	while(temp2->next){
		count=temp2->Ccount;
		if(temp2->studroll==num){
			printf("student Roll:%ld\nCourse count:%d\nCOURSE Id's:",temp2->studroll,count);
			for(j=1;j<=count;j++){
				printf("%d ",temp2->cID[j]);
			}printf("\n_________________\n");
			
		break;
		}
		temp2=temp2->next;
	}
	nCourses=checkCourseA(temp2,num);
	temp2->Ccount=temp2->Ccount+nCourses;
	printf("Enter courseID other than these courses:\n");
	for(i=0;i<nCourses;i++){
		scanf("%d",&a[i]);
	}
	j=count+1;
	for(i=0;i<nCourses;i++){
		temp2->cID[j]=a[i];
		j++;
             	
	}
	UpdatedCourse(temp,roll);
}
/*checks for the criteria of not having less than 6 courses*/
int checkCourse(SCLIST *ntemp ,long int roll){
	int nCourses,count;
	printf("->make sure the total courses won't be less than 6\n");
	count=ntemp->Ccount-6;
	printf("->you can drop atmost *%d* courses\n",ntemp->Ccount-6);
	printf("->number of courses you want to drop\n");
	scanf("%d",&nCourses);
	if(nCourses>ntemp->Ccount-6){
		printf("->please enter number of courses less than or equal to %d\n",ntemp->Ccount-6);
		checkCourse(ntemp,roll);
	}
	else{
		return nCourses;
	}
	
}
/*function that takes input of courses a student wants to drop from existing courses */
void DropCourses(STREE *stree,SCLIST *sclist,CTREE *ctree){
	int a[10],i;
	int nCourses;
	int count;
	int j;
	long int roll,num;
	STREE *temp1 = stree;
	SCLIST *temp = sclist;
	SCLIST *temp2 = sclist;
	CTREE *temp3 = ctree;
	printf("Please Enter your roll number:");
	scanf("%ld",&roll);
	num=CheckRoll(temp2,roll);
	while(temp2->next){
		count=temp2->Ccount,j;
		if(temp2->studroll==num){
			printf("student Roll:%ld\nCourse count:%d\nCOURSE Id's:",temp2->studroll,count);
			for(j=1;j<=count;j++){
				printf("%d ",temp2->cID[j]);
			}printf("\n\n");
			
		break;
		}
		temp2=temp2->next;
	}
	nCourses=checkCourse(temp2,num);
	printf("Enter courseID you want to drop:\n");
	for(i=0;i<nCourses;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<nCourses;i++){
		int flag=0;
		for(j=1;j<=temp2->Ccount;j++){
			if(temp2->cID[j]==a[i]){
				temp2->cID[j]=0;
				flag=1;
				break;
			}
		}	
	}
	for(i=1;i<=temp2->Ccount;i++){
		if(temp2->cID[i]==0){
			for(j=i;j<temp2->Ccount;j++){
				temp2->cID[j]=temp2->cID[j+1];
			}
			temp2->Ccount=temp2->Ccount-1;
			i--;	
		}	
	}
	UpdatedCourse(temp2,num);
	
}
/*recurrsive function that prints the students*/
void Search(STREE *stud,int intMark){
	
	if(stud!=NULL)
	{	if(stud->student->interMarks>=intMark){
			printf("%15s\t%d\n",stud->student->studentName,stud->student->interMarks);
		}
		Search(stud->left,intMark);
		Search(stud->right,intMark);
	}
}
/*function that searches the students above or equal to a given inter marks*/
void searchByInter(STREE *stree){
	STREE *stud=stree;
	int intMark;
	printf("please enter the interMarks :\n");
	scanf("%d",&intMark);
	printf("students above or equal to the given inter marks are:\n");
	Search(stud,intMark);	
}


NODE *HEADPTR=NULL;
/*allocates memory for a node*/
NODE *GetNode() {
	NODE *now = NULL;
	now = (NODE *)malloc(sizeof(NODE));
	if (now == NULL) exit(-1);
	return now;
}

/* Insert at the Front of the linked list */
NODE *InsertElementAtFront(NODE *list, char x[]) {
	NODE *now = GetNode();
	strcpy(now->Cname,x);
	if (list == NULL) {now->next = NULL;}
	else{ 
		now->next = list;
	}
	return now;
}
/*counts the number of courses taken by professor and stores them in a linked list*/
int facVerify(char s[],CTREE *Nptr){
	static int count=0;
	if(Nptr!=NULL)
	{
		if(strcmp(s,Nptr->course->facultyName)==0){
			count++;
			HEADPTR=InsertElementAtFront(HEADPTR, Nptr->course->courseName);
		}
		facVerify(s,Nptr->left);
		facVerify(s,Nptr->right);
	}
	if(count>1){
		return count;
	}
	else {
		return count;
	}
}

/*function that tells the courses under a faculty*/
void FacultyDetails(CTREE *ctree){
	char s[50];
	int value=0,i=0;
	CTREE *ptr=ctree;
	printf("enter professors names whom you want to check their courses:\n");
	scanf("%s",s);
	value=facVerify(s,ptr);
	NODE *NEW=HEADPTR;
	if(value>=1){
		printf("courses under %s course are:\n",s);
		while(NEW!=NULL){
			printf("%s ",NEW->Cname);
			NEW=NEW->next; 
		}       
		printf("\n\n");
	}
	else{
		printf("->there is no professor with that name\n");
		printf("->please check carefully and try again\n");
	}
	printf("\n");   
}
/*changes the faculty name as entered by the user*/
void EditFaculty(CTREE *Nptr,char s[],char s1[]){
	
	if(Nptr!=NULL)
	{
		if(strcmp(s,Nptr->course->facultyName)==0){
			strcpy(Nptr->course->facultyName,s1);
		}
		EditFaculty(Nptr->left,s,s1);
		EditFaculty(Nptr->right,s,s1);
	}
}
/*function to change faculty if he leaves the institute*/
void Faculty_change(CTREE *ctree){
	char mat[50],mat1[50];
	printf("please enter the faculty name who left the course:\n");
	scanf("%s",mat);
	printf("please enter the faculty now faculty name\n");
	scanf("%s",mat1);
	EditFaculty(ctree,mat,mat1);
}

/*int main(int argc,char *argv[])
{
	int n=argc>1?atoi(argv[1]):20;
	int m=17;
	srand((unsigned)time(NULL));
	STREE *stree=NULL;CTREE *ctree=NULL;
	ctree=generateCourseDataSet(ctree,m);//n is the number of courses
	printf("\t\t\tCOURSE DETAILS\t\t\t \n");
	printCourseDetails(ctree);
	printf("\n\n\n\n\n");
	printf("\t\t\tSTUDENT DETAILS\t\t\t \n");
	stree=generateStudentDataSet(stree,n,m);
	printStudentDetails(stree);
	printf("\n\n\n\n\n");
	printf("\t\t\tSTUDENT-COURSE DETAILS\t\t\t \n");
	printStudentCourseList(schead,stree);
	AddCourses(stree,headptr,ctree);
	printStudentCourseList(schead,stree);
	DropCourses(stree,headptr,ctree);
	//printStudentCourseList(schead,stree);
	Faculty_change(ctree);
	printCourseDetails(ctree);
	searchByInter(stree);
	FacultyDetails(ctree);
	//printCourseDetails(ctree);
	//printStudentCourseList(schead,stree);
return 0;
}*/

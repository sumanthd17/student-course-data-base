#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/*Function to traverse through stree tree to find  the rollnumber and print the student details*/

void traverse(STREE* root,long int rollnumber)
{
	if(root!=NULL)
	{
		traverse(root->left,rollnumber);
		if(rollnumber==root->student->sroll)
		{
			printf("\nRollNo:%ld\nStudent Name:%s\nFather Name:%s\nInterMarks:%d\ncourses:%d\n\n",root->student->sroll,root->student->studentName,root->student->fatherName,root->student->interMarks,root->student->courseNum);
		}
		traverse(root->right,rollnumber);
	}
}

/*This function is used to search the given courseid and print the course details */

void searchit(CTREE* root,int A[],int n)
{
	if(root!=NULL)
	{
		searchit(root->left,A,n);
		if(n==root->course->courseId)
		{
			printf("CourseId: %d\nCourseName:%s\nFacultyName:%s",root->course->courseId,root->course->courseName,root->course->facultyName);
		}
		searchit(root->right,A,n);

	}
}

/*This Function is used to search the student Rollnumber in the Student tree i.e stree*/

void RollSearch(STREE *root,int roll)
{
	if(root!=NULL)
	{
		RollSearch(root->left,roll);
		if(roll==root->student->sroll)
		{
			printf("\nStudent Name-%s",root->student->studentName);
			printf("\n---------------------------\n");
		}
		RollSearch(root->right,roll);
	}

}

/*This Function is used to search and print the student details who opted the respective course*/

void Searchbycid(SCLIST *head,int cid,STREE *root,int courses,int check)
{
	SCLIST *temp;
	temp=head;
	int count,i;
	char A[2];
	if(check==1){
		printf("\nPlease enter a valid course id: ");
		scanf("%d",&cid);
		Searchbycid(head,cid,root,courses,0);
	}
	else if(check==0 && cid>0 && cid<=courses)
	{
		printf(ANSI_COLOR_MAGENTA"\nThe Students opted for the course ID %d are:\n\n"ANSI_COLOR_RESET,cid);
		while(temp!=NULL)
		{
			count=temp->Ccount;
			for(i=0;i<=count;i++)
			{
				if(cid==temp->cID[i])
				{
					printf("RollNumber-%ld  ",temp->studroll);
					RollSearch(root,temp->studroll);
				}
			}
			temp=temp->next;

		}
	}
	else
	{
		printf(ANSI_COLOR_GREEN"\nThe courseid you entered is wrong\n");
		printf(ANSI_COLOR_RED"\nDo you want to search again[Y/N]: "ANSI_COLOR_RESET);
		scanf("%s",A);
		if(A[0]=='y' || A[0]=='Y')
		{
			Searchbycid(head,cid,root,courses,1);
		}
		else{
			printf(ANSI_COLOR_BLUE"Thank you bye--\n"ANSI_COLOR_RESET);
		}

	}

}

void Callit(SCLIST *head,CTREE *ctree,long int n);/*This function is used to call the Search by course function again*/

/*This function is used to search the course details of a student with given rollnumber*/

void SearchBycourse(SCLIST *head,long int roll,CTREE *ctree,int n)
{
	SCLIST* temp;
	char askit[2];
	int check=201601000;
	check = check+n;
	int total,A[30],i;
	temp=head;
	CTREE* temp1=ctree;
	if(roll-check>0 || roll<=201601000)
	{    
		printf(ANSI_COLOR_GREEN"\nThe rollnumber is not present \n\n");
		printf(ANSI_COLOR_RED"Do you Want to search Again(Y/N)?"ANSI_COLOR_RESET);
		scanf("%s",askit);


		if(askit[0]=='y' || askit[0]=='Y') 
		{
			Callit(head,ctree,n);


		}
		else
		{

			return;
		}

	}
	else
	{
		while(temp!=NULL)
		{
			if(roll==temp->studroll)
			{
				total=temp->Ccount;
				for(i=1;i<=total;i++)
				{
					A[i]=temp->cID[i];
				} 

				for(i=1;i<=total;i++)
				{
					printf("%d  ",A[i]);
				}
				printf("\n");
				printf("Course Details of Rollno %ld\n\n",roll);
				for(i=1;i<=total;i++)
				{
					searchit(temp1,A,A[i]);
					printf("\n_______________________\n");
				}

			}
			temp=temp->next;
		}
	}

}

/*This function is used to call the Search by course function again*/

void Callit(SCLIST *head,CTREE *ctree,long int n)
{
	long int roll;
	printf("\n\nEnter a roll number to search their course Details: ");
	scanf("%ld",&roll);

	SearchBycourse(head,roll,ctree,n);
}



void Callagain(STREE* root,int n,int select);/* This function is used to call the search list function again*/

/*Searchlist function is used to search the rollnumber of the student in the stree */

void SearchList(STREE* root,long int rollnumber,int n)
{
	char ask[2];
	int check=201601000;
	check = check+n;
	if(rollnumber<201601000 )
	{
		printf("Please enter a valid Rollnumber:");
		Callagain(root,n,0);
	}



	if(rollnumber-check>0 || rollnumber>check)
	{    
		printf(ANSI_COLOR_GREEN"\nThe rollnumber is not present in our database\n\n");
		printf(ANSI_COLOR_RED"Do you Want to search Again(Y/N)?"ANSI_COLOR_RESET);
		scanf("%s",ask);


		if(ask[0]=='y' || ask[0]=='Y') 
		{
			Callagain(root,n,1);


		}
		else
		{
			return;
		}

	}
	else
	{
		traverse(root,rollnumber);
	}

}
/* This function is used to call the search list function again*/

void Callagain(STREE* root,int n,int select)
{
	long int roll;
	if(select==1)
	{
		printf("Enter a rollnumber to Search:");
	}
	scanf("%ld",&roll);
	SearchList(root,roll,n);
}

void Call(int n,CTREE *root,int courses);/*This function is used to call Searchfaculty function*/


/*Searchfaculty function is used to search the course id and print the details of the Professor who is teaching it*/


void Searchfaculty(int cid,CTREE *root,int courses)
{
	CTREE* temp;
	temp=root;


	char A[2];

	if(cid<=0|| cid >courses)
	{
		printf("\nThe course you entered is wrong\n\n");
		printf(ANSI_COLOR_RED"Do you Want to search Again(Y/N)?"ANSI_COLOR_RESET);
		scanf("%s",A);
		if(A[0]=='y' || A[0]=='Y')
		{
			Call(cid,root,courses);
		}
		else{
			printf("\n-------------Thank You--------\n\n");
			return;
		}
	}
	else
	{
		if(root!=NULL)
		{
			Searchfaculty(cid,root->left,courses);
			if(root->course->courseId==cid)
			{
				printf("Course Details: \n\n");
				printf("CourseId:%d\nCourse Name:%s\nfaculty Name: %s\n\n",root->course->courseId,root->course->courseName,root->course->facultyName);
			}
			Searchfaculty(cid,root->right,courses);
		}
	}
}
/*This function is used to call Searchfaculty function*/

void Call(int cid,CTREE *root,int courses)
{
	printf("\nEnter a valid course id: ");
	scanf("%d",&cid);
	Searchfaculty(cid,root,courses);
}

/*Function to count the number of courses taken by professor*/

int facSearch(char s[],CTREE *Nptr,int a[]){
	static int count=0,i1=0;
	if(Nptr!=NULL)
	{
		if(strcmp(s,Nptr->course->facultyName)==0){
			count++;
			a[i1]=Nptr->course->courseId;
			i1++;
		}
		facSearch(s,Nptr->left,a);
		facSearch(s,Nptr->right,a);
	}
	if(count>=1){
		return i1;
	}

}

/*This function is used to search the professor name and print the student roll numbers who are present under his/her courses*/


void facView(CTREE *ctree,SCLIST *head,STREE *root,int courses){
	char s[50];
	int value=0,a[10],i=0;
	CTREE *ptr=ctree;
	printf("Enter professors name whom you want to check their courses: ");
	scanf("%s",s);
	value=facSearch(s,ptr,a);
	if(value>=1){
		printf("\ncourses under professor %s are:\n\n",s);
		for(i=0;i<value;i++){
			Searchbycid(head,a[i],root,courses,0);
			printf("\n\n");   
		}
		printf("\n");   
	}
	else
	{
		printf("\n\nPlease check the Professor name and Try again\n\n");
	}
}
/*int main(int argc,char *argv[])
  {
  int n=argc>1?atoi(argv[1]):20;
  int m=17;
  long int r,r1,r2;
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

///////////////

printf("\nEnter a roll number to search:");
scanf("%ld",&r);
SearchList(stree,r,n);
printf("\nEnter a roll number to search their course Details: ");
scanf("%d",&r1);
SearchBycourse(headptr,r1,ctree,n);
printf("\nEnter a CourseId: ");
scanf("%d",&r2);
Searchbycid(headptr,r2,stree,m,0);



return 0;
}*/

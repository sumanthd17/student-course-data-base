#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include"create.h"
#include"search.h"
#include"delete.h"
#include"modify.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

STREE *stree=NULL;CTREE *ctree=NULL;

int main(int argc, char *argv[]){
	clock_t begin = clock();
	
	int n=argc>1?atoi(argv[1]):20;
	int m=17;
	
	ctree=generateCourseDataSet(ctree,m);//n is the number of courses
	stree=generateStudentDataSet(stree,n,m);
	
	while(1){
	printf("Print : p\nSearch : s\nModify : m\nDelete : d\nExit : e\n");
	printf("Please Enter Input:\n");
	char op[2];
	char choice[2];
	scanf("%s", op);
	if(op[0] == 'e') break;

	if(op[0] != 'p' && op[0]!= 's' && op[0] != 'm' && op[0] != 'd' && op[0] != 'e'){
		printf("\nPlease Enter Valid Input!!!\n\n");
		continue;
	}
		 
	switch(op[0]){
		case 'p':
			printf("course ID \t course \t faculty\n");
			printCourseDetails(ctree);
			printf("\nRoll Number \t Student Name \t\t Father Name \t Inter Marks \t courses\n\n");
			printStudentDetails(stree);
			printf("\nroll number \t course number \t courses \n");
			printStudentCourseList(schead);
			break;
		
		case 's':
			while(1){
				printf("Search by Roll : r\n");
				printf("Search for course details : c\n");
				printf("Search course ID : i\n");
				printf("Search faculty by course : f\n");
				printf("Search students under faculty : s\n");
				printf("back : b\n");
				char id[2];
				scanf("%s",id);
				if(id[0] == 'b') break;
				long int roll;
				int cID;
				

				switch(id[0]){
					case 'r':
						printf("Enter a roll number : ");
						scanf("%ld",&roll);
						SearchList(stree,roll,n);
						break;
	
					case 'c':
						printf("\nEnter a roll number to search their course Details: ");
						scanf("%ld",&roll);
						SearchBycourse(headptr,roll,ctree,n);
						break;

					case 'i':
						printf("\nEnter a CourseId: ");
						scanf("%d",&cID);
						Searchbycid(headptr,cID,stree,m,0);
						break;
					case 'f':
						printf("\nEnter Course ID:");
						scanf("%d",&cID);
						Searchfaculty(cID,ctree,m);
						break;
					case 's':
						printCourseDetails(ctree);
						facView(ctree,headptr,stree,m);
						break;


				}
				
			}
			break;
		
		case 'm':
			while(1){
				printf("Add course : a\nDrop course : l\nChange Faculty : f\nSearch by Inter marks : i\nFaculty Details : x\nBack : b\n");
				char ops[2];
				scanf("%s",ops);
				if(ops[0] == 'b') break;
				switch(ops[0]){
					case 'a':
						AddCourses(stree,headptr,ctree);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printStudentCourseList(schead);
							printf("\n");
						}
						break;
					case 'l':
						DropCourses(stree,headptr,ctree);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printStudentCourseList(schead);
							printf("\n");
						}
						break;
					case 'f':
						printCourseDetails(ctree);
						Faculty_change(ctree);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printCourseDetails(ctree);
							printf("\n");
						}
						break;
					case 'i':
						searchByInter(stree);
						break;
					case 'x':
						printCourseDetails(ctree);
						FacultyDetails(ctree);
						break;
				}
			}
			break;
			 
		case 'd':
			while(1){
				printf("Delete Course ID : c\nDelete by Roll no : r\nDelete Faculty : f\nDelete Course : d\nDelete Student : s\nBack : b\n");
				char opr[2];
				scanf("%s",opr);
				if(opr[0] == 'b') break;
				int id;
				long int roll;
				char faculty[20],course[10],student[20];
				
				switch(opr[0]){
					case 'c':
						printf("Enter ID :");
						scanf("%d",&id);
						ctree = deleteCourse(ctree, id);
						schead = deleteSCid(schead, id);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printCourseDetails(ctree);
							printf("\n");
							printStudentCourseList(schead);
							printf("\n");
						}
						break;
						
					case 'r':
						printf("Enter Roll:");
						scanf("%ld",&roll);
						stree = deleteStudent(stree, roll);
						schead = deleteSClist(schead, roll);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printStudentDetails(stree);
							printf("\n");
							printStudentCourseList(schead);
							printf("\n");
						}
						break;
						
					case 'f':
						printf("EnterFaculty Name:");
						scanf("%s",faculty);
						CTREE *new_ctree = NULL;
						new_ctree = deleteFaculty(ctree, faculty);
						schead = deleteSCListFaculty(faculty, ctree, schead);
						break;
						
					case 'd':
						printf("Enter course name(valid course):");
						scanf("%s",course);
						id = getId(ctree, course);
						ctree = deleteCourse(ctree, id);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printCourseDetails(ctree);
						}
						break;
						
					case 's':
						printf("Enter student name:");
						scanf("%s",student);
						stree = getRoll(stree, stree, student);
						stree = deleteStudent(stree, roll);
						printf("Do you want to print the results [Y/N]");
						scanf("%s",choice);
						if(choice[0] == 'Y' || choice[0] == 'y'){
							printStudentDetails(stree);
							printf("\n");
						}
						break;
				}
				
			}
		}
		
	}
	
	clock_t end = clock();
		
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//printf("%lf\n",time_spent); // execution time
return 0;
}

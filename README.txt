#Task-1:

Done By:N.Prudhvi Krishna
Description:Creating The Data

1.Declaring Of the structures
	
	a.Student Details
	b.Course
	c.Student-course list
	d.tree which contains Student Details
	e.tree which contains Course Details
	f.list which holds student-course details
	g.list which holds binary digits

1.1 BINARY* add(BINARY **curr, int n)
	This function inserts the binary number obtained into a node

1.2 BINARY* genBinary(int number,BINARY *bhead)
	This function gets a decimal number and generates binary numbers in the form of a linked list
	
1.3 int inArray(int count, int input, int* array)
	This function ensures that randomly generated input does not repeat

1.4 SCLIST *getNode(STREE *temp,int k,int m)
	This function generates a random number and links the data in the form of a list

1.5 SCLIST *generateList(SCLIST *sclist,STREE *temp,int i,int m)
	Generates list consisting student-course details
		
1.6 STREE *generateStudentDataSet(STREE *stree,int n,int m)
	Generates student Details and inserts them into a complete binary tree

1.7 void printStudentDetails(STREE *stree)
	Prints the student details

1.8 CTREE *generateCourseDataSet(CTREE *ctree,int m)
	Generates course details and inserts them into a complete binary tree

1.9 void printCourseDetails(CTREE *ctree)
	Prints the courseid coursename and instructor

1.10 void printStudentCourseList(SCLIST *root)
	Prints the details of student ,his elected number of courses and course ID's

EMAIL : prudhvikrishna.n16@iiits.in

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Task-2:

Done By:K UPENDRA SAINATH REDDY
Description:SEARCHING THE DATA

1.Declaring Of the structures
	
	a.SearchList(stree,r,n)
	b.SearchBycourse(headptr,r1,ctree,n)
	c.Searchbycid(headptr,r2,stree,m,0)
	d.facView(ctree,headptr,stree,m)
	e.Searchfaculty(cID,ctree,m)

2.1 void SearchList(STREE* root,long int rollnumber,int n)
      a).This function is used to search the roll number the student and prints the details of the student and the course Id he taken
      b).Input:The input to this function is the student roll number 
      c).Ds used:data structure used for generating STREE in task1.(complete binary tree) 
    

2.2 void SearchBycourse(SCLIST *head,long int roll,CTREE *ctree,int n)
      a).This function is used to search the roll number of th student and prints the courses and course details of course he taken i.e course id,faculty name,course name
      b).Input:The input to this function is the student roll number 
      c).Ds used:data structure used for generating CTREE and SCLIST in task1.(complete binary tree,Linked List) 

2.3 void Searchbycid(SCLIST *head,int cid,STREE *root,int courses,int check)
      a).This function is used to retrive details of the students who are studying under the respective course
      b).Input: The input to this function is Course id which is a Number
      c).Ds used:data structure used for generating STREE and SCLIST in task1.(complete binary tree,Linked List) 

2.4 void Searchfaculty(int cid,CTREE *root,int courses)
      a).This function is used to print the faculty details who is teaching the given course
      b).Input: The input to this file is Course id which is a number
      c).Ds used:data structure used for generating STREE in task1.(complete binary tree)

2.5 void facView(CTREE *ctree,SCLIST *head,STREE *root,int courses)
    a).This function is used to search the professor name and print the student roll numbers who are present under his/her courses
    b).Input : The input to this Function is Professor Name and the Names and their respective courses are displayed and the Name should be entered as it is as the displayed way
    c).Ds used:data structure used for generating STREE,SCLIST and CTREE in task1.(complete binary tree,Linked List) 

EMAIL : sainathreddy.k16@iiits.in

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Task-3:

Done By:P.Rahul Raghava
Description:Modify Data and Search Data

declaration of structure:
	->NODE:for forming a linked list to store name of courses.

3.1 Function that takes input of courses a student wants to add apart from existing courses
	AddCourses(stree,headptr,ctree)
	DS Used: data structure used for generating stree in task1.(complete binary tree) 

3.2 Function that takes input of courses a student wants to drop from existing courses
	DropCourses(stree,headptr,ctree)
	
	DS Used: data structure used for generating stree in task1.(complete binary tree)

3.3 Function to change faculty if he leaves the institute
	Faculty_change(ctree)
	DS Used: data structure used for generating ctree in task1.(complete binary tree)

3.4 Function that prints the courses under a faculty
	searchByInter(stree)
	DS Used: data structure used for generating stree in task1.(complete binary tree)

3.5 Function that prints the courses under a faculty
	FacultyDetails(ctree)
	DS Used: data structure used for generating ctree in task1.(complete binary tree)

3.6 Checks whether the entered roll no exists or not
	CheckRoll(SCLIST *temp2,long int rollno)	
	DS Used: data structure used for generating sclist in task1.(linked list)

3.7 Checks for the criteria of not having less than 6 courses
	int checkCourse(SCLIST *ntemp ,long int roll)
	DS Used: data structure used for generating stree in task1.(linked list)

3.8 Checks for the criteria of not having more than 10 courses
	int checkCourseA(SCLIST *ptemp ,long int roll)
	DS Used: data structure used for generating stree in task1.(linked list)

**"All the details entered should be in accordance with the details displayed and should be entered in the same way""**

EMAIL : rahulraghava.p16@iiits.in
 -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#Task-4:

Done By : D Sumanth
Description : Deleting data

4 The process of deletion is done int this task. The deletion process is done taking different parameters namely roll number, courrse ID, faculty name, student name, course name.

4.1 Takes head node of course-tree and the id to be deleted and deletes the corresponding node from the tree
CTREE *deleteCourse(CTREE *CTree, int id)

4.2 Takes head node of student-course linked list and deletes the corresponding node
SCLIST *deleteSCid(SCLIST *head, int id)

4.3 Takes head node of std tree and roll number, creates a queue and deletes node from it
STREE *deleteStudent(STREE *head, long int roll)

4.4 To delete corresponding node from the std-course linked list
SCLIST *deleteSClist(SCLIST *queue, long int roll)

4.5 Takes head node of tree and string containing faculty name, creates a queue and deletes node from it
CTREE *deleteFaculty(CTREE *head, char fname[])

4.6 Deletes node from the student-course linked list
SCLIST *deleteSCListFaculty(char faculty[], CTREE *head, SCLIST *scHead)

4.7 To retrieve the course id from the tree
int getId(CTREE *head, char CName[])

4.8 To get roll number from the tree
STREE *getRoll(STREE *root, STREE *head, char name[])

EMAIL : sumanth.d16@iiits.in


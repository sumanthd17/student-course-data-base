// structure for the queue
typedef struct node{
	CTREE *node;
	struct node *next;
}QUEUE;


// structure for queue
typedef struct tree{
	STREE *stdNode;
	struct tree *next;
}stdQUEUE;

void deleteQueue(QUEUE *queue){
	if(queue->next != NULL)
		deleteQueue(queue->next);
	
	//deleteQueue(queue);
	free(queue);	
}

void deleteSqueue(stdQUEUE *queue){
	if(queue->next != NULL)
		deleteSqueue(queue->next);
	
	free(queue);
}

// to push nodes into the queue
QUEUE *push(QUEUE *queue, CTREE *head){
	QUEUE *front = queue, *rear;
	rear = (QUEUE*)malloc(sizeof(QUEUE));
	rear->node = head;
	rear->next = NULL;
	
	if(queue == NULL)
		return rear;
		
	while(queue->next != NULL)
		queue = queue->next;
		
	queue->next = rear;
	
	return front;
}

// it takes the head node of tree and tranverses each node and creates a queue
QUEUE *createQueue(CTREE *head){
	QUEUE *queue = NULL, *root = NULL;
	queue = push(queue, head);
	root = queue;
	while(queue != NULL){
		CTREE *current;
		current = queue->node;
		if(current->left != NULL)
			queue = push(queue, current->left);
			
		if(current->right != NULL)
			queue = push(queue, current->right);
		queue = queue->next;
	}
	return root;
}

// to print the values int the queue
void printQueue(QUEUE *head){
	while(head != NULL){
		printf("%d\n",head->node->course->courseId);
		head = head->next;
	}
}

// takes address of queue and deletes the corresponding node from queue
QUEUE *Delete(QUEUE *queue, int id, CTREE *root){
	QUEUE *temp;
	int count=0,i;
	temp=queue;
	while(temp!=NULL){
	    count++;
	    if(temp->node->course->courseId == id)
	        break;
	 
		temp=temp->next;
	}
	if(count == 1){
		temp = temp->next;
		return temp;
	}

	temp=queue;
	for(i = 0;i<count-2;i++)
	    temp=temp->next;

	    QUEUE* temp2 = temp->next;
	    temp->next = temp2->next;
	    free(temp2);
	return queue;    
}

// by transversing through each node in the queue, we create a tree
CTREE *generateTree(QUEUE *queue, CTREE *root){
	BINARY *bhead = NULL, *jump;
	CTREE *temp = NULL,*chead = NULL,*ctree = NULL;
	int count = 0,i;
	for(i = 1; queue/* change afterwards*/; i++){
		count = 0;
		bhead = genBinary(i, bhead);
		jump = bhead;
		
		temp = (CTREE*)malloc(sizeof(CTREE));
		temp->course = (COURSE*)malloc(sizeof(COURSE));
		
		temp->course->courseId = queue->node->course->courseId;
		strcpy(temp->course->courseName, queue->node->course->courseName);
		strcpy(temp->course->facultyName, queue->node->course->facultyName);
		temp->left = NULL;
		temp->right = NULL;
		queue = queue->next;
		while(jump){
			if(ctree==NULL)
			{
				chead=temp;
				ctree=temp;
			}
			else{
				if(bhead->num==0)
				{
					if(ctree->left==NULL)
					{
						ctree->left=temp;
					}
				else{
					ctree=ctree->left;}
				}
				if(bhead->num==1 && count>0)
				{
					if(ctree->right==NULL)
					{
						ctree->right=temp;
					}
				else{
					ctree=ctree->right;}
				}
			}
			jump=jump->next;
			bhead=bhead->next;
			count++;
		}
		ctree=chead;
	}
		
}

// deleting id from std-course linked list
SCLIST *checkList(SCLIST *root, int id){
	SCLIST *head;
	head = root;
	while(head){
		int i,j;
		for(i = 1; i <= head->Ccount; i++){
	
			if(head->cID[i] == id){
				for(j = i; j <= head->Ccount - 1; j++){
					head->cID[j] = head->cID[j+1];
				}
				head->Ccount--;
				break;
			}
		}
		head = head->next;
	}
	
	return root;
}

// takes head node of course-tree and the id to be deleted and deletes the corresponding node from the tree
CTREE *deleteCourse(CTREE *CTree, int id){
	QUEUE *queue = NULL;
	queue = createQueue(CTree);
	CTREE *node = NULL,*newTree = NULL;
	queue = Delete(queue, id, CTree);
	newTree = generateTree(queue, newTree);
	deleteQueue(queue);
	//deleteQueue(queue);
	printf("\n");
	return newTree;
}

// takes head node of student-course linked list and deletes the corresponding node
SCLIST *deleteSCid(SCLIST *head, int id){
	SCLIST *newHead;
	newHead = checkList(head, id);
	return newHead;
}

// to push node into queue
stdQUEUE *pushNode(stdQUEUE *queue, STREE *head){
	stdQUEUE *front = queue, *rear;
	rear = (stdQUEUE*)malloc(sizeof(stdQUEUE));
	rear->stdNode = head;
	rear->next = NULL;
	
	if(queue == NULL)
		return rear;
		
	while(queue->next != NULL)
		queue = queue->next;
		
	queue->next = rear;
	
	return front;
}

// creating a temporary queue
stdQUEUE *createStdQueue(STREE *head){
	stdQUEUE *queue = NULL, *root = NULL;
	queue = pushNode(queue, head);
	root = queue;
	while(queue != NULL){
		STREE *current;
		current = queue->stdNode;
		if(current->left != NULL)
			queue = pushNode(queue, current->left);
			
		if(current->right != NULL)
			queue = pushNode(queue, current->right);
		queue = queue->next;
	}
	return root;
}

// delete corresponding node from the temporary queue 
stdQUEUE *deleteSQueue(long int roll, stdQUEUE *queue){
	stdQUEUE *temp;
	int count=0,i,flag = 0;
	temp=queue;
	while(temp!=NULL){
	    count++;
	    if(temp->stdNode->student->sroll == roll){
	    	flag = 1;
	        break;
	       }
	 
		temp=temp->next;
	}
	if(flag == 0)
		return queue;
		
	if(count == 1){
		temp = temp->next;
		return temp;
	}

	temp=queue;
	for(i = 0;i<count-2;i++)
	    temp=temp->next;

	    stdQUEUE* temp2 = temp->next;
	    temp->next = temp2->next;
	    free(temp2);
	return queue;
}

// generating tree from the queue
STREE *genStdTree(stdQUEUE *queue , STREE *root){
	BINARY *bhead = NULL, *jump;
	STREE *temp = NULL,*shead = NULL,*stree = NULL;
	int count = 0,i;
	for(i = 1; queue/* change afterwards*/; i++){
		count = 0;
		bhead = genBinary(i, bhead);
		jump = bhead;
		
		temp = (STREE*)malloc(sizeof(STREE));
		temp->student = (STUDENT*)malloc(sizeof(STUDENT));
	
		temp->student->sroll = queue->stdNode->student->sroll;
		temp->student->interMarks = queue->stdNode->student->interMarks;
		temp->student->courseNum = queue->stdNode->student->courseNum;
		strcpy(temp->student->fatherName, queue->stdNode->student->fatherName);
		strcpy(temp->student->studentName, queue->stdNode->student->studentName);
		temp->left = NULL;
		temp->right = NULL;
		queue = queue->next;
		while(jump){
			if(stree==NULL)
			{
				shead=temp;
				stree=temp;

			}
			else{
				if(bhead->num==0)
				{
					if(stree->left==NULL)
					{
						stree->left=temp;
					}
				else{
					stree=stree->left;}
				}
				if(bhead->num==1 && count>0)
				{
					if(stree->right==NULL)
					{
						stree->right=temp;

					}
				else{
					stree=stree->right;}
				}
			}
			jump=jump->next;
			bhead=bhead->next;
			count++;
		}
			stree=shead;
		}
}

// takes head node of std tree and roll number, creates a queue and deletes node from it
STREE *deleteStudent(STREE *head, long int roll){
	stdQUEUE *SQueue = NULL;
	SQueue = createStdQueue(head);
	SQueue = deleteSQueue(roll, SQueue);
	STREE *newTree = NULL;
	newTree = genStdTree(SQueue, newTree);
	deleteSqueue(SQueue);
	//free(SQueue);
	return newTree;
}

// to delete corresponding node from the std-course linked list
SCLIST *deleteSClist(SCLIST *queue, long int roll){
	SCLIST *temp;
	int count=0,i;
	temp=queue;
	while(temp!=NULL){
	    count++;
	    if(temp->studroll == roll)
	        break;
	 
		temp=temp->next;
	}
	if(count == 1){
		temp = temp->next;
		return temp;
	}

	temp=queue;
	for(i = 0;i<count-2;i++)
	    temp=temp->next;

	    SCLIST* temp2 = temp->next;
	    temp->next = temp2->next;
	    free(temp2);
	return queue;
}

// deletes the correspnding node from the queue
QUEUE *deleteFacultyQueue(QUEUE *queue, char fname[]){
	QUEUE *temp;
	int count = 0,i,flag = 0;
	temp = queue;
	while(temp){
		count++;
		if(strcmp(temp->node->course->facultyName ,fname) == 0){
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if(flag == 0)
		return queue;
		
	if(count == 1){
		temp = temp->next;
		return temp;
	}
	
	temp = queue;
	for(int i = 0; i < count-2; i++)
		temp = temp->next;
		
	QUEUE *temp2 = temp->next;
	temp->next = temp2->next;	
	return queue;
}

// takes head node of tree and string containing faculty name, creates a queue and deletes node from it
CTREE *deleteFaculty(CTREE *head, char fname[]){
	QUEUE *queue,*temp;
	queue = createQueue(head);
	int count = 0;
	
	temp = queue;
	while(queue){
		temp = deleteFacultyQueue(temp, fname);
		queue = queue->next;
	}
	head = generateTree(temp, head);
	printCourseDetails(head);
	return head;
}

// deletes node from the student-course linked list
SCLIST *deleteSCListFaculty(char faculty[], CTREE *head, SCLIST *scHead){
	QUEUE *queue;
	queue = createQueue(head);
	while(queue){
		if(strcmp(queue->node->course->facultyName,faculty) == 0){
			scHead = deleteSCid(scHead, queue->node->course->courseId);
		}
		queue = queue->next;
	}
	printStudentCourseList(scHead);
	return scHead;
}

// to retrieve the course id from the tree
int getId(CTREE *head, char CName[]){
	QUEUE *queue;
	queue = createQueue(head);
	while(queue){
	if(strcmp(queue->node->course->courseName, CName) == 0){
		return queue->node->course->courseId;
	}
	queue = queue->next;
	}
	//deleteQueue(queue);
}

// to get roll number from the tree
STREE *getRoll(STREE *root, STREE *head, char name[]){
	stdQUEUE *queue = NULL;
	queue = createStdQueue(head);
	while(queue){
		if(strcmp(queue->stdNode->student->studentName, name) == 0){
			head = deleteStudent(head, queue->stdNode->student->sroll);
		}
		queue = queue->next;
	}
	return head;
}

/*int main(int argc,char *argv[])
{
	clock_t begin = clock();
	int n=argc>1?atoi(argv[1]):20;
	int m=17;
	
	//srand((unsigned)time(NULL));
	
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
	printStudentCourseList(schead);
	
	int id = 3;
	ctree = deleteCourse(ctree, id);
	schead = deleteSCid(schead, id);
	printCourseDetails(ctree);
	printf("\n");
	printStudentCourseList(schead);
	printf("\n");
	
	long int stdId = 201601001;
	stree = deleteStudent(stree, stdId);
	printStudentDetails(stree);
	printf("\n");

	schead = deleteSClist(schead, stdId);
	printStudentCourseList(schead);
	printf("\n");
	
	char faculty[] = "Shiv Ram";
	CTREE *new_ctree = NULL;
	new_ctree = deleteFaculty(ctree, faculty);
	schead = deleteSCListFaculty(faculty, ctree, schead);
	//printf("qwe\n");
	
	char CName[] = "DEC";
	id = getId(ctree, CName);
	//printf("%d\n",id);
	ctree = deleteCourse(ctree, id);
	printCourseDetails(ctree);
	printf("\n");
	
	char sname[] = "Apple";
	stree = getRoll(stree, stree, sname);
	//printf("%ld\n",roll);
	//stree = deleteStudent(stree, roll);
	printStudentDetails(stree);
	printf("\n");
	
	clock_t end = clock();
	
	
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n",time_spent); // execution time
return 0;
}*/

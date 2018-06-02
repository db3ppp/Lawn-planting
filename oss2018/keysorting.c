#include        <stdio.h>
#include        <stdlib.h>
#include        <string.h>

#define         MAX_SIZE        1000
#define         BUF_SIZE        80
#define SWAP(a,b,temp) {a=b; b=temp; temp=a;}

typedef struct {
        char    name[20];
        char    student_id[10];
        char    school[20];
        char    major[20];
        int     exam1;
        int     final;
        int     total;
} student;

void selectionsort(student student_list,int numStu);
void quicksort(student student_list,int numStu);
//void heapsort(student student_list,int numStu);

void SWAP (student* s, int a, int b)
{
	student temp;
	temp = s[a];
	s[a] = s[b];
	s[b] = temp;
}

int main()
{
char filename[] = "studentlist.txt";
FILE *fp;

int numStu = 0;
//student student_list[MAX_SIZE];
student* student_list;
char    buffer[BUF_SIZE];
int     i;

int sort;
printf("Sort algorithm 선택하세요\n (1. 2. quick sort 3. heap sort)");
scanf(" %d",&sort);

int key;
printf("Sort에 적용할 key 종류를 선택하세요\n (1.이름 2.학번 3.총점)");
scanf(" %d",&key);


/* reading the input data */
	fp = fopen(filename, "r");
	while (1) {
    if ( fgets(buffer, BUF_SIZE, fp)== NULL) break;

    strncpy(student_list[numStu].name, buffer, strlen(buffer)-1);
    fgets(buffer, BUF_SIZE, fp);
    strncpy(student_list[numStu].student_id, buffer, strlen(buffer)-1);
    fgets(buffer, BUF_SIZE, fp);
    strncpy(student_list[numStu].school, buffer, strlen(buffer)-1);
    fgets(buffer, BUF_SIZE, fp);
    strncpy(student_list[numStu].major, buffer, strlen(buffer)-1);
    fgets(buffer, BUF_SIZE, fp);
    student_list[numStu].exam1 = atoi(buffer);
    fgets(buffer, BUF_SIZE, fp);
    student_list[numStu].final = atoi(buffer);
    student_list[numStu].total = student_list[numStu].exam1 + student_list[numStu].final;
    	numStu++;
	}

	fclose(fp);

/* Sorting the list

        my_sortalgorithm(student_list, numStu);

*/
switch(sort){
  case 1: selectionsort(student_list,numStu);
          break;
  case 2: quicksort(student_list,numStu);
          break;
  case 3: heapsort(studentlist,numStu);
          break;
  default: printf("올바른 key를 입력하세요.\n");
} 


/* display the result */

	printf("\n\n\n  성 명     학 번       학 부     전 공      Exam1    기말      총점    \n\n");
	for (i = 0; i < numStu; i++)
	{
        	printf(" %s  ", student_list[i].name);
        	printf(" %s  ", student_list[i].student_id);
        	printf(" %s  ", student_list[i].school);
        	printf(" %s  ", student_list[i].major);
        	printf(" %6d  ", student_list[i].exam1);
	      	printf(" %6d  ", student_list[i].final);
        	printf(" %6d  ", student_list[i].total);
        	printf("\n");
	}
	printf("\n\n");

}

  void selectionsort(student *s,int numStu,int key){
    int i, j;
    student temp;

    if(key == 1){
    for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
            if(s[i].name > s[j].name)
            temp = s[i].name;
            s[i].name = s[j].name;
            s[j].name = temp;
        }
    }
    }
    else if(key == 2){
         for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
            if(s[i].name > s[j].student_id)
            temp = s[i].student_id;
            s[i].student_id = s[j].student_id;
            s[j].student_id = temp;
        }
    }
    }
    else
       for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
            if(s[i].total > s[j].total)
            temp = s[i].total;
            s[i].total = s[j].total;
            s[j].total = temp;
        }
    }

  }

  void quicksort(student *s,int left, int right, int key){
    student temp;
    int pivot,i,j;

    if(left < right){
      i = left; j = right+1;

      if(key == 1){
      pivot = s[left].name;

      do{
        do i++; while(s[i].name < pivot);
        do j++; while(s[j].name > pivot);
      if(i<j) SWAP(s,i,j);
      }while(i<j);
      SWAP(s,left,j);
      quicksort(s,left,j-1);
      quicksort(s,j+1,right);
      }

      else if(key == 2){
        pivot = s[left].student_id;

      do{
        do i++; while(s[i].student_id < pivot);
        do j++; while(s[j].student_id > pivot);
      if(i<j) SWAP(s,i,j);
      }while(i<j);
      SWAP(s,left,j);
      quicksort(s,left,j-1);
      quicksort(s,j+1,right);
      }

      else{
        pivot = s[left].total;

      do{
        do i++; while(s[i].total < pivot);
        do j++; while(s[j].total > pivot);
      if(i<j) SWAP(s,i,j);
      }while(i<j);
      SWAP(s,left,j);
      quicksort(s,left,j-1);
      quicksort(s,j+1,right);
      }

    }

  }

  /*void heapsort(student *s,int n,int key){
    int i,j;
    student temp;

    for(i = n/2; i>0; i--)
    adjust(s,i,n);

    for(i=n-1; i>0; i--){
    SWAP(s[1],s[i+1],temp);
    adjust(s,1,i);
  }

  }
  void adjust(student s[], int root, int n){
    int child,rootkey;
    student temp;
    temp = s[root];
    rootkey = s[root].key;
    child = 2*root;

    while(child <= n){
      if((child < n) && (s[child].key < s[child+1].key))
      child++;
      if(rootkey > s[child].key)
      break;
      else{
        s[child/2] = s[child];
        child *=2;
      }
    }
    s[child/2] = temp;
  }*/


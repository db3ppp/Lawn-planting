#include        <string.h>

#define         MAX_SIZE        1000
#define         BUF_SIZE        80

typedef struct {
        char    name[20];
        char    student_id[10];
        char    school[20];
        char    major[20];
        int     exam1;
        int     final;
        int     total;
} student;

void selectionsort(student* s,int numStu,int key);
void quicksort(student *s,int left, int right,int key);
//void heapsort(student* s,int numStu,int key);
//void adjust(student *s, int root, int n, int key);
void bubblesort(student* s, int numStu, int key);

void SWAP (student* s, int a, int b){
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
student student_list[MAX_SIZE];
char    buffer[BUF_SIZE];
int     i;
int sort,key;

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

while(1){
printf("Sort algorithm 선택하세요\n (1.selection sort 2. quick sort 3. bubble sort)");
scanf("%d",&sort);
if(sort==1||sort==2||sort==3)
break;
else printf("*올바른 algorithm을 다시 선택하세요*\n");
}
while(1){
printf("Sort에 적용할 key 종류를 선택하세요\n (1.이름 2.학번 3.총점)");
scanf("%d",&key);
if(key==1||key==2||key==3)
break;
else printf("*올바른 key를 다시 입력하세요*\n");
}


/* Sorting the list */

switch(sort){
  case 1: selectionsort(student_list,numStu,key);
          break;
  case 2: quicksort(student_list,0,numStu-1,key);
          break;
  //case 3: heapsort(student_list,numStu,key);
  case 3: bubblesort(student_list,numStu,key);
          break;
  default: printf("올바른 key를 입력하세요.\n");
  break;

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

    if(key == 1){
    for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
          if(strcmp(s[i].name, s[j].name)>0)
            SWAP(s,i,j);
        }
      }
    }
    else if(key == 2){
         for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
            if(strcmp(s[i].student_id, s[j].student_id)>0)
            SWAP(s,i,j);
        }
     }
    }
    else if(key == 3){
       for(i=0; i<numStu-1; i++) {
        for(j=i; j<numStu; j++) {
            if(s[i].total > s[j].total)
            SWAP(s,i,j);
        }
      }
    }
    else
      printf("올바른 key를 입력하세요.\n");

  }

  void quicksort(student *s, int left, int right, int key){

      if(key == 1){
        if(left>right) return;

        if(left <= right){
        int i,j;
        i = left; j = right+1;
        char* pivot = s[left].name;

        do{
         do i++; while(strcmp(s[i].name, pivot) < 0);
         do j--; while(strcmp(s[j].name, pivot) > 0);
         if(i<j) SWAP(s,i,j);
         }while(i<j);
       SWAP(s,left,j);
        quicksort(s,left,j-1,key);
        quicksort(s,j+1,right,key);
        }
      }

       else if(key == 2){
        if(left>right) return;

        if(left <= right){
        int i,j;
        i = left; j = right+1;
        char* pivot = s[left].student_id;

        do{
         do i++; while(strcmp(s[i].student_id, pivot) < 0);
         do j--; while(strcmp(s[j].student_id, pivot) > 0);
         if(i<j) SWAP(s,i,j);
         }while(i<j);
       SWAP(s,left,j);
        quicksort(s,left,j-1,key);
        quicksort(s,j+1,right,key);
        }
      }

      else if(key == 3){

        if(left>right) return;

        if(left <= right){
        int i,j;
        i = left; j = right+1;
        int pivot = s[left].total;

      do{
        do i++; while(s[i].total < pivot);
        do j--; while(s[j].total > pivot);
        if(i<j) SWAP(s,i,j);
        }while(i<j);
      SWAP(s,left,j);
      quicksort(s,left,j-1,key);
      quicksort(s,j+1,right,key);
       }
      }
      else
      printf("올바른 key를 입력하세요.\n");

    }

  void bubblesort(student* s, int n, int key){
    int i,j;
    if(key == 1){
    for(i=0; i<n-1; i++){
      for(j=i+1; j<n; j++){
        if(strcmp(s[i].name,s[j].name)>0)
        SWAP(s,i,j);
      }
    }
    }
    else if(key == 2){
      for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
        if(strcmp(s[i].student_id,s[j].student_id)>0)
        SWAP(s,i,j);
      }
    }
    }
    else if(key == 3){
      for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
        if(s[i].total>s[j].total)
        SWAP(s,i,j);
      }
    }
    }
    else
     printf("올바른 key를 입력하세요.\n");

  }  }



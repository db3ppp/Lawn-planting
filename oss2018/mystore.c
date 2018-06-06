#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsmn.h"

/*
 * A small example of jsmn parsing when JSON structure is known and number of
 * tokens is predictable.
 *a
*/
typedef enum {
	C_COFFEE = 0,
	C_FRAPPUCCINO = 1
}mycategory_t;
typedef struct {
	mycategory_t cat;
	char name[20];
	char size[10];
	int price;
}mymenu_t;

int menucount;

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

//lab 2
char * readjsonfile(const char * filename)
{
	char input[500]; 
	char *result;
	
	FILE *fp;
	fp = fopen(filename, "r");
	
	result = (char *) malloc(1);

	while(fgets(input, sizeof(input), fp) != NULL) {
		
		result = (char *) realloc(result, strlen(result) + strlen(input));
		strcat(result, input);
	}
	

	return result;
}

//lab 3
int makemymenu(const char* json, jsmntok_t* t, int tokcount, mymenu_t* m[]){
        int i,count;
	int price;
	char* category;
	char* parent;
	char* child;

	for(i=0,count=0; i<tokcount; i++){
		if(t[i+1].type == 2 && t[i+2].type == 1){
			category = (char*)malloc(t[i].end-t[i].start+1);
			strncpy(category, json+t[i].start,t[i].end-t[i].start);
		}

		if(t[i].size == 0){//하위token이 존재하지 않으면
			parent = (char*)malloc(t[t[i].parent].end-t[t[i].parent].start+1);
			strncpy(parent, json+t[t[i].parent].start, t[t[i].parent].end-t[t[i].parent].start);
			
			child = (char*)malloc(t[i].end-t[i].start+1);
			strncpy(child, json+t[i].start, t[i].end-t[i].start);
			price = atoi(child);
			
			if(strcmp(parent, "name") == 0){
				m[count] = (mymenu_t*)malloc(sizeof(mymenu_t));
				strcpy(m[count]->name, child);
			if(strcmp(category, "coffee") == 0)
				m[count]->cat = 0;
			else
				m[count]->cat = 1;
			}
			if(strcmp(parent, "size") == 0)
				strcpy(m[count]->size, child);
			if(strcmp(parent, "price") == 0){
				m[count]->price = price;
				count++;
				}
		}
	}
	return count;
}

//lab 4
void printmenu(mymenu_t* m[], int mcount){
	int i;
	char* category = (char*)malloc(20);

	printf("\n***** print menu *****\n");
	for(i=0; i<mcount; i++){
		if(m[i]->cat == 0)
			strcpy(category,"coffee");
		else
			strcpy(category,"frappuccino");

	printf("[%2d] %s (category: %s size: %s price: %d)\n",i+1, m[i]->name, category, m[i]->size, m[i]->price);

	}
}

// +추가과제: 매출계산하기
void salemenu(mymenu_t* m[], int mcount){
	int total=0;
	int menu,count;
	int i;
	int m_total[8] = {0};

	while(1){
	printmenu(m,mcount);
	printf("\n주문할 음료 번호를 선택하세요(9. 주문끝내기)\n");
	scanf("%d",&menu);
	if(menu == 9) break;

	printf("몇개를 주문하시겠습니까?\n");
	scanf("%d",&count);
	
	switch(menu){
	case 1: total += count *  m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
		break;
	case 2: total += count * m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
		break;
        case 3: total += count *  m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
                break;
        case 4: total += count * m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
                break;
        case 5: total += count *  m[menu-1]->price;
                m_total[menu-1] += count * m[menu-1]->price;
		break;
        case 6: total += count *  m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
                break;
        case 7: total += count *  m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
                break;
        case 8: total +=  count* m[menu-1]->price;
		m_total[menu-1] += count * m[menu-1]->price;
                break;
	default: printf("올바른 메뉴번호를 입력하세요.\n");
		break;
	}
 }
for(i=0; i<mcount; i++)
 printf("[%d]번 음료의 판매금액은 %d 원입니다.\n", i+1, m_total[i]);
printf("\n===총 판매금액은 %d 원입니다.===\n",total);

}

int main(){
	int i;
	int r;
	int keyarray[128];
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */
	mymenu_t * mymenu[20];

	char *JSON_STRING = readjsonfile("mymenu.json");
        printf("%s \n",JSON_STRING);
	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));


	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
		return 1;
	}

	menucount = makemymenu(JSON_STRING,t,r,mymenu);
	//printmenu(mymenu, menucount);
	salemenu(mymenu, menucount);
	return EXIT_SUCCESS;
}

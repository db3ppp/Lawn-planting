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


void printkeys(const char *json, jsmntok_t *t, int tokcount){
	printf("\n***** All Keys *****\n");
	int i;
	int keycount = 1;
	char* str = '\0';

	for( i=1; i < tokcount; i++){
		str = (char*)malloc(t[i].end-t[i].start+1);
		strncpy(str, json+t[i].start, t[i].end-t[i].start);
		
		if(t[i].size >0  && (t[i].type != 1 && t[i].type!= 2)){
		printf("[%d] %s(%d)\n",keycount, str, i);
		keycount++;
		}
	}
}

int findkeys(const char *json, jsmntok_t* t, int tokcount, int* keys){
	int i;
	int count = 0;
	char* str = '\0';

	for(i =0; i<tokcount; i++){
		str = (char*)malloc(t[i].end-t[i].start+1);
		strncpy(str, json+t[i].start, t[i].end-t[i].start);
		
		if(t[i].size > 0 && (t[i].type != 1 && t[i].type!= 2)){
		keys[count] = i;
		count++;
		}
	}
	printf("\n*print keys stored in array*\n");
	for(i=0;i<count;i++)
	printf("%d ",keys[i]);

	return count;
}
void printvalues(const char* json, jsmntok_t* t, int tokcount, int *keys){
	int i,j;
	char* str = '\0';
	
	printf("\n\n***** Print Values *****\n");

	for(i =0; i<tokcount; i++){
	        str = (char*)malloc(t[i].end-t[i].start+1);
	  	strncpy(str,json+t[i].start,t[i].end-t[i].start);

		for(j=0; j<menucount; j++){
			if(keys[j] == i)
			printf("key = %d, value = %s\n",keys[j],str);
		}	
	}
}


int main() {
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
	printmenu(mymenu, menucount);

	return EXIT_SUCCESS;
}

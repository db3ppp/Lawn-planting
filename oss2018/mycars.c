#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsmn.h"

/*
 * A small example of jsmn parsing when JSON structure is known and number of
 * tokens is predictable.
 *a
*/
typedef struct {
	char model[20];
	char maker[20];
	char gastype[20];
	int year;
}car_t;

int carcount;

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
	
	//first allocation
	result = (char *) malloc(1);

	while(fgets(input, sizeof(input), fp) != NULL) {
		
		//2~nth allocation
		result = (char *) realloc(result, strlen(result) + strlen(input));
		strcat(result, input);
	}
	return result;
}

int makecarlist(const char* json, jsmntok_t* t, int tokcount, car_t*list[]){
        int i,count;
        int year;
        char* category;
        char* parent;
        char* child;

        for(i=1,count=0; i<tokcount; i++){
//                if(t[i].size == 0){//하위token이 존재하지 않으면= value이면
                       if(t[i].size==0 && t[i].size !=1){

			parent = (char*)malloc(t[t[i].parent].end-t[t[i].parent].start+1);
                        strncpy(parent, json+t[t[i].parent].start, t[t[i].parent].end-t[t[i].parent].start);
	                
			child = (char*)malloc(t[i].end-t[i].start+1);
                        strncpy(child, json+t[i].start, t[i].end-t[i].start);
                        year = atoi(child);
                        printf("#%s#%s\n",parent,child); 

                        if(strcmp(parent, "model") == 0){
                                list[count] = (car_t*)malloc(sizeof(car_t));
                                strcpy(list[count]->model, child);
                        }

                        else if(strcmp(parent, "maker") == 0)
                                strcpy(list[count]->maker, child);
                 	else  if(strcmp(parent,"gas") == 0)
                                strcpy(list[count]->gastype, child);
                       else  if(strcmp(parent, "year") == 0){
                                list[count]->year = year;
                                count++;
                                }
                }
        }
        return count;

}

void printcarlist(car_t* list[], int carcount){
	int i;
        printf("\n***** print carlist *****\n");
	
        for(i=0; i<carcount; i++)
        printf("[%2d] (model: %s maker: %s year: %d gastype: %s)\n",i+1, list[i]->model, list[i]->maker, list[i]->year, list[i]->gastype);
}

int main() {
	int i;
	int r;
	int keyarray[128];
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */
	car_t* carlist[5];

	char *JSON_STRING = readjsonfile("cars.json");
        printf("%s \n",JSON_STRING);
	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));


	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
		return 1;
	}
	
	carcount = makecarlist(JSON_STRING,t,r,carlist);
	printf("carcount=%d\n",carcount);
	printcarlist(carlist,carcount);
	
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../jsmn.h"

/*
 * A small example of jsmn parsing when JSON structure is known and number of
 * tokens is predictable.
 */
int keyamount;

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

        result = (char *) malloc(1));


        while(!feof(fp)) {

                fgets(input, sizeof(input), fp);

                result = (char *) realloc(result, sizeof(result) + sizeof(input));

                strcat(result, input);

	}

        return result;

}



void printall(const char *json, jsmntok_t*t, int tokcount){

        printf("\n***** All Tokens *****\n");



        int i;

        char* type = (char*)malloc(20);

        char* str = '\0';



         for(i=1 ; i<tokcount ; i++){

                str = (char*)malloc(t[i].end-t[i].start+1);

                strncpy(str, json+t[i].start, t[i].end-t[i].start);

                if(t[i].type ==0)

                        strcpy(type,"JSMN_UNDEFINED");

                else if(t[i].type == 1)

                        strcpy(type,"JSMN_OBJECT");

                else if(t[i].type == 2)

                        strcpy(type,"JSMN_ARRAY");

                else if(t[i].type ==3)

                        strcpy(type,"JSMN_STRING");

                else if(t[i].type == 4)

                        strcpy(type,"JSMN_PRIMITIVE");

                else

                        strcpy(type,"UNDFINED");
		 

             printf("[%2d] %s  (size: %d, %d~%d, %s)\n" ,i ,str, t[i].size,t[i].start,t[i].end,type);

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

                for(j=0; j<keyamount; j++){
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

        char *JSON_STRING = readjsonfile("library.json");
        printf("%s \n",JSON_STRING);
        jsmn_init(&p);
        r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));



#ifdef DEBUG_MODE
        for(i=0;i<r;i++){
           printf("[%2d] (%d) %d~%d, size: %d\n",i,t[i].type,t[i].start,t[i].end                  ,t[i].size);
                }
#endif


        if (r < 0) {
                printf("Failed to parse JSON: %d\n", r);
                return 1;
        }

        printall(JSON_STRING,t,r);
        printkeys(JSON_STRING,t,r);

        keyamount = findkeys(JSON_STRING,t,r,keyarray);
        printvalues(JSON_STRING,t,r,keyarray);
        return EXIT_SUCCESS;
}

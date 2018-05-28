//Lab 1 : json text file 읽어오기
char * readjsonfile(const char * filename)
{
	char temp[200];
	char *result;
	
	FILE *fp;
	fp = fopen(filename, "rt");

	fgets(input, sizeof(temp), fp);

	result = (char *) malloc(strlen(temp));
	strncpy(result, temp, strlen(temp));

	while(!feof(fp)) {
		fgets(temp, sizeof(temp), fp);
		result = (char *) realloc(result, sizeof(result) + sizeof(temp));
		strcat(result, temp);
	}
	
	result[strlen(result)] = '\0';

	return result;
}

//Lab2: json token 정보출력
void printall(const char *json, jsmntok_t*t, int tokcount){
        printf("\n***** All Tokens *****\n");

        int i;
        char* type = (char*)malloc(20);
        char* str = '\0';
         for(i=1 ; i<tokcount ; i++){

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
                        strcpy(type,"JSMN_UNDFINED");

                str = (char*)malloc(t[i].end-t[i].start+1);
                strncpy(str, json+t[i].start , t[i].end-t[i].start);

             printf("[%2d] %s  (size: %d, %d~%d, %s)\n" ,i ,str, t[i].size,t[i].start,t[i].end,type);
 }
}

//Lab3: json keys 출력
void printkeys(const char *json, jsmntok_t *t, int tokcount){
        printf("\n***** All Keys *****\n");
        int i;
        int keycount = 1;
        char* str = '\0';

        for( i=1; i < tokcount; i++){
                str = (char*)malloc(t[i].end-t[i].start+1);
                strncpy(str, json+t[i].start, t[i].end-t[i].start);

                if(t[i].size == 1 && t[i].type == 3){
                printf("[%d] %s(%d)\n",keycount, str, i);
                keycount++;
                }
        }
}

//Lab4: json key token array찾기
int findkeys(const char *json, jsmntok_t* t, int tokcount, int* keys){
        int i;
        int count = 0;
        char* str = '\0';

        for(i =0; i<tokcount; i++){
                str = (char*)malloc(t[i].end-t[i].start+1);
                strncpy(str, json+t[i].start, t[i].end-t[i].start);

                if(t[i].size == 1 && t[i].type == 3){
                keys[count] = i;
                count++;
                }
        }
        printf("\n*print keys stored in array*\n");
        for(i=0;i<count;i++)
        printf("%d ",keys[i]);

        return count;
}

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 1000

int main()
{
    printf("Please enter the nr. of entries : ");

    int entries;
    scanf("%d",&entries);

    float count = 0;
    char kept_string[MAX_CHARS], rand_string[MAX_CHARS];

    FILE *in;
    in = fopen("words.txt","r");
    FILE *out;
    out = fopen("input.txt","w");

    for (; count<entries; count++){

        if (in != NULL){

            srand(time(NULL));

            while (fgets(rand_string,MAX_CHARS,in) != NULL){


                if (rand() / (float)RAND_MAX < (1.0 / count)){

                    count++;
                    if (count > entries){
                        break;
                    }

                    strcpy(kept_string,rand_string);

                    if (kept_string[strlen(kept_string)-1] == '\n'){

                        kept_string[strlen(kept_string)-1] = '\0';
                    }

                    if(count>1){
                        fprintf(out,"\n");
                    }

                    fprintf(out,"%d\n",rand()%11);
                    fprintf(out,"%s\n",kept_string);

                    if (fgets(rand_string,MAX_CHARS,in) != NULL){

                        strcpy(kept_string,rand_string);

                        if (kept_string[strlen(kept_string)-1] == '\n'){

                            kept_string[strlen(kept_string)-1] = '\0';

                        }

                    }

                    fprintf(out,"%s",kept_string);

                }

            }

        }

    }
    fprintf(out,"\n");
    fprintf(out,"\n");
    fprintf(out,"\n");
    fclose(in);
    fclose(out);
    printf("Entries added.\n");

    return 0;

}
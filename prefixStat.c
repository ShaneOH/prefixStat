#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

int wordcount(FILE *fp);
int linecount(FILE *fp);

int main(int argc, char *argv[])
{
    char help[] = "-h";
    char line[] = "-l";
    char word[] = "-w";
    char pre[] = "-p";

    if(argc < 2 || argc > 3){   /*check for correct number of input*/
    fprintf(stderr, "Invalid input.\n");
    }

    else
    {
    FILE *fp;
    fp = fopen("test.dat", "r");
        if(fp == NULL) /*check for file error*/
        {
          fprintf(stderr, "Could not open file.\n");
        }
        else if(argc == 2)
        {

            if(strcmp(argv[1], word) == 0)
            {
                int c;
                int nw = 1;

                while ((c = fgetc(fp)) != EOF)
                {
                    printf("%c", c);
                    if (c == ' ' || c == '\n' || c == '\t'){
                        nw++;
                    }
                }

                printf("\n%d", nw);

            }
            else if(strcmp(argv[1], line) == 0)
            {
                int c;
                int nl = 1;

                while ((c = fgetc(fp)) != EOF)
                {
                    printf("%c", c);

                    if(c == '\n'){
                    nl++;
                    }

                }

                printf("\n%d", nl);
            }
            else if(strcmp(argv[1], help) == 0)
            {
                printf("Welcome. Type one of the following options:\n");
                printf("'-w': output the words of your file and word count\n");
                printf("'-l': output the lines of your file and line count\n");
                printf("'-p <input word>': type in a prefix word to output the words of your file which contain that prefix\n");
            }


            else /*error if not -w, -l, or -h*/
            {
            fprintf(stderr, "Invalid input, please enter either -w, -h, or -l.\n");
            }
        }
        else /*here there must be three arguments passed*/
        {
            if(strcmp(argv[1], pre) != 0)
            {
                fprintf(stderr, "Invalid input.\n");
            }

            else /*here we will execute the prefix function*/
            {
                char tempword[1000];
                int length = strlen(argv[2]);
                char prefix[length];
                strcpy(prefix, argv[2]);

                int i, c;
                i = 0;

                while((c = fgetc(fp)) != EOF)
                {
                    if (c == ' ' || c == '\n' || c == '\t')
                    {
                        if (strncasecmp(prefix, tempword, length) == 0)
                            {
                                printf("%s ", tempword);
                            }
                        i = 0;
                        for(; i < 1000; i++)
                        {
                            tempword[i] = NULL;
                        }
                        continue;
                    }

                tempword[i] = c;
                i++;
                /*printf("%c\n", tempword[i]);*/
                }

            }

        }
    }



}

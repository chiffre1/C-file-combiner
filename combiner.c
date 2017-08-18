#include  <stdio.h>
#include <stdlib.h>




int  nargs;
char  **argstr;

 extern  char  *getarg();

 main(argc,  argv)
 int  argc;
 char **argv;
 {
     int i;
     char *string;
     FILE *fr, *fopen();
     
     allocarg(argc, argv);

     if (nargs == 1)
         filecopy(stdin);
     else
         for (i = 1; i < nargs; i++) {
             string = getarg(i);
             fr = fopen(string, "r");
             filecopy(fr);
             fclose(fr);
     }
}

allocarg(argc, argv)
int argc;
char **argv;
{
    int i;
    /*char *calloc(), *malloc(), *strcpy();*/
    
    nargs = argc;
    argstr = (char**)  calloc((unsigned)  argc,  sizeof(char*));          

    for (i = 0; i <argc; i++) {
        argstr[i] = malloc((unsigned)  strlen(argv[i])+1); 
        strcpy(argstr[i], argv[i]);
    }
}

char *getarg(n)
int n;
{
      if (n > nargs)
          return((char *)-1);
          return(argstr[n]);
}

filecopy(filein)
FILE *filein;
{
    register int c;

    while ((c = getc(filein)) != EOF)
        putc(c, stdout);
}


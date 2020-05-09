#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
   FILE *f1, *f2, *f3, *f4;
   int lc, sa, l, op1, o, len;
   char ml[20], la[20], op[20], otp[20];
    f1 = fopen("input.txt","r");
    f3 = fopen("symtab.txt","w");
    fscanf(f1,"%s%s%d",la, ml, &op1);
    if(strcmp(ml,"START")==0)
    {
	sa = op1;
	lc = sa;
	printf("\t%s\t%s\t%d\n",la,ml,op1);
    }
    else
	lc = 0;
	fscanf(f1,"%s%s",la,ml);
	while(!feof(f1))
	{
		fscanf(f1,"%s",op);
		printf("\n%d\t%s\t%s\t%s\n",lc,la,ml,op);
		if(strcmp(la,"-")!=0)
		{
			fprintf(f3,"\n%d\t%s\n",lc,la);
		}
		f2 = fopen("optab.txt","r");
		while(!feof(f2))
		{
		   if(strcmp(ml,otp)==0)
		   {
			lc = lc+3;
			break;
		   }
		fscanf(f2,"%s%d",otp,&o);
		}
		fclose(f2);
			if(strcmp(ml,"WORD")==0)
			{
				lc=lc+3;
			}
			else if(strcmp(ml,"RESW")==0)
			{
				op1=atoi(op);
				lc=lc+(3*op1);
			}
			else if(strcmp(ml,"BYTE")==0)
			{
				if(op[0]=='X')
					lc=lc+1;
				else
				{
					len=strlen(op)-2;
					lc=lc+len;
				}
			}
			else if(strcmp(ml,"RESB")==0)
			{
				op1=atoi(op);
				lc=lc+op1;
			}
			fscanf(f1,"%s%s",la,ml);
			}
			if(strcmp(ml,"END")==0)
			{
				printf("prigram length = %d\n",lc-sa);
			}
	fclose(f1);
	fclose(f3);

}


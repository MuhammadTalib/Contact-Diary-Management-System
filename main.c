#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
int UPDATE_IN_FILE();
void DELETE_FROM_FILE();
int SEARCH_IN_FILE();
void ADD_IN_FILE();
char *currenttime();
int compare(char a[], char b[]);
int same(char name[]);
int *ptr=0;
void main()
{
    char enter;
    enter='\n';
    do
    {
        system("cls");
        printf("\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("  |**************************************************************|\n");
        printf("  |**************************************************************|\n");
        printf("  |*********************Contact Diary Project********************|\n");
        printf("  |**************************************************************|\n");
        printf("  |**************************************************************|\n");
        printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("  |*******Which Operation you want to do in contact diary********|\n");
        printf("  |*******~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~********|\n");
        printf("  |******************|  1:Add New Contact     |******************|\n");
        printf("  |******************|  2:Search Any Contact  |******************|\n");
        printf("  |******************|  3:Edit Any Contact    |******************|\n");
        printf("  |******************|  4:Delete Any Contact  |******************|\n");
        printf("  |******************~~~~~~~~~~~~~~~~~~~~~~******************|\n");
        printf("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("                   Please Enter Your Choice:");
        char choice=getche();
        printf("\n");
        switch (choice)
        {
            case '1':
            ADD_IN_FILE();
            break;

            case '2':
            SEARCH_IN_FILE();
            break;

            case '3':
            UPDATE_IN_FILE();
            break;

            case '4':
            DELETE_FROM_FILE();
            break;
        }
        printf("          Press Any key to Continue Again:");
        enter=getch();
        printf("\n");
    }
    while(1);
}
void ADD_IN_FILE()
{
    FILE *fp;
    char name[25],number[25],temp[40],temp1[40];
    fp=fopen("Contacts.txt","a+");
    printf("\n");
    printf("                   Enter Contact Name:");
    int n,s;
    do
    {
    name[0]=getche();
    for(n=1;name[n-1]!=13;n++)
    {
        name[n]=getche();
        if(name[n]==13)
        {
            if(!((name[0]>='A'&&name[0]<='Z')||(name[0]>='a'&&name[0]<='z')))
            {
                printf("\b");
                printf("         Sorry first letter should'nt be a special character!\n");
                printf("                   Enter Name:");
                name[0]='\0';
                n=0;
                name[0]=getche();
            }

        }
    }
    name[n]='\0';
    s=same(name);
    if(s==1)
    {
        printf("\b       ");
        printf("\b                   Name already exist!");
        printf("\n            Please Re-Enter Name:");
    }

    }
    while(s==1);

    int i=0,k=0;
    printf("\n");
    while(1)
    {
        k=0;
         printf("                   Enter Number:");
         for(i=0;number[i-1]!=13;i++)
        {
            number[i]=getche();
        }
        number[i]='\0';
        for(i=0;number[i-1]!=13;i++)
        {
            if(((number[i]>='A'&&number[i]<='Z')||(number[i]>='a'&&number[i]<='z')))
            {
                    k=1;
            }
        }
        if(k==1)
        {
            printf("\b          Wrong Input!Number does not contain special characters!");
            printf("   ");
            continue;
        }
        else
            break;
    }
    printf("\n");
    fprintf(fp,name);
    fprintf(fp,"\n");
    fprintf(fp,"Number#");
    fprintf(fp,number);
    fprintf(fp,"\n");
    char arr[40];
    strcpy(arr,currenttime());
    printf("                   Current time:%s",arr);
    fprintf(fp,"Time#");
    fprintf(fp,arr);
    fprintf(fp,"\n");
    fputs("Name#",fp);
    fclose(fp);
    printf("\n         Your Contact is Saved to memory successfully\n");

}

int UPDATE_IN_FILE()
{

    FILE *fp1, *fp2;
    char temp1[40];
    printf("Which Number Do you want to update:");
    int line=SEARCH_IN_FILE(),counter=1;
    fp1 = fopen("Contacts.txt","r");
    fp2 = fopen("replica.txt","w");
    char y[6]={'N','a','m','e','#','\0'};
    fgets(temp1,40,fp1);
    while(compare(y,temp1))
    {
        if(counter!=line)
        {
            fputs(temp1,fp2);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;

        }
        else
        {
            char name1[40],number[40];
            counter++;
            counter++;
            fgets(temp1,40,fp1);
            counter++;
            fgets(temp1,40,fp1);
            counter++;
            fgets(temp1,40,fp1);
            printf("                   Enter Contact Name:");
            scanf("%s",name1);

            ADD_IN_FILE();
        }
        fgets(temp1,40,fp1);
    }
    fprintf(fp2,temp1);
    fclose(fp2);
    fclose(fp1);

    fp1=fopen("Contacts.txt","w");
    fp2=fopen("replica.txt","r");

    char temp2[40];
    while(compare(temp2,y))
    {
        fgets(temp2,40,fp2);
        fprintf(fp1,temp2);

    }

    fclose(fp2);
    fclose(fp1);
    remove("replica.txt");
    if(ptr==0)
        printf("                Your Contact is successfully Updated\n");
    else
        printf("That's why we can't update your contact");
}
void DELETE_FROM_FILE()
{
    FILE *fp1, *fp2;
    char temp1[40];
    printf("Which Contact Do you want to Delete");
    int line=SEARCH_IN_FILE(),counter=1;
    printf("%d",line);
    fp1 = fopen("Contacts.txt","r");
    fp2 = fopen("replica.txt","w");
    char y[6]={'N','a','m','e','#','\0'};
    fgets(temp1,40,fp1);
    while(compare(y,temp1))
    {
        if(counter!=line)
        {
            fputs(temp1,fp2);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;
            fgets(temp1,40,fp1);
            fprintf(fp2,temp1);
            counter++;

        }
        else
        {
            char name[40],number[40];
            counter++;
            counter++;
            fgets(temp1,40,fp1);
            counter++;
            fgets(temp1,40,fp1);
            counter++;
            fgets(temp1,40,fp1);
        }
        fgets(temp1,40,fp1);
    }
    fprintf(fp2,temp1);
    fclose(fp2);
    fclose(fp1);

    fp1=fopen("Contacts.txt","w");
    fp2=fopen("replica.txt","r");

    char temp2[40];
    while(compare(temp2,y))
    {
        fgets(temp2,40,fp2);
        fprintf(fp1,temp2);
    }

    fclose(fp2);
    fclose(fp1);
    remove("replica.txt");
}
int SEARCH_IN_FILE()
{
    int line_number=0;
    FILE *fp;
    fp=fopen("Contacts.txt","r");
    if(fp!=NULL)
    {
        char search[40];
        printf("                   Search:");
        scanf("%s",search);
        char search1[40],a1[40],temp[40],temp1[40];
        if((search[0]>='A'&&search[0]<='Z')||(search[0]>='a'&&search[0]<='z')) //name serach
        {
            int i,c=0;
            search1[0]='N';
            search1[1]='a';
            search1[2]='m';
            search1[3]='e';
            search1[4]='#';
            int l=strlen(search);
            for(i=5;i<5+l;i++)
            {
                search1[i]=search[i-5];
            }
            search1[i]='\0';
            fgets(temp,40,fp); //name
            line_number++;
            while(1)
            {
                if(strstr(temp,search1))
                {
                    printf("                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("                   %s ",temp);
                    printf("                  %s ",fgets(a1,40,fp));
                    printf("                  %s ",fgets(a1,40,fp));
                    printf("                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    break;
                }
                else
                {
                    fgets(a1,40,fp);
                    line_number++;     //number
                    fgets(a1,40,fp);
                    line_number++;      //time
                    fgets(a1,40,fp);
                    line_number++;      //space
                }
                fgets(temp,40,fp);
                line_number++;       //name
                char str[5]="Name#";
                str[5]='\0';
                if(!compare(str,temp))
                {
                    ptr=1;
                    printf("                   Sorry!there is no such contact in our diary ");
                    break;
                }
            }
            return line_number;
        }
        else if(search[0]>='0'&&search[0]<='9') //number search
        {
            search1[0]='N';
            search1[1]='u';
            search1[2]='m';
            search1[3]='b';
            search1[4]='e';
            search1[5]='r';
            search1[6]='#';
            int len=strlen(search),j;
            for(j=7;j<7+len;j++)
            {
                search1[j]=search[j-7];
            }
            search1[j]='\0';
            fgets(a1,40,fp); //name
            line_number++;
            fgets(temp,40,fp); //number
            line_number++;
            while(1)
            {
                if(strstr(temp,search1))
                {
                    printf("                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    printf("                   %s",a1); //name
                    printf("                   %s",temp); //number
                    printf("                   %s",fgets(a1,40,fp)); //time
                    printf("                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                    line_number++;
                    break;
                }
                else
                {
                    fgets(a1,40,fp); //time
                    line_number++;
                    fgets(a1,40,fp); //space
                    line_number++;
                    fgets(a1,40,fp); //name
                    line_number++;
                    fgets(temp,40,fp); //number
                line_number++;
                }

                if(compare(temp,"Name#"))
                {
                    ptr=1;
                    printf("                   Sorry!there is no such contact in our diary ");
                    break;
                }
            }
            return (line_number-2);
        }
    }
    else
    {
        printf("File is Empty");
    }

    fclose(fp);
}
char *currenttime()
{
   time_t ltime;

   time(&ltime);
   char arr[40];
   strcpy(arr,ctime(&ltime));

   return arr;
}
int compare(char a[], char b[])
{
    int c = 0;
    while (a[c] == b[c])
    {
        if (a[c]=='\0'||b[c]=='\0')
        {
            break;
        }
        c++;
    }
    if ((a[c]=='\0' && b[c]=='\0'))
    {
          return 0;
    }

    else
    {
      return -1;
    }
}
int same(char search[])
{
    int pt=0;
    int line_number=0;
    FILE *fp;
    fp=fopen("Contacts.txt","r");
    if(fp!=NULL)
    {
        char search1[40],a1[40],temp[40],temp1[40];
        int i,c=0;
        search1[0]='N';
        search1[1]='a';
        search1[2]='m';
        search1[3]='e';
        search1[4]='#';
        int l=strlen(search);
        for(i=5;i<5+l;i++)
        {
            search1[i]=search[i-5];
        }
        search1[i]='\0';
        fgets(temp,40,fp); //name
        while(1)
        {
            if(strstr(temp,search1))
            {
                pt=1;
                break;
            }
            else
            {
                fgets(a1,40,fp);//number
                fgets(a1,40,fp);//time
                fgets(a1,40,fp);//space
            }
            fgets(temp,40,fp);//name
            char str[5]="Name#";
            str[5]='\0';
            if(!compare(str,temp))
            {
                break;
            }
        }
    }
    else
    {
        printf("File is Empty");
    }
    fclose(fp);
    return pt;
}

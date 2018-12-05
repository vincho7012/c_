#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


#define SIZE 10
#define CR '\r'
#define UP 72
#define DOWN 80

void print_arr(int *a);
void enter_arr(int *a);
void enter_arr_file(int *a);
void new_arr(int *a,int *b);
int digit_n(int *a);
void print_arr_file(int *a);
void menu();
char get_arrow(int *select,int options);
void print_menu(int *select);
void print_submenu(int *select,int menu);



int size;


int main(int argc, char const *argv[])
{
    menu();
    return 0;
}


void print_arr(int *a)
{
    int i = 0;

    for(i = 0;i < SIZE;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void print_arr_file(int *a)
{
    FILE *fp;
    int i,j = 0;
    char filename[100];

    printf("Enter file name:\n");
    scanf("%s", filename);

    fp = fopen(filename, "w+");

    for(i = 0; i < SIZE; i++)
    {
        if(j < 3)
        {
            fprintf((FILE *)fp, "%d ", a[i]);
            j++;
        }
        else if(j == 3)
        {
            fprintf((FILE *)fp, "%d\n", a[i]);
            j = 0;
        }
    }
    fclose(fp);

}

void min_number_row(int *a)
{
    int i, min = a[0], row = 1;

    for(i = 0;i < SIZE; i++)
    {
        if(min > a[i])
        {
            min = a[i];
            row = i/4 + 1;
        }
    }
    printf("row = %d\n", row);
}

void enter_arr(int *a)
{
    int i = 0,j,err;
    for(i = 0;i < SIZE;i++)
    {
        printf("Enter element %d:\n", i);
        do{
          char s[10];
          scanf("%s",s);
          err = 0;
          for(j = 1;j < strlen(s);j++)
          {
              if(s[j] < '0' || s[j] > '9')
              {
                  err = -1;
                  break;
              }
          }
          if( err == 0 && s[0] != '-' &&( s[0] < '0' || s[0] > '9'))
          {
            err = -1;
          }

          if(err == 0)
            a[i] = atoi(s);

        }while(err < 0);
    }
}

void enter_arr_file(int *a)
{
    FILE *fp;
    int i,j=0,c=1,number = 0;
    char filename[100];
    char buff[255];
    printf("Enter file name:\n");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    while(fgets(buff,255,(FILE *)fp) && j < SIZE)
    {
        for(i = 0; i < strlen(buff);i++)
        {
            if(buff[i] != '-' &&( buff[i] < '0' || buff[i] > '9'))
                continue;
            else
            {
                 if(buff[i] == '-')
                 {
                    c = -1;
                    i++;
                 }
                else
                    c = 1;

                while(buff[i] >= '0' && buff[i] <= '9')
                {
                    number = number * 10  +  (buff[i] - '0');
                    i++;
                }
                a[j] = number * c;
                number = 0;
                j++;

            }
        }
    }

    fclose(fp);





}


void new_arr(int *a,int *b)
{
    int i, j, min = a[0], index = 0;

    for(i = 0;i < SIZE;i++)
    {
        if(a[i] < min)
        {
            min = a[i];
            index = i;
        }
    }

    for(i = 0;i < index ; i++)
        b[i] = a[i];

    for(i = 0; i < index; i++)
        for(j = i+1; j < index; j++)
            if(b[i] > b[j])
            {
                int swap = b[i];
                b[i] = b[j];
                b[j] = swap;
            }
    size = index;

    for(i = 0; i < index; i++)
        printf("%d ",b[i]);
    printf("\n");
}

int digit_n(int *a)
{
    int digit,count = 0,i;
    char ch;

    printf("enter digit:\n");
    do {
        ch = getchar();
    }while(ch < '0' || ch > '9');

    digit = ch - '0';

    for(i = 0;i < size;i++)
    {
        int temp = a[i];
        if(temp < 0)
            temp = temp * -1;
        while(temp > 0)
        {
            if(temp % 10 == digit )
                count++;
            temp /= 10;
        }
    }
    printf("count = %d\n",count);
    return count;
}


void menu()
{

    int a[SIZE], b[SIZE];

    int select[2] = {1, 1};
        while(1)
        {
            print_menu(&select[0]);

           if(get_arrow(&select[0],3) == CR)
           {
                if(select[0] == 1)
                {
                    while(1)
                    {
                        print_submenu(&select[1],1);
                        if(get_arrow(&select[1],3) == CR)
                        {
                                system("cls");
                                if(select[1] == 1)
                                {
                                    enter_arr(a);

                                }
                                else if(select[1] == 2)
                                {
                                    enter_arr_file(a);

                                }
                                else
                                {
                                    select[1] = 1;
                                    break;
                                }
                                printf("Press any key to continue\n");
                                _getch();
                                break;
                        }
                    }
                }
                if(select[0] == 2)
                {
                    while(1)
                    {
                        print_submenu(&select[1],2);
                        if(get_arrow(&select[1],6) == CR)
                        {
                                system("cls");
                                if(select[1] == 1)
                                {
                                    print_arr(a);
                                }
                                else if(select[1] == 2)
                                {
                                    print_arr_file(a);
                                }
                                else if(select[1] == 3)
                                {
                                    new_arr(a,b);
                                }
                                else if(select[1] == 4)
                                {
                                    digit_n(b);
                                }
                               else if(select[1] == 5)
                                {
                                    min_number_row(a);
                                }
                                else
                                {
                                    select[1] = 1;
                                    break;
                                }
                               printf("Press any key to continue\n");
                                _getch();
                                break;
                        }
                    }


                }
                else if(select[0] == 3)
                    break;
           }

        }
}

char get_arrow(int *select,int options)
{

    int ch = _getch ();
    if (ch == 0 || ch == 224)
    {
        switch (_getch ())
        {
            case UP:
                if(*select > 1)
                    (*select) -= 1;
                return 1;
                break;

            case DOWN:
                 if(*select < options)
                    (*select) += 1;
                return 1;
                break;

        }
    }
    else
        return ch;
    return 0;

}

void print_menu(int *select)
{
    int i;
    system("cls");

    char s[] = "Select option:\r\n  Enter array\r\n  Array options\r\n  Exit\r\n";
    int count = 0;

    for(i = 0;i < strlen(s) ;i++)
    {
        if(s[i] == '\n')
            count++;
        if(count == *select)
        {
            s[i+1] = '*';
            break;
        }
     }


    puts(s);
}

void print_submenu(int *select,int menu)
{
        int i;
    system("cls");

    char s[100];

    if(menu == 1)
        strcpy(s,"Read from:\r\n  stdin\r\n  file\r\n  Exit\r\n");
    else
        strcpy(s,"Array options:\r\n  print_arr\r\n  write_arr_file\r\n  new_arr\r\n  digits\r\n  row_min\r\n  Exit\r\n");
    int count = 0;

    for(i = 0;i < strlen(s) ;i++)
    {
        if(s[i] == '\n')
            count++;
        if(count == *select)
        {
            s[i+1] = '*';
            break;
        }
     }

    puts(s);
}


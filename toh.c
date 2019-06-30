/*
    Tower of Hanoi C Implementation
    Author: Mohammad Yasin Ud Dowla
    @yasinuddowla    
*/




#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y)
{

    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
char peg_disks[][10];
char disks[20][20];
char solve_string[10];
int moves=0,errors=0;
main()
{
    int no_disk;
    int i,j,k,l,m,n;
    system("title Tower Of Hanoi");
    system("color 2f");
    gotoxy(20,10);
    printf("Enter number of disks : ");
    scanf("%d",&no_disk);
    if(no_disk>8||no_disk<2)
    {
        system("cls");
        gotoxy(20,10);
        printf("Number of disks should be in between 2 and 8");
        getch();
        exit(0);
    }
    initiate_peg_disks(no_disk);
    while(1)
    {
        if(strlen(peg_disks[2])==no_disk)
        {
            system("cls");
            gotoxy(30,15);
            printf("You WON!");
            gotoxy(30,17);
            printf("Moves: %d",moves);
            gotoxy(30,18);
            printf("Errors: %d",errors);

            getch();
            break;
        }
        system("cls");
        print_pegs();
        print_disks();
        show_error_move();
        get_choice();
    }
    getch();
}
void show_error_move(void)
{
    gotoxy(10,2);
    printf("Moves: %d",moves);
    gotoxy(60,2);
    printf("Errors: %d",errors);
}
void get_choice(void)
{
    draw_border(4,1,2,70,'|','|','-','-');
    draw_border(4,4,15,70,'|','|',22,22);
    gotoxy(15,19);
    printf("To move use shortcuts...");
    gotoxy(5,21);
    printf("A to B --> 1");
    gotoxy(5,22);
    printf("A to C --> 2");
    gotoxy(5,23);
    printf("B to A --> 3");
    gotoxy(20,21);
    printf("B to C --> 4");
    gotoxy(20,22);
    printf("C to A --> 5");
    gotoxy(20,23);
    printf("C to B --> 6");
    gotoxy(40,22);
    printf("Your move is : ");
    char ch;
    ch=getch();
    moves++;
    if(ch=='1')
        move_disk(0,1);
    else if(ch=='2')
        move_disk(0,2);
    else if(ch=='3')
        move_disk(1,0);
    else if(ch=='4')
        move_disk(1,2);
    else if(ch=='5')
        move_disk(2,0);
    else if(ch=='6')
        move_disk(2,1);
    else if(ch==27)
    {
        system("cls");
        exit(0);
    }
    else
    {
        printf("\a");
    }
}
void move_disk(int from,int to)
{

    int last_char_from_peg=peg_disks[from][strlen(peg_disks[from])-1]-48;
    int last_char_to_peg=peg_disks[to][strlen(peg_disks[to])-1]-48;
    if(strlen(peg_disks[to])==0||last_char_to_peg<last_char_from_peg)
    {
        peg_disks[from][strlen(peg_disks[from])-1]='\0';
        peg_disks[to][strlen(peg_disks[to])]=last_char_from_peg+48;
        peg_disks[to][strlen(peg_disks[to])+1]='\0';
    }
    else
    {
        putchar('\a');
        errors++;
    }
}
void initiate_peg_disks(int n)
{
    int disk_char[]={174,176,240,219,247,15,175,254};
    int i,j,m,k=0;
    for(i=0;i<n;i++)
    {
        m=19-(i+1)*2;
        peg_disks[0][i]=49+i;
        for(j=0;j<m;j++)
        {
            disks[i][j]=176;
        }
        disks[i][1]=n-i+48;
        disks[i][m]='\0';
        k++;
    }
    peg_disks[0][n]='\0';
    strcpy(solve_string,peg_disks[0]);

}
void print_disks(void)
{
    int i,j,k,l,m,n;
    int x,y;
    int peg_char;
    for(k=0;k<3;k++)
    {
        y=14;
        n=strlen(peg_disks[k]);
        for(i=0;i<n;i++)
        {
            m=peg_disks[k][i]-48;
            x=5*(k*5+1)+m;
            gotoxy(x,y);
            peg_char=peg_disks[k][i]-48;
            printf("%s",disks[peg_char-1]);
            y--;
        }
    }
}
void print_pegs(void)
{
    int i,j,k,l,m,n;
    int num_hr_eqs=19,num_vr_ors=10-1,y_hr_rod=15,x_vr_rod=14;
    char hr_rod_char=219;
    char vr_rod_char=219;
    ///printing the horizontal rod
    gotoxy(5,y_hr_rod);
    for(i=1;i<=num_hr_eqs;i++)
        printf("%c",hr_rod_char);
    gotoxy(30,y_hr_rod);
    for(i=1;i<=num_hr_eqs;i++)
        printf("%c",hr_rod_char);
    gotoxy(55,y_hr_rod);
    for(i=1;i<=num_hr_eqs;i++)
        printf("%c",hr_rod_char);

    ///printing the vertical rod
    for(i=1;i<=num_vr_ors;i++)
    {
        gotoxy(x_vr_rod,5+i);
        printf("%c",vr_rod_char);
    }
    for(i=1;i<=num_vr_ors;i++)
    {
        gotoxy(30+10-1,5+i);
        printf("%c",vr_rod_char);
    }
    for(i=1;i<=num_vr_ors;i++)
    {
        gotoxy(55+10-1,5+i);
        printf("%c",vr_rod_char);
    }
    gotoxy(5+6,17);
    printf("PILLAR-A");
    gotoxy(30+6,17);
    printf("PILLAR-B");
    gotoxy(55+6,17);
    printf("PILLAR-C");
}
void draw_border(int x,int y,int h,int w,char lt,char rt,char ur,char lr)
{
    if(h>20||w>70||h<1||w<1)
    {
        system("cls");
        gotoxy(20,5);
        printf("Can Not Draw Such Border.");
        gotoxy(20,7);
        system("cls");
        return;
    }
    int i,j,k,l;
    int x_min=x;
    int x_max=x+w;
    int y_min=y;
    int y_max=y+h;
    for(i=y_min; i<=y_max; i++)     ///drawing left bar
    {
        gotoxy(x_min,i);
        printf("%c",lt);
    }
    for(i=y_min; i<=y_max; i++)     ///drawing right bar
    {
        gotoxy(x_max,i);
        printf("%c",rt);
    }
    for(i=x_min; i<=x_max; i++)     ///drawing Upper bar
    {
        gotoxy(i,y_min);
        printf("%c",ur);
    }
    for(i=x_min; i<=x_max; i++)     ///drawing Lower bar
    {
        gotoxy(i,y_max);
        printf("%c",lr);
    }
}

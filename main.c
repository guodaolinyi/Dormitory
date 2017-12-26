#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 100

//定义一个存储学生相关信息的结构体
typedef struct
{
    char S_name[31];   //学生姓名
    char S_class[31];  //学生班级
    char S_number[16]; //学生学号
    int D_number;      //学生所在寝室的宿舍号
    char S_phone[20];  //学生电话号码
    int Total;         //学生总数
}Student[M],St;

//判断学号是否与表中所存学号重复
void S_number_Judge(Student S,int t)
{
    int i;
    for(i=1;i<=(S->Total)-1;i++)
        while(strcmp(S[i].S_number,S[t].S_number)==0)
        {
            printf("学号输入失败,该学号已存在,请重新输入学号!\n");
            printf("请输入学生的学号(15个字符以内):");
            scanf("%s",S[t].S_number);
            getchar();
        }
}
//添加学生信息函数
void Add(Student S)
{
    printf("请输入学生姓名(30个字符以内):");
    scanf("%s",&S[++(S->Total)].S_name);
    getchar();//获取换行符
    printf("请输入学生班级(30个字符以内):");
    scanf("%s",&S[S->Total].S_class);
    getchar();
    printf("请输入学生的学号(15个字符以内):");
    scanf("%s",&S[S->Total].S_number);
    getchar();
    S_number_Judge(S,S->Total);//判断输入的学号是否与表中所存在的学号重复
    printf("请输入宿舍号码:");
    scanf("%d",&S[S->Total].D_number);
    getchar();
    printf("请输入学生电话号码:");
    scanf("%s",&S[S->Total]. S_phone);
    getchar();
    //dirty=1;
    printf("添加成功!\n\n");
}

//修改学生信息函数
void Alter(Student S)
{
    int i;
    int flag=0; //用来判断表中是否存在所要修改的学生的信息
    char name[20];
    printf("请输入你要修改学生的姓名:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("你所要修改的学生信息在表中不存在！\n");
    else
    {
        printf("新信息如下:\n");
        printf("请输入学生姓名(30个字符以内):");
        scanf("%s",S[flag].S_name);
        getchar();
        printf("请输入学生班级(30个字符以内):");
        scanf("%s",S[flag].S_class);
        getchar();

        printf("请输入学生的学号(15个字符以内):");
        scanf("%s",S[flag].S_number);
        getchar();
        S_number_Judge(S,flag);
        printf("请输入宿舍号:");
        scanf("%d",&S[flag].D_number);
        getchar();
        printf("请输入学生电话号码:");
        scanf("%s",&S[flag]. S_phone);
        getchar();
        //dirty=1;
        printf("修改成功!\n");
    }
    putchar('\n');
}

//删除学生信息
void Delete(Student S)
{
    int i,j;
    int flag=0;  //用来判断表中是否存在所要删除的学生的信息
    char name[20];
    printf("请输入你要删除学生的姓名:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("你所要删除的学生在表中不存在！");
    else
    {
        for(i=flag;i<S->Total;i++)
        {
            j=i+1;
            strcpy(S[i].S_name,S[j].S_name);
            strcpy(S[i].S_number,S[j].S_number);
            S[i].D_number=S[j].D_number;
        }
        (S->Total)--;
        //dirty=1;
        printf("删除成功!");
    }
    printf("\n\n");
}
//显示所有学生信息函数
void Display_All(Student S)
{
    int i;
    printf("全体学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for(i=1;i<=S->Total;i++)
        printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name,S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);

}

//排序函数按照寝室号从小到大排序(冒泡法)
void Sort_D_number(Student S)
{
    int i,j,t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for(i=1;i<=S->Total;i++)
        for(j=i;j<=S->Total;j++)
            if(S[i].D_number>S[j].D_number)
            {
                strcpy(name,S[i].S_name);
                strcpy(number,S[i].S_number);
                strcpy(Cnumber,S[i].S_class);
                t=S[i].D_number;
                strcpy(S[i].S_name,S[j].S_name);
                strcpy(S[i].S_number,S[j].S_number);
                strcpy(S[i].S_class,S[j].S_class);
                S[i].D_number=S[j].D_number;
                strcpy(S[j].S_name,name);
                strcpy(S[j].S_number,number);
                strcpy(S[j].S_class,Cnumber);
                S[j].D_number=t;
            }
}

//排序函数按照学号从小到大排序(冒泡法)
void Sort_S_number(Student S)
{
    int i,j,t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for(i=1;i<=S->Total;i++)
        for(j=i;j<=S->Total;j++)
            if(strcmp(S[i].S_number,S[j].S_number)>0)
            {
                strcpy(name,S[i].S_name);
                strcpy(number,S[i].S_number);
                strcpy(Cnumber,S[i].S_class);
                t=S[i].D_number;
                strcpy(S[i].S_name,S[j].S_name);
                strcpy(S[i].S_number,S[j].S_number);
                strcpy(S[i].S_class,S[j].S_class);
                S[i].D_number=S[j].D_number;
                strcpy(S[j].S_name,name);
                strcpy(S[j].S_number,number);
                strcpy(S[j].S_class,Cnumber);
                S[j].D_number=t;
            }
}

//排序函数按照班级号从小到大排序(冒泡法)
void Sort_S_class (Student S)
{
    int i,j,t;
    char name[30];
    char number[15];
    char  Cnumber[30];
    for(i=1;i<=S->Total;i++)
        for(j=i;j<=S->Total;j++)
            if(strcmp(S[i].S_class,S[j].S_class)>0)
            {
                strcpy(name,S[i].S_name);
                strcpy(number,S[i].S_number);
                strcpy(Cnumber,S[i].S_class);
                t=S[i]. D_number;
                strcpy(S[i].S_name,S[j].S_name);
                strcpy(S[i].S_number,S[j].S_number);
                strcpy(S[i].S_class,S[j].S_class);
                S[i]. D_number =S[j]. D_number;
                strcpy(S[j].S_name,name);
                strcpy(S[j].S_number,number);
                strcpy(S[j].S_class,Cnumber);
                S[j]. D_number =t;
            }
}

//查询函数以班级为关键字进行查询(顺序查找)
void Query_S_class(Student S)
{
    int i,j=0;
    char classnumber[31];
    printf("请输入你要查找的班级号(30个字符以内):");
    scanf("%s",classnumber);
    getchar();
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for(i=1;i<=S->Total;i++)
        if(strcmp(classnumber,S[i].S_class)==0)
        {
            printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name, S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
            j=1;
        }
    if(!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}


//查询函数以姓名为关键字进行查询(顺序查找)
void Query_S_name(Student S)
{
    int i,j=0;
    char name[31];
    printf("请输入你要查找的学生的姓名(30个字符以内):");
    scanf("%s",name);
    getchar();
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for(i=1;i<=S->Total;i++)
        if(strcmp(name,S[i].S_name)==0)
        {
            printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name, S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
            j=1;
        }
    if(!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}

//查询函数以学号为关键字进行查询(折半查找)
void Query_S_number(Student S)
{
    int i,j,top,base,mid;
    char number[15];
    j=0;
    base=1;
    top=S->Total;
    printf("请输入你要查找学生的学号:");
    scanf("%s",number);

    Sort_S_number(S);  //将表中原数据按照学号从小到大排序
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    if(strcmp(number,S[1].S_number)>=0&&strcmp(number,S[S->Total].S_number)>=0)
    {
        while(base<=top)
        {
            mid=(base+top)/2;
            if(strcmp(number,S[mid].S_number)==0)
            {
                printf("%-19s%-12s %-14s%-13d%s\n",S[mid].S_name, S[mid].S_class,S[mid].S_number,S[mid].D_number,S[mid].S_phone);
                putchar('\n');
                j=1;
                break;
            }
            else if(strcmp(number,S[mid].S_number)>0)
                base=mid+1;
            else
                top=mid-1;
        }
    }
    if(!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}

//查询函数以寝室号为关键字进行查询(折半查找)
void Query_D_number(Student S)
{
    int i,j,m,n,base,top,mid;
    j=0;
    base=1;
    top=S->Total;
    printf("请输入你要查询的寝室号:");
    scanf("%d",&i);
    getchar();
    Sort_D_number(S);//将表中原数据按照寝室号从小到大排序
    printf("所查找寝室信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    if(i>=S[1].D_number&&i<=S[S->Total].D_number)
    {
        while(base<=top)
        {
            mid=(base+top)/2;
            if(i==S[mid].D_number)
            {
                m=mid;
                n=mid-1;
                while(S[m].D_number==i)
                {
                    printf("%-19s%-12s %-14s%-13d%s\n",S[mid].S_name, S[mid].S_class,S[mid].S_number,S[mid].D_number,S[mid].S_phone);
                    m++;
                    if(m>S->Total)
                        break;
                }
                if(n>0)
                {
                    while(S[n].D_number==i)
                    {
                        printf("%-15s%-15s%-15d\n",S[n].S_name,S[n].S_number,S[n].D_number);
                        n--;
                        if(n<1)
                            break;
                    }
                }
                j=1;
                putchar('\n');
                break;
            }
            else if(i>S[mid].D_number)
                base=mid+1;
            else
                top=mid-1;
        }
    }
    if(!j)
        printf("\n查找失败,表中不存在该寝室的信息!\n\n");
}

//菜单
void Menu()
{
    //菜单
    printf("                                 宿舍管理系统\n\n");
    printf("*************************************菜单***************************************\n");
    printf(" 1.添加学生信息                       |   6.以宿舍号查询该寝室中的全部学生信息\n");
    printf(" 2.修改学生信息                       |   7.以班级号查询该班级中的全部学生信息\n");
    printf(" 3.删除学生信息                       |   8.显示所有学生的相关信息\n");
    printf(" 4.以姓名查询学生信息                 |   9.退出程序\n");
    printf(" 5.以学号查询学生信息                 |  \n");
    printf("********************************************************************************\n");

}

int main(void)
{
    int i;
    Student S;
    S->Total=0;
    do
    {
        Menu();
        printf("请选择所要实现的功能(请输入1~10中的任意一个数字):");
        scanf("%d",&i);
        getchar();  //获取换行符
        putchar('\n');
        switch(i)
        {
            case 1:Add(S);
                break;
            case 2:Alter(S);
                break;
            case 3:Delete(S);
                break;
            case 4:Query_S_name(S);
                break;
            case 5:Query_S_number(S);
                break;
            case 6:Query_D_number(S);
                break;
            case 7: Query_S_class (S);
                break;
            case 8:Display_All(S);
                break;
                /*
            case 9:Save(S);
                break;
            case 10:Judge_Save(dirty,S);
                 */
                //exit(0);
                //break;
            case 9:exit(0);
            default:printf("选择错误:请在选项到之间选择!\n\n");
                break;
        }
    }while(i!=14);
    return 0;
}


//学号3位： 19、12、14、13
//学号12位；19、8、18、13
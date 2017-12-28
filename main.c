#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"windows.h"
#include"preset.h"
#include"function.h"
int main(void) {
    int i;
    Student S;
    S->Total = 0;
	system("color 03");//调节控制台的背景和字体颜色
	Initialize(S);
    loading("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1欢迎使用宿舍管理系统\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");
    do {
        Menu();
        printf("请选择所要实现的功能(请输入1~9的任意一个数字):");
        scanf("%d", &i);
        getchar();  //获取换行符
        putchar('\n');
        switch (i) {
            case 1:
                Add(S);
                break;
            case 2:
                Alter(S);
                break;
            case 3:
                Delete(S);
                break;
            case 4:
                Query_S_name(S);
                break;
            case 5:
                Query_S_number(S);
                break;
            case 6:
                Query_D_number(S);
                break;
            case 7:
                Query_S_class(S);
                break;
            case 8:
                Display_All(S);
                break;
            case 9:
				char choice;
				printf("表中数据已改变，是否保存后再退出(Y/N)?:");
				choice=getchar();
				getchar();
				while(choice!='n'&&ch!='N'&&ch!='y'&&ch!='Y')
				{
					printf("请输入N(n)或者Y(y):");
					choice=getchar();
					getchar();
				}
				if(choice=='y'||choice=='Y')
					Exit_Save(S);
                exit(0);
            default:
                printf("选择错误:请在选项到之间选择!\n\n");
                break;
        }
    } while (i != 9);
    return 0;
}
//菜单
void Menu() {
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
//添加学生信息函数
void Add(Student S) {
    printf("请输入学生姓名:");
    scanf("%s", &S[++(S->Total)].S_name);
    getchar();//获取换行符
    printf("请输入学生班级:");
    scanf("%s", &S[S->Total].S_class);
    getchar();
    printf("请输入学生的学号:");
    scanf("%s", &S[S->Total].S_number);
    getchar();
    S_number_Judge(S, S->Total);//判断输入的学号是否与表中所存在的学号重复
    printf("请输入宿舍号码:");
    scanf("%d", &S[S->Total].D_number);
    getchar();
    printf("请输入学生电话号码:");
    scanf("%s", &S[S->Total].S_phone);
    getchar();
    printf("添加成功!\n\n");
}
//修改学生信息函数
void Alter(Student S) {
    int i;
    int flag = 0; //用来判断表中是否存在所要修改的学生的信息
    char name[20];
    printf("请输入你要修改学生的姓名:");
    scanf("%s", name);
    getchar();
    for (i = 1; i <= S->Total; i++)
        if (strcmp(S[i].S_name, name) == 0)
            flag = i;
    if (!flag)
        printf("你所要修改的学生信息在表中不存在！\n");
    else {
        Alter_Sub_Menu(S, flag);
    }
    putchar('\n');
}
void Alter_Sub_Menu(Student S, int flag) {
    int i;
    printf("请选择要修改的项目!\n\n");
    printf("1.修改班级              2.修改宿舍号\n");
    printf("3.修改电话号码          0.取消修改\n\n");
    scanf("%d", &i);
    switch (i) {
        case 1:
            printf("请输入新班级!\n");
            scanf("%s", S[flag].S_class);
            getchar();
            S_number_Judge(S, flag);
            printf("修改成功!\n");
            break;
        case 2:
            printf("请输入新宿舍号!\n");
            scanf("%d", &S[flag].D_number);
            getchar();
            printf("修改成功!\n");
            break;
        case 3:
            printf("请输入新手机号!\n");
            scanf("%s", &S[flag].S_phone);
            getchar();
            printf("修改成功!\n");
            break;
        case 0:
            break;
        default:
            printf("选择错误:请在选项到之间选择!\n\n");
            break;
    }
}
//删除学生信息
void Delete(Student S) {
    int i, j;
    int flag = 0;  //用来判断表中是否存在所要删除的学生的信息
    char name[20];
    printf("请输入你要删除学生的姓名:");
    scanf("%s", name);
    getchar();
    for (i = 1; i <= S->Total; i++)
        if (strcmp(S[i].S_name, name) == 0)
            flag = i;
    if (!flag)
        printf("你所要删除的学生在表中不存在！");
    else {
        for (i = flag; i < S->Total; i++) {
            j = i + 1;
            strcpy(S[i].S_name, S[j].S_name);
            strcpy(S[i].S_number, S[j].S_number);
            S[i].D_number = S[j].D_number;
        }
        (S->Total)--;
        printf("删除成功!");
    }
    printf("\n\n");
}
//显示所有学生信息函数
void Display_All(Student S) {
    int i;
    printf("全体学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for (i = 1; i <= S->Total; i++)
        printf("%-19s%-12s %-14s%-13d%s\n", S[i].S_name, S[i].S_class, S[i].S_number, S[i].D_number, S[i].S_phone);
}
//退出子菜单
void Exit_Sub_Menu(Student S)
{	

}
//存储函数
void Exit_Save(Student S)
{
	St Std;
	int i;
	int flag1=0,flag2=0; //判断存储是否成功
	FILE *fp;
    if((fp=fopen("data","w+"))==NULL)
    {
        printf("加载数据失败!\n\n");
        flag1=1;
        exit(0);  //结束程序
	}
	for(i=1;i<=S->Total;i++)
        if(fwrite(&S[i],sizeof(Std),1,fp)!=1)
        {
            printf("数据保存出错!\n\n");
            flag2=1;
			exit(0);
        }
    if(!flag1&&!flag2)
	{
        printf("数据存储成功,按任意键退出!\n\n");
	}
    fclose(fp);
}
//初始化加载记录函数
void Initialize(Student S)
{
	St Std;
	FILE *fp = NULL;
	if((fp=fopen("data","r"))==NULL)
	{
		printf("打开文件失败!\n\n");
		exit(0);
	}
	while(!feof(fp))
		fread(&S[++(S->Total)],sizeof(Std),1,fp);
	fclose(fp);
	loading("loading...");
    printf("加载数据成功！\n\n");
    (S->Total)--;   //由于读取问题，表中个数要减去
}
//加载动画
void loading(char *p)              //延时函数的定义
{
    while (1) {
        if (*p != 0)
            printf("%c", *p++);
        else
            break;
        Sleep(100);               //延时控制间断语句
    }
}
//查询函数以寝室号为关键字进行查询(折半查找)
void Query_D_number(Student S) {
    int i, j, base, top, mid;
    j = 0;
    base = 1;
    top = S->Total;
    printf("请输入你要查询的寝室号:");
    scanf("%d", &i);
    getchar();
    Sort_D_number(S);//将表中原数据按照寝室号从小到大排序
    printf("所查找寝室信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    if (i >= S[1].D_number && i <= S[S->Total].D_number) {
        while (base <= top) {
            mid = (base + top) / 2;
            if (i == S[mid].D_number) {
                printf("%-19s%-12s %-14s%-13d%s\n", S[mid].S_name, S[mid].S_class, S[mid].S_number, S[mid].D_number,
                       S[mid].S_phone);
                j = 1;
                putchar('\n');
                break;
            } else if (i > S[mid].D_number)
                base = mid + 1;
            else
                top = mid - 1;
        }
    }
    if (!j)
        printf("\n查找失败,表中不存在该寝室的信息!\n\n");
}
//查询函数以班级为关键字进行查询(顺序查找)
void Query_S_class(Student S) {
    int i, j = 0;
    char classnumber[31];
    printf("请输入你要查找的班级号:");
    scanf("%s", classnumber);
    getchar();
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for (i = 1; i <= S->Total; i++)
        if (strcmp(classnumber, S[i].S_class) == 0) {
            printf("%-19s%-12s %-14s%-13d%s\n", S[i].S_name, S[i].S_class, S[i].S_number, S[i].D_number, S[i].S_phone);
            j = 1;
        }
    if (!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}
//查询函数以姓名为关键字进行查询(折半查找)
void Query_S_name(Student S) {
    int j = 0, top, base, mid;
    char name[31];
    base = 1;
    top = S->Total;
    printf("请输入你要查找的学生的姓名:");
    scanf("%s", name);
    getchar();
    Sort_S_name(S);//将表中原数据按照姓名从小到大排序
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    if (strcmp(name, S[1].S_name) >= 0 && strcmp(name, S[S->Total].S_name) <= 0) {
        while (base <= top) {
            mid = (base + top) / 2;
            if (strcmp(name, S[mid].S_name) == 0) {
                printf("%-19s%-12s %-14s%-13d%s\n", S[mid].S_name, S[mid].S_class, S[mid].S_number, S[mid].D_number,
                       S[mid].S_phone);
                putchar('\n');
                j = 1;
                break;
            } else if (strcmp(name, S[mid].S_name) > 0)
                base = mid + 1;
            else
                top = mid - 1;
        }
    }
    if (!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}
//查询函数以学号为关键字进行查询(折半查找)
void Query_S_number(Student S) {
    int j, top, base, mid;
    char number[15];
    j = 0;
    base = 1;
    top = S->Total;
    printf("请输入你要查找学生的学号:");
    scanf("%s", number);
    Sort_S_number(S);  //将表中原数据按照学号从小到大排序
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    if (strcmp(number, S[1].S_number) >= 0 && strcmp(number, S[S->Total].S_number) <= 0) {
        while (base <= top) {
            mid = (base + top) / 2;
            if (strcmp(number, S[mid].S_number) == 0) {
                printf("%-19s%-12s %-14s%-13d%s\n", S[mid].S_name, S[mid].S_class, S[mid].S_number, S[mid].D_number,
                       S[mid].S_phone);
                putchar('\n');
                j = 1;
                break;
            } else if (strcmp(number, S[mid].S_number) > 0)
                base = mid + 1;
            else
                top = mid - 1;
        }
    }
    if (!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}
//判断学号是否与表中所存学号重复
void S_number_Judge(Student S, int t) {
    int i;
    for (i = 1; i <= (S->Total) - 1; i++)
        while (strcmp(S[i].S_number, S[t].S_number) == 0) {
            printf("学号输入失败,该学号已存在,请重新输入学号!\n");
            printf("请输入学生的学号:");
            scanf("%s", S[t].S_number);
            getchar();
            i = 0;//i 置为0 判断从头开始
        }
}
//排序函数按照寝室号从小到大排序(冒泡法)
void Sort_D_number(Student S) {
    int i, j, t;
    char name[30];
    char number[15];
    char Cnumber[30];//Cnumber 班别
    for (i = 1; i <= S->Total; i++)
        for (j = i; j <= S->Total; j++)
            if (S[i].D_number > S[j].D_number) {
                strcpy(name, S[i].S_name);
                strcpy(number, S[i].S_number);
                strcpy(Cnumber, S[i].S_class);
                t = S[i].D_number;
                strcpy(S[i].S_name, S[j].S_name);
                strcpy(S[i].S_number, S[j].S_number);
                strcpy(S[i].S_class, S[j].S_class);
                S[i].D_number = S[j].D_number;
                strcpy(S[j].S_name, name);
                strcpy(S[j].S_number, number);
                strcpy(S[j].S_class, Cnumber);
                S[j].D_number = t;
            }
}
//排序函数按照班级号从小到大排序(冒泡法)
void Sort_S_class(Student S) {
    int i, j, t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for (i = 1; i <= S->Total; i++)
        for (j = i; j <= S->Total; j++)
            if (strcmp(S[i].S_class, S[j].S_class) > 0) {
                strcpy(name, S[i].S_name);
                strcpy(number, S[i].S_number);
                strcpy(Cnumber, S[i].S_class);
                t = S[i].D_number;
                strcpy(S[i].S_name, S[j].S_name);
                strcpy(S[i].S_number, S[j].S_number);
                strcpy(S[i].S_class, S[j].S_class);
                S[i].D_number = S[j].D_number;
                strcpy(S[j].S_name, name);
                strcpy(S[j].S_number, number);
                strcpy(S[j].S_class, Cnumber);
                S[j].D_number = t;
            }
}
//排序函数按照名字从小到大排序(冒泡法)
void Sort_S_name(Student S) {
    int i, j, t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for (i = 1; i <= S->Total; i++)
        for (j = i; j <= S->Total; j++)
            if (strcmp(S[i].S_name, S[j].S_name) > 0) {
                strcpy(name, S[i].S_name);
                strcpy(number, S[i].S_number);
                strcpy(Cnumber, S[i].S_class);
                t = S[i].D_number;
                strcpy(S[i].S_name, S[j].S_name);
                strcpy(S[i].S_number, S[j].S_number);
                strcpy(S[i].S_class, S[j].S_class);
                S[i].D_number = S[j].D_number;
                strcpy(S[j].S_name, name);
                strcpy(S[j].S_number, number);
                strcpy(S[j].S_class, Cnumber);
                S[j].D_number = t;
            }
}
//排序函数按照学号从小到大排序(冒泡法)
void Sort_S_number(Student S) {
    int i, j, t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for (i = 1; i <= S->Total; i++)
        for (j = i; j <= S->Total; j++)
            if (strcmp(S[i].S_number, S[j].S_number) > 0) {
                strcpy(name, S[i].S_name);
                strcpy(number, S[i].S_number);
                strcpy(Cnumber, S[i].S_class);
                t = S[i].D_number;
                strcpy(S[i].S_name, S[j].S_name);
                strcpy(S[i].S_number, S[j].S_number);
                strcpy(S[i].S_class, S[j].S_class);
                S[i].D_number = S[j].D_number;
                strcpy(S[j].S_name, name);
                strcpy(S[j].S_number, number);
                strcpy(S[j].S_class, Cnumber);
                S[j].D_number = t;
            }
}
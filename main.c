#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h" 
#include"windows.h"
#include"preset.h"
#include"function.h"
#include"add.c"
#include"alter.c"
#include"delete.c"
#include"display_all.c"
#include"menu.c"
#include"plug.c"
#include"query_d_number.c"
#include"query_s_class.c"
#include"query_s_name.c"
#include"query_s_number.c"
#include"sort_d_number.c"
#include"sort_s_class.c"
#include"sort_s_number.c"
int main(void){
    int i,sum;
    Student S;
    S->Total=0;
    system("color 03");      //调节控制台的背景和字体颜色   
    sum=0;  
    loading("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1欢迎使用宿舍管理系统\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");  
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
            case 9:exit(0);
            default:printf("选择错误:请在选项到之间选择!\n\n");
                break;
        }
    }while(i!=14);
    return 0;
}
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
            i=0;//i 置为0 判断从头开始
        }
}
//学号3位： 19、12、14、13
//学号12位；19、8、18、13
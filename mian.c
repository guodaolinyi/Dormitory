#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h" 
#include"windows.h"
#include"preset.h"
#include"function.h"
#include"add.c"
#include"add.c"
int main(void){
    int i,sum;
    Student S;
    S->Total=0;
    system("color 03");      //���ڿ���̨�ı�����������ɫ   
    sum=0;  
    loading("\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1��ӭʹ���������ϵͳ\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");  
    do
    {
        Menu();
        printf("��ѡ����Ҫʵ�ֵĹ���(������1~10�е�����һ������):");
        scanf("%d",&i);
        getchar();  //��ȡ���з�
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
            default:printf("ѡ�����:����ѡ�֮��ѡ��!\n\n");
                break;
        }
    }while(i!=14);
    return 0;
}
//�ж�ѧ���Ƿ����������ѧ���ظ�
void S_number_Judge(Student S,int t)
{
    int i;
    for(i=1;i<=(S->Total)-1;i++)
        while(strcmp(S[i].S_number,S[t].S_number)==0)
        {
            printf("ѧ������ʧ��,��ѧ���Ѵ���,����������ѧ��!\n");
            printf("������ѧ����ѧ��(15���ַ�����):");
            scanf("%s",S[t].S_number);
            getchar();
            i=0;//i ��Ϊ0 �жϴ�ͷ��ʼ
        }
}
//ѧ��3λ�� 19��12��14��13
//ѧ��12λ��19��8��18��13
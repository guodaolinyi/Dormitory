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
	system("color 03");//���ڿ���̨�ı�����������ɫ
	Initialize(S);
    system("cls");
    loading("\n\n\n\t\t\1\1\1\1\1\1\1\1\1\1\1\1\1��ӭʹ���������ϵͳ\1\1\1\1\1\1\1\1\1\1\1\1\1\n\n\n");
    do {
        Menu();
        printf("��ѡ����Ҫʵ�ֵĹ���(������1~9������һ������):");
        scanf("%d", &i);
        getchar();  //��ȡ���з�
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
				Exit_Sub_Menu(S);
                exit(0);
            default:
                printf("ѡ�����:����ѡ�֮��ѡ��!\n\n");
                break;
        }
    } while (i != 9);
    return 0;
}
//�˵�
void Menu() {
    //�˵�
    printf("                                 �������ϵͳ\n\n");
    printf("***********************************���ܲ˵�*************************************\n");
    printf(" 1.���ѧ����Ϣ                       |   6.������Ų�ѯ�������е�ȫ��ѧ����Ϣ\n");
    printf(" 2.�޸�ѧ����Ϣ                       |   7.�԰༶�Ų�ѯ�ð༶�е�ȫ��ѧ����Ϣ\n");
    printf(" 3.ɾ��ѧ����Ϣ                       |   8.��ʾ����ѧ���������Ϣ\n");
    printf(" 4.��������ѯѧ����Ϣ                 |   9.�˳�����\n");
    printf(" 5.��ѧ�Ų�ѯѧ����Ϣ                 |  \n");
    printf("********************************************************************************\n");
}
//���ѧ����Ϣ����
void Add(Student S) {
    printf("������ѧ������:");
    scanf("%s", &S[++(S->Total)].S_name);
    getchar();//��ȡ���з�
    printf("������ѧ���༶:");
    scanf("%s", &S[S->Total].S_class);
    getchar();
    printf("������ѧ����ѧ��:");
    scanf("%s", &S[S->Total].S_number);
    getchar();
    S_number_Judge(S, S->Total);//�ж������ѧ���Ƿ�����������ڵ�ѧ���ظ�
    printf("�������������:");
    scanf("%d", &S[S->Total].D_number);
    getchar();
    printf("������ѧ���绰����:");
    scanf("%s", &S[S->Total].S_phone);
    getchar();
    printf("��ӳɹ�!\n\n");
}
//�޸�ѧ����Ϣ����
void Alter(Student S) {
    int i;
    int flag = 0; //�����жϱ����Ƿ������Ҫ�޸ĵ�ѧ������Ϣ
    char name[20];
    printf("��������Ҫ�޸�ѧ��������:");
    scanf("%s", name);
    getchar();
    for (i = 1; i <= S->Total; i++)
        if (strcmp(S[i].S_name, name) == 0)
            flag = i;
    if (!flag)
        printf("����Ҫ�޸ĵ�ѧ����Ϣ�ڱ��в����ڣ�\n");
    else {
        Alter_Sub_Menu(S, flag);
    }
    putchar('\n');
}
void Alter_Sub_Menu(Student S, int flag) {
    int i;
    printf("��ѡ��Ҫ�޸ĵ���Ŀ!\n\n");
    printf("1.�޸İ༶              2.�޸������\n");
    printf("3.�޸ĵ绰����          0.ȡ���޸�\n\n");
    scanf("%d", &i);
    switch (i) {
        case 1:
            printf("�������°༶!\n");
            scanf("%s", S[flag].S_class);
            getchar();
            S_number_Judge(S, flag);
            printf("�޸ĳɹ�!\n");
            break;
        case 2:
            printf("�������������!\n");
            scanf("%d", &S[flag].D_number);
            getchar();
            printf("�޸ĳɹ�!\n");
            break;
        case 3:
            printf("���������ֻ���!\n");
            scanf("%s", &S[flag].S_phone);
            getchar();
            printf("�޸ĳɹ�!\n");
            break;
        case 0:
            break;
        default:
            printf("ѡ�����:����ѡ�֮��ѡ��!\n\n");
            break;
    }
}
//ɾ��ѧ����Ϣ
void Delete(Student S) {
    int i, j;
    int flag = 0;  //�����жϱ����Ƿ������Ҫɾ����ѧ������Ϣ
    char name[20];
    printf("��������Ҫɾ��ѧ��������:");
    scanf("%s", name);
    getchar();
    for (i = 1; i <= S->Total; i++)
        if (strcmp(S[i].S_name, name) == 0)
            flag = i;
    if (!flag)
        printf("����Ҫɾ����ѧ���ڱ��в����ڣ�");
    else {
        for (i = flag; i < S->Total; i++) {
            j = i + 1;
            strcpy(S[i].S_name, S[j].S_name);
            strcpy(S[i].S_number, S[j].S_number);
            S[i].D_number = S[j].D_number;
        }
        (S->Total)--;
        printf("ɾ���ɹ�!");
    }
    printf("\n\n");
}
//��ʾ����ѧ����Ϣ����
void Display_All(Student S) {
    int i;
    printf("ȫ��ѧ����Ϣ����:\n");
    printf("ѧ������            ѧ���༶     ѧ��ѧ��      �����         ѧ���绰����\n");
    for (i = 1; i <= S->Total; i++) {
        printf("%-19s %-12s %-14s %-13d %s\n", S[i].S_name, S[i].S_class, S[i].S_number, S[i].D_number, S[i].S_phone);
    }
    printf("\n");
}
//�˳��Ӳ˵�
void Exit_Sub_Menu(Student S)
{
    char ch;
    printf("���������Ѹı䣬�Ƿ񱣴�����˳�(Y/N)?:");
    ch=getchar();
    getchar();
    while(ch!='n'&&ch!='N'&&ch!='y'&&ch!='Y')
    {
        printf("������N(n)����Y(y):");
        ch=getchar();
        getchar();
    }
    if(ch=='y'||ch=='Y')
        Exit_Save(S);
}
//�洢����
void Exit_Save(Student S)
{
	St Std;
	int i;
	int flag1=0,flag2=0; //�жϴ洢�Ƿ�ɹ�
	FILE *fp;
    if((fp=fopen("data","w+"))==NULL)
    {
        printf("��������ʧ��!\n\n");
        flag1=1;
        exit(0);  //��������
	}
	for(i=1;i<=S->Total;i++)
        if(fwrite(&S[i],sizeof(Std),1,fp)!=1)
        {
            printf("���ݱ������!\n\n");
            flag2=1;
			exit(0);
        }
    if(!flag1&&!flag2)
	{
        printf("���ݴ洢�ɹ�,��������˳�!\n\n");
	}
    fclose(fp);
}
//��ʼ�����ؼ�¼����
void Initialize(Student S)
{
	St Std;
	FILE *fp = NULL;
	if((fp=fopen("data","r"))==NULL)
	{
		printf("���ݼ���ʧ��!\n\n");
		exit(0);
	}
	while(!feof(fp))
		fread(&S[++(S->Total)],sizeof(Std),1,fp);
	fclose(fp);
	loading("loading.....�������ݳɹ���");
    (S->Total)--;   //���ڶ�ȡ���⣬���и���Ҫ��ȥ
}
//���ض���
void loading(char *p)              //��ʱ�����Ķ���
{
    while (1) {
        if (*p != 0)
            printf("%c", *p++);
        else
            break;
        Sleep(100);               //��ʱ���Ƽ�����
    }
}
//��ѯ���������Һ�Ϊ�ؼ��ֽ��в�ѯ(�۰����)
void Query_D_number(Student S) {
    int i, j, base, top, mid;
    j = 0;
    base = 1;
    top = S->Total;
    printf("��������Ҫ��ѯ�����Һ�:");
    scanf("%d", &i);
    getchar();
    Sort_D_number(S);//������ԭ���ݰ������ҺŴ�С��������
    printf("������������Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
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
        printf("\n����ʧ��,���в����ڸ����ҵ���Ϣ!\n\n");
}
//��ѯ�����԰༶Ϊ�ؼ��ֽ��в�ѯ(˳�����)
void Query_S_class(Student S) {
    int i, j = 0;
    char classnumber[31];
    printf("��������Ҫ���ҵİ༶��:");
    scanf("%s", classnumber);
    getchar();
    printf("������ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
    for (i = 1; i <= S->Total; i++)
        if (strcmp(classnumber, S[i].S_class) == 0) {
            printf("%-19s%-12s %-14s%-13d%s\n", S[i].S_name, S[i].S_class, S[i].S_number, S[i].D_number, S[i].S_phone);
            j = 1;
        }
    if (!j)
        printf("\n����ʧ��,���в����ڸ�ѧ������Ϣ!\n\n");
}
//��ѯ����������Ϊ�ؼ��ֽ��в�ѯ(�۰����)
void Query_S_name(Student S) {
    int j = 0, top, base, mid;
    char name[31];
    base = 1;
    top = S->Total;
    printf("��������Ҫ���ҵ�ѧ��������:");
    scanf("%s", name);
    getchar();
    Sort_S_name(S);//������ԭ���ݰ���������С��������
    printf("������ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
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
        printf("\n����ʧ��,���в����ڸ�ѧ������Ϣ!\n\n");
}
//��ѯ������ѧ��Ϊ�ؼ��ֽ��в�ѯ(�۰����)
void Query_S_number(Student S) {
    int j, top, base, mid;
    char number[15];
    j = 0;
    base = 1;
    top = S->Total;
    printf("��������Ҫ����ѧ����ѧ��:");
    scanf("%s", number);
    Sort_S_number(S);  //������ԭ���ݰ���ѧ�Ŵ�С��������
    printf("������ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
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
        printf("\n����ʧ��,���в����ڸ�ѧ������Ϣ!\n\n");
}
//�ж�ѧ���Ƿ����������ѧ���ظ�
void S_number_Judge(Student S, int t) {
    int i;
    for (i = 1; i <= (S->Total) - 1; i++)
        while (strcmp(S[i].S_number, S[t].S_number) == 0) {
            printf("ѧ������ʧ��,��ѧ���Ѵ���,����������ѧ��!\n");
            printf("������ѧ����ѧ��:");
            scanf("%s", S[t].S_number);
            getchar();
            i = 0;//i ��Ϊ0 �жϴ�ͷ��ʼ
        }
}
//�������������ҺŴ�С��������(ð�ݷ�)
void Sort_D_number(Student S) {
    int i, j, t;
    char name[30];
    char number[15];
    char Cnumber[30];//Cnumber ���
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
//���������հ༶�Ŵ�С��������(ð�ݷ�)
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
//�������������ִ�С��������(ð�ݷ�)
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
//����������ѧ�Ŵ�С��������(ð�ݷ�)
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
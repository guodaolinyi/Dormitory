//�޸�ѧ����Ϣ����
void Alter(Student S)
{
    int i;
    int flag=0; //�����жϱ����Ƿ������Ҫ�޸ĵ�ѧ������Ϣ
    char name[20];
    printf("��������Ҫ�޸�ѧ��������:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("����Ҫ�޸ĵ�ѧ����Ϣ�ڱ��в����ڣ�\n");
    else
    {
        printf("����Ϣ����:\n");
        //printf("������ѧ������(30���ַ�����):");
        //scanf("%s",S[flag].S_name);
        //getchar();
        printf("������ѧ���༶(30���ַ�����):");
        scanf("%s",S[flag].S_class);
        getchar();
        //printf("������ѧ����ѧ��(15���ַ�����):");
        //scanf("%s",S[flag].S_number);
        //getchar();
        S_number_Judge(S,flag);
        printf("�����������:");
        scanf("%d",&S[flag].D_number);
        getchar();
        printf("������ѧ���绰����:");
        scanf("%ld",&S[flag]. S_phone);
        getchar();
        printf("�޸ĳɹ�!\n");
    }
    putchar('\n');
}
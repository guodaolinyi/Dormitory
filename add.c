//���ѧ����Ϣ����
void Add(Student S)
{
    printf("������ѧ������(30���ַ�����):");
    scanf("%s",&S[++(S->Total)].S_name);
    getchar();//��ȡ���з�
    printf("������ѧ���༶(30���ַ�����):");
    scanf("%s",&S[S->Total].S_class);
    getchar();
    printf("������ѧ����ѧ��(15���ַ�����):");
    scanf("%s",&S[S->Total].S_number);
    getchar();
    S_number_Judge(S,S->Total);//�ж������ѧ���Ƿ�����������ڵ�ѧ���ظ�
    printf("�������������:");
    scanf("%d",&S[S->Total].D_number);
    getchar();
    printf("������ѧ���绰����:");
    scanf("%ld",&S[S->Total]. S_phone);
    getchar();
    printf("��ӳɹ�!\n\n");
}
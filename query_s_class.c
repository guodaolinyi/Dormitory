//��ѯ�����԰༶Ϊ�ؼ��ֽ��в�ѯ(˳�����)
void Query_S_class(Student S)
{
    int i,j=0;
    char classnumber[31];
    printf("��������Ҫ���ҵİ༶��(30���ַ�����):");
    scanf("%s",classnumber);
    getchar();
    printf("������ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
    for(i=1;i<=S->Total;i++)
        if(strcmp(classnumber,S[i].S_class)==0)
        {
            printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name, S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
            j=1;
        }
    if(!j)
        printf("\n����ʧ��,���в����ڸ�ѧ������Ϣ!\n\n");
}

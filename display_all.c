//��ʾ����ѧ����Ϣ����
void Display_All(Student S)
{
    int i;
    printf("ȫ��ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
    for(i=1;i<=S->Total;i++)
        printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name,S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
}
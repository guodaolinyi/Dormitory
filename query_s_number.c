//��ѯ������ѧ��Ϊ�ؼ��ֽ��в�ѯ(�۰����)
void Query_S_number(Student S)
{
    int j,top,base,mid;
    char number[15];
    j=0;
    base=1;
    top=S->Total;
    printf("��������Ҫ����ѧ����ѧ��:");
    scanf("%s",number);
    Sort_S_number(S);  //������ԭ���ݰ���ѧ�Ŵ�С��������
    printf("������ѧ����Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
    if(strcmp(number,S[1].S_number)>=0&&strcmp(number,S[S->Total].S_number)<=0)
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
        printf("\n����ʧ��,���в����ڸ�ѧ������Ϣ!\n\n");
}

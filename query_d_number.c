//��ѯ���������Һ�Ϊ�ؼ��ֽ��в�ѯ(�۰����)
void Query_D_number(Student S)
{
    int i,j,base,top,mid;
    j=0;
    base=1;
    top=S->Total;
    printf("��������Ҫ��ѯ�����Һ�:");
    scanf("%d",&i);
    getchar();
    Sort_D_number(S);//������ԭ���ݰ������ҺŴ�С��������
    printf("������������Ϣ����:\n");
    printf("ѧ������       ѧ���༶       ѧ��ѧ��       �����       ѧ���绰����\n");
    if(i>=S[1].D_number&&i<=S[S->Total].D_number)
    {
        while(base<=top)
        {
            mid=(base+top)/2;
            if(i==S[mid].D_number)
            {
				printf("%-19s%-12s %-14s%-13d%ld\n",S[mid].S_name, S[mid].S_class,S[mid].S_number,S[mid].D_number,S[mid].S_phone);
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
        printf("\n����ʧ��,���в����ڸ����ҵ���Ϣ!\n\n");
}
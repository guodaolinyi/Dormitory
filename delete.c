//ɾ��ѧ����Ϣ
void Delete(Student S)
{
    int i,j;
    int flag=0;  //�����жϱ����Ƿ������Ҫɾ����ѧ������Ϣ
    char name[20];
    printf("��������Ҫɾ��ѧ��������:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("����Ҫɾ����ѧ���ڱ��в����ڣ�");
    else
    {
        for(i=flag;i<S->Total;i++)
        {
            j=i+1;
            strcpy(S[i].S_name,S[j].S_name);
            strcpy(S[i].S_number,S[j].S_number);
            S[i].D_number=S[j].D_number;
        }
        (S->Total)--;
        printf("ɾ���ɹ�!");
    }
    printf("\n\n");
}
//删除学生信息
void Delete(Student S)
{
    int i,j;
    int flag=0;  //用来判断表中是否存在所要删除的学生的信息
    char name[20];
    printf("请输入你要删除学生的姓名:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("你所要删除的学生在表中不存在！");
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
        printf("删除成功!");
    }
    printf("\n\n");
}
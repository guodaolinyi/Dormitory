//修改学生信息函数
void Alter(Student S)
{
    int i;
    int flag=0; //用来判断表中是否存在所要修改的学生的信息
    char name[20];
    printf("请输入你要修改学生的姓名:");
    scanf("%s",name);
    getchar();
    for(i=1;i<=S->Total;i++)
        if(strcmp(S[i].S_name,name)==0)
            flag=i;
    if(!flag)
        printf("你所要修改的学生信息在表中不存在！\n");
    else
    {
        printf("新信息如下:\n");
        //printf("请输入学生姓名(30个字符以内):");
        //scanf("%s",S[flag].S_name);
        //getchar();
        printf("请输入学生班级(30个字符以内):");
        scanf("%s",S[flag].S_class);
        getchar();
        //printf("请输入学生的学号(15个字符以内):");
        //scanf("%s",S[flag].S_number);
        //getchar();
        S_number_Judge(S,flag);
        printf("请输入宿舍号:");
        scanf("%d",&S[flag].D_number);
        getchar();
        printf("请输入学生电话号码:");
        scanf("%ld",&S[flag]. S_phone);
        getchar();
        printf("修改成功!\n");
    }
    putchar('\n');
}
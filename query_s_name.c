//查询函数以姓名为关键字进行查询(顺序查找)
void Query_S_name(Student S)
{
    int i,j=0;
    char name[31];
    printf("请输入你要查找的学生的姓名(30个字符以内):");
    scanf("%s",name);
    getchar();
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for(i=1;i<=S->Total;i++)
        if(strcmp(name,S[i].S_name)==0)
        {
            printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name, S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
            j=1;
        }
    if(!j)
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}
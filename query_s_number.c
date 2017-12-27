//查询函数以学号为关键字进行查询(折半查找)
void Query_S_number(Student S)
{
    int j,top,base,mid;
    char number[15];
    j=0;
    base=1;
    top=S->Total;
    printf("请输入你要查找学生的学号:");
    scanf("%s",number);
    Sort_S_number(S);  //将表中原数据按照学号从小到大排序
    printf("所查找学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
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
        printf("\n查找失败,表中不存在该学生的信息!\n\n");
}

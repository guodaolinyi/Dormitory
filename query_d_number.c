//查询函数以寝室号为关键字进行查询(折半查找)
void Query_D_number(Student S)
{
    int i,j,base,top,mid;
    j=0;
    base=1;
    top=S->Total;
    printf("请输入你要查询的寝室号:");
    scanf("%d",&i);
    getchar();
    Sort_D_number(S);//将表中原数据按照寝室号从小到大排序
    printf("所查找寝室信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
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
        printf("\n查找失败,表中不存在该寝室的信息!\n\n");
}
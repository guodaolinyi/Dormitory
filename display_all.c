//显示所有学生信息函数
void Display_All(Student S)
{
    int i;
    printf("全体学生信息如下:\n");
    printf("学生姓名       学生班级       学生学号       宿舍号       学生电话号码\n");
    for(i=1;i<=S->Total;i++)
        printf("%-19s%-12s %-14s%-13d%s\n",S[i].S_name,S[i].S_class,S[i].S_number,S[i].D_number,S[i].S_phone);
}
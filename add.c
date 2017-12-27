//添加学生信息函数
void Add(Student S)
{
    printf("请输入学生姓名(30个字符以内):");
    scanf("%s",&S[++(S->Total)].S_name);
    getchar();//获取换行符
    printf("请输入学生班级(30个字符以内):");
    scanf("%s",&S[S->Total].S_class);
    getchar();
    printf("请输入学生的学号(15个字符以内):");
    scanf("%s",&S[S->Total].S_number);
    getchar();
    S_number_Judge(S,S->Total);//判断输入的学号是否与表中所存在的学号重复
    printf("请输入宿舍号码:");
    scanf("%d",&S[S->Total].D_number);
    getchar();
    printf("请输入学生电话号码:");
    scanf("%ld",&S[S->Total]. S_phone);
    getchar();
    printf("添加成功!\n\n");
}
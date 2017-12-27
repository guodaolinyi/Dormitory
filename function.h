#ifndef _function_H_
#define _function_H_
void S_number_Judge(Student S,int t);//判断学号是否与表中所存学号重复
void Add(Student S);//添加学生信息函数
void Alter(Student S);//修改学生信息函数
void Delete(Student S);//删除学生信息
void Display_All(Student S);//显示所有学生信息函数
void Sort_D_number(Student S);//排序函数按照寝室号从小到大排序(冒泡法)
void Sort_S_number(Student S);//排序函数按照学号从小到大排序(冒泡法)
void Sort_S_class (Student S);//排序函数按照班级号从小到大排序(冒泡法)
void Query_S_class(Student S);//查询函数以班级为关键字进行查询(顺序查找)
void Query_S_name(Student S);//查询函数以姓名为关键字进行查询(顺序查找)
void Query_S_number(Student S);//查询函数以学号为关键字进行查询(折半查找)
void Query_D_number(Student S);//查询函数以寝室号为关键字进行查询(折半查找)
#endif
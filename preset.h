#ifndef _preset_H_
#define _preset_H_
#define M 100
//定义一个存储学生相关信息的结构体
typedef struct
{
    char S_name[31];   //学生姓名
    char S_class[31];  //学生班级
    char S_number[16]; //学生学号
    int D_number;      //学生所在寝室的宿舍号
    long S_phone[20];  //学生电话号码
    int Total;         //学生总数
}Student[M],St;
#endif
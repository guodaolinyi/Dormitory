#ifndef _preset_H_
#define _preset_H_
#define M 100
//����һ���洢ѧ�������Ϣ�Ľṹ��
typedef struct
{
    char S_name[31];   //ѧ������
    char S_class[31];  //ѧ���༶
    char S_number[16]; //ѧ��ѧ��
    int D_number;      //ѧ���������ҵ������
    long S_phone[20];  //ѧ���绰����
    int Total;         //ѧ������
}Student[M],St;
#endif

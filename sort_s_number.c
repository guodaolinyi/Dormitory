//排序函数按照学号从小到大排序(冒泡法)
void Sort_S_number(Student S)
{
    int i,j,t;
    char name[30];
    char number[15];
    char Cnumber[30];
    for(i=1;i<=S->Total;i++)
        for(j=i;j<=S->Total;j++)
            if(strcmp(S[i].S_number,S[j].S_number)>0)
            {
                strcpy(name,S[i].S_name);
                strcpy(number,S[i].S_number);
                strcpy(Cnumber,S[i].S_class);
                t=S[i].D_number;
                strcpy(S[i].S_name,S[j].S_name);
                strcpy(S[i].S_number,S[j].S_number);
                strcpy(S[i].S_class,S[j].S_class);
                S[i].D_number=S[j].D_number;
                strcpy(S[j].S_name,name);
                strcpy(S[j].S_number,number);
                strcpy(S[j].S_class,Cnumber);
                S[j].D_number=t;
            }
}

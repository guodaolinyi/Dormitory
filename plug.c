//���ض���
void loading(char *p)              //��ʱ�����Ķ���  
{  
    while (1)  
    {  
    if (*p!=0)  
    printf("%c",*p++);  
    else  
    break;  
    Sleep(100);               //��ʱ���Ƽ�����  
    }  
} 
//加载动画
void loading(char *p)              //延时函数的定义  
{  
    while (1)  
    {  
    if (*p!=0)  
    printf("%c",*p++);  
    else  
    break;  
    Sleep(100);               //延时控制间断语句  
    }  
} 
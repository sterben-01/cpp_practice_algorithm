#include <arpa/inet.h>

int main(){
    //将点分10进制字符串转换为网络字节序的整数。
    char charIP[] = "192.168.1.100";

    unsigned int intIP = 0;
    inet_pton(AF_INET, charIP, &intIP); //修改需要传指针。也就是地址。

    unsigned char* ptr = (unsigned char*)&intIP; //这里需要对那个int进行按字节读取。因为小于255所以用unsigned char。然后记得先取地址。然后强转一下

    printf("%d.%d.%d.%d\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));

    //-------------------------------------
    //将网络字节序的整数转换为点分10进制的字符串

    char charIP1[16] = ""; //是16的原因是 255.255.255.255 这是3*4+3 =15位，再加一个\0的结束符一共是16;
    const char* ptr1 = inet_ntop(AF_INET, &intIP, charIP1, 16); 
    printf("%s\n", charIP1); //打印哪个都行。
    printf("%s\n", ptr1);  //打印哪个都行。


    return 0;
}
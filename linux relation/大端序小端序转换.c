/*

    网络通信时，需要将主机字节序转换成网络字节序（大端），
    另外一段获取到数据以后根据情况将网络字节序转换成主机字节序。

    // 转换端口
    uint16_t htons(uint16_t hostshort);		// 主机字节序 - 网络字节序
    uint16_t ntohs(uint16_t netshort);		// 主机字节序 - 网络字节序

    // 转IP
    uint32_t htonl(uint32_t hostlong);		// 主机字节序 - 网络字节序
    uint32_t ntohl(uint32_t netlong);		// 主机字节序 - 网络字节序

*/

#include <stdio.h>
#include <arpa/inet.h>

int main() {

    // htons 转换端口
    unsigned short a = 0x0102;
    printf("a : %x\n", a);
    unsigned short b = htons(a);
    printf("b : %x\n", b);

    printf("=======================\n");

    // htonl  转换IP
    //注意。unsigned char可以表示0-255。所以我们可以说在数字小于255的时候，unsigned char数组和int数组是一样的。
    //虽然int确实是4字节，char是1字节。但是1字节的int可以表示最大255 也就是0xff。
    unsigned char buf[4] = {100, 1, 168, 192}; //255以内的int可以用unsigned char 表示。所以这里是1*4 一共4个字节。这里假设是小端序的东西。
    int num = *(int *)buf; //用int类型的指针一口气去读4个字节。
    int sum = htonl(num); //转换成大端序
    unsigned char *p = (char *)&sum; //取sum的地址然后转换为char*

    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3)); // 然后每次读取一个字节。

    printf("=======================\n");

    // ntohl
    unsigned char buf1[4] = {192, 168, 1, 100};
    int num1 = *(int *)buf1;
    int sum1 = ntohl(num1); //转换为小端序
    unsigned char *p1 = (unsigned char *)&sum1;
    printf("%d %d %d %d\n", *p1, *(p1+1), *(p1+2), *(p1+3));
    
     // ntohs


    return 0;
}
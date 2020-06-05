#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//转置表，使用方式：一个字节的前四位为行，后四位为列
unsigned char sBox[] =
{ /*  0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f */
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76, /*0*/
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0, /*1*/
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15, /*2*/
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75, /*3*/
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84, /*4*/
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf, /*5*/
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8, /*6*/
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2, /*7*/
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73, /*8*/
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb, /*9*/
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79, /*a*/
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08, /*b*/
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a, /*c*/
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e, /*d*/
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf, /*e*/
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16  /*f*/
};
//逆转置表
unsigned char invsBox[256] =
{ /*  0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f  */
    0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38,0xbf,0x40,0xa3,0x9e,0x81,0xf3,0xd7,0xfb, /*0*/
    0x7c,0xe3,0x39,0x82,0x9b,0x2f,0xff,0x87,0x34,0x8e,0x43,0x44,0xc4,0xde,0xe9,0xcb, /*1*/
    0x54,0x7b,0x94,0x32,0xa6,0xc2,0x23,0x3d,0xee,0x4c,0x95,0x0b,0x42,0xfa,0xc3,0x4e, /*2*/
    0x08,0x2e,0xa1,0x66,0x28,0xd9,0x24,0xb2,0x76,0x5b,0xa2,0x49,0x6d,0x8b,0xd1,0x25, /*3*/
    0x72,0xf8,0xf6,0x64,0x86,0x68,0x98,0x16,0xd4,0xa4,0x5c,0xcc,0x5d,0x65,0xb6,0x92, /*4*/
    0x6c,0x70,0x48,0x50,0xfd,0xed,0xb9,0xda,0x5e,0x15,0x46,0x57,0xa7,0x8d,0x9d,0x84, /*5*/
    0x90,0xd8,0xab,0x00,0x8c,0xbc,0xd3,0x0a,0xf7,0xe4,0x58,0x05,0xb8,0xb3,0x45,0x06, /*6*/
    0xd0,0x2c,0x1e,0x8f,0xca,0x3f,0x0f,0x02,0xc1,0xaf,0xbd,0x03,0x01,0x13,0x8a,0x6b, /*7*/
    0x3a,0x91,0x11,0x41,0x4f,0x67,0xdc,0xea,0x97,0xf2,0xcf,0xce,0xf0,0xb4,0xe6,0x73, /*8*/
    0x96,0xac,0x74,0x22,0xe7,0xad,0x35,0x85,0xe2,0xf9,0x37,0xe8,0x1c,0x75,0xdf,0x6e, /*9*/
    0x47,0xf1,0x1a,0x71,0x1d,0x29,0xc5,0x89,0x6f,0xb7,0x62,0x0e,0xaa,0x18,0xbe,0x1b, /*a*/
    0xfc,0x56,0x3e,0x4b,0xc6,0xd2,0x79,0x20,0x9a,0xdb,0xc0,0xfe,0x78,0xcd,0x5a,0xf4, /*b*/
    0x1f,0xdd,0xa8,0x33,0x88,0x07,0xc7,0x31,0xb1,0x12,0x10,0x59,0x27,0x80,0xec,0x5f, /*c*/
    0x60,0x51,0x7f,0xa9,0x19,0xb5,0x4a,0x0d,0x2d,0xe5,0x7a,0x9f,0x93,0xc9,0x9c,0xef, /*d*/
    0xa0,0xe0,0x3b,0x4d,0xae,0x2a,0xf5,0xb0,0xc8,0xeb,0xbb,0x3c,0x83,0x53,0x99,0x61, /*e*/
    0x17,0x2b,0x04,0x7e,0xba,0x77,0xd6,0x26,0xe1,0x69,0x14,0x63,0x55,0x21,0x0c,0x7d  /*f*/
};
/*列混合矩阵系数*/
unsigned char var[4][4] = {
            { 0x02,0x03,0x01,0x01},
            {0x01,0x02,0x03,0x01},
            {0x01,0x01,0x02,0x03},
            {0x03,0x01,0x01,0x02},
};
/*逆列混合矩阵系数*/
unsigned char re_var[4][4] = {
            {0x0E,0x0B,0x0D,0x09},
            {0x09,0x0E,0x0B,0x0D},
            {0x0D,0x09,0x0E,0x0B},
            {0x0B,0x0D,0x09,0x0E},
};
/*轮常量Rcon 用于密钥扩展*/
unsigned int Rcon[] = { 0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80 , 0x1b , 0x36 };

/*使用指定的置换表对一个分组进行置换（一个分组4*4=16个字节），
    用于S盒置换
*/
void SubBytes(unsigned char state[][4], unsigned char* thissBox)
{
    int r, c;
    for (r = 0; r < 4; r++)
    {
        for (c = 0; c < 4; c++)
        {
            state[r][c] = thissBox[state[r][c]];
        }
    }
}
/*行位移*/
void ShiftRows(unsigned char state[][4])
{
    int r;
    for (r = 1; r < 4; r++)
    {
        *((unsigned int*)state[r]) = (*((unsigned int*)state[r]) >> (r * 8)) | (*((unsigned int*)state[r]) << (32 - r * 8));
    }
}
/*逆行位移*/
void ReverseShiftRows(unsigned char state[][4])
{
    int r;
    for (r = 1; r < 4; r++)
    {
        *((unsigned int*)state[r]) = (*((unsigned int*)state[r]) << (r * 8)) | ( *((unsigned int*)state[r]) >> (32 - r * 8) );
    }
}

/*实现有限域内mod算法*/
unsigned mod(unsigned a, unsigned b) {
    /*遍历获得a的最高位*/
    int maxLen_b = 0;
    for (maxLen_b = sizeof(b) * 8 - 1; maxLen_b >= 0; maxLen_b--)
        if ((b >> maxLen_b)) break;
    while (a > b)
    {
        int maxLen = 0;
        for (maxLen = sizeof(a) * 8 - 1; maxLen >= 0; maxLen--)
            if ((a >> maxLen)) break;
        a = a ^ (b << (maxLen - maxLen_b));
    }
    return a;
}
unsigned char GMul(unsigned u, unsigned v) {
    unsigned p = 0;

    for (int i = 0; i < 8; ++i) {
        if (u & 0x01) {
            p ^= v;
        }

        int flag = (v & 0x80);
        v <<= 1;
        if (flag) {
            v ^= 0x1B;  /* P(x) = x^8 + x^4 + x^3 + x + 1 */
        }

        u >>= 1;
    }

    return p;
}
/*实现有限域内乘法*/
unsigned char multipli_on_GF2_8(unsigned char a,unsigned char b) {
    unsigned char a1[] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80 };
    unsigned int bit[8] = { 0 };
    unsigned int t = 0;
    for (size_t i = 0; i < 8; i++)
    {
        bit[i] = (a1[i] & a) * b;
        if (bit[i] & 0x100)
        {
            bit[i] = /*mod*/(bit[i] ^ 0x011b);
        }
    }
    for (size_t i = 0; i < 8; i++)
    {
        t ^= bit[i];
    }
    return (char)mod(t, 0x011b);
 }
/*输出 4*4 矩阵*/
void PrintfMatrix(unsigned char m[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%4x", m[i][j]);
            if (j % 4 == 3)
                puts("");
        }

    }
}
/*实现单个行与列间，对应位相乘后模2加，用于计算矩阵使用 GMul*/
unsigned char mixpart(unsigned char a[4], unsigned char b[4]) {
    return (unsigned char)mod(multipli_on_GF2_8(a[0], b[0]) ^ multipli_on_GF2_8(a[1], b[1]) ^
        multipli_on_GF2_8(a[2], b[2]) ^ multipli_on_GF2_8(a[3], b[3]),0x011b);
}
unsigned char mixpart2(unsigned char a[4], unsigned char b[4]) {
    return GMul(a[0], b[0]) ^ GMul(a[1], b[1]) ^
        GMul(a[2], b[2]) ^ GMul(a[3], b[3]);
}

/*列混合 第一个参数矩阵和第二个状态矩阵 使用有限域GF2^8内乘法
    var * state
    逆运算使用逆运算矩阵作为var[4][4]参数传入
    re_var[1]
    0x4c,0x9f,0x42,0xbc
*/
void mixcolumns(unsigned char var[4][4],unsigned char state[4][4]) {
    unsigned char cipher[4][4];
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            unsigned char temp[4] = { state[0][j],state[1][j],state[2][j],state[3][j] };
            cipher[i][j] = mixpart(var[i], temp);
        }
    }
    *((long long*)state) = *((long long*)cipher);
    *(((long long*)state) +1) = *(((long long*)cipher)+1);

}
/*轮密钥加 */
void roundKeyAdd(unsigned char roundkey[4][4], unsigned char state[4][4], unsigned char out[4][4]) {
    
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            out[i][j] = roundkey[i][j] ^ state[i][j];

        }
    }
}
/*用于密钥扩展的T函数 w 为输入的列指针 , out 为T函数输出*/
void T(unsigned char w[4], unsigned int correntRcon, unsigned char out[4]) {
    unsigned char temp[4];
    unsigned* ptr = (unsigned int*)w;// 0x3c4fcf09 
    //字循环 循环左移一个字节，8位
    *(unsigned int*)temp = (*((unsigned int*)w) << 24) | (*((unsigned int*)w) >> 8);
    ptr = (unsigned int*)temp;// 0x4fcf093c
    //字节代换
    for (size_t i = 0; i < 4; i++)
    {
        temp[i] = sBox[temp[i]];
    }
    //与轮常量异或，
    /*
    轮常量后三字节全是0，开始打算只储存最高位的一个字节，考虑到win和linux存在高低字节序问题，懒得做适配，直接全部储存，把转换工作交给编译器
    */
    *(unsigned int*)temp = (*(unsigned int*)temp) ^ correntRcon;
    memcpy(out, temp,sizeof(temp));
}
/*两列做异或*/
void XOR_culunm(unsigned char a[4], unsigned char b[4], unsigned char *out) {
    out[0] = a[0] ^ b[0];
    out[1] = a[1] ^ b[1];
    out[2] = a[2] ^ b[2];
    out[3] = a[3] ^ b[3];
}
void transform(unsigned char a[4][4], unsigned char b[4][4]) {
    for (size_t i = 0; i < 4; i++)
    {
        b[i][0] = a[0][i];
        b[i][1] = a[1][i];
        b[i][2] = a[2][i];
        b[i][3] = a[3][i];
    }
}
/*密钥扩展*/
void KeyExpansition(unsigned char rootKey[4][4], unsigned char expandKey[10][4][4]) {
    unsigned char w[44][4];/*列转化为行，方便操作*/
    unsigned char tempBuf[4];
    /*前4列直接赋值*/
    for (size_t i = 0; i < 4; i++)
    {
        w[i][0] = rootKey[0][i];
        w[i][1] = rootKey[1][i];
        w[i][2] = rootKey[2][i];
        w[i][3] = rootKey[3][i];
    }
    for (size_t i = 1; i < 11; i++)
    {
        T(w[4*i - 1], Rcon[i - 1], tempBuf);
        XOR_culunm(tempBuf,    w[4 * i - 4], w[4 * i]);
        XOR_culunm(w[4 * i],   w[4 * i - 3], w[4 * i+1]);
        XOR_culunm(w[4 * i+1], w[4 * i - 2], w[4 * i+2]);
        XOR_culunm(w[4 * i+2], w[4 * i - 1], w[4 * i+3]);
    }
    /*将列转化为行*/
    for (size_t i = 0; i < 10; i++)
    {
        transform(w+ 4 * (i + 1), expandKey[i]);
    }
}

/*AES加密分组*/
void enAES(unsigned char m[4][4],unsigned char rootKey[4][4]) {
    /*密钥扩展*/
    unsigned char expandKey[10][4][4];
    KeyExpansition(rootKey, expandKey);
    /*第一步 明文和初始密钥执行轮密钥加*/
    roundKeyAdd(rootKey, m, m);
    /*接下来9轮加密操作相同
        1.字节代换
        2.行移位
        3.列混合
        4.轮密钥加
    第10轮没有 列混合
        */
    for (size_t i = 0; i < 9; i++)
    {
        //字节代换
        SubBytes(m, sBox);
        //行移位
        ShiftRows(m);
        //列混合
        mixcolumns(var, m);
        //轮密钥加
        roundKeyAdd(expandKey[i], m, m);
    }
    //第10次加密分组
    {
        //字节代换
        SubBytes(m, sBox);
        //行移位
        ShiftRows(m);
        //轮密钥加
        roundKeyAdd(expandKey[9], m, m);
    }
}
/*AES解密分组*/
void disAES(unsigned char m[4][4], unsigned char rootKey[4][4]) {
    /*密钥扩展*/
    unsigned char expandKey[10][4][4];
    KeyExpansition(rootKey, expandKey);
    roundKeyAdd(expandKey[9], m, m);
    for (int i = 8; i >= 0; i--)
    {
        //逆行移位
        ReverseShiftRows(m);
        //逆字节代换
        SubBytes(m, invsBox);
        //轮密钥加
        roundKeyAdd(expandKey[i], m, m);
        //逆列混合
        mixcolumns(re_var, m);
        
    }
    {
        //逆行移位
        ReverseShiftRows(m);
        //字节代换
        SubBytes(m, invsBox);
        //轮密钥加
        roundKeyAdd(rootKey, m, m);
    }
}
void encodeFile(char* soursePath, char* keyPath, char* desPath) {
    FILE* sourse, * KEY, * DES;
    unsigned byteCount = 0;
    if ((sourse = fopen(soursePath, "rb+")) == NULL ||
        (KEY = fopen(keyPath, "rb+")) == NULL ||
        (DES = fopen(desPath, "wb+")) == NULL)
    {
        printf("FILE OPEN ERROR");
        exit(0);
    }
    unsigned sourceReaded = 0;
    unsigned char sourseBuffer[4][4];//8个字节
    unsigned char keyBuffer[4][4];//8个字节
    unsigned char tempChars[4][4];//8个字节 加密后的缓冲区
    if (fread(keyBuffer, sizeof(char), 16, KEY) < 16)
    {
        printf("密钥文件破损！");
        exit(-1);
    };
    while (1) {
        sourceReaded = fread((char*)sourseBuffer, sizeof(char), 16, sourse);
        if (sourceReaded < 16 && sourceReaded != 0) {
            memset(sourseBuffer + sourceReaded, 0, 16 - sourceReaded);
        }
        else if (sourceReaded == 0) {
            break;
        }
        byteCount += sourceReaded;
        
        enAES(sourseBuffer, keyBuffer); 
        fwrite((char*)sourseBuffer,16,1, DES);
    }
    printf("共加密%d字节\n", byteCount);
    
    fclose(sourse);
    fclose(KEY);
    fclose(DES);
}
void decodeFile(char* soursePath, char* keyPath, char* desPath) {
    FILE* sourse, * KEY, * DES;
    if ((sourse = fopen(soursePath, "rb+")) == NULL ||
        (KEY = fopen(keyPath, "rb+")) == NULL ||
        (DES = fopen(desPath, "wb+")) == NULL)
    {
        printf("FILE OPEN ERROR");
        exit(0);
    }
    unsigned sourceReaded = 0;
    unsigned char sourseBuffer[4][4];//8个字节
    unsigned char keyBuffer[4][4];//8个字节
    unsigned char tempChars[4][4];//8个字节 加密后的缓冲区
    if (fread(keyBuffer, sizeof(char), 16, KEY) < 16)
    {
        printf("密钥文件破损！");
        exit(-1);
    };
    while (1) {
        sourceReaded = fread((char*)sourseBuffer, sizeof(char), 16, sourse);
        if (sourceReaded < 16 && sourceReaded != 0) {
            memset(sourseBuffer + sourceReaded, 0, 16 - sourceReaded);
        }
        else if (sourceReaded == 0) {
            break;
        }
        disAES(sourseBuffer, keyBuffer);
        fwrite((char*)sourseBuffer, 1, 16, DES);
    }
    fclose(sourse);
    fclose(KEY);
    fclose(DES);
}
int main() {
    char soursePath[] = "C:\\Users\\Lenovo\\Desktop\\2.txt";
    char keyPath[] = "C:\\Users\\Lenovo\\Desktop\\key.txt";
    char encryptted[] = "C:\\Users\\Lenovo\\Desktop\\my.txt";
    char myresult[] = "C:\\Users\\Lenovo\\Desktop\\myresult.txt";
    printf("源文本路径：%s\n", soursePath);
    printf("初始密钥路径：%s\n", keyPath);

    printf("开始加密...\n");
    encodeFile(soursePath,keyPath,encryptted);
    printf("密文路径：%s\n", encryptted);
    printf("开始解密...\n");
    decodeFile(encryptted, keyPath, myresult);
    printf("解密完成！\n");
    printf("解密文本路径：%s\n", myresult);
   /* unsigned char keys[4][4] = {
    0x2b, 0x28, 0xab, 0x09,
    0x7e, 0xae, 0xf7, 0xcf,
    0x15, 0xd2, 0x15, 0x4f,
    0x16, 0xa6, 0x88, 0x3c
    }; 
    unsigned char exampleIN[4][4] = { 0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37, 0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d
, 0xa2, 0x34 };

    printf("明文：\n");
    PrintfMatrix(exampleIN);

    enAES(exampleIN, keys);
    printf("密文：\n");
    PrintfMatrix(exampleIN);

    disAES(exampleIN, keys);
    printf("解密后：\n");
    PrintfMatrix(exampleIN);
    */
	return 0;
}  
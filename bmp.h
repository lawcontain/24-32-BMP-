#pragma once
#define MAXSIZE 2000
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef long LONG;
typedef int FXPT2DOT30;
#define REAL_WIDTH  bitInfo->bmiHeader->biWidth
#define REAL_HEIGHT  bitInfo->bmiHeader->biHeight ///bitInfo�Ǵ����λͼ����
#pragma pack(2)

/// <summary>
/// λͼ�ļ�ͷ
/// </summary>
typedef struct targetBITMAPFILEHEADER {
    WORD bfType; // λͼ�ļ�������
    DWORD bfSize; //�ļ���С(������14�ֽ�)
    WORD bfReserved1; //�����֣�������
    WORD bfReserved2; //�����֣�ͬ��
    DWORD bfOffBits; //ʵ��λͼ���ݵ�ƫ���ֽ���
}Fileheader;

/// <summary>
/// λͼ��Ϣͷ
/// </summary>
typedef struct targetBITMAPINFOHEADER 
{
    DWORD   biSize;             //ָ���˽ṹ��ĳ��ȣ�Ϊ40  
    LONG    biWidth;            //λͼ��  
    LONG    biHeight;           //λͼ��  
    WORD    biPlanes;           //ƽ������Ϊ1  
    WORD    biBitCount;         //������ɫλ����������1��2��4��8��16��24���µĿ�����32  
    DWORD   biCompression;      //ѹ����ʽ��������0��1��2������0��ʾ��ѹ��  
    DWORD   biSizeImage;        //ʵ��λͼ����ռ�õ��ֽ���  
    LONG    biXPelsPerMeter;    //X����ֱ���  
    LONG    biYPelsPerMeter;    //Y����ֱ���  
    DWORD   biClrUsed;          //ʹ�õ���ɫ�������Ϊ0�����ʾĬ��ֵ(2^��ɫλ��)  
    DWORD   biClrImportant;     //��Ҫ��ɫ�������Ϊ0�����ʾ������ɫ������Ҫ��  
}Infoheader;

/// <summary>
/// ������Ϣ
/// </summary>
typedef struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed; 
    BYTE rgbAlpha;
}DATA;

/// <summary>
/// λͼ�Ķ�������ɫ��Ϣ
/// </summary>
typedef struct tagBITMAPINFO
{
    Fileheader* bmfHeader;
    Infoheader* bmiHeader;
    DATA imgDate[MAXSIZE][MAXSIZE];
} Mapinfo;


/// <summary>
/// Ϊ��32λͼ��ʽ˳����ȡ���
/// </summary>
typedef struct tagCIEXYZ
{
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
}
CIEXYZ, * LPCIEXYZ;
typedef struct tagCIEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
}CIEXYZTRIPLE;



/// <summary>
/// ��ȡ24λͼ
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="fp"></param>
void readRGB24(Mapinfo* bitInfo, FILE* fp);

/// <summary>
/// ��ȡ32λͼ
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="fp"></param>
void readRGB32(Mapinfo* bitInfo, FILE* fp);

/// <summary>
/// ��ȡBMP�ļ�
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="path"></param>
void readBMP(Mapinfo* bitInfo, char path[]);

/// <summary>
/// ����Ƕ���תͼƬ��Ĭ��˳ʱ��Ϊ������ʱ��Ϊ��
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="angle"></param>
void rotatePicture(Mapinfo* bitInfo, double angle);

/// <summary>
/// �洢24λͼ
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="path"></param>
void savePicture24(Mapinfo* bitInfo, char path[]);

/// <summary>
/// �洢32λͼ
/// </summary>
/// <param name="bitInfo"></param>
/// <param name="path"></param>
void savePicture32(Mapinfo* bitInfo, char path[]);

/// <summary>
/// X������ת
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="theta"></param>
/// <returns></returns>
double xAfterRot(int x, int y, double theta);

/// <summary>
/// Y������ת
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="theta"></param>
/// <returns></returns>
double yAfterRot(int x, int y, double theta);

/// <summary>
/// Ϊ���ҵ���ͼ��ת��߽��ĸ��㣬�����װ�¸�ͼ��ͼƬ��͸�
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="theta"></param>
/// <returns></returns>
void findXY(int& x, int& y, double theta);
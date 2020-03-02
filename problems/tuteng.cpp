#include <stdio.h>
#include <string.h>
int P2[]={1,2,4,8,16,32,64,128,256,512,1024,2048};   //����math.h��pow����
char Map[2049][2049];   //�����Ļ���ͼ
int N;
void Pt1(int pyh,int pyl)  //��ƫ���ϴ�ӡ�������������
{
    Map[pyh][pyl]='/';
    Map[pyh][pyl+1]='\\';
    Map[pyh+1][pyl-1]='/';
    Map[pyh+1][pyl+2]='\\';
    Map[pyh+1][pyl]='_';
    Map[pyh+1][pyl+1]='_';
}
void Divide(int py1,int py2,int n)  //����
{
    if(n==1){Pt1(py1,py2);return;}  //ֻ��һ��ʹ�ӡ�˳�
    Divide(py1,py2,n-1);  
    Divide(py1+P2[n-1],py2-P2[n-1],n-1);
    Divide(py1+P2[n-1],py2+P2[n-1],n-1);//��֮����ѳ����������ݹ�
}
int main()
{
    scanf("%d",&N);
    memset(Map,' ',sizeof(Map));   //ȫ��Ϊ�ո���Ϊ��char������memset����ʵ��
    Divide(0,P2[N],N);
    int wia,wib;
    for(wia=0;wia<P2[N+1];++wia)
    {
        for(wib=1;wib<=P2[N+1];++wib)
            putchar(Map[wia][wib]);
        putchar('\n');
    }    //�Ѿ���һ��һ��������ͼ
    return 0;
}

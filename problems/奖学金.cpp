#include<algorithm>//ֱ�ӵ��ÿ������ݿ�
#include<iostream>//cin,cout�Ȳ���˵��
using namespace std;
struct student//�ṹ�壬������ÿ���˸��Ե�����
    {
        int num;//���
        int chn;//����
        int mat;//��ѧ
        int eng;//Ӣ��
    }stu[10001];//���鿪����һ�㣬��ֹ���ݹ���
int comp(const student &a,const student &b)//����Ҫ�����������˳�����ȷ��
{
if((a.chn+a.mat+a.eng)>(b.chn+b.mat+b.eng)) return 1;//�Ƚ��ܷ�
if((a.chn+a.mat+a.eng)<(b.chn+b.mat+b.eng)) return 0;
if(a.chn>b.chn) return 1;//����ͬ���Ƚ����ĳɼ�
if(a.chn<b.chn) return 0;
if(a.num<b.num) return 1;return 0;//����ٱȽ�����
}
int main()//������
{
    int n;cin>>n;//ȷ�����ݹ�ģ
    for(int i=1;i<=n;i++)
    {
        stu[i].num=i;//���ű���
        cin>>stu[i].chn>>stu[i].mat>>stu[i].eng;
    }
    sort(stu+1,stu+n+1,comp);//����
    for(int i=1;i<=5;i++)//ǰ����
    cout<<stu[i].num<<" "<<(stu[i].chn+stu[i].mat+stu[i].eng)<<endl;
    return 0;
}

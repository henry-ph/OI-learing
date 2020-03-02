#include<algorithm>//直接调用快排数据库
#include<iostream>//cin,cout等不多说了
using namespace std;
struct student//结构体，方便存放每个人各自的数据
    {
        int num;//编号
        int chn;//语文
        int mat;//数学
        int eng;//英语
    }stu[10001];//数组开大了一点，防止数据过多
int comp(const student &a,const student &b)//最重要的排序过程中顺序如何确定
{
if((a.chn+a.mat+a.eng)>(b.chn+b.mat+b.eng)) return 1;//比较总分
if((a.chn+a.mat+a.eng)<(b.chn+b.mat+b.eng)) return 0;
if(a.chn>b.chn) return 1;//若相同，比较语文成绩
if(a.chn<b.chn) return 0;
if(a.num<b.num) return 1;return 0;//最后再比较座号
}
int main()//主函数
{
    int n;cin>>n;//确定数据规模
    for(int i=1;i<=n;i++)
    {
        stu[i].num=i;//座号编排
        cin>>stu[i].chn>>stu[i].mat>>stu[i].eng;
    }
    sort(stu+1,stu+n+1,comp);//排序
    for(int i=1;i<=5;i++)//前五名
    cout<<stu[i].num<<" "<<(stu[i].chn+stu[i].mat+stu[i].eng)<<endl;
    return 0;
}

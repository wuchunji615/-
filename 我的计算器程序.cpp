#include <stdio.h>
#include <string.h>

struct student
{
    int number;//学号
    double sum;//三门课的总成绩
    double average;//三门课的平均分
    char name[20];//学生姓名
    double score[3];//三门课的成绩
};

student students[3];

double ave1=0,ave2=0,ave3=0;//学生的每门课的平均分

void input()//输入3个学生的信息的函数
{
    int i,j;
    for(i=0;i<3;i++)
    { 
       scanf("%d",&students[i].number);//输入学号
       scanf("%s",students[i].name);//输入姓名
       for(j=0;j<3;j++) scanf("%lf",&students[i].score[j]);//输入三门成绩
    }
}

void average1()//求每个学生的三门课的平均分
{
    int k,j;
    for(k=0;k<3;k++)//先计算总分再将总分除3 
    {
       students[k].sum=0;
       for(j=0;j<3;j++){
       	students[k].sum=students[k].score[j]+students[k].sum;
	   }
       students[k].average=students[k].sum/3;
    }
}

void average2()//求每个学生每门课的平均分
{
    int i;
    for(i=0;i<3;i++)//将每门课三个学生的分数相加 
    {
       ave1=ave1+students[i].score[0];
       ave2=ave2+students[i].score[1];
       ave3=ave3+students[i].score[2];
    }
    ave1=ave1/3;
    ave2=ave2/3;
    ave3=ave3/3;
}

void scort()//按平均分排序
{
    int i,j,k;
    student st;
    for(i=0;i<2;i++)//选择法排序   第一轮将分数最高的学生放在第一位，第二轮将剩下两个学生中分数最高的放在第二位 
    {
       k=i;
       for(j=i+1;j<3;j++)
         if(students[j].average>students[k].average) k=j;
         if(i!=k)
         {
             st=students[i];
             students[i]=students[k];
             students[k]=st;
         }
    }
}

void output()//输出信息
{
    int i,j;
    printf("\n");
    printf("第一门课程的学生的平均成绩:%0.2lf\n",ave1);
    printf("第二门课程的学生的平均成绩:%0.2lf\n",ave2);
    printf("第三门课程的学生的平均成绩:%0.2lf\n",ave3);
    printf("排名如下:\n");
    printf("\n");
    for(i=0;i<3;i++)
    {
      printf("名次 %d",i+1);
      printf("学生学号:%d 学生姓名:%s 三门课的平均分:%0.2lf\n",students[i].number,students[i].name,students[i].average);
      printf("三门课的总分是:%0.2lf\n",students[i].sum);
      printf("三门课的成绩是: ");
      for(j=0;j<3;j++)
      {
        printf("%0.2lf ",students[i].score[j]);
      }
      printf("\n\n");
    }
}

int main()
{
    printf("请输入三名学生的学号，姓名，三门课的成绩\n");
    input();
    average1();
    average2();
    scort();
    output();
}

#include <stdio.h>
#include <string.h>

struct student
{
    int number;//ѧ��
    double sum;//���ſε��ܳɼ�
    double average;//���ſε�ƽ����
    char name[20];//ѧ������
    double score[3];//���ſεĳɼ�
};

student students[3];

double ave1=0,ave2=0,ave3=0;//ѧ����ÿ�ſε�ƽ����

void input()//����3��ѧ������Ϣ�ĺ���
{
    int i,j;
    for(i=0;i<3;i++)
    { 
       scanf("%d",&students[i].number);//����ѧ��
       scanf("%s",students[i].name);//��������
       for(j=0;j<3;j++) scanf("%lf",&students[i].score[j]);//�������ųɼ�
    }
}

void average1()//��ÿ��ѧ�������ſε�ƽ����
{
    int k,j;
    for(k=0;k<3;k++)//�ȼ����ܷ��ٽ��ֳܷ�3 
    {
       students[k].sum=0;
       for(j=0;j<3;j++){
       	students[k].sum=students[k].score[j]+students[k].sum;
	   }
       students[k].average=students[k].sum/3;
    }
}

void average2()//��ÿ��ѧ��ÿ�ſε�ƽ����
{
    int i;
    for(i=0;i<3;i++)//��ÿ�ſ�����ѧ���ķ������ 
    {
       ave1=ave1+students[i].score[0];
       ave2=ave2+students[i].score[1];
       ave3=ave3+students[i].score[2];
    }
    ave1=ave1/3;
    ave2=ave2/3;
    ave3=ave3/3;
}

void scort()//��ƽ��������
{
    int i,j,k;
    student st;
    for(i=0;i<2;i++)//ѡ������   ��һ�ֽ�������ߵ�ѧ�����ڵ�һλ���ڶ��ֽ�ʣ������ѧ���з�����ߵķ��ڵڶ�λ 
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

void output()//�����Ϣ
{
    int i,j;
    printf("\n");
    printf("��һ�ſγ̵�ѧ����ƽ���ɼ�:%0.2lf\n",ave1);
    printf("�ڶ��ſγ̵�ѧ����ƽ���ɼ�:%0.2lf\n",ave2);
    printf("�����ſγ̵�ѧ����ƽ���ɼ�:%0.2lf\n",ave3);
    printf("��������:\n");
    printf("\n");
    for(i=0;i<3;i++)
    {
      printf("���� %d",i+1);
      printf("ѧ��ѧ��:%d ѧ������:%s ���ſε�ƽ����:%0.2lf\n",students[i].number,students[i].name,students[i].average);
      printf("���ſε��ܷ���:%0.2lf\n",students[i].sum);
      printf("���ſεĳɼ���: ");
      for(j=0;j<3;j++)
      {
        printf("%0.2lf ",students[i].score[j]);
      }
      printf("\n\n");
    }
}

int main()
{
    printf("����������ѧ����ѧ�ţ����������ſεĳɼ�\n");
    input();
    average1();
    average2();
    scort();
    output();
}

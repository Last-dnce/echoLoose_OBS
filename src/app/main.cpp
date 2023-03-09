#include "shuzhu.h"

int main()
{

	int number = 0;
	int leap = 0;
	time_t t0 = 0, t = 0, inter = 1;//上一历元t0;当前历元t;采样间隔（inter）
	char infile[100] = {};
	strcpy(infile,"20220312.obs");
	
	FILE* fp;
	gtime_t time = { 0 };
	char buff[MAXRNXLEN];
	fp = fopen(infile, "r");
	int flag = 11;

	if (0<flag<2||flag>10) {
		int xx = -1;
	}

	while (fgets(buff, MAXRNXLEN, fp))
	{
		char dest1[] = { ">" };
		char dest2[8] = { "" };

		strncpy(dest2, buff, 1);//
	
		if (!strcmp(dest1, dest2))//判断每一行第一个字符dest2是否为 >;若是，则执行以下代码
		{
			
			str2time(buff, 2, 27, &time, 1);//获取时间，将时间转换为以秒为单位
			t = time.time + time.sec;

			if (flag == 1) { t0 = t; flag = 0; continue; }//给t0赋初值

			if (abs(t - (t0 + inter))<=0.001)//如果当前历元(t)等于前一历元(t0)加采样间隔(inter)
			{ 
				t0 = t;
				number++; //历元数
			}
			else//如果当前历元(t)不等于前一历元(t0)加采样间隔(inter)
			{
				double ep[6];
				time2epoch(time,ep);//将时间转换为年月日时分秒
				for (int i = 0; i < 6; i++)
				{
					printf("%f ",ep[i]);//输出缺失历元的下一历元，便于查看缺失历元位置
				}
				printf("\n");
				
				t0 = t;
				leap++;
			}
			
			
		}

	}
	printf("All of echo:%d \n",number);
	printf("leap:%d \n",leap);
	int xx = -1;
}
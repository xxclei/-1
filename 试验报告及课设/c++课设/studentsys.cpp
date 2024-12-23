#include<fstream>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<vector>
#include <windows.h>
using namespace std;
class score
{protected:
	
	double Chinese_score;
	double math_score;
	double english_score;
	double score_number;
	double average;
	double sum;
	double class_number;
public:
	void virtual accumulate()
	{
		sum=Chinese_score+math_score+english_score;
		average=sum/3;
	}
	
};


class student_member:public score
	{	private:
	int num;
	char sex;
	int class_rank;
	string name;
	friend class Student_list;
public:
	student_member(double n=0,string na=0,char s=0,double c=0,double m=0,double e=0)
	{	num=n;
		name=na;
		Chinese_score=c;
		math_score=m;
		english_score=e;
		sex=s;
		accumulate();
	}
	
	
	
} ;


 
class Student_list
{	    
public:
	void accumulate_studentrank(score* s)
		{s->accumulate();
			
		}
	void setcolor_red(){
	_wsystem(L"color 04");
	}
	void setcolor_green(){
		_wsystem(L"color 0a");
	}
	void setcolor_black(){
		_wsystem(L"color 00");
	}
	void setcolor_blue(){
		_wsystem(L"color 01");
	}
	void regist()
	{
		string username;
		string password;
		ofstream regist(".login.txt",fstream::app);
	int loginway;
	cout<<"输入用户名:" ;
	cin>>username;
	cout<<"密码:" ;
	
	cin>>password;
	cout<<"选择注册方式:" <<"\t\t【1】学生"<<"\t\t"<<"【2】教师"<<"\t\t"<<"【3】管理员"<<endl;
	cin>>loginway;
	loginperson=loginway;
	regist.seekp(0,ios::end);
	regist<<loginway<<endl;
	regist<<username<<endl;
	regist<<password<<endl;
	system("cls") ; 
	cout<<"注册成功！"<<endl;
	
	regist.close(); 
}
	
	
	
	
	template<typename T>	//T表示任何可以被cout输出的类型
	void ColorCout(T t, const int ForeColor = 7, const int BackColor = 0)
	{
		//	0 = 黑色	1 = 蓝色	 2 = 绿色	 3 = 浅绿色		 4 = 红色	 5 = 紫色	 6 = 黄色	 7 = 白色
		//	8 = 灰色	9 = 淡蓝色	10 = 淡绿色	11 = 淡浅绿色	12 = 淡红色	13 = 淡紫色	14 = 淡黄色	15 = 亮白色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ForeColor + BackColor * 0x10);
		cout << t;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	
	void showgraphy_Chinese()
	{	int below60=0;
		int o60=0,o70=0,o80=0,o90=0,o100=0;
		for(int i=0;i<=s.size()-1;i++)
		{double sc=s[i]->Chinese_score;
		if(sc<60)
		below60++;
		if(sc>=60&&sc<70)
			o60++;
		if(sc>=70&&sc<80)
			o70++;
		if(sc>=80&&sc<90)
			o80++;
		if(sc>=90&&sc<100)
			o90++;
		if(sc==100)
				o100++;
		}
		
		int m=max({below60,o60,o70,o80,o90,o100});
		cout<<"        语文成绩分布图："<<endl;
		cout<<below60<<"人   "<<o60<<"人    "<<o70<<"人    "<<o80<<"人    "<<o90<<"人    "<<o100<<"人    "<<endl;
		for(int i=m;i>=1;i--)
		{	
			bool draw;
			
			for(int j=1;j<=12;j++)
			{if(j%2==0)
			{cout<<"     ";
				continue;}
			
			else
				{draw=0;
				if(below60==i&&j==1)
				{ColorCout("**",12,12);below60--;
				draw=1;}
				if(o60==i&&j==3)
				{ColorCout("**",12,12);o60--;
				draw=1;}
				if(o70==i&&j==5)
				{ColorCout("**",12,12);o70--;
				draw=1;}
				if(o80==i&&j==7)
				{ColorCout("**",12,12);o80--;
				draw=1;}
				if(o90==i&&j==9)
				{ColorCout("**",12,12);o90--;
				draw=1;}
				if(o100==i&&j==11)
				{ColorCout("**",12,12);o100--;
				draw=1;}
				if(draw==0)
					cout<<"  ";
				}
			
			}
			cout<<endl;}
		
			cout<<"<60  60-70  70-80  80-90  90-100  100"<<endl;
				
				
			}
	void showgraohy_math()
	{	int below60=0;
		int o60=0,o70=0,o80=0,o90=0,o100=0;
		for(int i=0;i<=s.size()-1;i++)
		{double sc=s[i]->math_score;
			if(sc<60)
				below60++;
			if(sc>=60&&sc<70)
				o60++;
			if(sc>=70&&sc<80)
				o70++;
			if(sc>=80&&sc<90)
				o80++;
			if(sc>=90&&sc<100)
				o90++;
			if(sc==100)
				o100++;
		}
		
		int m=max({below60,o60,o70,o80,o90,o100});
		cout<<"        数学成绩分布图："<<endl;
		cout<<below60<<"人   "<<o60<<"人    "<<o70<<"人    "<<o80<<"人    "<<o90<<"人    "<<o100<<"人    "<<endl;
		for(int i=m;i>=1;i--)
		{	
			bool draw;
			
			for(int j=1;j<=12;j++)
			{if(j%2==0)
			{cout<<"     ";
				continue;}
				
				else
				{draw=0;
					if(below60==i&&j==1)
					{ColorCout("**",12,12);below60--;
						draw=1;}
					if(o60==i&&j==3)
					{ColorCout("**",12,12);o60--;
						draw=1;}
					if(o70==i&&j==5)
					{ColorCout("**",12,12);o70--;
						draw=1;}
					if(o80==i&&j==7)
					{ColorCout("**",12,12);o80--;
						draw=1;}
					if(o90==i&&j==9)
					{ColorCout("**",12,12);o90--;
						draw=1;}
					if(o100==i&&j==11)
					{ColorCout("**",12,12);o100--;
						draw=1;}
					if(draw==0)
						cout<<"  ";
				}
				
			}
			cout<<endl;}
		
		cout<<"<60  60-70  70-80  80-90  90-100  100"<<endl;
		
		
	}
	void showgraohy_english()
	{	int below60=0;
		int o60=0,o70=0,o80=0,o90=0,o100=0;
		for(int i=0;i<=s.size()-1;i++)
		{double sc=s[i]->english_score;
			if(sc<60)
				below60++;
			if(sc>=60&&sc<70)
				o60++;
			if(sc>=70&&sc<80)
				o70++;
			if(sc>=80&&sc<90)
				o80++;
			if(sc>=90&&sc<100)
				o90++;
			if(sc==100)
				o100++;
		}
		
		int m=max({below60,o60,o70,o80,o90,o100});
		cout<<"        英语成绩分布图："<<endl;
		cout<<below60<<"人   "<<o60<<"人    "<<o70<<"人    "<<o80<<"人    "<<o90<<"人    "<<o100<<"人    "<<endl;
		for(int i=m;i>=1;i--)
		{	
			bool draw;
			
			for(int j=1;j<=12;j++)
			{if(j%2==0)
			{cout<<"     ";
				continue;}
				
				else
				{draw=0;
					if(below60==i&&j==1)
					{ColorCout("**",12,12);below60--;
						draw=1;}
					if(o60==i&&j==3)
					{ColorCout("**",12,12);o60--;
						draw=1;}
					if(o70==i&&j==5)
					{ColorCout("**",12,12);o70--;
						draw=1;}
					if(o80==i&&j==7)
					{ColorCout("**",12,12);o80--;
						draw=1;}
					if(o90==i&&j==9)
					{ColorCout("**",12,12);o90--;
						draw=1;}
					if(o100==i&&j==11)
					{ColorCout("**",12,12);o100--;
						draw=1;}
					if(draw==0)
						cout<<"  ";
				}
				
			}
			cout<<endl;}
		
		cout<<"<60  60-70  70-80  80-90  90-100  100"<<endl;
		
		
	}	
	
	
		
		
	
		
		
		
		
	
	
	
	void show_student(int n)
	{	s[n]->accumulate();
		cout<<"姓名:"<<s[n]->name<<" "<<"学号:"<<s[n]->num<<" "<<"性别"<<" "<<s[n]->sex<<endl;
		cout<<"语文成绩:";
		if(s[n]->Chinese_score<60)
			ColorCout(s[n]->Chinese_score,4);
		else
		cout<<s[n]->Chinese_score;
		setcolor_black();
		cout<<" "<<"数学成绩:";
		if(s[n]->math_score<60)
			ColorCout(s[n]->math_score,4);
		else
		cout<<s[n]->math_score;
		setcolor_black();
		cout<<" "<<"英语成绩:";
		if(s[n]->english_score<60)
		{ColorCout(s[n]->english_score,4);cout<<endl;}
		else
		cout<<s[n]->english_score<<endl;
		setcolor_black();
		s[n]->accumulate();
		cout<<"总分为:"<<s[n]->sum<<" "<<"平均分为:";
		if(s[n]->average<60)
		{ColorCout(s[n]->average,4);
		cout<<endl;	}
		else
		cout<<s[n]->average<<endl;
		setcolor_black();
		cout<<"总分排名为："<<s[n]->class_rank<<endl;
		
	}
	void errorshow()
	{cout<<"             输入错误，请重新输入！";
		
	}
	
		void acuumulate_60percent_averagescore()
	{	double csum=0;
		double cbelow60=0;
		double msum=0;
		double mbelow60=0;
		double esum=0;
		double ebelow60=0;
		for(int i=0;i<=s.size()-1;i++)
	{	csum+=s[i]->Chinese_score;
		if(s[i]->Chinese_score<60)
			cbelow60++;
		msum+=s[i]->math_score;
			if(s[i]->math_score<60)
				mbelow60++;
		esum+=s[i]->english_score;
			if(s[i]->english_score<60)
				ebelow60++;

	}
		double caverage=csum/s.size();
		double maverage=msum/s.size();
		double eaverage=esum/s.size();
		
		double cbelow=cbelow60/s.size();
		double mbelow=mbelow60/s.size();
		double ebelow=ebelow60/s.size();
		cout<<fixed<<setprecision(1);
		_wsystem(L"color 00");
		cout<<"语文平均分为:"<<caverage<<" "<<"合格率为"<<(1-cbelow)*100<<"%"<<endl;
		cout<<"数学平均分为:"<<maverage<<" "<<"合格率为"<<(1-mbelow)*100<<"%"<<endl;
		cout<<"英语平均分为:"<<eaverage<<" "<<"合格率为"<<(1-ebelow)*100<<"%"<<endl;
		cout<<"(均保留了一位小数)"<<endl<<endl;
		
		
	}
	
	int name_search(string name)	//按姓名检索
	{for(int i=0;i<=s.size()-1;i++)
		{if(s[i]->name==name)
			return i;
		}	
		return -1;
	}
	
	int name_search(int num)	//按学号检索
	{for(int i=0;i<=s.size()-1;i++)
	{if(s[i]->num==num)
		return i;
	}	
		return -1;
	}
	
	static int loginperson;
	void newstudent()
	{	int newnum;
		string newname;
		char newsex;
		double chscore;
		double mascore;
		double enscore;
		cout<<"输入学生姓名"<<endl;
		cin>>newname;
		cout<<"输入学生性别(F或M)"<<endl;
		sexagain:
		cin>>newsex;
		if(newsex!='F'&&newsex!='M')
		{cout<<"输入错误！ 请重新输入"<<endl;
		goto sexagain;}
		cout<<"输入学生学号"<<endl;
		cin>>newnum;
		cout<<"输入学生语文成绩"<<endl;
		cin>>chscore;
		cout<<"输入学生数学成绩"<<endl;
		cin>>mascore;
		cout<<"输入学生英语成绩"<<endl;
		cin>>enscore;
		s.push_back(new student_member(newnum,newname,newsex,chscore,mascore,enscore));
		fstream stuo(".student.txt");
		stuo.seekp(0,ios::end);
		stuo<<newnum<<" "<<newname<<" "<<newsex<< " "<<chscore<<" "<<mascore<<" "<<enscore<<endl;
		system("cls");
		cout<<"录入成功!"<<endl;
		int conti=0;
		cout<<"【1】继续使用        【2】结束运行"<<endl;
		cin>>conti;
		if(conti==2)
		{exit;}
		else;
		system("cls");
		select(loginperson);
//		for(long long unsigned int n=0;n<=s.size()-1;n++)
//		{cout<<s[n]->num<<endl;}
		
	}
	
	void show_all_student()
	{for(long long unsigned int i=0;i<=s.size()-1;i++)
		{show_student(i);
		cout<<endl;
		
		}
		
	}
	
	void fileread()
	{	s.resize(0);
		ifstream stu(".student.txt",fstream::app);
	while(stu>>tempn>>tempna>>temps>>tempc>>tempm>>tempe){

//	cout<<tempn<<" "<<tempna<<" "<<temps<<" "<<tempc<<" "<<tempm<<" "<<tempe<<endl;
		s.push_back(new student_member(tempn,tempna,temps,tempc,tempm,tempe));
		
		
	}
//		cout<<s.size();
	}
		
	static 	bool cmp_sum(student_member* a,student_member* b)
	{	int asum=a->sum;
		int bsum=b->sum;
		return asum>bsum;}
	void student_sort_sum()
	{
		sort(s.begin(),s.end(),cmp_sum);
		for(int i=0;i<=s.size()-1;i++)
		{s[i]->class_rank=i+1;}
	}
		
	
	void select(int n,int num=0)
	{system("cls");
		
		
		if(n==1)
		{cout<<"您目前的身份是学生"<<endl<<endl;
			cout<<"您的信息如下";
			student_sort_sum();
			show_student(name_search(num));
			int conti=0;
			cout<<"【1】退出登录        【2】结束运行"<<endl;
			cin>>conti;
			if(conti==2)
			{return;}
			else
			system("cls");
			login();
		}
		if(n==2)
		{	while(1)
		{	
			cout<<"                          您目前的身份是教师"<<endl;
			cout<<endl;
		ColorCout("                     -----------------------------",10,0);
			cout<<endl;
			cout<<"                     |      请选择如下功能        |"        <<endl;
		ColorCout("                     -----------------------------",10,0);
			cout<<endl;
			cout<<"                    | 【0】"<<"显示所有学生记录       |"<<endl;
			cout<<"                    | 【1】"<<"新增学生记录           |"<<endl;
			cout<<"                    | 【2】"<<"删除学生记录           |"<<endl;
			cout<<"                    | 【3】"<<"检索学生及成绩和排名   |"<<endl;
			cout<<"                    | 【4】"<<"查看各科平均分及及格率 |"<<endl;
			cout<<"                    | 【5】"<<"统计各科分数柱形图     |"<<endl;
			cout<<"                    | 【6】"<<"退出登录               |"<<endl;
		ColorCout("                    -------------------------------",10,0);
			cout<<endl;
			student_sort_sum();
			int choose=0;
			cin>>choose;
			if(choose==0)
			{	system("cls");
				cout<<endl<<"查询结果"<<endl;
				show_all_student();
				int conti=0;
				cout<<"【1】继续使用        【2】结束运行"<<endl;
				cin>>conti;
				if(conti==2)
				{exit;}
				else;
				system("cls");}
			if(choose==1)
			{newstudent();
				system("cls");
				cout<<"新建成功!"<<endl;
			}
			if(choose==2)
			{system("cls");
				int mode;
				cout<<"以哪种方式为索引删除"<<endl;
				cout<<"【1】以姓名检索"<<endl;
				cout<<"【2】以学号检索"<<endl;
				cin>>mode;
				if(mode==1)
				{	system("cls");
					string namesearch; 
					cout<<"请输入姓名"<<endl;
					cin>>namesearch;
					if(name_search(namesearch)!=-1)
					{delete s[name_search(namesearch)];
						s.erase(s.begin()+name_search(namesearch));
						cout<<"删除成功"<<endl;
					}
					
					else
						cout<<"检索学生不存在";
					cout<<endl;
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit;}
					else;
					system("cls");
				}
				if(mode==2)
				{	system("cls");
					int num; 
					cout<<"请输入学号"<<endl;
					cin>>num;
					if(name_search(num)!=-1)
					{delete s[name_search(num)];
						s.erase(s.begin()+name_search(num));
						cout<<"删除成功"<<endl;
					}
					
					else
						cout<<"检索学生不存在";
					cout<<endl;
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit;}
					else;
					system("cls");
				}
				
			}
			if(choose==3)
			{int mode;
				system("cls");
				cout<<"以哪种方式检索"<<endl;
				cout<<"【1】以姓名检索"<<endl;
				cout<<"【2】以学号检索"<<endl;
				cin>>mode;
				if(mode==1)
				{	system("cls");
					string namesearch; 
					cout<<"请输入姓名"<<endl;
					cin>>namesearch;
					if(name_search(namesearch)!=-1)
					{cout<<"检索成功！"<<endl;
						cout<<endl<<"查询结果"<<endl;
						show_student(name_search(namesearch));
					}
					
					else
						cout<<"检索学生不存在";
					cout<<endl;
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit;}
					else;
					system("cls");
				}
				if(mode==2)
				{	system("cls");
					int num; 
					cout<<"请输入学号"<<endl;
					cin>>num;
					if(name_search(num)!=-1)
					{cout<<"检索成功！"<<endl;
						cout<<endl<<"查询结果"<<endl;
						show_student(name_search(num));
					}
					
					else
						cout<<"检索学生不存在";
					cout<<endl;
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit(0);}
					else;
					system("cls");
				}
				
				
			}
			if(choose==4)
			{system("cls");
				acuumulate_60percent_averagescore();
				int conti=0;
				cout<<"【1】继续使用        【2】结束运行"<<endl;
				cin>>conti;
				if(conti==2)
				{exit;}
				else;
				system("cls");
			}
			if(choose==5)
			{system("cls");
			showgraphy_Chinese();
			cout<<endl;
			showgraohy_math();
			cout<<endl;
			showgraohy_english();
				cout<<endl;
				int conti=0;
				cout<<"【1】继续使用        【2】结束运行"<<endl;
				cin>>conti;
				if(conti==2)
				{exit(0);}
				else;
				system("cls");
			}
			if(choose==6)
			{system("cls");
				login();}
			
		}
			
		}	
		if(n==3)
		{	while(1)
		{	
			cout<<"                           您目前的身份是管理员"<<endl;
			
		ColorCout("                     -----------------------------",10,0);
			cout<<endl;
			cout<<"                     |      请选择如下功能        |"        <<endl;
		ColorCout("                     -----------------------------",10,0);
			cout<<endl;
			cout<<"                    | 【0】"<<"显示所有学生记录       |"<<endl;
			cout<<"                    | 【1】"<<"新增学生记录           |"<<endl;
			cout<<"                    | 【2】"<<"删除学生记录           |"<<endl;
			cout<<"                    | 【3】"<<"检索学生及成绩和排名   |"<<endl;
			cout<<"                    | 【4】"<<"查看各科平均分及及格率 |"<<endl;
			cout<<"                    | 【5】"<<"添加教师或管理员用户   |"<<endl;
			cout<<"                    | 【6】"<<"统计各科分数柱形图     |"<<endl;
			cout<<"                    | 【7】"<<"退出登录               |"<<endl;
		ColorCout("                    -------------------------------",10,0);
			cout<<endl;
			
				student_sort_sum();
				int choose=0;
				cin>>choose;
				if(choose==0)
				{	system("cls");
					cout<<endl<<"查询结果"<<endl;
					show_all_student();
				int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit;}
					else;
					system("cls");}
				if(choose==1)
					{newstudent();
					system("cls");
					cout<<"新建成功!"<<endl;
					}
				if(choose==2)
					{system("cls");
					int mode;
					cout<<"以哪种方式为索引删除"<<endl;
					cout<<"【1】以姓名检索"<<endl;
					cout<<"【2】以学号检索"<<endl;
					cin>>mode;
						if(mode==1)
						{	system("cls");
							string namesearch; 
							cout<<"请输入姓名"<<endl;
							cin>>namesearch;
							if(name_search(namesearch)!=-1)
							{delete s[name_search(namesearch)];
							s.erase(s.begin()+name_search(namesearch));
							cout<<"删除成功"<<endl;
							}
							
							else
								cout<<"检索学生不存在";
							cout<<endl;
							int conti=0;
							cout<<"【1】继续使用        【2】结束运行"<<endl;
							cin>>conti;
							if(conti==2)
							{exit;}
							else;
							system("cls");
						}
					if(mode==2)
					{	system("cls");
						int num; 
						cout<<"请输入学号"<<endl;
						cin>>num;
						if(name_search(num)!=-1)
						{delete s[name_search(num)];
							s.erase(s.begin()+name_search(num));
							cout<<"删除成功"<<endl;
						}
						
						else
							cout<<"检索学生不存在";
						cout<<endl;
						int conti=0;
						cout<<"【1】继续使用        【2】结束运行"<<endl;
						cin>>conti;
						if(conti==2)
						{exit;}
						else;
						system("cls");
					}
					
					}
				if(choose==3)
				{int mode;
					system("cls");
					cout<<"以哪种方式检索"<<endl;
					cout<<"【1】以姓名检索"<<endl;
					cout<<"【2】以学号检索"<<endl;
						cin>>mode;
						if(mode==1)
						{	system("cls");
							string namesearch; 
							cout<<"请输入姓名"<<endl;
							cin>>namesearch;
							if(name_search(namesearch)!=-1)
							{cout<<"检索成功！"<<endl;
								cout<<endl<<"查询结果"<<endl;
							show_student(name_search(namesearch));
							}
								
							else
							cout<<"检索学生不存在";
							cout<<endl;
							int conti=0;
							cout<<"【1】继续使用        【2】结束运行"<<endl;
							cin>>conti;
							if(conti==2)
							{exit;}
							else;
							system("cls");
						}
					if(mode==2)
					{	system("cls");
						int num; 
						cout<<"请输入学号"<<endl;
						cin>>num;
						if(name_search(num)!=-1)
						{cout<<"检索成功！"<<endl;
							cout<<endl<<"查询结果"<<endl;
							show_student(name_search(num));
						}
						
						else
							cout<<"检索学生不存在";
						cout<<endl;
						int conti=0;
						cout<<"【1】继续使用        【2】结束运行"<<endl;
						cin>>conti;
						if(conti==2)
						{exit;}
						else;
						system("cls");
					}
					
					
				}
				if(choose==4)
				{system("cls");
					acuumulate_60percent_averagescore();
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{exit;}
					else;
					system("cls");
				}
				if(choose==5)
				{	system("cls");
					regist();
					int conti=0;
					cout<<"【1】继续使用        【2】结束运行"<<endl;
					cin>>conti;
					if(conti==2)
					{return;}
					else
					system("cls");	
				}
			if(choose==6)
			{system("cls");
				showgraphy_Chinese();
				cout<<endl;
				showgraohy_math();
				cout<<endl;
				showgraohy_english();
				cout<<endl;
				int conti=0;
				cout<<"【1】继续使用        【2】结束运行"<<endl;
				cin>>conti;
				if(conti==2)
				{exit(0);}
				else;
				system("cls");
			}
				if(choose==7)
				{system("cls");
				login();}
				
			}
			
		}
		
	}
	
	void login()//登录系统
	{
		cout<<"                                          欢迎您进入学籍管理系统！"<<endl<<endl;
		string username;
		ofstream regist(".login.txt",fstream::app);
		
		string password;
		again: 
	ColorCout("                    ---------------------------------------------------------------------",10,0);
		cout<<endl;
		cout<<"                    | 请选择登陆方式                                                     |"<<endl;
		cout<<"                    |【1】学生登录               (学生登录默认用户名为学号，密码为123456)|"<<endl;
		cout<<"                    |【2】教师登录或管理员登录   (身份自动识别)                          |"<<endl;
		cout<<"                    |【3】退出使用                                                       |"<<endl;
	ColorCout("                    ---------------------------------------------------------------------",10,0);
  cout<<endl<<"                                                      ";
		//	0 = 黑色	1 = 蓝色	 2 = 绿色	 3 = 浅绿色		 4 = 红色	 5 = 紫色	 6 = 黄色	 7 = 白色
		//	8 = 灰色	9 = 淡蓝色	10 = 淡绿色	11 = 淡浅绿色	12 = 淡红色	13 = 淡紫色	14 = 淡黄色	15 = 亮白色
		int login_way;
		cin>>login_way;
		system("cls") ;
		if(login_way==3)
		{	cout<<"感谢您的使用！";
			exit(0);
			return;
		}
		if(login_way!=1&&login_way!=2&&login_way!=3)
		{errorshow();
			cout<<endl;
			int conti=0;
			cout<<"按任意键重新登录"<<endl;
			cin>>conti;
			system("cls");
			login();
		}
		
		
//		if(login_way==0)
//		{	int loginway;
//			cout<<"输入用户名:" ;
//			cin>>username;
//			cout<<"密码:" ;
//			
//			cin>>password;
//			cout<<"选择注册方式:" <<"\t\t【1】学生"<<"\t\t"<<"【2】教师"<<"\t\t"<<"【3】管理员"<<endl;
//			cin>>loginway;
//			loginperson=loginway;
//			regist.seekp(0,ios::end);
//			regist<<loginway<<endl;
//			regist<<username<<endl;
//			regist<<password<<endl;
//			
//			regist.close(); 
//			
//			
//			system("cls") ; 
//			cout<<"注册成功！"<<endl;
//			goto again;
//		}
//		else
		{
			
			ifstream login(".login.txt");
			string a[200];
			int i=0;
			
			while(login)
			{
				
				getline(login,a[i++]);
			}
			
			fileread();
			cout<<"输入用户名:" ;
			cin>>username;
			cout<<"密码:" ;
			cin>>password;
			login.close();
			
			int login_success=0;
			if(login_way==1)
			{for(int i=0;i<=s.size()-1;i++)
				{
				int number = (int)strtol(username.c_str(), nullptr, 10);
					if(s[i]->num==number)
					{	if(password=="123456")
						select(1,number);
		
					}
				}
				
			}
			
			else{
			for(int j=0;j<=i-2;j+=3)//核实密码是否正确
			{
				if(a[j+1]==username)
					if(a[j+2]==password)
					{
						cout<<"登录成功"<<"     您的身份为";
					
//						if(a[j]=="1")
//						{cout<<"学生";
//							loginperson=1;
//							
//							int number = (int)strtol(a[j+1].c_str(), nullptr, 10);
//							select(1,number);
//						}
						if(a[j]=="2")
						{cout<<"教师";
							loginperson=2;
							select(2);
						}
						if(a[j]=="3")
						{cout<<"管理员";	
							loginperson=3;
							select(3);
						}
						login_success=1;
						
					}
				
				
				
			}
			}
			if(login_success==0)//输入错误的处理		 
			{system("cls");
				ColorCout("                                  账号或密码错误，请输入正确的账号和密码！！！",4,0);
				cout<<endl;
				goto again;
				
			}
		}
	}
	private: 
	vector<student_member*> s;
	int tempn,tempc,tempm,tempe;
	string tempna;
	char temps;
	
	
};
int Student_list::loginperson=0;
int main()


{	ofstream regist(".login.txt",fstream::app);
	regist.seekp(0,ios::end);
	regist<<3<<endl;
	regist<<123<<endl;
	regist<<123<<endl;
	//默认添加初始管理员用户
	Student_list list;
	
	list.login();

	return 0;
	
}	


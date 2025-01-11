Java.lo.BufferedReader :Import
Importjava.io,I0Exception;
import java.io.InputStreamReader;
public class adressadvant {
public static void main(String[] args)throws I0Exception {
int memory =0;
int pagesize =0;
int pagen =0;
int n =0;
int adresslo =0;
int adressp =0;
int adressw =0;
int adressc =0;
int x=0;
int again1= 0;
0:again2int=
int again3 = 0;
BufferedReader buf;
String str;
int i =0;
int j = 0;
int k =0;
int max =50;
int[] pglist = new int[50];
for(i=0;i<max; i++){pglist[i] = 0;

    System.ut.
欢迎使用页式存储系统地址转换模拟软件\
d0
co i
buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("请输入内存大小\n\r");str = buf.readLine();
memory = Integer.parseInt(str);buf = new BufferedReader(new InputStreamReader(System.in));5ystem.out.print("请输入内存页面大小\r”);
str = buf.readLine();
pagesize = Integer.parseInt(str),}while((memory % pagesize)!=0);
pagen = memory/pagesize:5ystem.out.println("则内存页数为”+pagen);do buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("\n\r请输入进程块号数目n(页号:0,1,2，，必须小于内存页面数\n\r"):。n-2.n-1)
str = buf.readLine();
n = Integer.parseInt(str);
}while(n>= pagen;System,out.print("现在正在生成随机页表。。。\n\r")for(i =0;i<n; i+{pglist[i]=(int)Math.floor((Math.random()*(pagen -1))+ 1);for(j=0;j<i;j++){if(pglist[j] == pglist[i]){]--:
System.out.print("生成随机页表成功，如下所示\n\r");System.out.print("--页号--------页面号--\n\r");for(k=0:k<n:k++)

System.out.println(".+ pglist[k]"\nr";buf - new BufferedReader(new InputStreamReader(System.in));System.out.print("随机页表已生成，是否重新生成yes-0/no-1:\n\r");str - buf.readLine(),again2- Integer.parseInt(str);while((x!-0)&&(x1-1))buf = new BufferedReader(new InputStreamReader(System.in));5ystem.out.print("输入有误，请请选择是否重新生成yes-0/no-1:\n\r");str = buf.readLineo;
again2 = Integer.parseInt(str);
}while(again2 == 0);do {
buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("请选择输入逻辑地址的数制(十进制:1(直接输入):十六进制:2(字母小写))\n\r");
str = buf.readLine();
x= Integer.parseInt(str);
while((x!-1)&&(x!-2)){
buf - new BufferedReader(new InputStreamReader(System.in));
System.out.print(
"输入有误，请请选择输入逻辑地址的数制(十进制:1(直接输入);十六进制:2(字母小写))\n\r")
str - buf.readLine(,
x- Integer.parseInt(str);
1f(x=1){buf = new BufferedReader(new InputStreamReader(System.in));5ystem.out.print("请输入逻辑地址\\r");
str = buf.readLine(;
adresslo = Integer.parseInt(str),while(adresslo>=(n*pagesize)){buf = new BufferedReader(new InputStreamReader(Svstem.in)):System.out.print("地址非法，请重新输入逻辑地址\n\r");str = buf.readLine),adresslo - Integer.parseInt(str);

whlle (adresslo >=
(n - Daqes1ze)
buf = new BufferedReader(new InputStreamReader(System.in);System.out.print("地址非法，请重新输入逻辑地址\n\r");str = buf.readLine);
adresslo=Integer.parseInt(str);
= adresslo /pagesize,adressp
adresswadresslo % pagesize,
adressc =(pglist[adressp]*pagesize)+ adressw;
System.out.print("对应的物理地址为-(十进制)-:"+ adressc);
System.out.print("\n\r对应的物理地址为-(十六进制)-:Integer.toHexString(adressc)),
else if(x==2){
buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("请输入逻辑地址\n\r");str = buf.readLine;adresslo= Integer.parseInt(str,16),
while(adresslo>(n*pagesize)){buf = new BufferedReader(new InputStreamReader(System.in)),System.out.print("地址非法，请重新输入逻辑地址\n\r");str = buf.readLine();adresslo=Integer.parseInt(str,16);
adressp =adresslo/pagesize,
adressw=adresslo %pagesize;
adressc=(pglist[adressp*pagesize)+ adressw;
System.out.print("对应的物理地址为-(十进制)-:"+ adressc);

System.out.print("\n\r对应的物理地址为-
十六进制)
Integer.toHexString(adressc，
buf = new BufferedReader(new InputStreamReader(System.in)),5ystem.out.print("\n\r地址转换已完成，是否再次进行地址转换yes-0/n0-1:\n\r");str= buf.readLine();again3 = Integer.parseInt(str),
while((x!-0)&&(x!-1)){buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("输入有误，请请选择是否进行地址转换yes-0/no-1:\n\r");str = buf.readLine();again3=Integer.parseInt(str);
} while (again3 -- 0);
buf = new BufferedReader(new InputStreamReader(System.in));System.out.print("程序已运行完毕，是否重新运行yes-0/n0-1:\n\r");str = buf.readLine();
again1=Integer.parseInt(str):
while((x!-0)&&(x !- 1)){buf = new BufferedReader(new InputStreamReader(System.in));5ystem.out.print("输入有误，请请选择是否重新运行yes-0/no-1:\n\r");str = buf.readLine();
again1 = Integer.parsent(str),
while(again1 == 0):
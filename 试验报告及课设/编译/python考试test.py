#首先，我们提示用户输入一个三位及以上的整数。然后，通过整数除法来输出该数字的百位及以上的部分。
def a1():
    i=int(input("shu ru yi ge shu"))
    print(i//100)

#编写程序，生成包含1000个0至100之间的随机整数，并统计每个元素的出现次数
# import random
# from collections import Counter
# r=[random.randint(0,100) for _ in range(0,10000)]
# print(Counter(r))


#编写程序，生成包含20个随机数的列表，然后将前10个元素升序排列，后10个元素降序排列，并输出结果
import random 
def a3():
    r=[random.random() for _ in range(20)]
    r[10:].sort()
    r[:10].sort(reverse=True)
    print(r)

#例4: 编写程序，用户输入4位整数作为年份，判断其是否为闰年通过判断年份是否能被4整除但不能被100整除，或者能被400整除，来判断该年份是否为闰年。

def a4():
    year=int(input("type in year"))
    if(year%4==0 and year%100!=0)or(year%400==0):
        print("is runyear")
    else:
        print("no")

#例5: 编写程序，用户输入一段英文，然后输出这段英文中所有长度为3个字母的单词
def a5():
    words=input("type in English sentence")
    word=words.split(sep=" ")
    len3word=[w for w in word if len(w)==3]
    print(len3word)

#例6: 编写函数，判断一个整数是否为素数，并编写主程序调用该函数
# import math
# def iso(n):
#     for i in range(2,int(math.sqrt(n))+1):
#         if(n%i==0):
#             return False
#     return True


# print(iso(4))    

#例7: 编写函数，接收一个字符串，统计大写字母、小写字母、数字、其他字符的个数，并以元组的形式返回结果
# def detect_char_type(stri):
#     cap,small,dig,others=0,0,0,0
#     for char in str(stri):
#         if(char.islower()):
#             small+=1
#         if(char.isupper()):
#             cap+=1
#         if(char.isdigit()):
#             dig+=1
#     others=len(stri)-cap-small-dig-others
#     return[cap,small,dig,others]

# print(detect_char_type('SDASDasadas1231[][]'))

        
#例8: 假设有一个英文文本文件，编写程序读取其内容并将其中的大写字母变为小写字母
with open("file.txt",'r') as file :
    content=file.read()
content2s=content.lower()
print(content2s)
    
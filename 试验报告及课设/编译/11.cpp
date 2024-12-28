#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

// 定义枚举类表示Token类型
enum TokenType {
	IF, THEN, ELSE, END, REPEAT, UNTIL, READ, WRITE,
	ID, NUM, ASSIGN, EQUAL, LT, PLUS, MINUS, TIMES, OVER, LPAREN, RPAREN, SEMI,
	ERROR, ENDFILE
};

// Token结构体，存储种类和属性
struct Token {
	TokenType type;
	string attribute;
};

// 保留字表
map<string, TokenType> reservedWords = {
{"if", IF}, {"then", THEN}, {"else", ELSE}, {"end", END},
{"repeat", REPEAT}, {"until", UNTIL}, {"read", READ}, {"write", WRITE}
};

// 读取一个Token，忽略空白符和注释
Token getToken(istringstream& lineStream) {
	char ch;
	string word;
	
	while (lineStream >> ch) {
		if (isspace(ch)) continue;  // 跳过空白符
		
		if (ch == '{') {  // 跳过注释
			while (ch != '}' && lineStream.get(ch));
			continue;
		}
		
		if (isalpha(ch)) {  // 识别标识符或保留字
			word += ch;
			while (lineStream.get(ch) && isalnum(ch)) {
				word += ch;
			}
			lineStream.putback(ch);
			if (reservedWords.find(word) != reservedWords.end()) {
				return { reservedWords[word], word };  // 返回保留字
			} else {
				return { ID, word };  // 返回标识符
			}
		} else if (isdigit(ch)) {  // 识别数字
			word += ch;
			while (lineStream.get(ch) && isdigit(ch)) {
				word += ch;
			}
			lineStream.putback(ch);
			return { NUM, word };  // 返回数字
		} else {
			// 识别特殊符号
			switch (ch) {
				case '+': return { PLUS, "+" };
				case '-': return { MINUS, "-" };
				case '*': return { TIMES, "*" };
				case '/': return { OVER, "/" };
				case '=': return { EQUAL, "=" };
				case '<': return { LT, "<" };
				case '(': return { LPAREN, "(" };
				case ')': return { RPAREN, ")" };
				case ';': return { SEMI, ";" };
				case ':':  // 处理赋值符号 :=
				if (lineStream.get(ch) && ch == '=') {
					return { ASSIGN, ":=" };
				} else {
					lineStream.putback(ch);
					return { ERROR, ":" };
				}
			default:
				return { ERROR, string(1, ch) };  // 返回错误Token
			}
		}
	}
	
	return { ENDFILE, "" };  // 文件结束
}

// 打印Token
void printToken(const Token& token) {
	switch (token.type) {
		case IF: cout << "\t保留字: if\n"; break;
		case THEN: cout << "\t保留字: then\n"; break;
		case ELSE: cout << "\t保留字: else\n"; break;
		case END: cout << "\t保留字: end\n"; break;
		case REPEAT: cout << "\t保留字: repeat\n"; break;
		case UNTIL: cout << "\t保留字: until\n"; break;
		case READ: cout << "\t保留字: read\n"; break;
		case WRITE: cout << "\t保留字: write\n"; break;
		case ID: cout << "\t标识符, 名称: " << token.attribute << "\n"; break;
		case NUM: cout << "\t数字, 值: " << token.attribute << "\n"; break;
		case ASSIGN: cout << "\t赋值符号: :=\n"; break;
		case EQUAL: cout << "\t等号: =\n"; break;
		case LT: cout << "\t小于号: <\n"; break;
		case PLUS: cout << "\t加号: +\n"; break;
		case MINUS: cout << "\t减号: -\n"; break;
		case TIMES: cout << "\t乘号: *\n"; break;
		case OVER: cout << "\t除号: /\n"; break;
		case LPAREN: cout << "\t左括号: (\n"; break;
		case RPAREN: cout << "\t右括号: )\n"; break;
		case SEMI: cout << "\t分号: ;\n"; break;
		case ERROR: cout << "\t错误符号: " << token.attribute << "\n"; break;
		case ENDFILE: cout << "\t文件结束\n"; break;
		default: cout << "\t未知符号\n"; break;
	}
}

// 分析并输出每行源代码
void analyzeLine(const string& line, int lineNumber) {
	cout << "\t第 " << lineNumber << " 行: " << line << endl;  // 带缩进的行输出
	
	istringstream lineStream(line);  // 使用stringstream分析行
	Token token;
	
	while ((token = getToken(lineStream)).type != ENDFILE) {
		printToken(token);
	}
}

int main() {
	ifstream inputFile("test.txt");  // 打开文件
	if (!inputFile) {
		cerr << "无法打开文件!" << endl;
		return 1;
	}
	
	string line;
	int lineNumber = 0;
	
	while (getline(inputFile, line)) {
		lineNumber++;
		analyzeLine(line, lineNumber);  // 分析每行
	}
	
	inputFile.close();  // 关闭文件
	return 0;
}


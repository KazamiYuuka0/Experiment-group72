#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string bth(string str)//二进制转换为十六进制
{
	string hex = "";
	int t = 0;
	while (str.size() % 4 != 0)
	{
		str = "0" + str;
	}
	for (int i = 0; i < str.size(); i += 4)
	{
		t = (str[i] - '0') * 8 + (str[i + 1] - '0') * 4 + (str[i + 2] - '0') * 2 + (str[i + 3] - '0') * 1;
		if (t < 10) {
			hex += to_string(t);
		}
		else 
		{
			hex += 'A' + (t - 10);
		}
	}
	return hex;
}
string htb(string str)//十六进制转换为二进制
{
	string bin = "";
	string table[16] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			bin += table[str[i] - 'A' + 10];
		}
		else
		{
			bin += table[str[i] - '0'];
		}
	}
	return bin;
}
int btd(string str)//二进制转换为十进制
{
	int dec = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		dec += (str[i] - '0') * pow(2, str.size() - i - 1);
	}
	return dec;
}
string dtb(int str)//十进制转换为二进制
{
	string bin = "";
	while (str >= 1) 
	{
		bin = to_string(str % 2) + bin;
		str = str / 2;
	}
	return bin;
}
int htd(string str)//十六进制转换为十进制]
{
	int dec = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		if (str[i] >= 'A' && str[i] <= 'F')
		{
			dec += (str[i] - 'A' + 10) * pow(16, str.size() - i - 1);
		}
		else
		{
			dec += (str[i] - '0') * pow(16, str.size() - i - 1);
		}
	}
	return dec;
}
string dth(int str)//十进制转换为十六进制
{
	string hex = "";
	int temp = 0;
	while (str >= 1) 
	{
		temp = str % 16;
		if (temp < 10 && temp >= 0)
		{
			hex = to_string(temp) + hex;
		}
		else
		{
			hex += ('A' + (temp - 10));
		}
		str = str / 16;
	}
	return hex;
}

string tran(string str)
{
	string a = "";
	for (int i = 0; i < str.size(); i++)
	{
		a += dth((int)str[i]);
	}
	return a;
}

string padding(string str) //填充 
{
	string a = "";
	for (int i = 0; i < str.size(); i++) 
	{
		a += dth((int)str[i]);
	}
	cout << "输入字符串的ASCII码表示为：" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
		if ((i + 1) % 8 == 0) 
		{
			cout << "  ";
		}
		if ((i + 1) % 64 == 0 || (i + 1) == a.size()) 
		{
			cout << endl;
		}
	}
	cout << endl;
	int a_length = a.size() * 4;
	a += "8";
	while (a.size() % 128 != 112) {
		a += "0";
	}
	string a_len = dth(a_length);
	while (a_len.size() != 16) {
		a_len = "0" + a_len;
	}
	a += a_len;
	return a;
}

string padding1(string a)
{
	int a_length = a.size() * 4;
	a += "8";
	while (a.size() % 128 != 112) {
		a += "0";
	}
	string a_len = dth(a_length);
	while (a_len.size() != 16) {
		a_len = "0" + a_len;
	}
	a += a_len;
	return a;
}

string padding2(string str) //填充 
{
	string a = "";
	for (int i = 0; i < str.size(); i++)
	{
		a += dth((int)str[i]);
	}
	//cout << "输入字符串的ASCII码表示为：" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		//cout << a[i];
		if ((i + 1) % 8 == 0)
		{
			//cout << "  ";
		}
		if ((i + 1) % 64 == 0 || (i + 1) == a.size())
		{
			//cout << endl;
		}
	}
	cout << endl;
	int a_length = a.size() * 4;
	a += "8";
	while (a.size() % 128 != 112) {
		a += "0";
	}
	string a_len = dth(a_length);
	while (a_len.size() != 16) {
		a_len = "0" + a_len;
	}
	a += a_len;
	return a;
}

string yw(string str, int len)//移位
{
	string a = htb(str);
	a = a.substr(len) + a.substr(0, len);
	return bth(a);
}

string XOR(string str1, string str2)//异或
{
	string x = htb(str1);
	string y = htb(str2);
	string a = "";
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == y[i])
		{
			a += "0";
		}
		else 
		{
			a += "1";
		}
	}
	return bth(a);
}

string AND(string str1, string str2)//与
{
	string x = htb(str1);
	string y = htb(str2);
	string a = "";
	for (int i = 0; i < x.size(); i++) 
	{
		if (x[i] == '1' && y[i] == '1')
		{
			a += "1";
		}
		else
		{
			a += "0";
		}
	}
	return bth(a);
}

string OR(string str1, string str2)//或 
{
	string x = htb(str1);
	string y = htb(str2);
	string a = "";
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '0' && y[i] == '0') 
		{
			a += "0";
		}
		else 
		{
			a += "1";
		}
	}
	return bth(a);
}

string NOT(string str)//非
{
	string x = htb(str);
	string a = "";
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '0')
		{
			a += "1";
		}
		else 
		{
			a += "0";
		}
	}
	return bth(a);
}

char binXor(char str1, char str2) //单比特异或
{
	return str1 == str2 ? '0' : '1';
}

char binAnd(char str1, char str2)//单比特与
{
	return (str1 == '1' && str2 == '1') ? '1' : '0';
}

string ModAdd(string str1, string str2)//mod 2^32运算
{
	string x = htb(str1);
	string y = htb(str2);
	char t = '0';
	string a = "";
	for (int i = x.size() - 1; i >= 0; i--)
	{
		a = binXor(binXor(x[i], y[i]), t) + a;
		if (binAnd(x[i], y[i]) == '1')
		{
			t = '1';
		}
		else {
			if (binXor(x[i], y[i]) == '1') 
			{
				t = binAnd('1', t);
			}
			else 
			{
				t = '0';
			}
		}
	}
	return bth(a);
}

string P1(string str) //P1（X）
{
	return XOR(XOR(str, yw(str, 15)), yw(str, 23));
}

string P0(string str)//P0（X）
{
	return XOR(XOR(str, yw(str, 9)), yw(str, 17));
}

string T(int j)//返回Tj
{
	if (0 <= j && j <= 15) 
	{
		return "79CC4519";
	}
	else
	{
		return "7A879D8A";
	}
}

string FF(string str1, string str2, string str3, int j)//布尔函数FF
{
	if (0 <= j && j <= 15)
	{
		return XOR(XOR(str1, str2), str3);
	}
	else
	{
		return OR(OR(AND(str1, str2), AND(str1, str3)), AND(str2, str3));
	}
}

string GG(string str1, string str2, string str3, int j) //布尔函数GG
{
	if (0 <= j && j <= 15)
	{
		return XOR(XOR(str1, str2), str3);
	}
	else
	{
		return OR(AND(str1, str2), AND(NOT(str1), str3));
	}
}
string extension(string str)//消息扩展
{
	string a = str;
	for (int i = 16; i < 68; i++)
	{
		a += XOR(XOR(P1(XOR(XOR(a.substr((i - 16) * 8, 8), a.substr((i - 9) * 8, 8)), yw(a.substr((i - 3) * 8, 8), 15))), yw(a.substr((i - 13) * 8, 8), 7)), a.substr((i - 6) * 8, 8));
	}
	cout << "扩展后的消息：" << endl;
	cout << "W0,W1,……,W67的消息：" << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a.substr(i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << a.substr(512, 8) << "  " << a.substr(520, 8) << "  " << a.substr(528, 8) << "  " << a.substr(536, 8) << endl;
	cout << endl;
	for (int i = 0; i < 64; i++)
	{
		a += XOR(a.substr(i * 8, 8), a.substr((i + 4) * 8, 8));
	}
	cout << "W0',W1',……,W63'的消息：" << endl;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a.substr(544 + i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << endl;
	return a;
}

string compress(string str1, string str2)//消息压缩 
{
	string IV = str2;
	string A = IV.substr(0, 8), B = IV.substr(8, 8), C = IV.substr(16, 8), D = IV.substr(24, 8), E = IV.substr(32, 8), F = IV.substr(40, 8), G = IV.substr(48, 8), H = IV.substr(56, 8);
	string SS1 = "", SS2 = "", TT1 = "", TT2 = "";
	cout << "迭代压缩中间值: " << endl;
	cout << "    A         B         C         D         E         F        G         H " << endl;
	cout << A << "  " << B << "  " << C << "  " << D << "  " << E << "  " << F << "  " << G << "  " << H << endl;
	for (int j = 0; j < 64; j++)
	{
		SS1 = yw(ModAdd(ModAdd(yw(A, 12), E), yw(T(j), (j % 32))), 7);
		SS2 = XOR(SS1, yw(A, 12));
		TT1 = ModAdd(ModAdd(ModAdd(FF(A, B, C, j), D), SS2), str1.substr((j + 68) * 8, 8));
		TT2 = ModAdd(ModAdd(ModAdd(GG(E, F, G, j), H), SS1), str1.substr(j * 8, 8));
		D = C;
		C = yw(B, 9);
		B = A;
		A = TT1;
		H = G;
		G = yw(F, 19);
		F = E;
		E = P0(TT2);
		cout << A << "  " << B << "  " << C << "  " << D << "  " << E << "  " << F << "  " << G << "  " << H << endl;
	}
	string a = (A + B + C + D + E + F + G + H);
	cout << endl;
	return a;
}

string iteration(string str)//迭代压缩 
{
	int num = str.size() / 128;
	cout << "消息经过填充之后共有 " + to_string(num) + " 个消息分组。" << endl;
	cout << endl;
	string V = "7380166F4914B2B9172442D7DA8A0600A96F30BC163138AAE38DEE4DB0FB0E4E";
	string B = "", eB = "", cB = "";
	for (int i = 0; i < num; i++)
	{
		cout << "第 " << to_string(i + 1) << " 个消息分组：" << endl;
		cout << endl;
		B = str.substr(i * 128, 128);
		eB = extension(B);
		cB = compress(eB, V);
		V = XOR(V, cB);
	}
	return V;
}

int main() 
{
	string str[2];
	string w, b;
	/*str[0] = "abc";
	str[1] = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd";*/
	/*for (int num = 0; num < 2; num++)
	{
		cout << "示例 " + to_string(num + 1) + " ：输入消息为字符串: " + str[num] << endl;
		cout << endl;
		string paddingValue = padding(str[num]);
		cout << "填充后的消息为：" << endl;
		for (int i = 0; i < paddingValue.size() / 64; i++) 
		{
			for (int j = 0; j < 8; j++) 
			{
				cout << paddingValue.substr(i * 64 + j * 8, 8) << "  ";
			}
			cout << endl;
		}
		cout << endl;
		string result = iteration(paddingValue);
		cout << "杂凑值：" << endl;
		for (int i = 0; i < 8; i++) 
		{
			cout << result.substr(i * 8, 8) << "  ";
		}
		cout << endl;
		cout << endl;
	}*/

	str[0] = "no rice";//原本信息
	str[1] = " and nooddles";//需添加的信息

	cout << "输入消息为字符串: " + str[0] << endl;
	cout << endl;
	string paddingValue = padding(str[0]);
	cout << "填充后的消息为：" << endl;
	for (int i = 0; i < paddingValue.size() / 64; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << paddingValue.substr(i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << endl;
	string result = iteration(paddingValue);
	cout << "杂凑值：" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << result.substr(i * 8, 8) << "  ";
	}
	cout << endl;
	cout << endl;
	
	double dur;
	clock_t start, end;
	start = clock();
	w = tran(str[1]);
	b = padding2(str[0]) + w;
	string paddingValue1 = padding1(b);
	cout << "进行攻击后填充后的消息为："<< endl;
	for (int i = 0; i < paddingValue1.size() / 64; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << paddingValue1.substr(i * 64 + j * 8, 8) << "  ";
		}
		cout << endl;
	}
	cout << endl;
	string result1 = iteration(paddingValue1);
	cout << "杂凑值：" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << result1.substr(i * 8, 8) << "  ";
	}
	cout << endl;
	cout << endl;
	end = clock();
	dur = (double)(end - start);
	printf("Use Time:%f\n", (dur / CLOCKS_PER_SEC));
}
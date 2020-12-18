#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
struct BigInteger{
	int num[MAXN], len;
	BigInteger(){
		memset(num, 0, sizeof(num));
		len = 0;
	}
	
	// 大整数的存储 
	BigInteger(int num){
		*this = num;
	}
	BigInteger(char*s){
		*this = s;
	}
	BigInteger operator=(int num){
		char s[20];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	BigInteger operator=(const char* s){
		len = strlen(s);
		for(int i = 0; i < len; ++i)
			num[i] = s[len-i-1]^48;
		while((!num[len-1]) && len>1) --len;
		return *this;
	}
	
	// 大整数的输入输出
	friend ostream& operator<<(ostream& out, const BigInteger& x){
		for(int i = x.len-1; i >= 0; --i)
			printf("%d", x.num[i]);
		return out;
	} 
	friend istream& operator>>(istream& in, BigInteger& x){
		string s;
		if(!(in>>s)) return in;
		x = s.c_str();
		return in;
	}
	
	// 大整数加法
	BigInteger operator+(const BigInteger& b){
		BigInteger c;
		int lenth = max(len, b.len);
		for(int i = 0; i < lenth; i++){
			c.num[i] += num[i] + b.num[i];
			if(c.num[i] >= 10){
				++c.num[i+1];
				c.num[i] %= 10;
			}
		}
		if(c.num[lenth]) lenth++;
		c.len = lenth;
		return c;
	}
	
	// 大整数减法，只能大减小 
	// 小减大的话可以判断大小关系 
	BigInteger operator-(const BigInteger& b){
		BigInteger c = *this;
		for(int i = 0; i < c.len; i++){
			c.num[i] -= b.num[i];
			if(c.num[i] < 0){
				c.num[i] += 10;
				--c.num[i+1];
			}
		}
		while((!c.num[c.len-1]) && c.len>1) --c.len;
		return c;
	} 
	
	// 高精度乘法
	BigInteger operator*(const BigInteger& b){
		BigInteger c;
		for(int i = 0; i < len; i++)
			for(int j = 0; j < b.len; j++)
				c.num[i+j] += num[i]*b.num[j];
		c.len = len + b.len;
		for(int i = 0, last = 0; i < c.len; i++){
			c.num[i] += last;
			last = c.num[i]/10;
			c.num[i] %= 10;
		}
		while((!c.num[c.len-1]) && c.len>1) --c.len;
		return c;
	} 
	
	bool operator<(const BigInteger& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; --i)
			if(num[i] != b.num[i]) return num[i] < b.num[i];
		return false;
	}
};

const int maxn = 20005;
bool bs[maxn];
stack<char> s1;
stack<int> s2;
int main(){
	char ch;
	string s;
	int flag = 0;
	cin>>s;
	int len = s.length();
	for(int i = 0; i < len; ++i){
		if(s1.empty() && s[i] == '+'){
			flag = 0;
			continue;
		}
		ch = s[i];
		if(ch == '(' || ch == '+') s1.push(ch);
		else if(isdigit(ch)) s2.push(ch-'0');
		else{
			int a, b;
			while(s1.top() == '+'){
				s1.pop();
				a = s2.top(); s2.pop();
				b = s2.top(); s2.pop();
				s2.push(a+b);
			}
			s1.pop();
			a = s2.top(); s2.pop(); s2.pop();
			s2.push(1<<a);
		}
		if(s1.empty()){
			int a;
			if(s2.size() == 2) a = s2.top();
			else a = 1;
			bs[a] = true;
			while(!s1.empty()) s1.pop();
			while(!s2.empty()) s2.pop();
		}
	}
	len = maxn - 1;
	while(!bs[len]) --len;
	BigInteger a;
	for(int i = len; i >= 0; --i){
		a = (a*2) + BigInteger(bs[i]);
	}
	cout<<a<<endl;
	system("pause");
	return 0;
}
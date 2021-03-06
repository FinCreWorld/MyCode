#include<bits/stdc++.h>
using namespace std;
struct BigInteger{
	static const int MAXN = 10000;
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
	}
	BigInteger operator=(const char* s){
		len = strlen(s);
		for(int i = 0; i < len; ++i)
			num[i] = s[len-i-1]^48;
		while((!num[len-1]) && len>1) --len;
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
	BigInteger operator*(const BigInteger& b) const{
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
	
	BigInteger operator*(const int b){
		return (*this)*BigInteger(b);
	}
	
	// 高精度除法
	BigInteger operator/(const BigInteger& b){
		if(b == BigInteger(0)){
			cout<<"除0错误\n";
			exit(-1); 
		}
		BigInteger a = 0, c = 0;
		c.len = len;
		for(int i = len-1; i >= 0; i--){
			a = a*10 + BigInteger(num[i]);
			int k = 0;
			while(a > b*(k+1) || a == b*(k+1)) ++k;// 对于const对象只能调用const函数 
			c.num[i] = k;
			a = a - b*k;
		}
		while((!c.num[c.len-1]) && c.len>1) --c.len;
		return c;
	} 
	
	// 高精度除以低精度 
	BigInteger operator/(int b){
		if(b == 0){
			cout<<"除0错误\n";
			exit(-1); 
		}
		int a = 0;
		BigInteger c = 0;
		c.len = len;
		for(int i = len-1; i >= 0; i--){
			a = a*10 + num[i];
			int k = 0;
			while(a >= b*(k+1)) ++k;
			c.num[i] = k;
			a = a - b*k;
		}
		while((!c.num[c.len-1]) && c.len>1) --c.len;
		return c;
	}

    // 高精度对低精度取模
    int operator%(int b){
        int d = 0;
        for(int i = len - 1; i >= 0; i--){
            // cout<<d<<" "<<num[i]<<endl;
            d = (d*10 + num[i]) % b;
        }
        return d;
    }
	
	bool operator<(const BigInteger& b) const{
		if(len != b.len) return len < b.len;
		for(int i = len-1; i >= 0; --i)
			if(num[i] != b.num[i]) return num[i] < b.num[i];
		return false;
	}
	
	bool operator == (const BigInteger& b) const{
		return !((*this < b) || (b < *this));
	}
	
	bool operator>(const BigInteger& b) const{
		if(*this == b) return false;
		return b < *this;
	}
};
int main(){
    BigInteger a;
    int b;
    for(;;)
    {cin>>a;
    cin>>b;
    // cout<<a<<" % "<<b<<" = "<<a%b<<endl;
    cout<<a%b<<endl;
    }
}
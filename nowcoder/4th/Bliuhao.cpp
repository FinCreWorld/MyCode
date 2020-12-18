#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

const int times = 50;
int number = 0;

map<long long, int>m;
long long Random( long long n )
{
	return ((double)rand( ) / RAND_MAX*n + 0.5);
}

long long q_mul( long long a, long long b, long long mod ) //快速乘法取模
{
	long long ans = 0;
	while(b)
	{
		if(b & 1)
		{
			ans += a;
		}
		b /= 2;
		a = (a + a) % mod;

	}
	return ans;
}

long long q_pow( long long a, long long b, long long mod ) //快速乘法下的快速幂，叼
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = q_mul( ans, a, mod );
		}
		b /= 2;
		a = q_mul( a, a, mod );
	}
	return ans;
}

bool witness( long long a, long long n )//miller_rabin算法的精华
{
	long long tem = n - 1;
	int j = 0;
	while(tem % 2 == 0)
	{
		tem /= 2;
		j++;
	}

	long long x = q_pow( a, tem, n ); //得到a^(n-1) mod n
	if(x == 1 || x == n - 1) return true;
	while(j--)
	{
		x = q_mul( x, x, n );
		if(x == n - 1) return true;
	}
	return false;
}

bool miller_rabin( long long n )  //检验n是否是素数
{

	if(n == 2)
		return true;
	if(n < 2 || n % 2 == 0)
		return false;

	for(int i = 1; i <= times; i++)  //做times次随机检验
	{
		long long a = Random( n - 2 ) + 1; //得到随机检验算子 a
		if(!witness( a, n ))  //用a检验n是否是素数
			return false;
	}
	return true;
}

long long gcd( long long a, long long b )
{
	if(b == 0)
		return a;
	return gcd( b, a%b );
}

long long pollard_rho( long long n, long long c )//找到n的一个因子
{
	long long x, y, d, i = 1, k = 2;
	x = Random( n - 1 ) + 1;
	y = x;
	while(1)
	{
		i++;
		x = (q_mul( x, x, n ) + c) % n;
		d = gcd( y - x, n );
		if(1<d&&d<n)
			return d;
		if(y == x)//找到循环，选取失败，重新来
			return n;
		if(i == k) //似乎是一个优化，但是不是很清楚
		{
			y = x;
			k <<= 1;
		}
	}
}

void find( long long n, long long c )
{
	if(n == 1)
		return;
	if(miller_rabin( n ))
	{
		m[n]++;
		number++;
		return;
	}

	long long p = n;
	while(p >= n)
		p = pollard_rho( p, c-- );
	find( p, c );
	find( n / p, c );
}

int main( )
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int n;
        long long c;
        cin>>n>>c;
        find(n,2137342);
        long long sum=0;
        if(m.empty()) cout<<"1"<<endl;
        else
        {
            for(map<long long, int>::iterator q = m.begin(); q != m.end();++q)
            {
                sum+=q->second;
            }
            for(int i = 1; i < sum; i++){
                c = c*c;
                if(c>1000000000) c = c % 1000000007;
            }
            cout<<c<<endl;
        }
    }
    //system("pause");
    return 0;
}
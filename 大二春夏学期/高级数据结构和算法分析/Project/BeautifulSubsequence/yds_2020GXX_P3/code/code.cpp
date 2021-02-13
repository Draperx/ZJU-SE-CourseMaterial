#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lowbit(x) x&(-x)
using namespace std;
/*Beautiful Subsequence
����˼ά�����������������������m�������У����ҳ�֮Ϊ�������У��������������ܸ�����ȥ���õ���
�����ö�̬�滮dp����״����ʵ�֣�tree[x]�м�¼����x��β�ĳ������и���*/

const int mod = 1e9 + 7;            //��ĿҪ�� 
const int maxn = 1e5 + 10;
int n,m;
int result;
int dp[maxn];                       //dp������� 
int inc[maxn];                      //����������е������������� 
int tree[maxn];                     //��״���� 
int a[maxn];                        //ԭ���� 

//����n�����ĳ��ȴ��ڵ���2���������ܸ��� 
int count(int x)
{
	return pow(2, x) - x - 1;
}

//���ص�������inc��<=x���������λ�� 
int flag(int x)            
{
  int min = 1;
  int max = n;
  int mid;
  while(min <= max){
    mid = (min + max) / 2;
    if(inc[mid] > x) max = mid - 1;
    else  min = mid + 1;
  }
  return min - 1;
}

//���������ǹ�����״����ĺ���
void update(int x, int dx)          //����״�����е�tree[x] + dx 
{
	while(x < maxn)
    {
        tree[x] = (tree[x] + dx) % mod; 
        x += lowbit(x);
    }
}

int getsum(int x)                   //��״����ǰx��Ԫ����� 
{
	int sum = 0;
	while(x > 0)
    {
        sum = (sum + tree[x]) % mod;
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
	int i;
	int self, upper, lower;                               //ԭλ �Ͻ� �½�
	int tip;                                              //��¼�����и�����һ���м�ֵ 
	cin >> n >> m;
	for(i = 1;i <= n;i++){
	    cin >> a[i];
		inc[i] = a[i]; 
	}
	sort(inc + 1, inc + 1 + n);                           //algorithm�еĺ���, ʹ�����������
	dp[0] = 0;                                            //dp��ʼ�� 
	for(i = 1; i <= n; i++){
		self = flag(a[i]);
        upper = flag(a[i] + m);
		lower = flag(a[i] - m - 1);                    
        tip = getsum(n) - getsum(upper) + getsum(lower);   //�ؼ�һ�� ȷ�����������ķ�Χ 
        tip = (tip % mod + mod) % mod;
        update(self, tip + 1);                             //д����״���� 
        dp[i] = (dp[i-1] + tip) % mod;                     //��̬�滮��ϵʽ 
	}
	result = count(n) - dp[n];
	cout << result << endl;
    system("PAUSE");
	return 0; 
}

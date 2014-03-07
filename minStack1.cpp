/*
* @author jdpdyx@126.com
* @date 2014-03-04
* @note push\pop\min��ʱ�临�Ӷȶ���O(1)��ע�⣬���ʵ�ֲ��Ƕ��̰߳�ȫ��
*/
#include <stack>

using std::stack;

class MinStack
{
public:
	MinStack(){}
	MinStack(const MinStack& ms)
	{
		vStack = ms.vStack;
		mStack = ms.mStack;
	}
	~MinStack() {}

	void push(int v)
	{
		vStack.push(v);
		if (mStack.empty())
		{
			mStack.push(v); // ��һ��Ԫ�أ��϶��ǵ�ǰ��СԪ��
		}
		else if(v < mStack.top())
		{
			mStack.push(v); // ���ָ�С��ֵ
		}
		else 
		{
			mStack.push(mStack.top()); // ��Ȼ����һ����Сֵ
		}
	}
	int top()
	{
		if(vStack.empty()) throw "Empty MinStack";
		else return vStack.top();
	}

	void pop()
	{
		vStack.pop();
		mStack.pop();
	}

	int min()
	{
		if(mStack.empty()) throw "Empty MinStack";
		else return mStack.top();
	}

	bool empty()
	{
		return vStack.empty();
	}
private:
	stack<int> vStack; // �����洢��ջ�ռ�
	stack<int> mStack; // ����ջ�ռ䣬�����洢ÿ���׶ε���Сֵ
};

int main()
{
	MinStack ms;
	int a[] = {3,2,4,5,1};
	for(int i:a)
	{
		ms.push(i);
		cout << "push " << i << endl;
		cout << "min " << ms.min() << endl;
	}
	return 0;
}
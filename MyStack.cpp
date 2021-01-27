/*225. 用队列实现栈
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
*/
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x)
	{
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop()
	{
		int val;
		while (!q1.empty())
		{
			val = q1.front();
			q1.pop();
			if (q1.empty())
				return val;
			q2.push(val);
		}
		while (!q2.empty())
		{
			val = q2.front();
			q2.pop();
			if (q2.empty())
				break;
			q1.push(val);
		}
		return val;
	}

	/** Get the top element. */
	int top()
	{
		int val;
		while (!q1.empty())
		{
			val = q1.front();
			q1.pop();
			q2.push(val);
			if (q1.empty())
				return val;
		}
		while (!q2.empty())
		{
			val = q2.front();
			q2.pop();
			q1.push(val);
			if (q2.empty())
				break;
		}
		return val;
	}
	/** Returns whether the stack is empty. */
	bool empty()
	{
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;

};

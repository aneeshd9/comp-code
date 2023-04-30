#include <stack>
#include <cassert>

class MyQueue {
public:
	void push(int x) {
		this->push_stack.push(x);
	}

	int pop() {
		if (this->pop_stack.empty()) {
			while (!this->push_stack.empty()) {
				int top = this->push_stack.top();
				this->push_stack.pop();
				this->pop_stack.push(top);
			}
		}

		assert(!this->pop_stack.empty());

		int ans = this->pop_stack.top();
		this->pop_stack.pop();
		return ans;
	}

	int peek() {
		if (this->pop_stack.empty()) {
			while (!this->push_stack.empty()) {
				int top = this->push_stack.top();
				this->push_stack.pop();
				this->pop_stack.push(top);
			}
		}

		assert(!this->pop_stack.empty());
		return this->pop_stack.top();
	}

	bool empty() {
		return this->pop_stack.empty() && this->push_stack.empty();
	}

private:
	std::stack<int> push_stack;
	std::stack<int> pop_stack;
};
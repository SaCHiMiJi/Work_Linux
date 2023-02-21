#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct Frequency
{
public:
	vector<char> c;
	vector<int> f;
	int numChar;
};

class treeNode
{
public:
	char character;
	int frequency;
	treeNode *leftChild;
	treeNode *rightChild;

	treeNode(char charac, int freq)
	{
		leftChild = nullptr;
		rightChild = nullptr;
		this->character = charac;
		this->frequency = freq;
	}
};

class HuffmanTree
{
private:
	treeNode *root;

public:
	HuffmanTree()
	{
		root = nullptr;
	}

	void buildTree(Frequency *freq)
	{
		treeNode *left, *right, *top;
		queue<treeNode *> s_queue;
		queue<treeNode *> m_queue;

		for (int i = 0; i < freq->numChar; ++i)
		{
			s_queue.push(new treeNode(freq->c[i], freq->f[i]));
		}

		while (s_queue.size() + m_queue.size() != 1)
		{
			int s;
			int t;
			int l;
			int m;
			if (s_queue.size() >= 1)
			{
				s = s_queue.front()->frequency;
			}
			else
			{
				s = 1000;
			}
			if (s_queue.size() >= 2)
			{
				queue<treeNode *> s_queue2 = s_queue;
				s_queue2.pop();
				t = s_queue2.front()->frequency;
			}
			else
			{
				t = 1000;
			}

			if (m_queue.size() == 0)
			{
				l = 1000;
				m = 1000;
			}
			else if (m_queue.size() == 1)
			{
				l = m_queue.front()->frequency;
				m = 1000;
			}
			else
			{
				l = m_queue.front()->frequency;
				queue<treeNode *> m_queue2 = m_queue;
				m_queue2.pop();
				m = m_queue2.front()->frequency;
			}
			if ((s + t <= s + l) && (s + t <= l + m))
			{
				left = s_queue.front();
				s_queue.pop();
				right = s_queue.front();
				s_queue.pop();
				top = new treeNode('$', left->frequency + right->frequency);
				top->leftChild = left;
				top->rightChild = right;
				m_queue.push(top);
			}
			else if ((s + l < s + t) && (s + l <= l + m))
			{
				if (s <= l)
				{
					left = s_queue.front();
					s_queue.pop();
					right = m_queue.front();
					m_queue.pop();
					top = new treeNode('$', left->frequency + right->frequency);
					top->leftChild = left;
					top->rightChild = right;
					m_queue.push(top);
				}
				else
				{
					left = m_queue.front();
					m_queue.pop();
					right = s_queue.front();
					s_queue.pop();
					top = new treeNode('$', left->frequency + right->frequency);
					top->leftChild = left;
					top->rightChild = right;
					m_queue.push(top);
				}
			}
			else
			{
				left = m_queue.front();
				m_queue.pop();
				right = m_queue.front();
				m_queue.pop();
				top = new treeNode('$', left->frequency + right->frequency);
				top->leftChild = left;
				top->rightChild = right;
				m_queue.push(top);
			}
		}
		root = m_queue.front();
	}

	void decode(string code)
	{
		string ans = "";
		treeNode *curr = root;
		for (int i = 0; i < code.size(); i++)
		{
			if (code[i] == '0')
				curr = curr->leftChild;
			else
				curr = curr->rightChild;

			if (curr->leftChild == nullptr && curr->rightChild == nullptr)
			{
				ans += curr->character;
				curr = root;
			}
		}
		cout << ans << endl;
	}
};
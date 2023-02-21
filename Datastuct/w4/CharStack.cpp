class CharStack
{
private:
    char items[10];
    int s_top;

public:
    CharStack()
    { // constructor
        s_top = -1;
    }

    void push(char new_item)
    {
        s_top++;
        items[s_top] = new_item;

    }

    char pop()
    {
        items[s_top] = ' ';
        s_top--;
        return items[s_top];
    }

    char top()
    {
        return items[s_top];
    }

    bool isEmpty()
    {
        return (s_top == -1);
    }
};

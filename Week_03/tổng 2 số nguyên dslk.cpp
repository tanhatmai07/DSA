stack<int>sa, sb;
Node* p = a.head;
while (p != NULL)
{
    sa.push(p->num);
    p = p->next;
}
p = b.head;
while (p != NULL)
{
    sb.push(p->num);
    p = p->next;
}
int carry = 0;
while (!sa.empty() || !sb.empty() || carry > 0)
{
    int ValA = 0;
    int ValB = 0;
    if (!sa.empty())
    {
        ValA = sa.top();
        sa.pop();
    }
    else
    {
        ValA = 0;
    }
    if (!sb.empty())
    {
        ValB = sb.top();
        sb.pop();
    }
    else
    {
        ValB = 0;
    }
    int total = ValA + ValB + carry;
    int digit = total % 10;
    carry = total / 10;
    AddHead(c, digit);
}
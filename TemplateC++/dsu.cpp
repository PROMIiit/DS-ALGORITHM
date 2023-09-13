long long parent[100005], child[100005];

void make_set(long long a)
{
    parent[a] = a;
    child[a] = 1;
}

long long find_set(long long a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}

void union_set(long long a, long long b)
{
    a = find_set(a);
    b = find_set(b);
    if(child[a] < child[b])
    {
        swap(a, b);
    }
    child[a] += child[b];
    parent[b] = a;
}

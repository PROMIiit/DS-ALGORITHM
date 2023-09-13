
bool cmp(const pair<long long,long long>i,const pair<long long,long long>j)
{
    if(i.first>j.first)
        return true;
    else if(i.first<j.first)
        return false;
    else
        return i.second<j.second;
}



static bool comp(Interval a, Interval b)
{
    if (a.start < b.start)
        return true;
    return false;
}
vector<Interval> Solution::merge(vector<Interval> &A)
{

    vector<Interval> ans;
    sort(A.begin(), A.end(), comp);
    ans.push_back({A[0].start, A[0].end});
    for (int i = 1; i < A.size(); i++)
    {
        if (ans.back().end < A[i].start)
        {
            ans.push_back({A[i].start, A[i].end});
        }
        else
        {
            ans.back().end = max(ans.back().end, A[i].end);
        }
    }
    return ans;
}

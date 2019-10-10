string removeConsecutiveDuplicates(string s)
{
string res;
int j = 0;
res.push_back(s[0]);
int n = s.length();
for(int i = 0; i < n; i++)
{
if(s[i] == res[j])
continue;
else
{
res.push_back(s[i]);
j++;
}
}
return res;
}

int kadane(int arr[],int num)
{
int sum=0,maxsum=INT_MIN;
for (int i = 0; i < num; ++i)
{
sum+=arr[i];
maxsum=max(maxsum,sum);
if(sum<0)
{
sum=0;
}
}
return maxsum;
}
int reversekadane(int arr[],int num)
{
int rsum[num],sum[num],maxv,ans=INT_MIN;
rsum[num-1]=arr[num-1];
for (int i = num-2; i >= 0; i--)
{
rsum[i]=rsum[i+1]+arr[i];
}
sum[0]=arr[0];
for (int i = 1; i < num; ++i)
{
sum[i]=sum[i-1]+arr[i];
}
maxv=sum[0];
for (int i = 1,j=0; i < num; ++i,j++)
{
maxv=max(maxv,sum[j]);
ans=max(ans,maxv+rsum[i]);
}
return ans;
}
int circularSubarraySum(int arr[], int num){

int k = kadane(arr,num);
int rk = reversekadane(arr,num);
return max(k, rk);
}

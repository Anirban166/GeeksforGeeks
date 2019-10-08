    public static int binarySubstring(int a, String str)
    {
    int ctr=0;
    for(int i=0; i<a; i++)
        ctr = (str.charAt(i)=='1')?ctr+1:ctr;
    return (ctr*(ctr-1)/2);
    }

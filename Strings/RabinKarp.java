    static boolean search(String pat, String txt, int q)
    {
    boolean res=false;
    int patSize = pat.length();
    for(int i=0;i<=txt.length()-patSize;i++) 
    {
    String checkSub = txt.substring(i,i+patSize);
    if(pat.equals(checkSub))res=true;
    }
    return res;
    }

    static int repeatedCharacter(String S)
    {
    int leftMost = -1;
    int[] indexArr = new int[256];
    int len = S.length();
    for(int i=len-1; i>=0; i--)
    {
        leftMost = (indexArr[(int)S.charAt(i)]!=0)?i:leftMost;
        indexArr[(int)S.charAt(i)] = i;
    }
    return leftMost;
    }

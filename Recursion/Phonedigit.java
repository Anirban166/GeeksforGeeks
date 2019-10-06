class PhoneDigit
{
static String key[] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

static void possibleWords(int a[], int N)
{
// your code here 
int l = 0,seq = 0;
String curr = "";
wordsutil(a, N, l, seq, curr);

}

static void wordsutil(int a[], int N, int index,int seq, String curr){
if(N == index){ 
System.out.print(curr + " ");
return;
}
else{
for(int i = 0; i < key[a[index]].length(); i++){
wordsutil(a,N,index+1,seq,curr+key[a[index]].charAt(seq+i));
}
}
}

}

//OR:

class phoneDigit{
static void possibleWords(int a[], int N)
{
possibleWords(a,0,""); 
}
private static String keyHelper(int n){
String str [] = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
return str[n-1];
}

public static void possibleWords(int a[], int si, String outputSoFar){
String temp = outputSoFar;
if(si == a.length){
System.out.print(outputSoFar + " ");
return;
}
String str = keyHelper(a[si]);
for(int i=0; i<str.length(); i++){="" outputsofar="outputSoFar" +="" str.charat(i);="" possiblewords(a,si+1,outputsofar);="" outputsofar="temp;" }="" }="" }="">

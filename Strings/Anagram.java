// Anagram - same characters in different order. Eg : beat - teab - eatb - btae etc are Anagram of each other.

public static boolean isAnagram(String s1,String s2)
{
    int len1 = s1.length();
    if(len1!=s2.length())
        return false;
            
    HashMap<Character, Integer> hm_s1 = new HashMap<Character, Integer>();
    HashMap<Character, Integer> hm_s2 = new HashMap<Character, Integer>();
       
    for(int i=0; i<len1; i++)
    {
        hm_s1.put(s1.charAt(i), (hm_s1.containsKey(s1.charAt(i))?hm_s1.get(s1.charAt(i))+1:1));
        hm_s2.put(s2.charAt(i), (hm_s2.containsKey(s2.charAt(i))?hm_s2.get(s2.charAt(i))+1:1));
    }
    if(hm_s1.hashCode()==hm_s2.hashCode())
        return true;
    return false;
}

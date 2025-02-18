
class Solution{
    public String[] reorderLogFiles(String[] logs){
        List<String> digiList = newArrayList<>();
        List<String> letterList = newArrayList<>();
        String[] res = new String[logs.length];
        for(String s : logs){
            if(Character.isAlphabetic(s.charAt(s.length()-1))) letterList.add(s);
            else digiList.add(s);
        }
        letterList.sort((s1,s2)->{
            int a = s1.indexOf(" ");
            int b = s2.indexOf(" ");
            String temp1 = s1.substring(0,a);
            String temp2 = s2.substring(0,b);
            String toSort1 = s1.substring(a+1);
            String toSort2 = s2.substring(b+1);
            return toSort1.equals(toSort2) ? temp1.compareTo(temp2) : toSort1.compareTo(toSort2);});
        
            int i = 0;
            for(String s : letterList) res[i++] = s;
            for(String s : digitList) res[i++] = s;

            return res;
    }
}
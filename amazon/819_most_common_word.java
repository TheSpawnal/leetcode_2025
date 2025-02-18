
//regex finding
class Solution{
    public String mostCommonWord(String s1, String[] ban){
        s1 = s1.toLowerCase().replaceAll("\\W+"," ");
        String[] arr = s1.split("\\s+");
        int n = arr.length;
        HashMap<String, Integer> hp = new HashMap<>();
        for(int i =0; i < n; i++){
            hp.put(arr[i], hp.getOrDefault(arr[i], 0)+1);
        }
        HashSet<String> h = new HashSet<>();
        for(int i =0; i < ban.length;i++){
            h.add(ban[i]);
        }
        int freq = 0;
        String ans = "";
        for(var a: hp.keySet()){
            if(hp.get(a) > freq && !h.contains(a)){
                freq = hp.get(a); 
                ans = a;
            }
        }
        return ans;
    }
}

//much more fast
class Solution{
    public String mostCommonWord(String paragraph, String[] banned){
        Set<String> bannedWords = new HashSet();
        for(String word : banned)
            bannedWords.add(word);

        String ans = "";
        int maxCount = 0;
        Map<String,Integer> wordCount = new HashMap();
        StringBuilder wordBuffer = new StringBuilder();
        char[] chars = paragraph.toCharArray();
        for(int i = 0; i < chars.length; i++){
            char currChar = chars[i];
            if(Character.isLetter(currChar)){
                wordBuffer.append(Character.toLowerCase(currChar));
                if(i !=chars.length -1)
                    continue;
            }
            if(wordBuffer.length() > 0){
                String word = wordBuffer.toString();
                if(!bannedWords.contains(word)){
                    int newCount = wordCount.getOrDefault(word, 0)+1;
                    wordCount.put(word, newCount);
                    if(newCount>maxCount){
                        ans = word;
                        maxCount = newCount;
                    }
                }
                wordBuffer = new StringBuilder();
            }
        }
        return ans;
    }
}
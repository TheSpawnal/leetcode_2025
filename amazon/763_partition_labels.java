class Solution{
    public List<Integer> partitionLabels(String S){
        Integer[] positions = new Integer[26];
        char[] chs = S.toCharArray();
        for(int i =0; i < chs.length; i++)
            positions[chs[i] - 'a'] = i;
        List<Integer> resLs = new ArrayList<>();
        int pos = 0, end = 0, anchor =0;
        while(pos< chs.length){
            end = Math.max(positions[chs[pos]-'a'], end);
            if(pos == end){
                resLs.add(pos-anchor+1);
                anchor = pos+1;
            }
            pos++;
        }
        return resLs
    }
}
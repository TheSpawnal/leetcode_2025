

class Solution{
    public boolean wordBreak(String s, List<String> wordDict){
        boolean[] f = new boolean[s.length()+1];
        f[0] = true;

        for(int i = 1; i <= s.length();i++){
            for(int j = 0; j < i; j++){
                if(f[j] && wordDict.contains(s.substring(j, i))){
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.length()];
    }
}


//memoized
class Trim{
    Trim[] ch = new Trim[26];
    boolean point_end;
}
class Solution{
    public boolean wordBreak(String s, List<String> wordDict){
        int[] dp = new int[s.length()+1];
        Arrays.fill(dp, -1);
        Trim root = new Trim();
        for(String str:wordDict) insert(root, str);

        return dfs(0, s,root, s.length(),dp);
    }
    public boolean dfs(int idx, String s, Trim root, int n, int[] dp){
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx] == 0 ? false:true;
        Trim curr = root;
        for(int i = idx; i < n; i++){
            int j = s.charAt(i)-97;
            if(curr.ch[j]==null){
                dp[idx]=0; return false;
            }
            else{
                curr = curr.ch[j];
                if(curr.point_end){
                    if(dfs(i+1,s,root,n,dp)) {
                        dp[idx]=1; return true;
                    }
                }
            }
        }
        dp[idx] = 0;
        return false;
    }
    public void insert(Trim root, String s){
        Trim curr = root;
        for(int i = 0; i < s.length();i++){
            int idx = s.charAt(i)-97;
            if(curr.ch[idx]==null){
                curr.ch[idx]= new Trim();
            }
            curr = curr.ch[idx];
        }
        curr.point_end = true;
    }
}
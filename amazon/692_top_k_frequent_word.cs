public class Solution {
    public IList<string> TopKFrequent(string[] words, int k) {
        Dictionary<string, int> freq = new Dictionary<string, int>();
        foreach(var s in words){
            if(freq.ContainsKey(s)) freq[s]++;
            else freq.Add(s, 1);
        }
        var resList = freq.ToList();
        resList.Sort((p1, p2)=>{
            if(p2.Value - p1.Value == 0) return String.Compare(p1.Key, p2.Key);
            return p2.Value - p1.Value;
        });
        List<string> ans = new List<string>();
        int i = 0;
        foreach(var n in resList){
            ans.Add(n.Key);
            if(++i == k) return ans;
        }
        return null;
    }
}
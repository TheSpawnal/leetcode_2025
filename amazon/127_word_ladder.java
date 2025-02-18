class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }
        Set<String> beginSet = new HashSet<>();
        beginSet.add(beginWord);
        Set<String> endSet = new HashSet<>();
        endSet.add(endWord);
        Set<String> visit = new HashSet<>();
        int step = 1;
        Set<String> dict = new HashSet<>(wordList);
        while (!beginSet.isEmpty()) {
            if (beginSet.size() > endSet.size()) {
                Set<String> temp = beginSet;
                beginSet = endSet;
                endSet = temp;
            }
            Set<String> nextBegin = new HashSet<>();
            for (String begin : beginSet) {
                visit.add(begin);
                int n = begin.length();
                char[] strArr = begin.toCharArray();
                for (int i = 0; i < n; i++) {
                    char old = strArr[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) {
                            continue;
                        }
                        strArr[i] = c;
                        String newStr = String.valueOf(strArr);
                        if (endSet.contains(newStr)) {
                            return step + 1;
                        }
                        if (!visit.contains(newStr) && dict.contains(newStr)) {
                            nextBegin.add(newStr);
                        }
                    }
                    strArr[i] = old;
                }
            }
            step++;
            beginSet = nextBegin;
        }
        return 0;
    }
}
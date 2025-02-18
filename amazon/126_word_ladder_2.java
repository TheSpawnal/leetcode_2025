import java.util.*;

public class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) {
            return Collections.emptyList();
        }

        Map<String, List<String>> adj = new HashMap<>();
        Set<String> visited = new HashSet<>();
        Deque<String> queue = new ArrayDeque<>();
        queue.offer(beginWord);
        visited.add(beginWord);
        boolean found = false;

        while (!queue.isEmpty() && !found) {
            int levelSize = queue.size();
            Set<String> currentLevelVisited = new HashSet<>();
            for (int i = 0; i < levelSize; i++) {
                String currentWord = queue.poll();
                char[] wordChars = currentWord.toCharArray();

                for (int j = 0; j < wordChars.length; j++) {
                    char originalChar = wordChars[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        wordChars[j] = c;
                        String tempWord = new String(wordChars);
                        if (wordSet.contains(tempWord) && !tempWord.equals(currentWord)) {
                            if (tempWord.equals(endWord)) {
                                found = true;
                            }
                            if (!visited.contains(tempWord)) {
                                if (!currentLevelVisited.contains(tempWord)) {
                                    queue.offer(tempWord);
                                    currentLevelVisited.add(tempWord);
                                }
                                adj.computeIfAbsent(tempWord, k -> new ArrayList<>()).add(currentWord);
                            }
                        }
                    }
                    wordChars[j] = originalChar; // Reset back to original character
                }
            }
            visited.addAll(currentLevelVisited);
        }

        List<List<String>> results = new ArrayList<>();
        if (found) {
            LinkedList<String> path = new LinkedList<>();
            path.add(endWord);
            backtrack(endWord, beginWord, adj, path, results);
        }
        return results;
    }

    private void backtrack(String currentWord, String beginWord,
                           Map<String, List<String>> adj,
                           LinkedList<String> path, List<List<String>> results) {
        if (currentWord.equals(beginWord)) {
            results.add(new ArrayList<>(path));  // Add a reversed copy of the path
            return;
        }
        for (String nextWord : adj.getOrDefault(currentWord, Collections.emptyList())) {
            path.addFirst(nextWord); // Prepend to path
            backtrack(nextWord, beginWord, adj, path, results);
            path.removeFirst(); // Remove the prepended word
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<String> wordList = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
        String beginWord = "hit";
        String endWord = "cog";
        List<List<String>> result = sol.findLadders(beginWord, endWord, wordList);
        for (List<String> path : result) {
            System.out.println(path);
        }
    }
}

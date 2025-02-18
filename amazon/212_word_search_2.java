
import java.util.*;


class Solution {
    class TrieNode{
        TrieNode[] children = new TrieNode[26];
        String word = null;
    }

    public List<String> findWords(char[][] board, String[] words) {
        //step 1;construct the trie from the given words
        TrieNode root = new TrieNode();
        for(String word: words){
            TrieNode node = root;
            for(char c: word.toCharArray()){
                int index = c - 'a';
                if(node.children[index] == null){
                    node.children[index] = new TrieNode();
                }
                node = node.children[index];
            }
            node.word = word; //mark the end of the word
        }

        Set<String> result = new HashSet<>();
        int rows = board.length;
        int cols = board[0].length;

        for(int i=0; i < rows; i++){
            for(int j = 0; j< cols; j++){
                if(root.children[board[i][j]-'a']!=null){
                    dfs(board, i, j, root, result);
                }
            }
        }
        return new ArrayList<>(result);
    }

    private void dfs(char[][] board, int i, int j, TrieNode node, Set<String> result){
        char c = board[i][j];
        if(c == '#' || node.children[c - 'a'] == null){
            return;//either visited or not in the trie
        }
        node = node.children[c-'a'];
        if(node.word != null){
            result.add(node.word);
            node.word = null;
        }
        board[i][j] = '#';

        if( i > 0)dfs(board, i-1, j, node, result);//up 
        if( i < board.length - 1)dfs(board, i+1, j, node, result);//down
        if( j > 0) dfs(board,i, j-1, node, result);//left
        if(j < board[0].length -1) dfs(board, i, j+1, node, result);//right

        //restore the original cell value after dfs
        board[i][j] = c;
    }
}
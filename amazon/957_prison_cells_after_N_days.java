import java.util.*;

class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        Map<String, Integer> seen = new HashMap<>();
        boolean hasCycle = false;
        int cycleLength = 0;

        for (int i = 0; i < n; i++) {
            int[] nextDayCells = nextDay(cells);
            String stateKey = Arrays.toString(nextDayCells);

            if (seen.containsKey(stateKey)) {
                hasCycle = true;
                cycleLength = i - seen.get(stateKey);
                break;
            } else {
                seen.put(stateKey, i);
            }
            cells = nextDayCells;
        }

        if (hasCycle) {
            n = n % cycleLength;
            for (int i = 0; i < n; i++) {
                cells = nextDay(cells);
            }
        }
        
        return cells;
    }

    private int[] nextDay(int[] cells) {
        int[] newCells = new int[8];
        for (int i = 1; i < 7; i++) {
            newCells[i] = (cells[i - 1] == cells[i + 1]) ? 1 : 0;
        }
        return newCells;
    }
}

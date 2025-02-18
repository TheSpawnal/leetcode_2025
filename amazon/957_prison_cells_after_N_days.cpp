class Solution {
    int toInt(vector<int> &cells) {
        int value = 0;
        for (int i = 0; i < cells.size(); ++i) {
            value <<= 1;
            value |= cells[i];
        }
        return value;
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int count = cells.size();
        vector<vector<int>> table(1, cells);
        unordered_map<int, int> indices{{toInt(cells), 0}};
        int period = 0;
        for (int i = 1; i <= n; ++i) {
            vector<int> next_cells(count);
            for (int j = 1; j < count - 1; ++j) {
                if (table[i - 1][j - 1] == table[i - 1][j + 1]) {
                    next_cells[j] = 1;
                } else {
                    next_cells[j] = 0;
                }
            }
            int key = toInt(next_cells);
            auto it = indices.find(key);
            if (it == indices.end()) {
                indices[key] = i;
                table.emplace_back(next_cells);
            } else {
                period = i - it->second;
                break;
            }
        }
        if (table.size() == n + 1) {
            return table[n];
        }
        int base = table.size() - period;
        return table[base + (n - base) % period];
    }
};
package knights_tour;
import java.util.ArrayList;

public class Knight {
    private static ArrayList<Integer> path = new ArrayList<>();

    private static final int[][] jumpOffset = {
        {-2, -1}, // 2 up, 1 left
        {-2, 1},  // 2 up, 1 right
        {-1, -2},  // 1 up, 2 left
        {-1, 2},  // 1 up, 2 right
        {1, -2},  // 1 down, 2 left
        {1, 2},   // 1 down, 2 right
        {2, -1},  // 2 down, 1 left
        {2, 1},   // 2 down, 1 right
    };

    private static boolean isValid(int nextRow, int nextCol, int n, boolean[][] visited) {
        return (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]);
    }

    private static void backtrack(ArrayList<Integer> currPath, boolean[][] visited, int row, int col, int n) {
      if (!path.isEmpty()) {
          return;
      }
      visited[row][col] = true;
      currPath.add(row * n + col);

      if (currPath.size() == n * n) {
          path = new ArrayList<>(currPath);
          return;
      }

      int nextRow, nextCol;
      for (int[] jump : jumpOffset) {
          nextRow = row + jump[0];
          nextCol = col + jump[1];
          if (isValid(nextRow, nextCol, n, visited)) {
              backtrack(currPath, visited, nextRow, nextCol, n);
          }
      }

      visited[row][col] = false;
      currPath.remove(currPath.size() - 1);
    }

    public static ArrayList<Integer> knightsTour(int n) {
        if (n < 5) {
            return new ArrayList<>();
        }
        ArrayList<Integer> currPath = new ArrayList<>();
        boolean[][] visited = new boolean[n][n];
        backtrack(currPath, visited, 0, 0, n);
        return path;
    }

    public static void main(String[] args) {
        int n = 10;
        ArrayList<Integer> res = knightsTour(n);
        for (int pos : res) {
            System.out.print(pos + " ");
        }
        System.out.println(res.isEmpty() ? "\nNo valid path exists." : "\nA valid path has been found.");
    }
}
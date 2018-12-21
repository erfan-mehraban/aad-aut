import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class count2 {
    static int n, q;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line1 = br.readLine();
        String[] sline1 = line1.trim().split("\\s+");
        n = Integer.parseInt(sline1[0]);
        q = Integer.parseInt(sline1[1]);
        int arr[] = new int[n];
        String line2 = br.readLine();
        String[] strs = line2.trim().split("\\s+");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(strs[i]);
        }

        int[][] matrix = new int[n + 1][n + 1];
        int mid = 0;
        for (int i = 1; i <= n; i++)
            matrix[i][i - 1] = 1;

        for (int i = 2; i < n + 1; i++) {
            for (int k = 0; k < n - i + 1; k++) {
                if (is_sorted(arr, k, i + k) == 0) {
                    mid = i / 2 + k;
                    matrix[i + k][k] = 1 + matrix[mid][k] + matrix[i + k][mid];
                } else {
                    matrix[i + k][k] = 1;
                }
            }
        }
        for (int i = 0; i < q; i++) {
            String line = br.readLine();
            String[] sline = line.trim().split("\\s+");
            int l = Integer.parseInt(sline[0]);
            int r = Integer.parseInt(sline[1]);
            /*for (int k=0;k<n+1;k++){
                for (int j=0;j<n+1;j++)
                    System.out.print(matrix[k][j]+"\t");
                System.out.println();
            }*/
            System.out.println(matrix[r - 1][l - 1]);

        }
    }

    static int is_sorted(int[] arr, int a, int n) {
        if (n - a == 1 || n - a == 0 || n == a) {
            return 1;
        }
        if (arr[n - 1] < arr[n - 2]) {
            return 0;
        }

        return is_sorted(arr, a, n - 1);
    }


}

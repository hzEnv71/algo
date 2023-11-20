
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main3 {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        int t = 1;
        while (t-- > 0) {
            solve(sc);
        }
    }

    public static void solve(MyScanner input) {
        int n, t, f;

        n = input.nextInt();
        t = input.nextInt();
        f = input.nextInt();

        int[] p1 = new int[n];
        int[] p2 = new int[n];
        for (int i = 0; i < n; i++) {
            p1[i] = input.nextInt();
            p2[i] = input.nextInt();
        }

        int ans = 0;
        for (int i = p1.length - 1; i >= 0; i--) {
            if (Math.abs(p1[i] - f) <= Math.abs(p2[i] - t)) {
                ans++;
            }
        }

        System.out.println(ans);
    }

}

class MyScanner {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer("");
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String nextString() {
        while (!st.hasMoreTokens())
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        return st.nextToken();
    }

    int nextInt() { return Integer.parseInt(nextString());}

    double nextDouble() { return Double.parseDouble(nextString());}

    long nextLong() { return Long.parseLong(nextString());}

    <T> void print(T i) {
        try {
            bw.write(String.valueOf(i));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    <T> void println(T t) {
        try {
            bw.write(String.valueOf(t));
            bw.newLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void flush() {
        try {
            bw.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    
}


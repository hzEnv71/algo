
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main4 {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc);
        }
    }

    public static void solve(MyScanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        String s = sc.nextString();

        Set<Pair> S = new HashSet<>();

        int[] nxt = new int[n + 1];
        int[] lst = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            lst[i] = -1;
            nxt[i] = n;
        }
        for (int i = 0; i < n; i++) {
            lst[i + 1] = s.charAt(i) == '0' ? i : lst[i];
            nxt[n - i - 1] = s.charAt(n - i - 1) == '1' ? n - i - 1 : nxt[n - i];
        }

        while (m-- > 0) {
            int l = sc.nextInt() - 1;
            int r = sc.nextInt();
            l = nxt[l];
            r = lst[r];
            if (l > r) {
                l = r = -1;
            }
            S.add(new Pair(l, r));
        }
        sc.println(S.size());
        sc.flush();
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

    int nextInt() {
        return Integer.parseInt(nextString());
    }

    double nextDouble() {
        return Double.parseDouble(nextString());
    }

    long nextLong() {
        return Long.parseLong(nextString());
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

    <T> void print(T i) {
        try {
            bw.write(String.valueOf(i));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Pair {
    int first, second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Pair pair = (Pair) o;
        return first == pair.first && second == pair.second;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(first) ^ Integer.hashCode(second);
    }
}

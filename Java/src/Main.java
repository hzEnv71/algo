import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int t = fs.nextInt();
        while (t-- > 0) {
            solve(fs);
        }
    }

    public static void solve(FastScanner fs) {
        int n = fs.nextInt();
        int k = fs.nextInt();
        Pair[] p = new Pair[n + 1];
        p[0]=new Pair(0, 0);
        for (int i = 1; i <= n; i++) {
            int tmp=fs.nextInt();
            p[i] = new Pair(tmp % k, i);
        }
        Arrays.sort(p, 1, n + 1);

        int i = 1;
        for (; i <= n; i++) {
            if (p[i].first == 0) {
                // System.out.print(p[i].second + " ");
                fs.print(p[i].second + " ");
            } else {
                break;
            }
        }

        for (int j = n; j >= i; j--) {
            int cnt = 0;
            while (p[j].first == p[j - 1].first) {
                cnt++;
                j--;
            }
            for (int l = j; l <= cnt + j; l++) {
                fs.print(p[l].second + " ");
            }
        }
        fs.println("");
        fs.flush();
    }    
    static class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(first, other.first);
        }
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        String nextString() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
        int nextInt() { return Integer.parseInt(nextString()); }
        double nextDouble() { return Double.parseDouble(nextString()); }
        long nextLong() { return Long.parseLong(nextString()); }

         <T> void println(T t){
            try {
                bw.write(String.valueOf(t));
                bw.newLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        
        <T> void print(T i){
            try {
                bw.write(String.valueOf(i));
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
}
 
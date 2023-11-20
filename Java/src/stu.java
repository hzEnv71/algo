
// import java.io.BufferedInputStream;
// import java.io.BufferedOutputStream;
// import java.io.FileInputStream;
// import java.io.FileNotFoundException;
// import java.io.FileOutputStream;
// import java.io.IOException;
// import java.io.InputStream;
// import java.io.InputStreamReader;
// import java.io.OutputStream;
// import java.io.OutputStreamWriter;
// import java.text.ParseException;
// import java.text.SimpleDateFormat;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Collection;
// import java.util.Comparator;
// import java.util.Date;
// import java.util.HashSet;
// import java.util.List;
// import java.util.Objects;
// import java.util.Random;
// import java.util.Scanner;
// import java.util.Set;
// import java.util.TreeSet;
// import java.util.function.UnaryOperator;
// import java.util.stream.Collectors;
// import java.util.stream.Stream;

public class stu {

    // public static void main(String[] args) {
    // Scanner sc = new Scanner(System.in);
    // String number = sc.next();
    // System.out.println(number.substring(3, 7));
    // }
    // public static void main(String[] args) {
    // Scanner sc = new Scanner(System.in);
    // String number = sc.next();
    // String regex = "[1-9]{6,11}";
    // boolean flag = number.matches(regex);
    // System.out.println("QQ号是是否合法:" + flag);

    // }
    // public static void main(String[] args) {
    // System.out.println(String.valueOf(new Random().nextDouble(100)).substring(0,
    // 5));
    // }
    // public static void main(String[] args) {
    // String[] strs = "91 27 46 38 50".split(" ");
    // int[] arr =
    // Arrays.asList(strs).stream().mapToInt(Integer::parseInt).toArray();
    // Arrays.sort(arr);
    // for (int a : arr) {
    // System.out.print(a + " ");
    // }
    // }

    // String name;
    // int age;
    // int score;

    // public stu() {
    // }

    // public stu(String name, int age, int score) {
    // this.name = name;
    // this.age = age;
    // this.score = score;
    // }

    // @Override
    // public boolean equals(Object o) {
    // stu student = (stu) o;
    // return Objects.equals(name, student.name);
    // }

    // @Override
    // public String toString() {
    // return "Student{" +
    // "name='" + name + '\'' +
    // ", age=" + age +
    // ", score=" + score +
    // '}';
    // }

    // @Override
    // public int hashCode() {
    // return Objects.hash(name);
    // }
    // public static void main(String[] args) {
    // stu[] stus = { new stu("张飞", 18, 89), new stu("关羽", 20, 80) };
    // Arrays.sort(stus, (stu s1, stu s2) -> s1.score - s2.score);
    // System.out.println(Arrays.toString(stus));
    // }

    // public static void main(String[] args) {
    // Scanner sc = new Scanner(System.in);
    // stu[] stus = new stu[5];
    // for (int i = 0; i < 5; i++) {
    // String[] tmp = sc.nextLine().split(",");
    // stus[i] = new stu(tmp[0], Integer.parseInt(tmp[1]),
    // Integer.parseInt(tmp[2]));
    // }
    // Set<stu> set = new HashSet<>(Arrays.asList(stus));
    // Set<stu> set = new TreeSet<>(new Comparator<stu>() {
    // @Override
    // public int compare(stu o1, stu o2) {
    // return o2.name.hashCode() - o1.name.hashCode();
    // }
    // });
    // for (int i = 0; i < 5; i++) {
    // String[] tmp = sc.nextLine().split(",");
    // set.add( new stu(tmp[0], Integer.parseInt(tmp[1]),
    // Integer.parseInt(tmp[2])));
    // }

    // for (stu s : set) {
    // System.out.println(s.name + " " + s.age + " " + s.score);
    // }
    // }

    // public static void main(String[] args) throws ParseException {
    // SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
    // String date = "2050-5-1";
    // Date parse = sdf.parse(date);
    // System.out.println(parse.toString().substring(0,4));
    // }
    // public static void main(String[] args) {

    // }

    // private int listTest(ArrayList list, Integer s) {
    // for (int i = 0; i < list.size(); i++) {
    // if (i == s) {
    // return i;
    // }
    // }
    // return -1;
    // }
    // public static void main(String[] args) {
    // ArrayList<String> list = new ArrayList<>();
    // list.add("张三");
    // list.add("二丫");
    // list.add("李四");
    // System.out.println(list.toString());
    // list.set(list.indexOf("二丫"), "王小丫");
    // System.out.println(list.toString());
    // }
    // public static void main(String[] args) {
    // Set<String> set = new HashSet<>(Arrays.asList("a", "b", "c", "d", "e"));
    // set.addAll(new HashSet<>(Arrays.asList("d", "e", "f", "g", "h")));
    // System.out.println(set);
    // }
    // public static void main(String[] args) {
    // Scanner sc = new Scanner(System.in);
    // String s = sc.nextLine();
    // Set<Integer> set = new TreeSet<>();
    // for (int i = 0; i < s.length(); i++) {
    // Integer tmp = s.charAt(i) - '0';
    // if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
    // set.add(tmp);
    // }
    // }
    // System.out.println(set.toString());
    // }
    // public static void main(String[] args) throws IOException {
    // FileInputStream fis = new
    // FileInputStream("/Users/mac/ProblemSet/Java/src/copy1.txt");
    // FileOutputStream fos = new
    // FileOutputStream("/Users/mac/ProblemSet/Java/src/copy2.txt");
    // byte[] b = new byte[1024];
    // int len;
    // while ((len = fis.read(b)) != -1) {
    // fos.write(b, 0, len);
    // }
    // fis.close();
    // fos.close();
    // }
    // public static void main(String[] args) throws IOException {
    // InputStreamReader isr = new InputStreamReader(new
    // FileInputStream("/Users/mac/ProblemSet/Java/src/copy1.txt"), "UTF-8");
    // OutputStreamWriter osw=new OutputStreamWriter(new
    // FileOutputStream("/Users/mac/ProblemSet/Java/src/copy2.txt"));
    // char[] b = new char[1024];
    // int len;
    // while ((len = isr.read(b)) != -1) {
    // osw.write(b, 0, len);
    // }
    // isr.close();
    // osw.close();
    // }
    // public static void main(String[] args) throws IOException {
    // BufferedInputStream bis = new BufferedInputStream(
    // new FileInputStream("/Users/mac/ProblemSet/Java/src/copy1.txt"), 1024);
    // BufferedOutputStream bos = new BufferedOutputStream(
    // new FileOutputStream("/Users/mac/ProblemSet/Java/src/copy2.txt"));
    // byte[] b = new byte[1024];
    // int len;
    // while ((len = bis.read(b)) != -1) {
    // bos.write(b, 0, len);
    // }
    // bis.close();
    // bos.close();
    // }

    // String name;

    // public stu() {
    // }

    // public stu(String name) {
    // this.name = name;
    // }

    // public static void main(String[] args) {
    // useCacl((int a, int b) -> {
    // return a - b;
    // });
    // getProduct(2, 3, (int a, int b) -> {
    // return a * b;
    // });
    // List<String> list1 = List.of("陈玄风", "梅超风", "陆乘风", "曲灵风", "武眠风", "冯默风",
    // "罗玉风");
    // List<String> list2 = List.of("宋远桥", "俞莲舟", "俞岱岩", "张松溪", "张翠山", "殷梨亭",
    // "莫声谷");
    // list1.stream().filter(s -> s.length() == 3).forEach(System.out::print);
    // System.out.println("\n=============================");
    // list1.stream().limit(6).forEach(System.out::print);
    // System.out.println("\n=============================");
    // list2.stream().filter(s -> s.startsWith("张")).forEach(System.out::print);
    // System.out.println("\n=============================");
    // list2.stream().skip(1).forEach(System.out::print);
    // System.out.println("\n=============================");
    // Stream.concat(list1.stream(),
    // list2.stream()).collect(Collectors.toList()).forEach(System.out::print);
    // System.out.println("\n=============================");
    // list1.stream().map(stu::new).collect(Collectors.toList()).forEach(System.out::print);
    // System.out.println("\n=============================");
    // list1.stream().map(stu::new).forEach(System.out::print);
    // }

    // public static void useCacl(Calculator calculator) {
    // int c = calculator.calc(1, 2);
    // System.out.println(c);
    // }

    // public static void getProduct(int a, int b, IntCalc calc) {
    // int c = calc.calc(a, b);
    // System.out.println(c);
    // }
}

// interface Calculator {
// int calc(int a, int b);
// }

// @FunctionalInterface
// interface IntCalc {
// int calc(int a, int b);
// }

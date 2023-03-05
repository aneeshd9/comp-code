package com.aneeshd9.app.problemset;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Watermelon4A {
  private static BufferedReader reader;
  private static StringTokenizer tokenizer;

  private static String next() throws IOException {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      tokenizer = new StringTokenizer(reader.readLine());
    }
    return tokenizer.nextToken();
  }

  private static int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  public static String solution(int w) {
    if (w > 2 && w % 2 == 0) return "YES";
    else return "NO";
  }

  public static void main(String[] args) throws IOException {
    reader = new BufferedReader(new InputStreamReader(System.in));

    int w = nextInt();
    System.out.println(solution(w));
  }
}

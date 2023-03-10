package com.aneeshd9.app.problemset;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WayTooLongWords71A {
  static BufferedReader reader;
  static StringTokenizer tokenizer;

  static String next() throws IOException {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      tokenizer = new StringTokenizer(reader.readLine());
    }
    return tokenizer.nextToken();
  }

  static int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  public static String solution(String word) {
    if (word.length() <= 10) return word;
    else return "" + word.charAt(0) + (word.length() - 2) + word.charAt(word.length() - 1);
  }

  public static void main(String[] args) throws IOException {
    reader = new BufferedReader(new InputStreamReader(System.in));

    int t = nextInt();
    for (int tc = 0; tc < t; ++tc) {
      String word = next();
      System.out.println(solution(word));
    }
  }
}

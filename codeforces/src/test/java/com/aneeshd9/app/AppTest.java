package com.aneeshd9.app;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

import com.aneeshd9.app.problemset.Watermelon4A;

public class AppTest {

  @Test
  public void watermelon4ATest() {
    assertTrue(Watermelon4A.solution(8) == "YES");
  }
}

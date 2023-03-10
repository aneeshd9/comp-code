package com.aneeshd9.app;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

import com.aneeshd9.app.problemset.Watermelon4A;
import com.aneeshd9.app.problemset.WayTooLongWords71A;

public class AppTest {
  @Test
  public void watermelon4ATest() {
    assertTrue(Watermelon4A.solution(8) == "YES");
  }

  @Test
  public void wayTooLongWords71ATest() {
    assertTrue(WayTooLongWords71A.solution("word").equals("word"));
    assertTrue(WayTooLongWords71A.solution("localization").equals("l10n"));
    assertTrue(WayTooLongWords71A.solution("internationalization").equals("i18n"));
    assertTrue(WayTooLongWords71A.solution("pneumonoultramicroscopicsilicovolcanoconiosis").equals("p43s"));
  }
}

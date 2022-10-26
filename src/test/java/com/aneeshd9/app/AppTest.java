package com.aneeshd9.app;

import static org.junit.Assert.assertTrue;

import org.junit.Test;

import com.aneeshd9.app.leetcode.DailyChallenge;
import com.aneeshd9.app.leetcode.DynamicProgramming;

/**
 * Unit test for simple App.
 */
public class AppTest 
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue()
    {
        assertTrue( true );
    }

    @Test
    public void testLeetcodeFibonacci() {
        DynamicProgramming dp = new DynamicProgramming();
        assertTrue(dp.fib(2) == 1);
        assertTrue(dp.fib(3) == 2);
        assertTrue(dp.fib(4) == 3);
    }

    @Test
    public void testLeetcodeClimbingStairs() {
        DynamicProgramming dp = new DynamicProgramming();
        assertTrue(dp.climbStairs(2) == 2);
        assertTrue(dp.climbStairs(3) == 3);
    }

    @Test
    public void testLeetcodeMinCostClimbingStairs() {
        DynamicProgramming dp = new DynamicProgramming();
        assertTrue(dp.minCostClimbingStairs(new int[]{10, 15, 20}) == 15);
        assertTrue(dp.minCostClimbingStairs(new int[]{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) == 6);
    }

    @Test
    public void testLeetcodeContinuousSubarraySum() {
        DailyChallenge dc = new DailyChallenge();
        assertTrue(dc.checkSubarraySum(new int[]{23, 2, 4, 6, 7}, 6));
        assertTrue(dc.checkSubarraySum(new int[]{23, 2, 6, 4, 7}, 6));
        assertTrue(!dc.checkSubarraySum(new int[]{23, 2, 6, 4, 7}, 13));
    }
}

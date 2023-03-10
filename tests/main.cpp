#include <algorithm>
#include <cassert>  // assert()
#include <cstddef>
#include <iostream>  // cout, endl
#include <iterator>  // std::begin(), std::end()

#include <unordered_map>

#include "../src/median.h"
#include "tm/tm.h"

int main(void)
{
  TestManager tm{ "Median of 3 Tests" };
  {
    BEGIN_TEST(tm, "Median(1) ", "Vetor com tamanho inferior a 3.");
    int V[]{ 1, 2, 3 };
    int V_expected[]{ 1, 2, 3 };

    median_of_3(V, 0);
    // The original array must remain the same
    EXPECT_TRUE(std::equal(V, V + 3, V_expected));
  }
  {
    BEGIN_TEST(tm, "Median(2) ", "Odd -> Lo-Md-Hi");
    constexpr std::size_t len{ 7 };
    int V[]{ 10, 4, 5, 20, 6, 7, 30 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = V[3];

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(3) ", "Even -> Lo-Md-Hi");
    constexpr std::size_t len{ 6 };
    int V[]{ 10, 4, 30, 30, 5, 20 };
    int V_sorted[]{ 4, 5, 10, 20, 30, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(4) ", "Odd -> Lo-Hi-Md");
    constexpr std::size_t len{ 7 };
    int V[]{ 10, 4, 5, 30, 6, 7, 20 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(5) ", "Even -> Lo-Hi-Md");
    constexpr std::size_t len{ 6 };
    int V[]{ 10, 4, 30, 30, 5, 20 };
    int V_sorted[]{ 4, 5, 10, 20, 30, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(6) ", "Odd -> Md-Lo-Hi");
    constexpr std::size_t len{ 7 };
    int V[]{ 20, 4, 5, 10, 6, 7, 30 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(7) ", "Even -> Md-Lo-Hi");
    constexpr std::size_t len{ 6 };
    int V[]{ 20, 4, 10, 10, 5, 30 };
    int V_sorted[]{ 4, 5, 10, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(8) ", "Odd -> Md-Hi-Lo");
    constexpr std::size_t len{ 7 };
    int V[]{ 20, 4, 5, 30, 6, 7, 10 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(9) ", "Even -> Md-Hi-Lo");
    constexpr std::size_t len{ 6 };
    int V[]{ 20, 4, 30, 30, 5, 10 };
    int V_sorted[]{ 4, 5, 10, 20, 30, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(10) ", "Odd -> Hi-Md-Lo");
    constexpr std::size_t len{ 7 };
    int V[]{ 30, 4, 5, 20, 6, 7, 10 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(11) ", "Even -> Hi-Md-Lo");
    constexpr std::size_t len{ 6 };
    int V[]{ 30, 4, 20, 20, 5, 10 };
    int V_sorted[]{ 4, 5, 10, 20, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(12) ", "Odd -> Hi-Lo-Md");
    constexpr std::size_t len{ 7 };
    int V[]{ 30, 4, 5, 10, 6, 7, 20 };
    int V_sorted[]{ 4, 5, 6, 7, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median must be  V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }
  {
    BEGIN_TEST(tm, "Median(13) ", "Even -> Hi-Lo-Md");
    constexpr std::size_t len{ 6 };
    int V[]{ 30, 4, 10, 10, 5, 20 };
    int V_sorted[]{ 4, 5, 10, 10, 20, 30 };
    int median = 20;

    median_of_3(V, len);

    // Median might be either V[2] or V[3]
    EXPECT_TRUE(V[len - 1] == median);

    // Check whether we have all values.
    std::sort(V, V + len);
    EXPECT_TRUE(std::equal(V, V + len, V_sorted));
  }

  tm.summary();
  std::cout << std::endl;
  //== Reverse
  return EXIT_SUCCESS;
}

#include <gtest/gtest.h>

#include <ranges>
#include <vector>

#include "background/FillVec.hpp"

using Vec = std::vector<std::vector<bool>>;

struct FillVecTest : ::testing::Test {
  inline static constexpr size_t SIZE = 4;

  FillVecTest() : mVec(SIZE) {
    for (auto& v : mVec) {
      v = std::vector(SIZE, false);
    }
  }
  Vec mVec;
};

void compare(const Vec& lhs, const Vec& rhs) {
  ASSERT_EQ(lhs.size(), rhs.size());
  for (int i = 0; i < lhs.size(); ++i) {
    ASSERT_TRUE(std::ranges::equal(lhs[i], rhs[i]));
  }
}

TEST_F(FillVecTest, FillWholeVec) {
  fill_vec(mVec, 0, 0, SIZE, SIZE, true);
  compare(mVec, {
                    {true, true, true, true},
                    {true, true, true, true},
                    {true, true, true, true},
                    {true, true, true, true},
                });
}

TEST_F(FillVecTest, FillZeroElements) {
  fill_vec(mVec, 2, 2, 2, 2, true);
  compare(mVec, {
                    {false, false, false, false},
                    {false, false, false, false},
                    {false, false, false, false},
                    {false, false, false, false},
                });
}

TEST_F(FillVecTest, FillFirstTwoRows) {
  fill_vec(mVec, 0, 0, 2, SIZE, true);
  compare(mVec, {
                    {true, true, true, true},
                    {true, true, true, true},
                    {false, false, false, false},
                    {false, false, false, false},
                });
}

TEST_F(FillVecTest, FillLastTwoColumns) {
  fill_vec(mVec, 0, 2, SIZE, SIZE, true);
  compare(mVec, {
                    {false, false, true, true},
                    {false, false, true, true},
                    {false, false, true, true},
                    {false, false, true, true},
                });
}

TEST_F(FillVecTest, InvalidRangeShouldThrow) {
  EXPECT_THROW(fill_vec(mVec, 1, 1, 0, 1, true), std::runtime_error);
}

#pragma once
#include <SFML/Graphics.hpp>
#include <background/Ground.hpp>

class TextureStore;

class RoadGenerator {
 public:
  using RoadVec = std::vector<std::vector<bool>>;
  using GroundTypeVec = std::vector<std::vector<GroundType>>;

  static RoadVec generate();
};

namespace RoadPattern {
enum Pattern {
  /* * * * *
   - - - - -
   * * * * *
   * * * * *
   * * * * */
  VerticalLine = 0,
  /* * * | *
   * * * | *
   * * * | *
   * * * | *
   * * * | */
  HorizontalLine,
  /* * * | *
     - - - + -
   * * * | *
   * * * | *
   * * * | */
  SingleCrossroad,
  //    /* * | * *
  //     * * | * *
  //     * * | * *
  //     * * L - -
  //     * * * * */
  //    UpperRight,
  //    UpperLeft,
  //    LowerRight,
  //    LowerLeft,
  //    /* * * * *
  //     - - - - -
  //     * * | * *
  //     * * | * *
  //     * * | * */
  //    LetterT,
  //    /* * | * *
  //     * * | * *
  //     - - - - -
  //     * * * * *
  //     * * * * */
  //    ReversedT
  Size
};
}

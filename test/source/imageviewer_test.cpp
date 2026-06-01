#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "imageviewer" ? 0 : 1;
}

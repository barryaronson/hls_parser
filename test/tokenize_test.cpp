#include "tokenize.h"
#include "gtest/gtest.h"
#include <regex>

namespace {

TEST(Test, Tokenize) {
  std::string read = "tag:attribute1=1,attribute2=2";
  std::vector<std::string> expectedTokens = {"tag", "attribute1", "1",
                                             "attribute2", "2"};
  Tokenize tokenizer(read, std::regex(R"([:|,|=]+)"));

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    EXPECT_FALSE(expected == expectedTokens.end());
    EXPECT_EQ((*expected), (*token));
    ++expected;
  }
}

} // namespace
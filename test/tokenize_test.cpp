#include "tokenize.h"
#include "gtest/gtest.h"
#include <regex>

namespace {

/*
Tokenize a simple pseudo HLS line with a tag and its attributes
*/
TEST(Test, Tokenize) {
  std::string HLSLine = "tag:attribute1=1,attribute2=2";
  Tokenize tokenizer(HLSLine);

  std::vector<std::string> expectedTokens = {"tag", "attribute1", "1",
                                             "attribute2", "2"};

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    EXPECT_FALSE(expected == expectedTokens.end());
    EXPECT_EQ((*expected), (*token)); // check that each token matches what is expected
    ++expected;
  }
}

} // namespace
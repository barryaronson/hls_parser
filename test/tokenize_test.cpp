#include "tokenize.h"
#include "gtest/gtest.h"
#include <regex>

namespace {

/*
Tokenize a simple pseudo HLS line with a tag and its attributes
*/
TEST(Tokenize, Generic) {
  std::string line = "tag:attribute1=1,attribute2=2";
  Tokenize tokenizer(line);

  std::vector<std::string> expectedTokens = {"tag", "attribute1", "1",
                                             "attribute2", "2"};

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    EXPECT_FALSE(expected == expectedTokens.end());
    EXPECT_EQ((*expected),
              (*token)); // check that each token matches what is expected
    ++expected;
  }
}

/*
Tokenize HLS playlist first line
*/
TEST(Tokenize, M3U) {
  std::string line = "#EXTM3U";
  Tokenize tokenizer(line);

  std::vector<std::string> expectedTokens = {"#EXTM3U"};

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    EXPECT_FALSE(expected == expectedTokens.end());
    EXPECT_EQ((*expected),
              (*token)); // check that each token matches what is expected
    ++expected;
  }
}

/*
Tokenize a simple HLS line with a tag
*/
TEST(Tokenize, INDEPENDENT_SEGMENTS) {
  std::string line = "#EXT_X_INDEPENDENT_SEGMENTS";
  Tokenize tokenizer(line);

  std::vector<std::string> expectedTokens = {"#EXT_X_INDEPENDENT_SEGMENTS"};

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    EXPECT_FALSE(expected == expectedTokens.end());
    EXPECT_EQ((*expected),
              (*token)); // check that each token matches what is expected
    ++expected;
  }
}

/*
Tokenize an HLS line with multiple tags and attributes
*/
TEST(Tokenize, MEDIA) {
  std::string line =
      "EXT-X-MEDIA:TYPE=AUDIO,GROUP-ID=\"aac-128k\",NAME=\"English\",LANGUAGE="
      "\"en\",DEFAULT=YES,AUTOSELECT=YES,CHANNELS=\"2\",URI=\"audio/unenc/"
      "aac_128k/vod.m3u8\"";
  Tokenize tokenizer(line);

  std::vector<std::string> expectedTokens = {"EXT-X-MEDIA",
                                             "TYPE",
                                             "AUDIO",
                                             "GROUP-ID",
                                             "aac-128k",
                                             "NAME",
                                             "English",
                                             "LANGUAGE",
                                             "en",
                                             "DEFAULT",
                                             "YES",
                                             "AUTOSELECT",
                                             "YES",
                                             "CHANNELS",
                                             "2",
                                             "URI",
                                             "audio/unenc/aac_128k/vod.m3u8"};

  auto expected = expectedTokens.begin();
  for (auto token = tokenizer.begin(); token != tokenizer.end(); ++token) {
    ASSERT_TRUE(expected != expectedTokens.end());
    EXPECT_EQ((*expected),
              (*token)); // check that each token matches what is expected
    ++expected;
  }
}

/*
#EXT-X-STREAM-INF:BANDWIDTH=2483789,AVERAGE-BANDWIDTH=1762745,CODECS="mp4a.40.2,hvc1.2.4.L90.90",RESOLUTION=960x540,FRAME-RATE=23.97,VIDEO-RANGE=PQ,AUDIO="aac-128k",CLOSED-CAPTIONS=NONE
hdr10/unenc/1650k/vod.m3u8
*/

/*
Tokenize an HLS line with multiple tags and attributes
*/
TEST(Tokenize, STREAM_INFO) {
  std::string line =
      "#EXT-X-STREAM-INF:BANDWIDTH=2483789,AVERAGE-BANDWIDTH=1762745,CODECS="
      "\"mp4a.40.2,hvc1.2.4.L90.90\",RESOLUTION=960x540,FRAME-RATE=23.97,VIDEO-"
      "RANGE=PQ,AUDIO=\"aac-128k\",CLOSED-CAPTIONS=NONE";
  Tokenize lineTokenizer(line);

  std::vector<std::string> expectedLineTokens = {
      "#EXT-X-STREAM-INF", "BANDWIDTH", "2483789",    "AVERAGE-BANDWIDTH",
      "1762745",           "CODECS",    "mp4a.40.2",  "hvc1.2.4.L90.90",
      "RESOLUTION",        "960x540",   "FRAME-RATE", "23.97",
      "VIDEO-RANGE",       "PQ",        "AUDIO",      "aac-128k",
      "CLOSED-CAPTIONS",   "NONE"};

  auto expectedLine = expectedLineTokens.begin();
  for (auto token = lineTokenizer.begin(); token != lineTokenizer.end();
       ++token) {
    ASSERT_TRUE(expectedLine != expectedLineTokens.end());
    EXPECT_EQ((*expectedLine),
              (*token)); // check that each token matches what is expected
    ++expectedLine;
  }

  std::string URI = "hdr10/unenc/1650k/vod.m3u8";
  Tokenize URITokenizer(URI);
  std::vector<std::string> expectedURITokens = {"hdr10/unenc/1650k/vod.m3u8"};

  auto expectedURI = expectedURITokens.begin();
  for (auto token = URITokenizer.begin(); token != URITokenizer.end();
       ++token) {
    ASSERT_TRUE(expectedURI != expectedLineTokens.end());
    EXPECT_EQ((*expectedURI),
              (*token)); // check that each token matches what is expected
    ++expectedURI;
  }
}

} // namespace
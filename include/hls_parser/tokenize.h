#pragma once

#include <regex>
#include <string>

/*! \class Tokenize
    \brief Tokenizes playlist.

    A single line from a playlist is tokenized for later parsing.
*/
class Tokenize {
public:
  // The constructor splits 'str' into a series tokens using 're' and stores the
  // sequence in 'it' so that the whole range of tokens ('it, {}') can be used
  // to initialize a vector of tokens ('tokenized')
  Tokenize(const std::string &str, const std::regex re)
      : it{str.begin(), str.end(), re, -1}, tokenized{it, {}} {}
  const auto begin() const { return tokenized.begin(); }
  const auto end() const { return tokenized.end(); }

private:
  std::sregex_token_iterator it; // for tokenizing
  std::vector<std::string>
      tokenized; // input string is split into tokens and stored here
};
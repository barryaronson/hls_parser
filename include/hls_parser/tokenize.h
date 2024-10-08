#pragma once

#include <regex>
#include <string>

/*! \class Tokenize
    \brief Tokenizes an HLS playlist.
    \details A single line from an HLS playlist is tokenized for later parsing.
*/
class Tokenize {
public:
  /*! \brief Constructor for tokenizing a single line (or concatenated continued
      lines) from an HLS playlist for later parsing.
      \param line A line from a playlist (see `Playlist`)
      \param re Regular expression used for parsing (default should work for all
      playlists)
      \returns Nothing
  */
  Tokenize(const std::string &line,
           const std::regex re = std::regex(R"([:|,|=]+)"))
      : it{line.begin(), line.end(), re, -1}, tokenized{it, {}} {
  } // The constructor splits 'str' into a series tokens using 're' and stores
    // the sequence in 'it' so that the whole range of tokens ('it, {}') can be
    // used to initialize a vector of tokens ('tokenized')

  /*! \brief Gets an iterator that points to the first token.
      \returns Iterator
  */
  const auto begin() const { return tokenized.begin(); }

  /*! \brief Gets an iterator that points to the end of the tokens.
      \returns Iterator
  */
  const auto end() const { return tokenized.end(); }

private:
  std::sregex_token_iterator it; // for tokenizing
  std::vector<std::string>
      tokenized; // input string is split into tokens and stored here
};
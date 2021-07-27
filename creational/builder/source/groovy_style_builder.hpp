/**
 * Copyright 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_GROOVY_STYLE_BUILDER_HPP_
#define DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_GROOVY_STYLE_BUILDER_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>


struct Tag {
  const int kIndentSize = 2;
  std::string name;
  std::string text;
  std::vector<Tag> children;
  std::vector<std::pair<std::string, std::string>> attributes;

  std::string Str(int indent = 0) const;

  Tag(const std::string &name, const std::string &text = "");
  Tag(const std::string &name, const std::vector<Tag> &children);
};

struct P : Tag {
  P(const std::string &text);
  P(std::initializer_list<Tag> children);
};

struct IMG : Tag {
  explicit IMG(const std::string &url);
};

struct BODY : Tag {
  BODY(std::initializer_list<Tag> children);
};

#endif  // DESIGN_PATTERNS_CREATIONAL_BUILDER_SOURCE_GROOVY_STYLE_BUILDER_HPP_

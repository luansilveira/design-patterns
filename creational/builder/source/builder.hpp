/**
 * Copyright 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_
#define DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_

#include <iostream>
#include <string>
#include <vector>

class HtmlElement {
 public:
  explicit HtmlElement(const std::string &name, const std::string &text = "");

  void AddChild(const std::string &name, const std::string &text);

  std::string Str(int indent = 0) const;

 private:
  const size_t kIndentSize = 2;
  std::string name_;
  std::string text_;
  std::vector<HtmlElement> children_;
};

class HtmlBuilder {
 public:
  HtmlBuilder(const std::string &root_name);

  void AddChild(const std::string &name, const std::string &text);

  std::string Str() const;

 private:
  HtmlElement root_;
};

#endif  // DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_

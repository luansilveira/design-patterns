//
// Created by Luan Silveira on 23/07/2021.
//

#ifndef DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_
#define DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class HtmlElement {
 public:
  HtmlElement(const std::string &name, const std::string &text = "");

  void add_child(const std::string &name, const std::string &text);

  std::string str(int indent = 0) const;

 private:
  const size_t kIndentSize = 2;
  std::string name_;
  std::string text_;
  std::vector<HtmlElement> children_;
};

class HtmlBuilder {
 public:
  HtmlBuilder(const std::string &root_name);

  void add_child(const std::string &name, const std::string &text);

  std::string str() const;

 private:
  HtmlElement root_;
};

#endif  // DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_BUILDER_HPP_

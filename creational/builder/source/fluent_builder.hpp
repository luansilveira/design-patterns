/**
 * Copyright 2021 Luan Silveira
 */

#ifndef DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_FLUENT_BUILDER_HPP_
#define DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_FLUENT_BUILDER_HPP_

#include <iostream>
#include <string>
#include <vector>

class FluentHtmlBuilder;

class FluentHtmlElement {
 public:
  explicit FluentHtmlElement(const std::string &name,
                             const std::string &text = "");

  void AddChild(const std::string &name, const std::string &text);

  std::string Str(int indent = 0) const;

  static FluentHtmlBuilder Create(const std::string &root_name);

 private:
  const size_t kIndentSize = 2;
  std::string name_;
  std::string text_;
  std::vector<FluentHtmlElement> children_;
};

class FluentHtmlBuilder {
 public:
  FluentHtmlBuilder(const std::string &root_name);

  FluentHtmlBuilder &AddChild(const std::string &name, const std::string &text);

  std::string Str() const;

  operator FluentHtmlElement() const;

  FluentHtmlElement Build() const;

 private:
  FluentHtmlElement root_;
};

#endif  // DESIGN_PATTERNS_BEHAVIORAL_BUILDER_SOURCE_FLUENT_BUILDER_HPP_

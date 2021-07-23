/**
 * Copyright 2021 Luan Silveira
 */

#include "builder.hpp"

HtmlElement::HtmlElement(const std::string& name, const std::string& text)
    : name_(name), text_(text) {}

void HtmlElement::add_child(const std::string& name, const std::string& text) {
  children_.emplace_back(name, text);
}

std::string HtmlElement::str(int indent) const {
  std::ostringstream oss;
  std::string i(kIndentSize * indent, ' ');
  oss << i << "<" << name_ << ">" << std::endl;
  if (!text_.empty()) {
    oss << std::string(kIndentSize * (indent + 1), ' ') << text_ << std::endl;
  }
  for (const auto& e : children_) {
    oss << e.str(indent + 1);
  }
  oss << i << "</" << name_ << ">" << std::endl;
  return oss.str();
}

HtmlBuilder::HtmlBuilder(const std::string& root_name) : root_(root_name) {}

std::string HtmlBuilder::str() const { return root_.str(); }

void HtmlBuilder::add_child(const std::string& name, const std::string& text) {
  root_.add_child(name, text);
}

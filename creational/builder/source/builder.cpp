/**
 * Copyright 2021 Luan Silveira
 */

#include "builder.hpp"

#include <sstream>

HtmlElement::HtmlElement(const std::string& name, const std::string& text)
    : name_(name), text_(text) {}

void HtmlElement::AddChild(const std::string& name, const std::string& text) {
  children_.emplace_back(name, text);
}

std::string HtmlElement::Str(int indent) const {
  std::ostringstream oss;
  std::string i(kIndentSize * indent, ' ');
  oss << i << "<" << name_ << ">" << std::endl;
  if (!text_.empty()) {
    oss << std::string(kIndentSize * (indent + 1), ' ') << text_ << std::endl;
  }
  for (const auto& e : children_) {
    oss << e.Str(indent + 1);
  }
  oss << i << "</" << name_ << ">" << std::endl;
  return oss.str();
}

HtmlBuilder::HtmlBuilder(const std::string& root_name) : root_(root_name) {}

std::string HtmlBuilder::Str() const { return root_.Str(); }

void HtmlBuilder::AddChild(const std::string& name, const std::string& text) {
  root_.AddChild(name, text);
}

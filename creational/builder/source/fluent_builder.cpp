/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "fluent_builder.hpp"

#include <sstream>

FluentHtmlElement::FluentHtmlElement(const std::string& name,
                                     const std::string& text)
    : name_(name), text_(text) {}

void FluentHtmlElement::AddChild(const std::string& name,
                                 const std::string& text) {
  children_.emplace_back(name, text);
}

std::string FluentHtmlElement::Str(int indent) const {
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

FluentHtmlBuilder FluentHtmlElement::Create(const std::string& root_name) {
  return {root_name};
}

FluentHtmlBuilder::FluentHtmlBuilder(const std::string& root_name)
    : root_(root_name) {}

std::string FluentHtmlBuilder::Str() const { return root_.Str(); }

FluentHtmlBuilder& FluentHtmlBuilder::AddChild(const std::string& name,
                                               const std::string& text) {
  root_.AddChild(name, text);
  return *this;
}

FluentHtmlBuilder::operator FluentHtmlElement() const { return root_;}

FluentHtmlElement FluentHtmlBuilder::Build() const { return root_;}

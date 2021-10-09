/*
 * Copyright (c) 2021 Luan Silveira
 */

#include "groovy_style_builder.hpp"

Tag::Tag(const std::string &name, const std::string &text)
    : name(name),
      text(text) {}

Tag::Tag(const std::string &name, const std::vector<Tag> &children)
    : name(name),
      children(children) {}

std::string Tag::Str(int indent) const {
  std::ostringstream oss;
  std::string i(kIndentSize * indent, ' ');
  oss << i << "<" << name;
  for (const auto &att : attributes) {
    oss << " " << att.first << "=\"" << att.second << "\"";
  }
  if (children.empty() && text.empty()) {
    oss << "/>" << std::endl;
  } else {
    oss << ">" << std::endl;
    if (!text.empty()) {
      oss << std::string(kIndentSize * (indent + 1), ' ') << text << std::endl;
    }
    for (const auto &child : children) {
      oss << child.Str(indent + 1);
    }
    oss << i << "</" << name << ">" << std::endl;
  }
  return oss.str();
}

P::P(const std::string &text)
    : Tag("p", text) {}

P::P(std::initializer_list<Tag> children)
    : Tag("p", children) {}


IMG::IMG(const std::string &url)
    : Tag("img") {
  attributes.emplace_back("url", url);
}

BODY::BODY(std::initializer_list<Tag> children)
: Tag("body", children) {}


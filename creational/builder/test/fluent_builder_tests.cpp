/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "fluent_builder.hpp"

TEST(FluentHtmlBuilderTestSuite, UnorderedList) {
  auto builder = FluentHtmlElement::Create("ul")
                     .AddChild("li", "Hello")
                     .AddChild("li", "World");
  std::string expect_result = R"(<ul>
  <li>
    Hello
  </li>
  <li>
    World
  </li>
</ul>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

TEST(FluentHtmlBuilderTestSuite, Paragraph) {
  auto builder = FluentHtmlElement::Create("body")
                     .AddChild("p", "This is a paragraph");
  std::string expect_result = R"(<body>
  <p>
    This is a paragraph
  </p>
</body>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

TEST(FluentHtmlBuilderTestSuite, EmptyHtml) {
  auto builder = FluentHtmlElement::Create("body");
  std::string expect_result = R"(<body>
</body>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

TEST(FluentHtmlBuilderTestSuite, FluentHtmlElementConversion) {
  FluentHtmlElement element = FluentHtmlElement::Create("body");
  std::string expect_result = R"(<body>
</body>
)";
  ASSERT_EQ(expect_result, element.Str());
}

TEST(FluentHtmlBuilderTestSuite, FluentHtmlElementBuild) {
  FluentHtmlElement element = FluentHtmlElement::Create("body").Build();
  std::string expect_result = R"(<body>
</body>
)";
  ASSERT_EQ(expect_result, element.Str());
}

/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "builder.hpp"

TEST(HtmlBuilderTestSuite, UnorderedList) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"ul"};
  builder.AddChild("li", "Hello");
  builder.AddChild("li", "World");
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

TEST(HtmlBuilderTestSuite, Paragraph) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"body"};
  builder.AddChild("p", "This is a paragraph");
  std::string expect_result = R"(<body>
  <p>
    This is a paragraph
  </p>
</body>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

TEST(HtmlBuilderTestSuite, EmptyHtml) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"body"};
  std::string expect_result = R"(<body>
</body>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "builder.hpp"

TEST(HtmlBuilderTestSuite, UnorderedList) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "Hello");
  builder.add_child("li", "World");
  std::string expect_result = R"(<ul>
  <li>
    Hello
  </li>
  <li>
    World
  </li>
</ul>
)";
  ASSERT_EQ(expect_result, builder.str());
}

TEST(HtmlBuilderTestSuite, Paragraph) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"body"};
  builder.add_child("p", "This is a paragraph");
  std::string expect_result = R"(<body>
  <p>
    This is a paragraph
  </p>
</body>
)";
  ASSERT_EQ(expect_result, builder.str());
}

TEST(HtmlBuilderTestSuite, EmptyHtml) {
  ASSERT_TRUE(true);
  HtmlBuilder builder{"body"};
  std::string expect_result = R"(<body>
</body>
)";
  ASSERT_EQ(expect_result, builder.str());
}

/**
 * Copyright 2021 Luan Silveira
 */

#include <gtest/gtest.h>

#include "groovy_style_builder.hpp"

TEST(GroovyStyleHtmlBuilderTestSuite, Image) {
  auto html = P {
        IMG { "https://my_image_url.com"}
  };
  std::string expect_result = R"(<p>
  <img url="https://my_image_url.com"/>
</p>
)";
  ASSERT_EQ(expect_result, html.Str());
}

TEST(GroovyStyleHtmlBuilderTestSuite, Paragraph) {
  auto html = BODY {
    P {
      "This is a paragraph"
    }
  };
  std::string expect_result = R"(<body>
  <p>
    This is a paragraph
  </p>
</body>
)";
  ASSERT_EQ(expect_result, html.Str());
}

TEST(GroovyStyleHtmlBuilderTestSuite, EmptyHtml) {
  auto builder = BODY {};
  std::string expect_result = R"(<body/>
)";
  ASSERT_EQ(expect_result, builder.Str());
}

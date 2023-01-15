#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include "doctest.h"
#include "Json.h"

TEST_CASE("tests for json") {
CHECK_EQ(Json{{}, {}}.toString(), "{}");

std::vector<std::string> keys = {"bool_token",
                                 "str_token",
                                 "array_token",
                                 "double_token",
                                 "int_token"};
std::vector<Token> tokens = {BoolToken(true),
                             StrToken("hi"),
                             ArrayToken({NumToken(1), StrToken("ok"), BoolToken(false)}),
                             DoubleToken(7.68),
                             NumToken(9090)};

CHECK_EQ(Json{keys, tokens}.toString(),
"{\"bool_token\":true,\"str_token\":\"hi\",\"array_token\":[1,\"ok\",false],"
"\"double_token\":7.680000,\"int_token\":9090}");

CHECK_EQ(Json{{"str_token"}, {StrToken("hello world")}}.toString(),
"{\"str_token\":\"hello world\"}");

keys = {"array_token"};
tokens = {ArrayToken({StrToken("hello"), ArrayToken({BoolToken(true), BoolToken(false)}), StrToken("world")})};

CHECK_EQ(Json{keys, tokens}.toString(),
"{\"array_token\":[\"hello\",[true,false],\"world\"]}");
}

#pragma once
#include <string>
#include <vector>

class Token {
public:
    std::string token{};
};

class NumToken : public Token {
public:
    explicit NumToken(int i) {
        token = std::to_string(i);
    }
};

class DoubleToken : public Token {
public:
    explicit DoubleToken(double d) {
        token = std::to_string(d);
    }
};

class StrToken : public Token {
public:
    explicit StrToken(std::string s) {
        token = std::move(s);
        token.append("\"");
        token.insert(0, "\"");
    }
};

class BoolToken : public Token {
public:
    explicit BoolToken(bool b) {
        token = b ? "true" : "false";
    }
};

class ArrayToken : public Token {
public:
    explicit ArrayToken(std::vector<Token> v) {
        token = "[";
        for (auto &i : v) {
            token.append(i.token);
            token.append(",");
        }
        token.pop_back();
        token.append("]");
    }
};

class Json {
public:
    std::vector<std::string> keys;
    std::vector<Token> tokens;
    Json(std::vector<std::string> k, std::vector<Token> t) : keys(std::move(k)), tokens(std::move(t)) {}

    std::string toString() {
        std::string json = "{";
        for (int i = 0; i < keys.size(); ++i) {
            json.append("\"");
            json.append(keys[i]);
            json.append("\"");
            json.append(":");
            json.append(tokens[i].token);
            json.append(",");
        }
        if (json.size() > 1) json.pop_back();
        json.append("}");
        return json;
    }
};

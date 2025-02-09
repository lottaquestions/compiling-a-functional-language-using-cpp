#pragma once
#include <memory>
#include <vector>
#include <string>
#include "langtypes.hpp"
#include "env.hpp"

struct ast{
  virtual ~ast() = default;
  virtual type_ptr typecheck(type_mgr& mgr, const type_env& env) const = 0;
  virtual void print(int indent, std::ostream& to) const = 0;
  //virtual void match(type_ptr t, type_mgr& mgr, type_env& env) const;
};

using ast_ptr = std::unique_ptr<ast>;

struct pattern{
  virtual ~pattern() = default;

  virtual void print(std::ostream& to) const = 0;
  virtual void match(type_ptr t, type_mgr& mgr, type_env& env) const = 0;
};

using pattern_ptr = std::unique_ptr<pattern>;

struct branch{
  pattern_ptr pat;
  ast_ptr expr;

  branch(pattern_ptr p, ast_ptr a) : pat(std::move(p)), expr(std::move(a)){}
};

using branch_ptr = std::unique_ptr<branch>;

struct constructor{
  std::string name;
  std::vector<std::string> types;

  constructor(std::string n, std::vector<std::string> ts) : name(std::move(n)), types(std::move(ts)){}
};

using constructor_ptr = std::unique_ptr<constructor>;

struct definition{
  virtual ~definition() = default;

  virtual void typecheck_first(type_mgr& mgr, type_env& env) = 0;
  virtual void typecheck_second(type_mgr& mgr, const type_env& env) const = 0;
};


using definition_ptr = std::unique_ptr<definition>;

enum binop { PLUS, MINUS, TIMES, DIVIDE };

struct ast_int : public ast {
  int value;

  explicit ast_int(int v) : value(v){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct ast_lid : public ast {
  std::string id;

  explicit ast_lid(std::string i) : id(std::move(i)){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct ast_uid : public ast {
  std::string id;

  explicit ast_uid(std::string i) : id(std::move(i)){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct ast_binop : public ast {
  binop op;
  ast_ptr left;
  ast_ptr right;

  ast_binop(binop o, ast_ptr l, ast_ptr r) : op(o), left(std::move(l)), right(std::move(r)){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct ast_app : public ast {
  ast_ptr left;
  ast_ptr right;

  ast_app(ast_ptr l, ast_ptr r) : left(std::move(l)), right(std::move(r)){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct ast_case : public ast {
  ast_ptr of;
  std::vector<branch_ptr> branches;

  ast_case(ast_ptr o, std::vector<branch_ptr> b) : of(std::move(o)), branches(std::move(b)){}

  void print(int indent, std::ostream& to) const;
  type_ptr typecheck(type_mgr& mgr, const type_env& env) const;
};

struct pattern_var : public pattern {
  std::string var;

  pattern_var(std::string v) : var(std::move(v)){}

  void print(std::ostream& to) const;
  void match(type_ptr t, type_mgr& mgr, type_env& env) const;
};

struct pattern_constr : public pattern{
  std::string constr;
  std::vector<std::string> params;

  pattern_constr(std::string c, std::vector<std::string> p) : constr(std::move(c)), params(std::move(p)){}

  void print(std::ostream& to) const;
  void match(type_ptr t, type_mgr& mgr, type_env& env) const;
};

struct definition_defn : public definition{
  std::string name;
  std::vector<std::string> params;
  ast_ptr body;

  type_ptr return_type;
  std::vector<type_ptr> param_types;

  definition_defn(std::string n, std::vector<std::string> p, ast_ptr b) : name(std::move(n)), params(std::move(p)), body(std::move(b)){}
  void typecheck_first(type_mgr& mgr, type_env& env);
  void typecheck_second(type_mgr& mgr, const type_env& env) const;
};

struct definition_data : public definition{
  std::string name;
  std::vector<constructor_ptr> constructors;

  definition_data(std::string n, std::vector<constructor_ptr> cs) : name(std::move(n)), constructors(std::move(cs)){}
  void typecheck_first(type_mgr& mgr, type_env& env);
  void typecheck_second(type_mgr& mgr, const type_env& env) const;
};

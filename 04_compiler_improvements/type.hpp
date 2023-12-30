#pragma once
#include <memory>
#include <map>

struct type_mgr;

struct type{
  virtual ~type() = default;

  virtual void print(const type_mgr& mgr, std::ostream& to) const = 0;
};

using type_ptr = std::shared_ptr<type>;

struct type_var : public type {
  std::string name;

  type_var(std::string n) : name(std::move(n)){}
  void print(const type_mgr& mgr, std::ostream& to) const;
};


struct type_base : public type {
  std::string name;

  type_base(std::string n) : name(std::move(n)){}
  void print(const type_mgr& mgr, std::ostream& to) const;
};

struct type_arr : public type {
  type_ptr left;
  type_ptr right;

  type_arr(type_ptr l, type_ptr r) : left(std::move(l)), right(std::move(r)){}
  void print(const type_mgr& mgr, std::ostream& to) const;
};

struct type_mgr{
  int last_id = 0;
  std::map<std::string, type_ptr> types;

  std::string new_type_name();
  type_ptr new_type();
  type_ptr new_arrow_type();

  void unify(type_ptr l, type_ptr r);
  type_ptr resolve(type_ptr t, type_var*& var);
  void bind(const std::string& s, type_ptr t);
};

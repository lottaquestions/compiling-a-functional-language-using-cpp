// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.



// First part of user prologue.
#line 1 "parser.y"

  #include <string>
  #include <iostream>
  #include "ast.hpp"
  #include "parser.hpp"

  std::vector<definition_ptr> program;
  extern yy::parser::symbol_type yylex();
  /*
  Next, we must recognize that Bison was originally made for C, rather than C++. In order to allow the parser to store and operate on semantic values of various types, the canonical solution back in those times was to use a C union. Unions are great, but for C++, they’re more trouble than they’re worth: unions don’t allow for non-trivial constructors! This means that stuff like std::unique_ptr and std::string is off limits as a semantic value. But we’d really much rather use them! The solution is to:
   
      1. Specify the language to be C++, rather than C.
      2. Enable the variant API feature, which uses a lightweight std::variant alternative in place of a union.
      3. Enable the creation of token constructors, which we will use in Flex.
   
  In order to be able to use the variant-based API, we also need to change the Flex yylex function to return yy::parser::symbol_type. You can see it in our forward declaration of yylex in scanner.l

  To compile: 
  bison -o parser.cpp -d parser.y

  Note : We used the -d option for Bison to generate the compiler_parser.hpp header file, which exports our token declarations and token creation functions, allowing us to use them in Flex.
 */

#line 64 "parser.cpp"


#include "parser.hpp"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 141 "parser.cpp"


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 28: // aAdd
      case 29: // aMul
      case 30: // app
      case 31: // appBase
      case 32: // case
        value.YY_MOVE_OR_COPY< ast_ptr > (YY_MOVE (that.value));
        break;

      case 34: // branch
        value.YY_MOVE_OR_COPY< branch_ptr > (YY_MOVE (that.value));
        break;

      case 38: // constructor
        value.YY_MOVE_OR_COPY< constructor_ptr > (YY_MOVE (that.value));
        break;

      case 24: // definition
      case 25: // defn
      case 36: // data
        value.YY_MOVE_OR_COPY< definition_ptr > (YY_MOVE (that.value));
        break;

      case 7: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 35: // pattern
        value.YY_MOVE_OR_COPY< pattern_ptr > (YY_MOVE (that.value));
        break;

      case 19: // LID
      case 20: // UID
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 33: // branches
        value.YY_MOVE_OR_COPY< std::vector<branch_ptr> > (YY_MOVE (that.value));
        break;

      case 37: // constructors
        value.YY_MOVE_OR_COPY< std::vector<constructor_ptr> > (YY_MOVE (that.value));
        break;

      case 22: // program
      case 23: // definitions
        value.YY_MOVE_OR_COPY< std::vector<definition_ptr> > (YY_MOVE (that.value));
        break;

      case 26: // lowercaseParams
      case 27: // uppercaseParams
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 28: // aAdd
      case 29: // aMul
      case 30: // app
      case 31: // appBase
      case 32: // case
        value.move< ast_ptr > (YY_MOVE (that.value));
        break;

      case 34: // branch
        value.move< branch_ptr > (YY_MOVE (that.value));
        break;

      case 38: // constructor
        value.move< constructor_ptr > (YY_MOVE (that.value));
        break;

      case 24: // definition
      case 25: // defn
      case 36: // data
        value.move< definition_ptr > (YY_MOVE (that.value));
        break;

      case 7: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case 35: // pattern
        value.move< pattern_ptr > (YY_MOVE (that.value));
        break;

      case 19: // LID
      case 20: // UID
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 33: // branches
        value.move< std::vector<branch_ptr> > (YY_MOVE (that.value));
        break;

      case 37: // constructors
        value.move< std::vector<constructor_ptr> > (YY_MOVE (that.value));
        break;

      case 22: // program
      case 23: // definitions
        value.move< std::vector<definition_ptr> > (YY_MOVE (that.value));
        break;

      case 26: // lowercaseParams
      case 27: // uppercaseParams
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 28: // aAdd
      case 29: // aMul
      case 30: // app
      case 31: // appBase
      case 32: // case
        value.copy< ast_ptr > (that.value);
        break;

      case 34: // branch
        value.copy< branch_ptr > (that.value);
        break;

      case 38: // constructor
        value.copy< constructor_ptr > (that.value);
        break;

      case 24: // definition
      case 25: // defn
      case 36: // data
        value.copy< definition_ptr > (that.value);
        break;

      case 7: // INT
        value.copy< int > (that.value);
        break;

      case 35: // pattern
        value.copy< pattern_ptr > (that.value);
        break;

      case 19: // LID
      case 20: // UID
        value.copy< std::string > (that.value);
        break;

      case 33: // branches
        value.copy< std::vector<branch_ptr> > (that.value);
        break;

      case 37: // constructors
        value.copy< std::vector<constructor_ptr> > (that.value);
        break;

      case 22: // program
      case 23: // definitions
        value.copy< std::vector<definition_ptr> > (that.value);
        break;

      case 26: // lowercaseParams
      case 27: // uppercaseParams
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 28: // aAdd
      case 29: // aMul
      case 30: // app
      case 31: // appBase
      case 32: // case
        value.move< ast_ptr > (that.value);
        break;

      case 34: // branch
        value.move< branch_ptr > (that.value);
        break;

      case 38: // constructor
        value.move< constructor_ptr > (that.value);
        break;

      case 24: // definition
      case 25: // defn
      case 36: // data
        value.move< definition_ptr > (that.value);
        break;

      case 7: // INT
        value.move< int > (that.value);
        break;

      case 35: // pattern
        value.move< pattern_ptr > (that.value);
        break;

      case 19: // LID
      case 20: // UID
        value.move< std::string > (that.value);
        break;

      case 33: // branches
        value.move< std::vector<branch_ptr> > (that.value);
        break;

      case 37: // constructors
        value.move< std::vector<constructor_ptr> > (that.value);
        break;

      case 22: // program
      case 23: // definitions
        value.move< std::vector<definition_ptr> > (that.value);
        break;

      case 26: // lowercaseParams
      case 27: // uppercaseParams
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 28: // aAdd
      case 29: // aMul
      case 30: // app
      case 31: // appBase
      case 32: // case
        yylhs.value.emplace< ast_ptr > ();
        break;

      case 34: // branch
        yylhs.value.emplace< branch_ptr > ();
        break;

      case 38: // constructor
        yylhs.value.emplace< constructor_ptr > ();
        break;

      case 24: // definition
      case 25: // defn
      case 36: // data
        yylhs.value.emplace< definition_ptr > ();
        break;

      case 7: // INT
        yylhs.value.emplace< int > ();
        break;

      case 35: // pattern
        yylhs.value.emplace< pattern_ptr > ();
        break;

      case 19: // LID
      case 20: // UID
        yylhs.value.emplace< std::string > ();
        break;

      case 33: // branches
        yylhs.value.emplace< std::vector<branch_ptr> > ();
        break;

      case 37: // constructors
        yylhs.value.emplace< std::vector<constructor_ptr> > ();
        break;

      case 22: // program
      case 23: // definitions
        yylhs.value.emplace< std::vector<definition_ptr> > ();
        break;

      case 26: // lowercaseParams
      case 27: // uppercaseParams
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 62 "parser.y"
                  { program = std::move(yystack_[0].value.as < std::vector<definition_ptr> > ()); }
#line 779 "parser.cpp"
    break;

  case 3:
#line 66 "parser.y"
                             { yylhs.value.as < std::vector<definition_ptr> > () = std::move(yystack_[1].value.as < std::vector<definition_ptr> > ()); yylhs.value.as < std::vector<definition_ptr> > ().push_back(std::move(yystack_[0].value.as < definition_ptr > ())); }
#line 785 "parser.cpp"
    break;

  case 4:
#line 67 "parser.y"
                 { yylhs.value.as < std::vector<definition_ptr> > () = std::vector<definition_ptr>() ; yylhs.value.as < std::vector<definition_ptr> > ().push_back(std::move(yystack_[0].value.as < definition_ptr > ())); }
#line 791 "parser.cpp"
    break;

  case 5:
#line 71 "parser.y"
           { yylhs.value.as < definition_ptr > () = std::move(yystack_[0].value.as < definition_ptr > ()); }
#line 797 "parser.cpp"
    break;

  case 6:
#line 72 "parser.y"
           { yylhs.value.as < definition_ptr > () = std::move(yystack_[0].value.as < definition_ptr > ());}
#line 803 "parser.cpp"
    break;

  case 7:
#line 76 "parser.y"
                                                        { yylhs.value.as < definition_ptr > () = definition_ptr(new definition_defn(std::move(yystack_[5].value.as < std::string > ()), std::move(yystack_[4].value.as < std::vector<std::string> > ()), std::move(yystack_[1].value.as < ast_ptr > ())));}
#line 809 "parser.cpp"
    break;

  case 8:
#line 80 "parser.y"
             { yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>(); }
#line 815 "parser.cpp"
    break;

  case 9:
#line 81 "parser.y"
                          { yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[1].value.as < std::vector<std::string> > ()); yylhs.value.as < std::vector<std::string> > ().push_back(std::move(yystack_[0].value.as < std::string > ())); }
#line 821 "parser.cpp"
    break;

  case 10:
#line 85 "parser.y"
             { yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>(); }
#line 827 "parser.cpp"
    break;

  case 11:
#line 86 "parser.y"
                          { yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[1].value.as < std::vector<std::string> > ()); yylhs.value.as < std::vector<std::string> > ().push_back(std::move(yystack_[0].value.as < std::string > ())); }
#line 833 "parser.cpp"
    break;

  case 12:
#line 90 "parser.y"
                     { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_binop(PLUS, std::move(yystack_[2].value.as < ast_ptr > ()), std::move(yystack_[0].value.as < ast_ptr > ()))); }
#line 839 "parser.cpp"
    break;

  case 13:
#line 91 "parser.y"
                      { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_binop(MINUS, std::move(yystack_[2].value.as < ast_ptr > ()), std::move(yystack_[0].value.as < ast_ptr > ()))); }
#line 845 "parser.cpp"
    break;

  case 14:
#line 92 "parser.y"
           { yylhs.value.as < ast_ptr > () = std::move(yystack_[0].value.as < ast_ptr > ()); }
#line 851 "parser.cpp"
    break;

  case 15:
#line 96 "parser.y"
                     { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_binop(TIMES, std::move(yystack_[2].value.as < ast_ptr > ()), std::move(yystack_[0].value.as < ast_ptr > ()))); }
#line 857 "parser.cpp"
    break;

  case 16:
#line 97 "parser.y"
                      { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_binop(DIVIDE, std::move(yystack_[2].value.as < ast_ptr > ()), std::move(yystack_[0].value.as < ast_ptr > ()))); }
#line 863 "parser.cpp"
    break;

  case 17:
#line 98 "parser.y"
          { yylhs.value.as < ast_ptr > () = std::move(yystack_[0].value.as < ast_ptr > ()); }
#line 869 "parser.cpp"
    break;

  case 18:
#line 102 "parser.y"
                  { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_app(std::move(yystack_[1].value.as < ast_ptr > ()), std::move(yystack_[0].value.as < ast_ptr > ()))); }
#line 875 "parser.cpp"
    break;

  case 19:
#line 103 "parser.y"
              { yylhs.value.as < ast_ptr > () = std::move(yystack_[0].value.as < ast_ptr > ()); }
#line 881 "parser.cpp"
    break;

  case 20:
#line 107 "parser.y"
          { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_int(yystack_[0].value.as < int > ())); }
#line 887 "parser.cpp"
    break;

  case 21:
#line 108 "parser.y"
          { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_lid(std::move(yystack_[0].value.as < std::string > ()))); }
#line 893 "parser.cpp"
    break;

  case 22:
#line 109 "parser.y"
          { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_uid(std::move(yystack_[0].value.as < std::string > ()))); }
#line 899 "parser.cpp"
    break;

  case 23:
#line 110 "parser.y"
                        { yylhs.value.as < ast_ptr > () = std::move(yystack_[1].value.as < ast_ptr > ()); }
#line 905 "parser.cpp"
    break;

  case 24:
#line 111 "parser.y"
           { yylhs.value.as < ast_ptr > () = std::move(yystack_[0].value.as < ast_ptr > ()); }
#line 911 "parser.cpp"
    break;

  case 25:
#line 115 "parser.y"
                                          { yylhs.value.as < ast_ptr > () = ast_ptr(new ast_case(std::move(yystack_[4].value.as < ast_ptr > ()), std::move(yystack_[1].value.as < std::vector<branch_ptr> > ()))); }
#line 917 "parser.cpp"
    break;

  case 26:
#line 119 "parser.y"
                      { yylhs.value.as < std::vector<branch_ptr> > () = std::move(yystack_[1].value.as < std::vector<branch_ptr> > ()); yystack_[1].value.as < std::vector<branch_ptr> > ().push_back(std::move(yystack_[0].value.as < branch_ptr > ())); }
#line 923 "parser.cpp"
    break;

  case 27:
#line 120 "parser.y"
             { yylhs.value.as < std::vector<branch_ptr> > () = std::vector<branch_ptr>(); yylhs.value.as < std::vector<branch_ptr> > ().push_back(std::move(yystack_[0].value.as < branch_ptr > ())); }
#line 929 "parser.cpp"
    break;

  case 28:
#line 124 "parser.y"
                                       { yylhs.value.as < branch_ptr > () = branch_ptr(new branch(std::move(yystack_[4].value.as < pattern_ptr > ()), std::move(yystack_[1].value.as < ast_ptr > ()))); }
#line 935 "parser.cpp"
    break;

  case 29:
#line 128 "parser.y"
          { yylhs.value.as < pattern_ptr > () = pattern_ptr(new pattern_var(std::move(yystack_[0].value.as < std::string > ()))); }
#line 941 "parser.cpp"
    break;

  case 30:
#line 129 "parser.y"
                          { yylhs.value.as < pattern_ptr > () = pattern_ptr(new pattern_constr(std::move(yystack_[1].value.as < std::string > ()), std::move(yystack_[0].value.as < std::vector<std::string> > ()))); }
#line 947 "parser.cpp"
    break;

  case 31:
#line 133 "parser.y"
                                                { yylhs.value.as < definition_ptr > () = definition_ptr(new definition_data(std::move(yystack_[4].value.as < std::string > ()), std::move(yystack_[1].value.as < std::vector<constructor_ptr> > ()))); }
#line 953 "parser.cpp"
    break;

  case 32:
#line 137 "parser.y"
                                     { yylhs.value.as < std::vector<constructor_ptr> > () = std::move(yystack_[2].value.as < std::vector<constructor_ptr> > ()); yylhs.value.as < std::vector<constructor_ptr> > ().push_back(std::move(yystack_[0].value.as < constructor_ptr > ())); }
#line 959 "parser.cpp"
    break;

  case 33:
#line 138 "parser.y"
                  { yylhs.value.as < std::vector<constructor_ptr> > () = std::vector<constructor_ptr>(); yylhs.value.as < std::vector<constructor_ptr> > ().push_back(std::move(yystack_[0].value.as < constructor_ptr > ())); }
#line 965 "parser.cpp"
    break;

  case 34:
#line 142 "parser.y"
                          { yylhs.value.as < constructor_ptr > () = constructor_ptr(new constructor(std::move(yystack_[1].value.as < std::string > ()), std::move(yystack_[0].value.as < std::vector<std::string> > ()))); }
#line 971 "parser.cpp"
    break;


#line 975 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -27;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      22,   -15,   -12,    13,    22,   -27,   -27,   -27,   -27,     3,
     -27,   -27,    24,    17,    36,   -27,     5,    -4,   -27,    23,
     -27,   -27,    -4,    -4,   -27,   -27,     6,     8,    -4,   -27,
     -27,    29,   -27,     5,    21,     2,    -4,    -4,   -27,    -4,
      -4,   -27,   -27,   -27,    38,   -27,     8,     8,    -4,    -4,
      25,   -27,   -27,    14,   -27,    18,    32,   -27,   -27,    40,
      -4,    15,   -27
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     4,     5,     6,     8,     0,
       1,     3,     0,     0,     0,     9,     0,     0,    10,     0,
      33,    20,     0,     0,    21,    22,     0,    14,    17,    19,
      24,    34,    31,     0,     0,     0,     0,     0,     7,     0,
       0,    18,    11,    32,     0,    23,    12,    13,    15,    16,
       0,    29,     8,     0,    27,     0,    30,    25,    26,     0,
       0,     0,    28
  };

  const signed char
  parser::yypgoto_[] =
  {
     -27,   -27,   -27,    33,   -27,     1,   -27,   -22,     4,     7,
     -26,   -27,   -27,     9,   -27,   -27,   -27,    26
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,     6,    12,    31,    26,    27,    28,
      29,    30,    53,    54,    55,     7,    19,    20
  };

  const signed char
  parser::yytable_[] =
  {
      34,    35,    41,    21,     8,    36,    22,    37,     9,    36,
      23,    37,    39,    10,    40,    24,    25,    45,    36,    38,
      37,    13,    41,    41,    36,    18,    37,    57,    62,    16,
       1,     2,    44,    51,    52,    59,    32,    11,    61,    33,
      46,    47,    14,    15,    51,    52,    48,    49,    17,    42,
      50,    15,    60,    56,     0,     0,     0,     0,     0,    43,
       0,     0,    58
  };

  const signed char
  parser::yycheck_[] =
  {
      22,    23,    28,     7,    19,     3,    10,     5,    20,     3,
      14,     5,     4,     0,     6,    19,    20,    15,     3,    13,
       5,    18,    48,    49,     3,    20,     5,    13,    13,    12,
       8,     9,    11,    19,    20,    17,    13,     4,    60,    16,
      36,    37,    18,    19,    19,    20,    39,    40,    12,    20,
      12,    19,    12,    52,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    53
  };

  const signed char
  parser::yystos_[] =
  {
       0,     8,     9,    22,    23,    24,    25,    36,    19,    20,
       0,    24,    26,    18,    18,    19,    12,    12,    20,    37,
      38,     7,    10,    14,    19,    20,    28,    29,    30,    31,
      32,    27,    13,    16,    28,    28,     3,     5,    13,     4,
       6,    31,    20,    38,    11,    15,    29,    29,    30,    30,
      12,    19,    20,    33,    34,    35,    26,    13,    34,    17,
      12,    28,    13
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    21,    22,    23,    23,    24,    24,    25,    26,    26,
      27,    27,    28,    28,    28,    29,    29,    29,    30,    30,
      31,    31,    31,    31,    31,    32,    33,    33,    34,    35,
      35,    36,    37,    37,    38
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     7,     0,     2,
       0,     2,     3,     3,     1,     3,     3,     1,     2,     1,
       1,     1,     1,     3,     1,     6,     2,     1,     5,     1,
       2,     6,     3,     1,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "PLUS", "TIMES", "MINUS", "DIVIDE",
  "INT", "DEFN", "DATA", "CASE", "OF", "OCURLY", "CCURLY", "OPAREN",
  "CPAREN", "COMMA", "ARROW", "EQUAL", "LID", "UID", "$accept", "program",
  "definitions", "definition", "defn", "lowercaseParams",
  "uppercaseParams", "aAdd", "aMul", "app", "appBase", "case", "branches",
  "branch", "pattern", "data", "constructors", "constructor", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,    62,    62,    66,    67,    71,    72,    76,    80,    81,
      85,    86,    90,    91,    92,    96,    97,    98,   102,   103,
     107,   108,   109,   110,   111,   115,   119,   120,   124,   128,
     129,   133,   137,   138,   142
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1304 "parser.cpp"


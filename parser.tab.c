/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parser.y" /* yacc.c:339  */
  
#include <stdio.h> 
#include <stdlib.h> 
#include "ast.h"    
#include "CFG.h"   
            
struct Program *head = NULL;		//Head for abstract syntax tree


#line 76 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_INTNUM = 258,
    TK_FLOATNUM = 259,
    TK_ID = 260,
    TK_INT = 261,
    TK_FLOAT = 262,
    TK_PLUS = 263,
    TK_MINUS = 264,
    TK_MULT = 265,
    TK_DIV = 266,
    TK_ASSIGN = 267,
    TK_EQUAL = 268,
    TK_NOTEQUAL = 269,
    TK_LESS = 270,
    TK_GREATER = 271,
    TK_LESS_EQ = 272,
    TK_GREATER_EQ = 273,
    TK_COLON = 274,
    TK_SEMICOLON = 275,
    TK_RANGE_RES = 276,
    TK_PERIOD = 277,
    TK_COMMA = 278,
    TK_OPEN_PAR = 279,
    TK_CLOSE_PAR = 280,
    TK_OPEN_BRACE = 281,
    TK_CLOSE_BRACE = 282,
    TK_OPEN_BRACKET = 283,
    TK_CLOSE_BRACKET = 284,
    TK_CLASS = 285,
    TK_PRIVATE = 286,
    TK_PUBLIC = 287,
    TK_MAIN = 288,
    TK_RETURN = 289,
    TK_WHILE = 290,
    TK_DO = 291,
    TK_FOR = 292,
    TK_IF = 293,
    TK_ELSE = 294,
    SIGN_MINUS = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "parser.y" /* yacc.c:355  */

	int intnum;
	int floatnum;
	char varid[255];
	struct Program * ptr_Program;
	struct Class * ptr_class;
	struct Member * ptr_Member;     
	struct VarDecl * ptr_VarDecl;
	struct MethodDecl * ptr_MethodDecl;
	struct MethodDef * ptr_MethodDef;
	struct ClassMethodDef * ptr_ClassMethodDef;
	struct MainFunc * ptr_MainFunc;
	struct Param * ptr_Param;
	struct Ident * ptr_Ident;
	struct Type * ptr_Type;
	struct CompoundStmt * ptr_CompoundStmt;
	struct Stmt * ptr_Stmt;
	struct ExprStmt * ptr_ExprStmt;
	struct AssignStmt * ptr_AssignStmt;
	struct RetStmt * ptr_RetStmt;
	struct WhileStmt * ptr_WhileStmt;
	struct DoStmt * ptr_DoStmt;
	struct ForStmt * ptr_ForStmt;
	struct IfStmt * ptr_IfStmt;
	struct Expr * ptr_Expr;
	struct OperExpr * ptr_OperExpr;
	struct RefExpr * ptr_RefExpr;
	struct RefVarExpr * ptr_RefVarExpr;
	struct RefCallExpr * ptr_RefCallExpr;
	struct IdentExpr * ptr_IdentExpr;
	struct CallExpr * ptr_CallExpr;
	struct Arg * ptr_Arg;
	struct UnOp * ptr_UnOp;
	struct AddiOp * ptr_AddiOp;
	struct MultOp * ptr_MultOp;
	struct RelaOp * ptr_RelaOp;
	struct EqltOp * ptr_EqltOp;

#line 196 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   121,   122,   123,   124,   128,   129,   133,
     134,   135,   136,   140,   141,   142,   143,   144,   145,   146,
     147,   151,   152,   155,   156,   160,   161,   165,   166,   169,
     170,   173,   174,   178,   179,   182,   183,   187,   191,   192,
     195,   198,   199,   202,   203,   204,   208,   209,   210,   211,
     215,   216,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   239,   243,   247,   248,   252,   256,   260,   264,   265,
     272,   273,   274,   275,   284,   285,   286,   287,   288,   289,
     292,   295,   296,   299,   300,   303,   304,   305,   306,   309,
     310,   314,   315,   318,   319,   322,   323,   327,   328,   332,
     333,   337,   338
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INTNUM", "TK_FLOATNUM", "TK_ID",
  "TK_INT", "TK_FLOAT", "TK_PLUS", "TK_MINUS", "TK_MULT", "TK_DIV",
  "TK_ASSIGN", "TK_EQUAL", "TK_NOTEQUAL", "TK_LESS", "TK_GREATER",
  "TK_LESS_EQ", "TK_GREATER_EQ", "TK_COLON", "TK_SEMICOLON",
  "TK_RANGE_RES", "TK_PERIOD", "TK_COMMA", "TK_OPEN_PAR", "TK_CLOSE_PAR",
  "TK_OPEN_BRACE", "TK_CLOSE_BRACE", "TK_OPEN_BRACKET", "TK_CLOSE_BRACKET",
  "TK_CLASS", "TK_PRIVATE", "TK_PUBLIC", "TK_MAIN", "TK_RETURN",
  "TK_WHILE", "TK_DO", "TK_FOR", "TK_IF", "TK_ELSE", "SIGN_MINUS",
  "$accept", "PROGRAM", "CLASS_LIST", "CLASS", "MEMBER", "VAR_DECL_LIST",
  "METHOD_DECL_LIST", "METHOD_DEF_LIST", "VAR_DECL", "FUNC_DECL",
  "FUNC_DEF", "CLASS_METHOD_LIST", "CLASS_METHOD_DEF", "MAINFUNC",
  "PARAM_LIST", "PARAM", "IDENT", "TYPE", "COMPOUND_STMT", "STMT_LIST",
  "STMT", "EXPR_STMT", "ASSIGN_STMT", "RET_STMT", "WHILE_STMT", "DO_STMT",
  "FOR_STMT", "IF_STMT", "EXPR", "OPER_EXPR", "UNOP", "ADDIOP", "MULTOP",
  "RELAOP", "EQLTOP", "REF_EXPR", "REF_VAR_EXPR", "REF_CALL_EXPR",
  "IDENT_EXPR", "CALL_EXPR", "ARG_LIST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,  -154,   -19,  -154,    21,    37,    22,  -154,   114,  -154,
    -154,    38,    49,    71,  -154,  -154,   114,  -154,  -154,  -154,
     101,   115,    17,  -154,   136,   120,  -154,   128,   131,   125,
      27,  -154,   130,   130,    75,  -154,  -154,    14,  -154,    36,
    -154,    36,  -154,   221,   133,   285,   135,   137,   175,  -154,
     149,  -154,   213,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,   398,  -154,  -154,  -154,  -154,  -154,  -154,   138,   143,
    -154,  -154,  -154,    91,   130,   130,   130,  -154,  -154,   157,
     140,   120,    47,  -154,   149,   107,    36,    -8,   476,  -154,
     333,  -154,   411,    36,   129,    36,    36,  -154,  -154,   249,
     141,    46,  -154,  -154,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,  -154,   158,    36,  -154,   152,   130,
     130,   130,  -154,   163,  -154,   168,   110,  -154,  -154,   130,
     120,  -154,  -154,   476,    60,   316,  -154,  -154,   346,   151,
     424,   359,  -154,   174,    36,  -154,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,  -154,  -154,   437,   130,
     130,   159,   161,    99,  -154,  -154,    36,  -154,  -154,   285,
      36,    36,   285,   162,   450,  -154,   160,   108,   -13,    84,
     476,  -154,   372,   463,   147,  -154,  -154,  -154,   120,   104,
    -154,  -154,    -9,   172,    36,   285,   120,  -154,  -154,  -154,
     385,  -154,   285,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    45,    43,    44,     0,     0,     0,     8,     0,    34,
       5,     0,     0,     0,     1,     7,     0,     3,    33,     4,
       0,     0,     0,     2,     0,     0,    12,     0,     0,     0,
       0,    37,    20,    20,     0,    72,    73,    98,    43,     0,
      60,     0,    49,     0,     0,     0,     0,     0,     0,    22,
       0,    59,     0,    51,    52,    53,    54,    55,    56,    57,
      58,     0,    70,    74,    75,    76,    77,    78,    71,    91,
      92,    94,    96,     0,    19,    18,    17,    24,    26,     0,
       0,     0,     0,    39,     0,     0,     0,    98,    80,    91,
       0,    64,     0,     0,     0,     0,     0,    47,    21,     0,
      41,     0,    48,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,    10,     0,    14,
      15,    16,    23,     0,    25,     0,    41,    11,    36,     0,
       0,    40,   100,   102,     0,     0,    79,    63,     0,     0,
       0,     0,    46,     0,     0,    28,    81,    82,    83,    84,
      89,    90,    85,    86,    87,    88,    93,    95,     0,    20,
      13,     0,     0,     0,    38,    35,     0,    99,    97,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     0,
     101,    65,     0,     0,    69,    42,    27,     9,     0,     0,
      30,    32,     0,     0,     0,     0,     0,    29,    31,    66,
       0,    68,     0,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,   187,   -29,   164,   122,   -69,   -39,   -73,
     -64,   191,    63,    68,  -153,    74,   116,    69,   -22,   156,
     -44,  -154,  -154,  -154,  -154,  -154,  -154,  -154,   -18,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,   -30,  -154,    90,    92,
    -154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    73,    74,    75,    76,    49,    77,
      78,     8,     9,    10,    82,    83,   101,    11,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    89,    70,    71,    72,
     134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    94,   122,    31,    80,   120,   121,   190,   103,    98,
     179,   197,   124,    30,    12,    69,    85,    30,    69,   -45,
      86,    88,    69,    90,   189,    92,    13,     1,     2,     3,
      35,    36,    37,    38,     3,    98,    39,    14,    85,    35,
      36,    87,    86,    20,    26,    39,   122,    40,    27,    28,
     160,    41,     4,    30,    42,   103,   124,   124,   144,   128,
      41,    43,    44,    45,    46,    47,   145,   133,   135,    69,
     129,    18,   130,    21,    17,   138,    19,   140,   141,    18,
       1,    38,     3,   166,    23,   167,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   124,    22,   158,    50,
      81,    79,    79,    84,     1,    38,     3,   129,   165,   192,
      35,    36,    87,     1,    38,     3,    39,    50,   117,     1,
       2,     3,    24,   118,   178,   181,   174,   129,   184,   196,
     176,    41,   132,   188,   163,     1,    38,     3,   143,    69,
      25,    29,    69,    79,   123,   125,    30,    32,   180,    34,
      33,   201,   182,   183,   100,   116,   191,    93,   203,    95,
     115,    96,   126,    87,   139,    69,   191,   127,   161,   143,
     198,   159,    69,   162,   198,   170,   200,   173,    35,    36,
      37,    38,     3,   163,    39,   177,   195,   187,   123,   125,
     125,   185,   199,    15,    48,    40,   119,    16,    84,    41,
     131,    30,    97,   164,    99,   156,     0,   157,     0,    43,
      44,    45,    46,    47,     0,     0,    35,    36,    87,     0,
       0,     0,    39,     0,    35,    36,    87,     0,    79,   125,
      39,     0,    84,    40,     0,     0,     0,    41,     0,    30,
     102,    91,     0,     0,     0,    41,    84,    43,    44,    45,
      46,    47,    35,    36,    87,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
       0,     0,     0,    41,     0,    30,   142,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    35,    36,
      87,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,    41,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,   104,   105,   106,   107,     0,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   168,   108,   109,   110,   111,
     112,   113,     0,     0,   104,   105,   106,   107,   136,   108,
     109,   110,   111,   112,   113,     0,     0,   104,   105,   106,
     107,   169,   108,   109,   110,   111,   112,   113,     0,     0,
     104,   105,   106,   107,   172,   108,   109,   110,   111,   112,
     113,     0,     0,   104,   105,   106,   107,   193,   108,   109,
     110,   111,   112,   113,     0,     0,   104,   105,   106,   107,
     202,   108,   109,   110,   111,   112,   113,     0,   114,   104,
     105,   106,   107,     0,   108,   109,   110,   111,   112,   113,
       0,   137,   104,   105,   106,   107,     0,   108,   109,   110,
     111,   112,   113,     0,   171,   104,   105,   106,   107,     0,
     108,   109,   110,   111,   112,   113,     0,   175,   104,   105,
     106,   107,     0,   108,   109,   110,   111,   112,   113,     0,
     186,   104,   105,   106,   107,     0,   108,   109,   110,   111,
     112,   113,     0,   194,   104,   105,   106,   107,     0,   108,
     109,   110,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
      30,    45,    75,    25,    33,    74,    75,    20,    52,    48,
     163,    20,    76,    26,    33,    45,    24,    26,    48,     5,
      28,    39,    52,    41,   177,    43,     5,     5,     6,     7,
       3,     4,     5,     6,     7,    74,     9,     0,    24,     3,
       4,     5,    28,     5,    27,     9,   119,    20,    31,    32,
     119,    24,    30,    26,    27,    99,   120,   121,    12,    81,
      24,    34,    35,    36,    37,    38,    20,    85,    86,    99,
      23,     8,    25,    24,     6,    93,     8,    95,    96,    16,
       5,     6,     7,    23,    16,    25,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   160,    26,   116,    30,
      25,    32,    33,    34,     5,     6,     7,    23,   130,    25,
       3,     4,     5,     5,     6,     7,     9,    48,    27,     5,
       6,     7,    21,    32,    25,   169,   144,    23,   172,    25,
     159,    24,    25,    25,    24,     5,     6,     7,    28,   169,
      25,     5,   172,    74,    75,    76,    26,    19,   166,    24,
      19,   195,   170,   171,     5,    12,   178,    24,   202,    24,
      22,    24,     5,     5,    35,   195,   188,    27,     5,    28,
     192,    19,   202,     5,   196,    24,   194,     3,     3,     4,
       5,     6,     7,    24,     9,    24,    39,    27,   119,   120,
     121,    29,    20,     6,    30,    20,    74,     6,   129,    24,
      84,    26,    27,   129,    48,   115,    -1,   115,    -1,    34,
      35,    36,    37,    38,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,     9,    -1,     3,     4,     5,    -1,   159,   160,
       9,    -1,   163,    20,    -1,    -1,    -1,    24,    -1,    26,
      27,    20,    -1,    -1,    -1,    24,   177,    34,    35,    36,
      37,    38,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,     3,     4,
       5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    10,    11,    29,    13,    14,    15,    16,
      17,    18,    -1,    -1,     8,     9,    10,    11,    25,    13,
      14,    15,    16,    17,    18,    -1,    -1,     8,     9,    10,
      11,    25,    13,    14,    15,    16,    17,    18,    -1,    -1,
       8,     9,    10,    11,    25,    13,    14,    15,    16,    17,
      18,    -1,    -1,     8,     9,    10,    11,    25,    13,    14,
      15,    16,    17,    18,    -1,    -1,     8,     9,    10,    11,
      25,    13,    14,    15,    16,    17,    18,    -1,    20,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      -1,    20,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    -1,    20,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    -1,    20,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    -1,
      20,     8,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    -1,    20,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    30,    42,    43,    44,    52,    53,
      54,    58,    33,     5,     0,    44,    52,    54,    53,    54,
       5,    24,    26,    54,    21,    25,    27,    31,    32,     5,
      26,    59,    19,    19,    24,     3,     4,     5,     6,     9,
      20,    24,    27,    34,    35,    36,    37,    38,    46,    49,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    45,    46,    47,    48,    50,    51,    58,
      45,    25,    55,    56,    58,    24,    28,     5,    69,    77,
      69,    20,    69,    24,    61,    24,    24,    27,    49,    60,
       5,    57,    27,    61,     8,     9,    10,    11,    13,    14,
      15,    16,    17,    18,    20,    22,    12,    27,    32,    47,
      48,    48,    50,    58,    51,    58,     5,    27,    59,    23,
      25,    57,    25,    69,    81,    69,    25,    20,    69,    35,
      69,    69,    27,    28,    12,    20,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    79,    80,    69,    19,
      48,     5,     5,    24,    56,    59,    23,    25,    29,    25,
      24,    20,    25,     3,    69,    20,    45,    24,    25,    55,
      69,    61,    69,    69,    61,    29,    20,    27,    25,    55,
      20,    59,    25,    25,    20,    39,    25,    20,    59,    20,
      69,    61,    25,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    43,    43,    44,
      44,    44,    44,    45,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    57,    57,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    63,    64,    64,    65,    66,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     0,     2,     1,    10,
       7,     7,     4,     3,     2,     2,     2,     1,     1,     1,
       0,     2,     1,     2,     1,     2,     1,     5,     3,     6,
       5,     6,     5,     2,     1,     8,     7,     5,     3,     1,
       2,     1,     4,     1,     1,     1,     4,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     2,     5,     7,     9,     7,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     1,     3,     1,     4,     1,     4,
       3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "parser.y" /* yacc.c:1646  */
    { head = alloc_ast_program((yyvsp[-2].ptr_class),(yyvsp[-1].ptr_ClassMethodDef),(yyvsp[0].ptr_MainFunc)); }
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "parser.y" /* yacc.c:1646  */
    { head = alloc_ast_program((yyvsp[-1].ptr_class),NULL,(yyvsp[0].ptr_MainFunc)); }
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "parser.y" /* yacc.c:1646  */
    { head = alloc_ast_program(NULL,(yyvsp[-1].ptr_ClassMethodDef),(yyvsp[0].ptr_MainFunc)); }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 123 "parser.y" /* yacc.c:1646  */
    { head = alloc_ast_program(NULL,NULL,(yyvsp[0].ptr_MainFunc)); }
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "parser.y" /* yacc.c:1646  */
    { head = NULL; }
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_Class_List((yyvsp[-1].ptr_class),(yyvsp[0].ptr_class)); }
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_Class_List(NULL,(yyvsp[0].ptr_class)); }
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_class((yyvsp[-8].varid),(yyvsp[-4].ptr_Member),(yyvsp[-1].ptr_Member)); }
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_class((yyvsp[-5].varid),(yyvsp[-1].ptr_Member),NULL);}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_class((yyvsp[-5].varid),NULL,(yyvsp[-1].ptr_Member));}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_class) = alloc_ast_class((yyvsp[-2].varid),NULL,NULL);}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member((yyvsp[-2].ptr_VarDecl),(yyvsp[-1].ptr_MethodDecl),(yyvsp[0].ptr_MethodDef)); }
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member((yyvsp[-1].ptr_VarDecl),(yyvsp[0].ptr_MethodDecl),NULL); }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member((yyvsp[-1].ptr_VarDecl),NULL,(yyvsp[0].ptr_MethodDef)); }
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member(NULL,(yyvsp[-1].ptr_MethodDecl),(yyvsp[0].ptr_MethodDef)); }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member(NULL,NULL,(yyvsp[0].ptr_MethodDef)); }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member(NULL,(yyvsp[0].ptr_MethodDecl),NULL); }
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member((yyvsp[0].ptr_VarDecl),NULL,NULL); }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Member) = alloc_ast_member(NULL,NULL,NULL); }
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 151 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_VarDecl) = alloc_ast_VarDecl_List((yyvsp[-1].ptr_VarDecl),(yyvsp[0].ptr_VarDecl));}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 152 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_VarDecl) = alloc_ast_VarDecl_List(NULL,(yyvsp[0].ptr_VarDecl)); }
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDecl) = alloc_ast_MethodDecl_List((yyvsp[-1].ptr_MethodDecl),(yyvsp[0].ptr_MethodDecl)); }
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDecl) = alloc_ast_MethodDecl_List(NULL,(yyvsp[0].ptr_MethodDecl)); }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDef) = alloc_ast_MethodDef_List((yyvsp[-1].ptr_MethodDef),(yyvsp[0].ptr_MethodDef)); }
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDef) = alloc_ast_MethodDef_List(NULL,(yyvsp[0].ptr_MethodDef)); }
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_VarDecl) = alloc_ast_vardecl((yyvsp[-4].ptr_Type),(yyvsp[-3].ptr_Ident),(yyvsp[-1].ptr_Expr));}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_VarDecl) = alloc_ast_vardecl((yyvsp[-2].ptr_Type),(yyvsp[-1].ptr_Ident),NULL); }
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDecl) = alloc_ast_methoddecl((yyvsp[-4].varid),(yyvsp[-5].ptr_Type),(yyvsp[-2].ptr_Param)); }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDecl) = alloc_ast_methoddecl((yyvsp[-3].varid),(yyvsp[-4].ptr_Type),NULL); }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDef) = alloc_ast_methoddef((yyvsp[-4].varid),(yyvsp[-5].ptr_Type),(yyvsp[-2].ptr_Param),(yyvsp[0].ptr_CompoundStmt)); }
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MethodDef) = alloc_ast_methoddef((yyvsp[-3].varid),(yyvsp[-4].ptr_Type),NULL,(yyvsp[0].ptr_CompoundStmt)); }
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ClassMethodDef) = alloc_ast_ClassMethodDef_List((yyvsp[-1].ptr_ClassMethodDef),(yyvsp[0].ptr_ClassMethodDef)); }
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ClassMethodDef) = alloc_ast_ClassMethodDef_List(NULL,(yyvsp[0].ptr_ClassMethodDef)); }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ClassMethodDef) = alloc_ast_classmethoddef((yyvsp[-7].ptr_Type),(yyvsp[-6].varid),(yyvsp[-4].varid),(yyvsp[-2].ptr_Param),(yyvsp[0].ptr_CompoundStmt));}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ClassMethodDef) = alloc_ast_classmethoddef((yyvsp[-6].ptr_Type),(yyvsp[-5].varid),(yyvsp[-3].varid),NULL,(yyvsp[0].ptr_CompoundStmt)); }
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MainFunc) = alloc_ast_mainfunc((yyvsp[0].ptr_CompoundStmt)); }
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Param) = alloc_ast_Param_List((yyvsp[-2].ptr_Param),(yyvsp[0].ptr_Param)); }
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Param) = alloc_ast_Param_List(NULL,(yyvsp[0].ptr_Param)); }
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Param) = alloc_ast_Param((yyvsp[-1].ptr_Type),(yyvsp[0].ptr_Ident)); }
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 198 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Ident) = alloc_ast_ident((yyvsp[0].varid),0); }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Ident) = alloc_ast_ident((yyvsp[-3].varid),(yyvsp[-1].intnum)); }
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Type) = alloc_ast_type(NULL,eInt); }
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Type) = alloc_ast_type(NULL,eFloat); }
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Type) = alloc_ast_type((yyvsp[0].varid),eClass); }
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 208 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CompoundStmt) = alloc_ast_compoundstmt((yyvsp[-2].ptr_VarDecl),(yyvsp[-1].ptr_Stmt)); }
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CompoundStmt) = alloc_ast_compoundstmt((yyvsp[-1].ptr_VarDecl),NULL); }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CompoundStmt) = alloc_ast_compoundstmt(NULL,(yyvsp[-1].ptr_Stmt)); }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 211 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CompoundStmt) = alloc_ast_compoundstmt(NULL,NULL); }
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_Stmt_List((yyvsp[-1].ptr_Stmt),(yyvsp[0].ptr_Stmt)); }
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_Stmt_List(NULL,(yyvsp[0].ptr_Stmt)); }
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eExpr,(yyvsp[0].ptr_ExprStmt)); }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eAssign,(yyvsp[0].ptr_AssignStmt)); }
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 229 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eRet,(yyvsp[0].ptr_RetStmt)); }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 230 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eWhile,(yyvsp[0].ptr_WhileStmt)); }
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 231 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eDo,(yyvsp[0].ptr_DoStmt)); }
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 232 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eFor,(yyvsp[0].ptr_ForStmt)); }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eIf,(yyvsp[0].ptr_IfStmt)); }
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eCompound,(yyvsp[0].ptr_CompoundStmt)); }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Stmt) = alloc_ast_stmt(eSemi,NULL); }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ExprStmt) = alloc_ast_exprstmt((yyvsp[-1].ptr_Expr)); }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 243 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_AssignStmt) = alloc_ast_assignstmt((yyvsp[-3].ptr_RefVarExpr),(yyvsp[-1].ptr_Expr)); }
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 247 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RetStmt) = alloc_ast_retstmt((yyvsp[-1].ptr_Expr)); }
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 248 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RetStmt) = alloc_ast_retstmt(NULL); }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_WhileStmt) = alloc_ast_whilestmt((yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Stmt)); }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_DoStmt) = alloc_ast_dostmt((yyvsp[-2].ptr_Expr),(yyvsp[-5].ptr_Stmt)); }
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_ForStmt) = alloc_ast_forstmt((yyvsp[-6].ptr_Expr),(yyvsp[-4].ptr_Expr),(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Stmt)); }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_IfStmt) = alloc_ast_ifstmt((yyvsp[-4].ptr_Expr),(yyvsp[-2].ptr_Stmt),(yyvsp[0].ptr_Stmt)); }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_IfStmt) = alloc_ast_ifstmt((yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Stmt),NULL); }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 272 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Expr) = alloc_ast_expr(eOper,(yyvsp[0].ptr_OperExpr),0,0); }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Expr) = alloc_ast_expr(eRef,(yyvsp[0].ptr_RefExpr),0,0); }
#line 1910 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Expr) = alloc_ast_expr(eIntnum,NULL,(yyvsp[0].intnum),0); }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Expr) = alloc_ast_expr(eFloatnum,NULL,0,(yyvsp[0].floatnum)); }
#line 1922 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eUn,(yyvsp[0].ptr_UnOp)); }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eAddi,(yyvsp[0].ptr_AddiOp)); }
#line 1934 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eMult,(yyvsp[0].ptr_MultOp)); }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 287 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eRela,(yyvsp[0].ptr_RelaOp));}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 288 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eEqlt,(yyvsp[0].ptr_EqltOp)); }
#line 1952 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_OperExpr) = alloc_ast_operexpr(eBracket,(yyvsp[-1].ptr_Expr)); }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 292 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_UnOp) = alloc_ast_unop(eNegative,(yyvsp[0].ptr_Expr)); }
#line 1964 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 295 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_AddiOp) = alloc_ast_AddiOp(ePlus,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 296 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_AddiOp) = alloc_ast_AddiOp(eMinus,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 1976 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 299 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MultOp) = alloc_ast_MultOp(eMul,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 300 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_MultOp) = alloc_ast_MultOp(eDiv,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 1988 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 303 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RelaOp) = alloc_ast_RelaOp(eLT,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 304 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RelaOp) = alloc_ast_RelaOp(eGT,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 2000 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RelaOp) = alloc_ast_RelaOp(eLE,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RelaOp) = alloc_ast_RelaOp(eGE,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 309 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_EqltOp) = alloc_ast_EqltOp(eEQ,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 310 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_EqltOp) = alloc_ast_EqltOp(eNE,(yyvsp[-2].ptr_Expr),(yyvsp[0].ptr_Expr)); }
#line 2024 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 314 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefExpr) = alloc_ast_refexpr(eVar,(yyvsp[0].ptr_RefVarExpr)); }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 315 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefExpr) = alloc_ast_refexpr(eCall,(yyvsp[0].ptr_RefCallExpr)); }
#line 2036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 318 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefVarExpr) = alloc_ast_refvarexpr((yyvsp[-2].ptr_RefExpr),(yyvsp[0].ptr_IdentExpr)); }
#line 2042 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 319 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefVarExpr) = alloc_ast_refvarexpr(NULL,(yyvsp[0].ptr_IdentExpr)); }
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefCallExpr) = alloc_ast_refcallexpr((yyvsp[-2].ptr_RefExpr),(yyvsp[0].ptr_CallExpr)); }
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 323 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_RefCallExpr) = alloc_ast_refcallexpr(NULL,(yyvsp[0].ptr_CallExpr)); }
#line 2060 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 327 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_IdentExpr) = alloc_ast_identexpr((yyvsp[-3].varid),(yyvsp[-1].ptr_Expr)); }
#line 2066 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 328 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_IdentExpr) = alloc_ast_identexpr((yyvsp[0].varid),NULL); }
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CallExpr) = alloc_ast_callexpr((yyvsp[-3].varid),(yyvsp[-1].ptr_Arg)); }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_CallExpr) = alloc_ast_callexpr((yyvsp[-2].varid),NULL); }
#line 2084 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Arg) = alloc_ast_Arg_List((yyvsp[-2].ptr_Arg),(yyvsp[0].ptr_Expr)); }
#line 2090 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.ptr_Arg) = alloc_ast_Arg_List(NULL,(yyvsp[0].ptr_Expr)); }
#line 2096 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2100 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 342 "parser.y" /* yacc.c:1906  */
   
 
int main(int argc, char* argv[])
{
	extern FILE *yyin;
  
	char filename[256];
	char filename2[256];

	yyin = fopen(argv[1], "r");
	printf("AST 를 생성 중입니다....................\n");
	yyparse(); //parsing
	fclose(yyin);
  
	printf("AST 생성완료!\n");
	strcpy(filename, "AST_restore_code.cpp");
	
	fout = fopen(filename, "w");
	printHEAD(head);
	fclose(fout);
	printf("AST 바탕으로 소스코드 복원파일 생성! \n");

	strcpy(filename2,"AST_Symbol_Table.txt");
	fout = fopen(filename2, "w");
	printSymbolTable(head);
	fclose(fout);
	printf("AST 바탕으로 심볼테이블 생성! \n");
  
	strcpy(filename2,"CFG.out");
	fout = fopen(filename2, "w");
	printCFG(head);
	fclose(fout);
	printf("AST 바탕으로 Control Flow Graph 생성! \n");
 	
	strcpy(filename2,"Liveness.out");
	fout = fopen(filename2, "w");
	fclose(fout);
	printf("Liveness는 구현하지 못했습니다... \n");
 
 
   
	return 0;
}

 




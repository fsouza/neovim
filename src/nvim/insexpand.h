#ifndef NVIM_INSEXPAND_H
#define NVIM_INSEXPAND_H

#include "nvim/api/private/defs.h"
#include "nvim/vim.h"

/// state for pum_ext_select_item.
EXTERN struct {
  bool active;
  int item;
  bool insert;
  bool finish;
} pum_want;
//
// Function for use in filtering completion entries.
// Can either be a string referencing a viml function,
// or a LuaRef to a lua function.
typedef enum {
  kFuncTypeString,
  kFuncTypeLuaRef,
  kFuncTypeNil,
} FuncType;
struct compl_filterfunc_S {
  FuncType type;
  union {
    char *name;
    LuaRef func;
  } data;
};
typedef struct compl_filterfunc_S compl_filterfunc_T;

// local filtering function set by vim.api.nvim_complete. Overrides
// the global option 'completefilterfunc', if it exists.
extern compl_filterfunc_T local_filter_func;

#ifdef INCLUDE_GENERATED_DECLARATIONS
# include "insexpand.h.generated.h"
#endif
#endif  // NVIM_INSEXPAND_H

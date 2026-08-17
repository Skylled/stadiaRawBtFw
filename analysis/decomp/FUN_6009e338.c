// 6009e338  FUN_6009e338  size=178 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f131c FUN_600f131c
//   600f147c FUN_600f147c
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_6009e338(undefined4 param_1,char param_2,char *param_3)

{
  int iVar1;
  undefined1 auStack_30 [34];
  undefined1 local_e;
  char local_d;
  int local_c;
  
  thunk_EXT_FUN_0000b5ba(auStack_30,0,0x1f);
  if ((*(int *)(DAT_6009e3ec + 0x9c0) != 0) && ((param_2 == '\0' || (param_2 == '\x01')))) {
    local_d = *param_3;
    if (local_d != '\0') {
      local_c = FUN_600f147c(param_3 + 1,9,&local_e);
      if (local_c == 0) {
        local_c = FUN_600f147c(param_3 + 1,8,&local_e);
      }
      if (local_c != 0) {
        thunk_EXT_FUN_0000b572(auStack_30,local_c,local_e);
      }
    }
    iVar1 = (**(code **)(DAT_6009e3ec + 0x9c0))(param_1,auStack_30);
    if (iVar1 != 0) {
      FUN_600f131c(param_1);
    }
  }
  return;
}



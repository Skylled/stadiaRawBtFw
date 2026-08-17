// 6009c088  FUN_6009c088  size=150 bytes
// --- callers ---
//   6009c124 FUN_6009c124
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554


void FUN_6009c088(char param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  byte local_d;
  char *local_c;
  
  local_c = DAT_6009c120;
  for (local_d = 0; local_d < 10; local_d = local_d + 1) {
    if ((*local_c != '\0') && (iVar1 = thunk_EXT_FUN_0000b554(local_c + 2,param_2,6), iVar1 == 0)) {
      local_c[1] = param_1;
      local_c[8] = param_3;
      return;
    }
    if (*local_c == '\0') break;
    local_c = local_c + 9;
  }
  if (local_d != 10) {
    *local_c = '\x01';
    local_c[1] = param_1;
    local_c[8] = param_3;
    thunk_EXT_FUN_0000b572(local_c + 2,param_2,6);
  }
  return;
}



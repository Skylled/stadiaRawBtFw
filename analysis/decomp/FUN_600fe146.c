// 600fe146  FUN_600fe146  size=164 bytes
// --- callers ---
// --- callees ---
//   600ef476 FUN_600ef476
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600eedee FUN_600eedee
//   60094d24 FUN_60094d24
//   600ab620 FUN_600ab620


void FUN_600fe146(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_38 [8];
  undefined1 local_30;
  char local_2f;
  undefined4 local_2c;
  undefined1 local_28 [2];
  short local_26;
  short local_a;
  
  local_a = 0;
  thunk_EXT_FUN_0000b5ba(local_28,0,0x1c);
  thunk_EXT_FUN_0000b5ba(auStack_38,0,0x10);
  iVar1 = FUN_600ef476(param_1,param_2);
  if (iVar1 != 0) {
    local_a = FUN_600eedee(*(undefined4 *)(param_1 + 8),param_2 + 0xc,param_2 + 0x28,
                           *(undefined4 *)(param_2 + 0x40));
    if (local_a == 0) {
      local_2f = -0x7b;
    }
    else {
      local_28[0] = *(undefined1 *)(param_2 + 8);
      local_26 = local_a;
      local_2f = FUN_600ab620(*param_1,2,local_28);
    }
    if (local_2f != '\0') {
      local_30 = 2;
      local_2c = 0;
      FUN_60094d24(param_1,0x1d10,auStack_38);
    }
  }
  return;
}



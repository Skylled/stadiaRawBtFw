// 600fe1ea  FUN_600fe1ea  size=276 bytes
// --- callers ---
// --- callees ---
//   600ef476 FUN_600ef476
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600eedee FUN_600eedee
//   60094d24 FUN_60094d24
//   600ab620 FUN_600ab620


void FUN_600fe1ea(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_40 [8];
  undefined1 local_38;
  char local_37;
  undefined4 local_34;
  undefined1 local_30 [2];
  ushort local_2e;
  char *local_14;
  char local_d;
  short local_c;
  ushort local_a;
  
  local_d = '\0';
  iVar1 = FUN_600ef476(param_1,param_2);
  if (iVar1 != 0) {
    thunk_EXT_FUN_0000b5ba(local_30,0,0x1c);
    local_14 = *(char **)(param_2 + 0xc);
    local_a = 0;
    while( true ) {
      if ((*(byte *)(param_2 + 9) <= local_a) || (local_14 == (char *)0x0)) goto LAB_600fe296;
      local_c = 0;
      if (*local_14 == '\0') {
        local_c = FUN_600eedee(*(undefined4 *)(param_1 + 8),local_14 + 4,local_14 + 0x20,0);
      }
      else if (*local_14 == '\x01') {
        local_c = FUN_600eedee(*(undefined4 *)(param_1 + 8),local_14 + 4,local_14 + 0x20,
                               local_14 + 0x38);
      }
      if (local_c == 0) break;
      local_a = local_a + 1;
      local_14 = local_14 + 0x50;
    }
    local_d = -0x7b;
LAB_600fe296:
    if (local_d == '\0') {
      local_2e = (ushort)*(byte *)(param_2 + 9);
      local_30[0] = *(undefined1 *)(param_2 + 8);
      local_d = FUN_600ab620(*param_1,3,local_30);
    }
    if (local_d != '\0') {
      thunk_EXT_FUN_0000b5ba(auStack_40,0,0x10);
      local_37 = local_d;
      local_38 = 2;
      local_34 = 0;
      FUN_60094d24(param_1,0x1d10,auStack_40);
    }
  }
  return;
}



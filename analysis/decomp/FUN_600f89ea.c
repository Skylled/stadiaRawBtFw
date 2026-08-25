// 600f89ea  FUN_600f89ea  size=172 bytes
// --- callers ---
// --- callees ---
//   600b5e00 FUN_600b5e00
//   600aa340 FUN_600aa340
//   600bb6dc FUN_600bb6dc
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600f89ea(undefined4 param_1,undefined4 param_2,int param_3,char param_4)

{
  int iVar1;
  char local_2e;
  undefined1 auStack_28 [6];
  char local_22;
  int local_18;
  int local_14;
  undefined1 local_d;
  int local_c;
  
  local_2e = param_4;
  if (param_4 == '\x11') {
    local_2e = '\0';
  }
  local_22 = local_2e;
  thunk_EXT_FUN_0000b572(auStack_28,param_1,6);
  local_14 = FUN_600bb6dc(param_1,1);
  if (local_14 != 0) {
    iVar1 = *(int *)(local_14 + 0x5c);
    do {
      local_c = iVar1;
      if (local_c == 0) {
        return;
      }
      local_18 = *(int *)(local_c + 0x124);
      iVar1 = local_18;
    } while (local_c != param_3);
    if (local_2e == '\0') {
      local_d = 7;
    }
    else {
      if (local_2e == '\x0f') {
        FUN_600aa340(local_c + 0x13c,3,2);
        return;
      }
      local_d = 8;
    }
    FUN_600b5e00(local_c,local_d,auStack_28);
  }
  return;
}



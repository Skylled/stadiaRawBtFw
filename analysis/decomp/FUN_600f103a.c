// 600f103a  FUN_600f103a  size=270 bytes
// --- callers ---
//   6009b368 FUN_6009b368
//   600f15b0 FUN_600f15b0
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013d168 thunk_EXT_FUN_0000b554
//   6009ff18 FUN_6009ff18
//   60098ec8 FUN_60098ec8


void FUN_600f103a(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 local_1c;
  undefined2 local_18;
  int local_14;
  char local_d;
  int local_c;
  
  local_14 = FUN_6009ff18(param_1);
  local_c = 0;
  local_d = '\0';
  local_1c = 0;
  local_18 = 0;
  iVar1 = thunk_EXT_FUN_0000b554(&local_1c,param_2,6);
  if (iVar1 == 0) {
    local_d = '\x01';
  }
  if (local_14 != 0) {
    thunk_EXT_FUN_0000b572(local_14 + 0x74,param_2,6);
    if (param_3 == '\0') {
      if (local_d == '\0') {
        uVar2 = 1;
      }
      else {
        uVar2 = 2;
      }
      *(undefined1 *)(local_14 + 0x7a) = uVar2;
    }
    else {
      *(char *)(local_14 + 0x7a) = param_3;
    }
    local_c = FUN_60098ec8(local_14 + 0x10,2);
    if (local_c == 0) {
      local_c = FUN_60098ec8(local_14 + 100,2);
    }
    if (local_c != 0) {
      if (param_3 == '\0') {
        if (local_d == '\0') {
          *(undefined1 *)(local_c + 0x13c) = 1;
          thunk_EXT_FUN_0000b572(local_c + 0x136,param_2,6);
        }
        else {
          *(undefined1 *)(local_c + 0x13c) = *(undefined1 *)(local_14 + 0x6b);
          thunk_EXT_FUN_0000b572(local_c + 0x136,local_14 + 0x6c,6);
        }
      }
      else {
        *(char *)(local_c + 0x13c) = param_3;
        thunk_EXT_FUN_0000b572(local_c + 0x136,param_2,6);
      }
    }
  }
  return;
}



// 6009b290  FUN_6009b290  size=206 bytes
// --- callers ---
//   600f0d2e FUN_600f0d2e
//   6009b368 FUN_6009b368
// --- callees ---
//   6009ff18 FUN_6009ff18
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009fcf4 FUN_6009fcf4


void FUN_6009b290(undefined4 param_1,undefined2 param_2,undefined4 param_3,char param_4,
                 undefined1 param_5,char param_6)

{
  int iVar1;
  int iVar2;
  int *local_c;
  
  local_c = (int *)FUN_6009ff18(param_1);
  iVar1 = DAT_6009b360;
  if (local_c == (int *)0x0) {
    local_c = (int *)FUN_6009fcf4(param_1);
    if (local_c == (int *)0x0) {
      return;
    }
  }
  else {
    iVar2 = *(int *)(DAT_6009b364 + 0x1170);
    *(int *)(DAT_6009b364 + 0x1170) = iVar2 + 1;
    *local_c = iVar2;
  }
  *(byte *)(local_c + 0x39) = *(byte *)(local_c + 0x39) | 2;
  *(undefined2 *)((int)local_c + 0x5e) = param_2;
  *(undefined1 *)((int)local_c + 0x6a) = param_5;
  thunk_EXT_FUN_0000b572(local_c + 0x19,param_1,6);
  if (param_4 == '\0') {
    *(undefined1 *)((int)local_c + 0x52) = 1;
  }
  if (param_6 == '\0') {
    *(undefined1 *)((int)local_c + 0x7a) = 0;
  }
  if ((*(char *)((int)local_c + 0x6a) == '\x01') && (param_6 == '\0')) {
    thunk_EXT_FUN_0000b572(local_c + 0x1d,param_1,6);
  }
  *(undefined1 *)(iVar1 + 0x1e) = 0;
  return;
}



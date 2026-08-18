// 600d25f4  FUN_600d25f4  size=136 bytes
// --- callers ---
//   600569e4 FUN_600569e4
//   600d265a FUN_600d265a
// --- callees ---
//   600d332a FUN_600d332a
//   600d2298 FUN_600d2298
//   600d15c4 private_heap__600835ac
//   600d3256 FUN_600d3256
//   600d15e4 thunk_EXT_FUN_000080d8


undefined4 FUN_600d25f4(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_2 + 0x43d) != '\0') || (*(char *)(param_2 + 0x43c) != '\0')) {
    FUN_600d2298();
  }
  if (*(int *)(param_2 + 0x418) != 0) {
    FUN_600d332a(param_1,*(int *)(param_2 + 0x418),0);
    FUN_600d3256(param_1,*(undefined4 *)(param_2 + 0x418));
    *(undefined4 *)(param_2 + 0x418) = 0;
  }
  if (*(int *)(param_2 + 0x41c) != 0) {
    private_heap__600835ac();
  }
  cVar1 = *(char *)(param_2 + 0x443);
  private_heap__600835ac(*(undefined4 *)(param_2 + 0x414));
  uVar2 = thunk_EXT_FUN_000080d8(param_2);
  if (cVar1 == '\x01') {
    if (param_1 == (undefined4 *)0x0) {
      uVar2 = 3;
    }
    else {
      uVar2 = (**(code **)(param_1[0xb4] + 0x18))
                        (*param_1,2,&stack0xfffffff7,*(code **)(param_1[0xb4] + 0x18),param_1,
                         0x3000003);
    }
    return uVar2;
  }
  return uVar2;
}



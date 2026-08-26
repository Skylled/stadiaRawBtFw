// 60101ac8  FUN_60101ac8  size=68 bytes
// --- callers ---
//   600df072 FUN_600df072
//   600d38c8 FUN_600d38c8
//   600d37fe FUN_600d37fe
//   600d398a FUN_600d398a
// --- callees ---


undefined4 FUN_60101ac8(int *param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  if (*(char *)*param_1 == '[') {
    iVar1 = param_1[2];
    if (iVar1 + 3U <= (uint)param_1[1]) {
      if (iVar1 == 2) {
        iVar1 = 1;
      }
      else {
        ((char *)*param_1)[iVar1 + -1] = ',';
        *(undefined1 *)(*param_1 + param_1[2]) = 0x20;
        iVar1 = param_1[2] + 1;
      }
      param_1[2] = iVar1;
      return 1;
    }
    uVar2 = 8;
  }
  else {
    uVar2 = 9;
  }
  *(undefined1 *)((int)param_1 + 0xd) = uVar2;
  *(undefined1 *)(param_1 + 3) = uVar2;
  return 0;
}



// 600f0726  FUN_600f0726  size=272 bytes
// --- callers ---
//   600f3378 FUN_600f3378
//   600fd328 FUN_600fd328
// --- callees ---
//   6009ff18 FUN_6009ff18


void FUN_600f0726(undefined4 param_1,ushort param_2,ushort param_3,ushort param_4,ushort param_5)

{
  int iVar1;
  
  iVar1 = FUN_6009ff18(param_1);
  if (((((5 < param_2) && (param_2 < 0xc81)) || (param_2 == 0xffff)) &&
      ((((5 < param_3 && (param_3 < 0xc81)) || (param_3 == 0xffff)) &&
       (((9 < param_5 && (param_5 < 0xc81)) || (param_5 == 0xffff)))))) &&
     ((((param_4 < 0x1f5 || (param_4 == 0xffff)) && (iVar1 != 0)) &&
      ((param_2 != 0xffff || (param_3 != 0xffff)))))) {
    if (param_2 == 0xffff) {
      *(ushort *)(iVar1 + 0xe6) = param_3;
    }
    else {
      *(ushort *)(iVar1 + 0xe6) = param_2;
    }
    if (param_3 == 0xffff) {
      *(ushort *)(iVar1 + 0xe8) = param_2;
    }
    else {
      *(ushort *)(iVar1 + 0xe8) = param_3;
    }
    if (param_4 == 0xffff) {
      *(undefined2 *)(iVar1 + 0xea) = 0;
    }
    else {
      *(ushort *)(iVar1 + 0xea) = param_4;
    }
    if (param_5 == 0xffff) {
      *(undefined2 *)(iVar1 + 0xec) = 2000;
    }
    else {
      *(ushort *)(iVar1 + 0xec) = param_5;
    }
  }
  return;
}



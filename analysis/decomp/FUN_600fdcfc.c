// 600fdcfc  FUN_600fdcfc  size=272 bytes
// --- callers ---
// --- callees ---
//   600f3e00 FUN_600f3e00
//   60095c34 FUN_60095c34
//   60094d24 FUN_60094d24
//   600ef7f8 FUN_600ef7f8


void FUN_600fdcfc(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_11 [5];
  
  if (param_2 != 0) {
    *param_1 = *(undefined2 *)(param_2 + 6);
    iVar1 = FUN_600f3e00(*(undefined2 *)(param_2 + 6),auStack_11,param_1 + 1,param_1 + 4);
    if (iVar1 == 0) {
      return;
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 8) + 7) = 1;
  if (*(short *)(*(int *)(param_1 + 8) + 0x34) == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x34) = 0x17;
  }
  if ((*(int *)(*(int *)(param_1 + 8) + 0xc) == 0) || (*(char *)(*(int *)(param_1 + 8) + 8) != '\0')
     ) {
    if (*(char *)(*(int *)(param_1 + 8) + 8) == '\0') {
      *(undefined1 *)(*(int *)(param_1 + 8) + 8) = 1;
      FUN_60094d24(param_1,0x1d12,0);
    }
    else {
      *(undefined1 *)(param_1 + 0xe) = 3;
    }
  }
  else if (*(char *)(*(int *)(param_1 + 8) + 0x31) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 8) + 0x31) = 0;
    FUN_60094d24(param_1,0x1d0e,0);
  }
  if ((*(int *)(param_1 + 6) != 0) && ((*(byte *)(param_1 + 0xc) & 2) == 0)) {
    if (*(char *)(param_1 + 4) == '\x01') {
      FUN_60095c34(0x1d,0xff,param_1 + 1);
    }
    FUN_600ef7f8(*(undefined4 *)(param_1 + 6),0,param_1 + 1,*param_1,*(undefined1 *)(param_1 + 4),
                 *(undefined2 *)(*(int *)(param_1 + 8) + 0x34));
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 2;
  }
  return;
}



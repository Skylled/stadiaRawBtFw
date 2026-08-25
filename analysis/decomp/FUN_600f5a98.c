// 600f5a98  FUN_600f5a98  size=154 bytes
// --- callers ---
//   600f74a8 FUN_600f74a8
//   600f3da6 FUN_600f3da6
//   600ad8fc FUN_600ad8fc
//   600f7278 FUN_600f7278
//   600f5b32 FUN_600f5b32
//   600f7052 FUN_600f7052
//   600ab9b8 FUN_600ab9b8
// --- callees ---
//   600f3bde FUN_600f3bde
//   600f5a00 FUN_600f5a00
//   600f6dc6 FUN_600f6dc6
//   600f048a FUN_600f048a


void FUN_600f5a98(undefined1 param_1,int param_2,char param_3,char param_4)

{
  int iVar1;
  
  FUN_600f5a00(param_1,param_2,param_3);
  if ((((param_4 != '\0') && (param_2 != 0)) && (*(short *)(param_2 + 0x18) == 4)) &&
     (iVar1 = FUN_600f048a(param_2 + 0xd,*(undefined1 *)(param_2 + 0x13)), iVar1 != 0xffff)) {
    if (param_3 == '\0') {
      iVar1 = FUN_600f6dc6(param_2);
      if (iVar1 == 0) {
        FUN_600f3bde(param_2 + 0xd,0xffff,*(undefined1 *)(param_2 + 0x13));
      }
    }
    else {
      FUN_600f3bde(param_2 + 0xd,0xffff,*(undefined1 *)(param_2 + 0x13));
    }
  }
  return;
}



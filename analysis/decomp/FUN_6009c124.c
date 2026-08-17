// 6009c124  FUN_6009c124  size=108 bytes
// --- callers ---
//   600f139a FUN_600f139a
//   6009ca80 FUN_6009ca80
// --- callees ---
//   600f1334 FUN_600f1334
//   6009c088 FUN_6009c088
//   600f1376 FUN_600f1376


undefined4 FUN_6009c124(char param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined1 *)(DAT_6009c190 + 0xf6);
  if (((param_1 == '\0') || (*(char *)(DAT_6009c190 + 0xf4) != '\0')) &&
     ((param_1 != '\0' || (*(char *)(DAT_6009c190 + 0xf4) != *(char *)(DAT_6009c190 + 0xf5))))) {
    FUN_600f1334(uVar1);
    FUN_6009c088(param_1,param_2,param_3);
    FUN_600f1376(uVar1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// 600c7048  FUN_600c7048  size=94 bytes
// --- callers ---
//   600a08c4 FUN_600a08c4
//   600fcf5c FUN_600fcf5c
// --- callees ---
//   600c6f50 FUN_600c6f50
//   600c6fe4 FUN_600c6fe4


char FUN_600c7048(undefined1 param_1,undefined1 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_14 [12];
  
  iVar2 = FUN_600c6f50(auStack_14,param_1,param_2);
  if (iVar2 == 0) {
    cVar1 = '\x05';
  }
  else {
    cVar1 = FUN_600c6fe4(auStack_14);
    if (cVar1 == '\0') {
      *(undefined1 *)(DAT_600c70a8 + 0x1ab9) = param_1;
      *(undefined1 *)(DAT_600c70a8 + 0x1aba) = param_2;
    }
  }
  return cVar1;
}



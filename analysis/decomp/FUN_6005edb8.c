// 6005edb8  FUN_6005edb8  size=90 bytes
// --- callers ---
//   6005c07c FUN_6005c07c
// --- callees ---
//   600d45e8 FUN_600d45e8
//   6010138c FUN_6010138c
//   6005ebe0 FUN_6005ebe0
//   6010135a FUN_6010135a
//   600d46fe FUN_600d46fe
//   600cc3b4 FUN_600cc3b4


uint FUN_6005edb8(void)

{
  uint uVar1;
  int iVar2;
  undefined4 local_3b4;
  undefined1 auStack_3b0 [20];
  undefined4 local_39c;
  undefined1 auStack_394 [272];
  undefined1 auStack_284 [632];
  
  FUN_600d46fe(auStack_394);
  local_3b4 = DAT_6005ee14;
  FUN_600d45e8(auStack_284,&local_3b4,1);
  FUN_6010135a(auStack_3b0,DAT_6005ee18,0,0,auStack_394,auStack_284);
  uVar1 = FUN_6005ebe0(auStack_3b0);
  if (((uVar1 & 0xff) == 0) &&
     ((iVar2 = FUN_600cc3b4(local_39c), iVar2 != 0 ||
      (uVar1 = FUN_6010138c(auStack_3b0,local_39c), (uVar1 & 0xff) == 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



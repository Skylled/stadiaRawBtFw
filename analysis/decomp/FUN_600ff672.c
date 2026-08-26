// 600ff672  FUN_600ff672  size=34 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b1264 FUN_600b1264


undefined4 FUN_600ff672(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_600b1264(param_1);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// 600ff764  FUN_600ff764  size=58 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b4258 FUN_600b4258


undefined4 FUN_600ff764(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_c = param_2[2];
  iVar1 = FUN_600b4258(param_1,&local_14);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



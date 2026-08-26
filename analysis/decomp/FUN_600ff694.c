// 600ff694  FUN_600ff694  size=60 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   600b3dbc FUN_600b3dbc


undefined4 FUN_600ff694(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_c = param_2[2];
  iVar1 = FUN_600b3dbc(param_1,&local_14);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


